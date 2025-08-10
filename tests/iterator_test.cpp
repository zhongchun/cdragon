#include <gtest/gtest.h>

#include <istream>
using std::string;
using std::vector;

TEST(IteratorTest, BasicOperator) {
  string s("some string");
  if (s.begin() != s.end()) {
    auto it = s.begin();
    *it = tolower(*it);
  }
  std::cout << s << std::endl;

  for (auto it = s.begin(); it != s.end(); ++it) {
    *it = tolower(*it);
  }
  std::cout << s << std::endl;

  SUCCEED();
}