#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include <LinkedList.hpp>

class Serialization {
  public:
    Serialization()  = default;
    ~Serialization() = default;

    void free_memory(ListNode* head);
    
    ListNode* recreate_list(const std::string &filename);
    void serialize(ListNode* head, const std::string &filename);
    ListNode* deserialize(const std::string &filename);
};