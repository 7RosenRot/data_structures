#include <vector>
#include <string>

#include <LinkedList.hpp>

mds::LinkedList::LinkedList() {
  m_head = nullptr;
  m_tail = nullptr;

  m_length = 0;
}

mds::LinkedList::~LinkedList() {
  while (m_head != nullptr) {
    pop_back();
  }
}

ListNode* mds::LinkedList::push_back(std::string push_data) {
  ListNode* current = new ListNode();
  
  if (m_head == nullptr) {
    m_head = current;
  }

  if (m_tail != nullptr) {
    current->prev = m_tail;

    m_tail->next = current;
  }

  m_tail = current;

  current->data = push_data;
  m_length += 1;

  return current;
}

void mds::LinkedList::pop_back() {
  if (m_tail == nullptr) {
    return;
  }
  
  ListNode* current = m_tail;

  if (m_tail == m_head) {
    m_tail = nullptr;
    m_head = nullptr;

    delete current;
    m_length -= 1;
    
    return;
  }

  m_tail = current->prev;
  m_tail->next = nullptr;
  
  delete current;
  m_length -= 1;
}

ListNode* mds::LinkedList::push_front(std::string push_data) {
  ListNode* current = new ListNode();

  if (m_tail == nullptr) {
    m_tail = current;
  }

  if (m_head != nullptr) {
    current->next = m_head;

    m_head->prev = current;
  }

  m_head = current;

  current->data = push_data;
  m_length += 1;

  return current;
}

void mds::LinkedList::pop_front() {
  if (m_head == nullptr) {
    return;
  }

  ListNode* current = m_head;
  
  if (m_head == m_tail) {
    m_head = nullptr;
    m_tail = nullptr;

    delete current;
    m_length -= 1;

    return;
  }

  m_head = current->next;
  m_head->prev = nullptr;

  delete current;
  m_length -= 1;
}

ListNode* mds::LinkedList::get_ptr(int index) {  
  if (index < 0 || index >= m_length) {
    return nullptr;
  }
  
  ListNode* current = m_head;

  while (index > 0) {
    if (current == nullptr) {
      return current;
    }

    current = current->next;

    index -= 1;
  }

  return current;
}

std::string mds::LinkedList::operator[](int index) {
  ListNode* current = get_ptr(index);
  
  if (current == nullptr) {
    return "nullptr";
  }

  return current->data;
}

void mds::LinkedList::insert_node(int index, std::string insert_data) {
  ListNode* current = get_ptr(index);
  
  if (current == nullptr) {
    push_back(insert_data);
    return;
  }

  if (current == m_head) {
    push_front(insert_data);
    return;
  }
  
  ListNode* insert = new ListNode();

  current->prev->next = insert;
  insert->prev = current->prev;

  current->prev = insert;
  insert->next = current;

  insert->data = insert_data;
  m_length += 1;
}

void mds::LinkedList::delete_node(int index) {
  ListNode* current = get_ptr(index);

  if (current == m_head) {
    pop_front();
    return;
  }

  if (current == m_tail) {
    pop_back();
    return;
  }

  ListNode* left = current->prev;
  ListNode* right = current->next;

  left->next = right;
  right->prev = left;

  delete current;
  m_length -= 1;
}