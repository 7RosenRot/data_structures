#pragma once
#include <string>

struct ListNode {
  ListNode* prev{nullptr};
  ListNode* next{nullptr};
  ListNode* rand{nullptr};
  std::string data;
};

class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  
  ListNode* push_back(std::string push_data);
  void pop_back();
  
  ListNode* push_front(std::string push_data);
  void pop_front();
  
  void insert_node(int index, std::string insert_data);
  void delete_node(int index);
  
  ListNode* get_ptr(int index);
  std::string operator[](int index);
  
  int size() { return m_length; }
private:
  ListNode* m_head;
  ListNode* m_tail;

  int m_length;
};