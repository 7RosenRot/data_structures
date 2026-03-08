#include <gtest/gtest.h>
#include "LinkedList.hpp"

TEST(lnklst_TEST, insertion) {
  LinkedList list;
  list.push_front("A");
  list.push_back("C");

  list.insert_node(1, "B");

  EXPECT_EQ(list[1], "B");
  EXPECT_EQ(list[2], "C");
}