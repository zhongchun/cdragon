#include "strings.h"

#include <cstring>
#include <iostream>

String::String(const char *str) {
  m_data = new char[strlen(str) + 1];
  strcpy(m_data, str);
  std::cout << "Constructor: " << m_data << std::endl;
}

String::String(const String &other) {
  m_data = new char[strlen(other.m_data) + 1];
  strcpy(m_data, other.m_data);
  std::cout << "Copy Constructor: " << m_data << std::endl;
}

String::String(String &&other) noexcept : m_data(other.m_data) {
  other.m_data = nullptr;
  std::cout << "Move Constructor: " << (m_data ? m_data : "null") << std::endl;
}

String &String::operator=(const String &other) {
  std::cout << "Copy Assignment: " << other.m_data << std::endl;
  if (this != &other) {
    delete[] m_data;

    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);
  }
  return *this;
}

String &String::operator=(String &&other) noexcept {
  std::cout << "Move Assignment: " << (other.m_data ? other.m_data : "null")
            << std::endl;
  if (this != &other) {
    delete[] m_data;

    m_data = other.m_data;
    other.m_data = nullptr;
  }
  return *this;
}

String::~String() {
  if (m_data) {
    std::cout << "Destructor: " << m_data << std::endl;
    delete[] m_data;
  } else {
    std::cout << "Destructor: null" << std::endl;
  }
}
