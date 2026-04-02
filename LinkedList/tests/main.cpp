#include <gtest/gtest.h>
#include "LinkedList.hpp"

TEST(LNKLST, push_ops) {
  mds::LinkedList list;
  list.push_back("C");
  list.push_back("D");
  list.push_front("B");
  list.push_front("A");

  EXPECT_EQ(list[0], "A");
  EXPECT_EQ(list[1], "B");
  EXPECT_EQ(list[2], "C");
  EXPECT_EQ(list[3], "D");

  EXPECT_EQ(list.size(), 4);
}

TEST(LNKLST, pop_ops) {
  mds::LinkedList list;
  list.push_back("B");
  list.push_front("A");
  
  list.pop_back();
  list.pop_front();

  EXPECT_EQ(list.get_ptr(0), nullptr);
  EXPECT_EQ(list.size(), 0);
}

TEST(LNKLST, get_data_ops) {
  mds::LinkedList list;
  list.push_back("C");
  list.push_front("B");
  list.push_back("D");
  list.push_front("A");

  EXPECT_NE(list.get_ptr(0), nullptr);
  EXPECT_NE(list.get_ptr(3), nullptr);
  
  EXPECT_EQ(list[0], "A");
  EXPECT_EQ(list[3], "D");
}

TEST(LNKLST, delete_ops) {
  mds::LinkedList list;
  list.push_front("A");
  list.push_front("B");
  list.push_back("C");
  list.push_back("D");

  list.delete_node(2);
  EXPECT_EQ(list.get_ptr(1)->next, list.get_ptr(2));

  EXPECT_EQ(list.size(), 3);
  
  list.delete_node(2);
  EXPECT_EQ(list.get_ptr(2), nullptr);

  EXPECT_EQ(list.size(), 2);
}

TEST(LNKLST, insert_ops) {
  mds::LinkedList list;
  list.push_front("B");
  list.push_back("D");

  list.insert_node(1, "C");

  EXPECT_EQ(list.get_ptr(0)->next, list.get_ptr(1));
  EXPECT_EQ(list.get_ptr(0)->next->data, list[1]);

  EXPECT_EQ(list.get_ptr(2)->prev, list.get_ptr(1));
  EXPECT_EQ(list.get_ptr(2)->prev->data, list[1]);

  EXPECT_EQ(list.size(), 3);
  
  list.insert_node(0, "A");

  EXPECT_EQ(list.get_ptr(0)->next, list.get_ptr(1));
  EXPECT_EQ(list.get_ptr(0)->next->data, list[1]);

  EXPECT_EQ(list.get_ptr(2)->prev, list.get_ptr(1));
  EXPECT_EQ(list.get_ptr(2)->prev->data, list[1]);

  EXPECT_EQ(list.size(), 4);
}