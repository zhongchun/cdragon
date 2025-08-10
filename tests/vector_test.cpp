#include <gtest/gtest.h>

#include <vector>

using std::string;
using std::vector;

TEST(VectorTest, Init) {
  vector<int> ivec;
  vector<int> ivec2(ivec);
  vector<int> ivec3 = ivec;

  vector<string> articles = {"a", "an", "the"};
  vector<string> v1{"a", "an", "the"};

  vector<int> ivec4(10, -1);
  vector<string> svec1(10, "hi");

  vector<int> ivec5(10);
  vector<string> svec2(10);
  vector<string> svec3(10, "hi");
  vector<string> svec4(10, "hello");
  for (auto item : svec3) {
    std::cout << item << std::endl;
  }
  svec4[1] = "world";
  for (auto item : svec4) {
    std::cout << item << std::endl;
  }

  SUCCEED();
}

TEST(VectorTest, PushBack) {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }
  decltype(v.size()) len = 10;
  ASSERT_EQ(len, v.size());
}