#include <String.hpp>

#include <iostream>

int main(void) {
  // default constructor: In -> none, Out <- none
  mds::String def_str;
  std::cout << def_str << std::endl;

  // copy constructor: In -> const char*, Out <- none
  mds::String init_str_1("initializing"); // initializing string by temp char array
  std::cout << init_str_1 << std::endl;
  
  // copy constructor: In -> const String&, Out <- none
  mds::String init_str_2(init_str_1); // initializing string by string
  std::cout << init_str_2 << std::endl;

  // move constructor: In -> String&&, Out <- none
  mds::String tmp_str("temp string");
  mds::String mv_str_1(std::move(tmp_str)); // initializing string by moving pointer to other string
  std::cout << mv_str_1 << std::endl;

  // assign operator: In -> const char*, Out <- String&
  const char* array_1 = "array 1";
  def_str = array_1; // assign string by const char ptr. assign operator for char ptr
  std::cout << def_str << std::endl;

  // assign operator: In -> const String&, Out <- String&
  def_str = init_str_2; // assign existing string by existing string
  std::cout << def_str << std::endl;

  // assign operator (moving): In -> String&&, Out <- String&
  mds::String mv_str_2;
  mv_str_2 = std::move(mv_str_1); // assign string by moving pointer to other string
  std::cout << mv_str_2 << std::endl;

  const char* array_2 = "array 2";
  mds::String cat_str_1;
  const mds::String cat_str_2 = "cat string 2";
  cat_str_1 += "";
  cat_str_1 += array_2;
  cat_str_1 += " + " + cat_str_2;
  std::cout << cat_str_1 << std::endl;

  mds::String cin_str;
  std::cin >> cin_str;
  std::cout << cin_str << std::endl;

  mds::String get_str;
  mds::getline(std::cin, get_str);
  std::cout << get_str << std::endl;

  return 0;
}