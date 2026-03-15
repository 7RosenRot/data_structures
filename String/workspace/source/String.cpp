#include <String.hpp>

mds::String::String() : pString_(nullptr), size_(0) {}

mds::String::String(const char* other) {  
  size_t size = 0;
  while (other[size] != '\0') {
    size += 1;
  }

  this->size_ = size;
  this->pString_ = new char[size_ + 1];
  
  for (size_t i = 0; i < size_; i += 1) {
    pString_[i] = other[i];
  }
  pString_[size_] = '\0';
}

mds::String::String(const String& other) {
  this->pString_ = new char[other.size_ + 1];

  for (size_t i = 0; i < other.size_; i += 1) {
    this->pString_[i] = other.pString_[i];
  }
  this->pString_[other.size_] = '\0';

  this->size_ = other.size_;
}

mds::String::String(String&& other) noexcept : pString_(other.pString_), size_(other.size_) {
  other.pString_ = nullptr;
  other.size_ = 0;
}

mds::String::~String() {
  if (pString_ != nullptr) {
    delete[] pString_;
  }

  pString_ = nullptr;
  size_ = 0;
}

mds::String& mds::String::operator=(const char* other) {
  size_t size = 0;
  while (other[size] != '\0') {
    size += 1;
  }

  if (this->pString_ != nullptr) {
    delete[] this->pString_;
  }
  
  this->size_ = size;
  this->pString_ = new char[size_ + 1];
  
  for (size_t i = 0; i < size_; i += 1) {
    pString_[i] = other[i];
  }
  pString_[size_] = '\0';

  return *this;
}

mds::String& mds::String::operator=(const String& other) {
  if (this->pString_ != nullptr) {
    delete[] this->pString_;
  }

  this->size_ = other.size_;
  this->pString_ = new char[this->size_ + 1];

  for (size_t i = 0; i < this->size_; i += 1) {
    this->pString_[i] = other.pString_[i];
  }
  this->pString_[this->size_] = '\0';

  return *this;
}

mds::String& mds::String::operator=(String&& other) noexcept {
  if (this->pString_ != nullptr) {
    delete[] this->pString_;
  }

  this->size_ = other.size_;
  this->pString_ = other.pString_;

  other.size_ = 0;
  other.pString_ = nullptr;

  return *this;
}

char& mds::String::operator[](size_t index) {  
  if (index >= this->size_) {
    static char null = '\0';
    return null;
  }
  
  return this->pString_[index];
}

const char& mds::String::operator[](size_t index) const {
  if (index >= this->size_) {
    static char null = '\0';
    return null;
  }

  return this->pString_[index];
}

mds::String mds::String::operator+(const char* other) const {
  size_t size = 0;
  while (other[size] != '\0') {
    size += 1;
  }
  
  mds::String result;
  result.size_ = this->size_ + size;
  result.pString_ = new char[result.size_ + 1];

  for (size_t i = 0; i < this->size_; i += 1) {
    result.pString_[i] = this->pString_[i];
  }

  for (size_t i = 0; i < size; i += 1) {
    result.pString_[this->size_ + i] = other[i];
  }

  result.pString_[result.size_] = '\0';

  return result;
}

mds::String mds::String::operator+(const String& other) const {
  mds::String result;
  result.size_ = this->size_ + other.size_;
  result.pString_ = new char[result.size_ + 1];

  for (size_t i = 0; i < this->size_; i += 1) {
    result.pString_[i] = this->pString_[i];
  }

  for (size_t i = 0; i < other.size_; i += 1) {
    result.pString_[this->size_ + i] = other.pString_[i];
  }

  result.pString_[result.size_] = '\0';

  return result;
}

mds::String mds::operator+(const char* left, const String& right) {
  size_t size = 0;
  while (left[size] != '\0') {
    size += 1;
  }

  mds::String result;
  result.size_ = size + right.size_;
  result.pString_ = new char[result.size_ + 1];

  for (size_t i = 0; i < size; i += 1) {
    result.pString_[i] = left[i];
  }

  for (size_t i = 0; i < right.size_; i += 1) {
    result.pString_[size + i] = right.pString_[i];
  }

  result.pString_[result.size_] = '\0';

  return result;
}

mds::String& mds::String::operator+=(const char* other) {
  size_t size = 0;
  while (other[size] != '\0') {
    size += 1;
  }

  char* buffer = new char[this->size_ + size + 1];
  
  for (size_t i = 0; i < this->size_; i += 1) {
    buffer[i] = this->pString_[i];
  }

  for (size_t i = 0; i < size; i += 1) {
    buffer[this->size_ + i] = other[i];
  }
  
  buffer[this->size_ + size] = '\0';

  if (this->pString_ != nullptr) {
    delete[] this->pString_;
  }

  this->size_ = this->size_ + size;
  this->pString_ = buffer;

  return *this;
}

mds::String& mds::String::operator+=(const String& other) {
  char* buffer = new char[this->size_ + other.size_ + 1];

  for (size_t i = 0; i < this->size_; i += 1) {
    buffer[i] = this->pString_[i];
  }

  for (size_t i = 0; i < other.size_; i += 1) {
    buffer[this->size_ + i] = other.pString_[i];
  }

  buffer[this->size_ + other.size_] = '\0';

  if (this->pString_ != nullptr) {
    delete[] this->pString_;
  }

  this->size_ = this->size_ + other.size_;
  this->pString_ = buffer;

  return *this;
}

std::istream& mds::operator>>(std::istream& is, mds::String& string) {
  size_t size = 16;
  char* buffer = new char[size];

  char character;
  while (is.get(character) && std::isspace(character));

  if (is.eof()) {
    return is;
  }

  buffer[0] = character;

  size_t index = 1;
  while (is.get(character) && !std::isspace(character)) {
    buffer[index] = character;
    index += 1;

    if (index + 1 >= size) {
      size *= 2;
      char* up_buffer = new char[size];

      for (size_t i = 0; i < index; i += 1) {
        up_buffer[i] = buffer[i];
      }

      delete[] buffer;
      
      buffer = up_buffer;
      up_buffer = nullptr;
    }
  }

  if (character != '\n') {
    is.putback(character);
  }

  if (string.pString_ != nullptr) {
    delete[] string.pString_;
  }

  string.size_ = index;
  string.pString_ = new char[string.size_ + 1];

  for (size_t i = 0; i < string.size_; i += 1) {
    string.pString_[i] = buffer[i];
  }
  string.pString_[string.size_] = '\0';

  delete[] buffer;

  return is;
}

std::istream& mds::getline(std::istream& is, mds::String& string) {
  size_t size = 16;
  char* buffer = new char[size];
  
  char character;

  size_t index = 0;
  while (is.get(character) && character != '\n') {
    buffer[index] = character;
    index += 1;

    if (index + 1 >= size) {
      size *= 2;
      char* up_buffer = new char[size];

      for (size_t i = 0; i < index; i += 1) {
        up_buffer[i] = buffer[i];
      }

      delete[] buffer;

      buffer = up_buffer;
      up_buffer = nullptr;
    }
  }

  if (string.pString_ != nullptr) {
    delete[] string.pString_;
  }

  string.size_ = index;
  string.pString_ = new char[string.size_ + 1];

  for (size_t i = 0; i < string.size_; i += 1) {
    string.pString_[i] = buffer[i];
  }
  string.pString_[string.size_] = '\0';

  delete[] buffer;
  
  return is;
}

std::ostream& mds::operator<<(std::ostream& os, const mds::String& string) {
  if (string.pString_ == nullptr) {
    return os;
  }

  os << string.pString_;
  
  return os;
}
