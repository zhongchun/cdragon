#include <iostream>

#include "jsons.h"
#include "strings_util.h"

int main(int argc, char *argv[]) {
  std::cout << "===========================================" << std::endl;
  test_string();
  std::cout << "===========================================" << std::endl;
  test_json();
  std::cout << "===========================================" << std::endl;
  return 0;
}