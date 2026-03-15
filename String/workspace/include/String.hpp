#pragma once
#include <iostream>

namespace mds {
  class String {
   private:
    char* pString_;
    size_t size_;

    void string_copy(char* to_string, const char* from_string);

   public:
    String(); // default constructor
    String(const char* other); // assignement constructor
    String(const String& other); // copy constructor
    String(String&& other) noexcept;

    ~String();

    String& operator=(const char* other); // assign one string by copying array of char
    String& operator=(const String& other); // assign one string by copying other string
    String& operator=(String&& other) noexcept; // assign one string by movimg other string

    const char& operator[](size_t index) const; // get character of const object by index
    char& operator[](size_t index); // get character by index
    
    String operator+(const char* other) const;
    String operator+(const String& other) const; // concatonate two strings to new one
    friend String operator+(const char* left, const String& right);
    String& operator+=(const char* other);
    String& operator+=(const String& other);

    friend std::istream& operator>>(std::istream& is, String& string);
    friend std::istream& getline(std::istream& is, String& string);

    friend std::ostream& operator<<(std::ostream& os, const String& string);

    size_t size() const { return size_; }
    const char* c_str() const { return pString_; };
  };

  String operator+(const char* left, const String& right);

  std::istream& getline(std::istream& is, String& other);
}  // mds - my data structure