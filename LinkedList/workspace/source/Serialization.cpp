#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

#include <Serialization.hpp>

void mds::Serialization::free_memory(ListNode* head) {
  while (head != nullptr) {
    ListNode* temp_node{head};
    head = head->next;

    delete temp_node;
  }
}

ListNode* mds::Serialization::recreate_list(const std::string &filename) {
  std::ifstream input(filename);
  if (!input.is_open()) {
    return nullptr;
  }

  ListNode* previous_node{nullptr};
  std::vector<ListNode*> nodes;
  std::vector<int> rand_index;

  std::string line;
  while (std::getline(input, line)) {
    ListNode* current = new ListNode();

    if (previous_node != nullptr) {
      previous_node->next = current;
    }

    size_t position = line.find_last_of(';');
    std::string current_data = line.substr(0, position);
    int         current_rand = std::stoi(line.substr(position + 1));
    
    current->data = current_data;
    current->prev = previous_node;

    nodes.push_back(current);
    rand_index.push_back(current_rand);

    previous_node = current;
  }

  for (size_t i = 0; i < nodes.size(); i += 1) {
    if (rand_index[i] < 0 || rand_index[i] >= nodes.size()) {
      nodes[i]->rand = nullptr;
      continue;
    }

    nodes[i]->rand = nodes[rand_index[i]];
  }

  return nodes[0];
}

void mds::Serialization::serialize(ListNode* head, const std::string &filename) {
  std::ofstream output(filename, std::ios::binary);
  if (!output.is_open()) {
    return;
  }

  std::unordered_map<ListNode*, int> list_nodes;
  ListNode* temp_node{head};
  int index{0};
  
  while (temp_node != nullptr) {
    list_nodes[temp_node] = index;

    temp_node = temp_node->next;
    index += 1;
  }

  output.write(reinterpret_cast<const char*>(&index), sizeof(index));

  temp_node = head;
  size_t data_size;
  int rand_index;

  while (temp_node != nullptr) {
    data_size = temp_node->data.size();
    output.write(reinterpret_cast<const char*>(&data_size), sizeof(data_size));
    
    output.write(temp_node->data.data(), data_size);

    rand_index = -1;
    if (temp_node->rand != nullptr) {
      rand_index = list_nodes[temp_node->rand];
    }
    output.write(reinterpret_cast<const char*>(&rand_index), sizeof(rand_index));

    temp_node = temp_node->next;
  }
}

ListNode* mds::Serialization::deserialize(const std::string &filename) {
  std::ifstream input(filename, std::ios::binary);
  if (!input.is_open()) {
    return nullptr;
  }

  size_t total_nodes{0};
  if (!input.read(reinterpret_cast<char*>(&total_nodes), sizeof(total_nodes))) {
    return nullptr;
  }

  if (total_nodes == 0 || total_nodes > 1000000) {
    return nullptr;
  }

  std::vector<ListNode*> nodes(total_nodes);
  std::vector<int>  rand_index(total_nodes);

  ListNode* previous_node{nullptr};
  for (size_t i = 0; i < total_nodes; i += 1) {
    nodes[i] = new ListNode();

    size_t data_size;
    input.read(reinterpret_cast<char*>(&data_size), sizeof(data_size));

    if (data_size > 1000) {
      free_memory(nodes[0]);
      
      return nullptr;
    }

    nodes[i]->data.resize(data_size);
    input.read(&nodes[i]->data[0], data_size);

    input.read(reinterpret_cast<char*>(&rand_index[i]), sizeof(rand_index[i]));
    nodes[i]->prev = previous_node;

    if (previous_node != nullptr) {
      previous_node->next = nodes[i];
    }

    previous_node = nodes[i];
  }

  for (size_t i = 0; i < total_nodes; i += 1) {
    if (rand_index[i] != -1) {
      nodes[i]->rand = nodes[rand_index[i]];
    }
  }

  return nodes[0];
}