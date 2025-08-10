#include "strings_util.h"

#include <iostream>

String createString() {
  String temp("Temporary string");
  return temp;
}

bool test_string() {
  std::cout << "Testing string..." << std::endl;

  std::cout << "========= Creating a string ========" << std::endl;
  String s1("Hello");

  std::cout << "\n========= Copy constructor ========" << std::endl;
  String s2 = s1;

  std::cout << "\n========= Move constructor ========" << std::endl;
  String s3 = createString();

  std::cout << "\n========= Move constructor(explict) ========" << std::endl;
  String s4 = std::move(s1);

  std::cout << "\n========= Copy assignment ========" << std::endl;
  String s5("World");
  s5 = s2;

  std::cout << "\n========= Move assignment ========" << std::endl;
  String s6("Test");
  s6 = std::move(s3);

  std::cout << "\n========= More assignments ========" << std::endl;
  s6 = s6;
  s6 = std::move(s6);

  std::cout << "\n========= Destruction ========" << std::endl;
  return true;
}
