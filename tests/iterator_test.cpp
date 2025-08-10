#include <gtest/gtest.h>

#include <istream>

using std::string;
using std::vector;

TEST(IteratorTest, BasicOperator) {
  string s("test string");
  if (s.begin() != s.end()) {
    auto it = s.begin();
    *it = toupper(*it);
  }
  std::cout << s << std::endl;

  for (auto it = s.begin(); it != s.end(); ++it) {
    *it = toupper(*it);
  }
  std::cout << s << std::endl;

  SUCCEED();
}

TEST(IteratorTest, Arithmetical) {
  vector<int> text = {1, 3, 5, 6, 7, 9};
  int sought = 5;
  auto beg = text.begin(), end = text.end();
  auto mid = text.begin() + (end - beg) / 2;
  while (mid != end && *mid != sought) {
    if (sought < *mid) {
      end = mid;
    } else {
      beg = mid + 1;
    }
    mid = beg + (end - beg) / 2;
  }
  std::cout << * mid << std::endl;

  SUCCEED();
}