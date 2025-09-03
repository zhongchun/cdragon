#include <gtest/gtest.h>

#include <set>

TEST(SmartPointerTest, SharedPtr) {
  std::shared_ptr<float> p0;
  std::shared_ptr<double> p1 = std::make_shared<double>(1.0);
  std::shared_ptr<int> p2(new int(42));

  ASSERT_FALSE(p0);
  ASSERT_EQ(*p1, 1.0);
  ASSERT_EQ(*p2, 42);
}

TEST(SmartPointerTest, UniquePtr) {
  std::unique_ptr<double> p1;
  std::unique_ptr<int> p2(new int(42));

  ASSERT_FALSE(p1);
  ASSERT_EQ(*p2, 42);

  std::unique_ptr<int> p3(p2.release());
  ASSERT_FALSE(p2);
  ASSERT_TRUE(p3);
  ASSERT_EQ(*p3, 42);

  std::unique_ptr<int> p4(new int(52));
  p3.reset(p4.release());
  ASSERT_TRUE(p3);
  ASSERT_FALSE(p4);
  ASSERT_EQ(*p3, 52);
}

TEST(SmartPointerTest, WeakPtr) {
  auto p = std::make_shared<int>(42);
  std::weak_ptr<int> wp(p);

  ASSERT_TRUE(wp.lock());
  ASSERT_EQ(*(wp.lock()), 42);

  std::set<int> s;
  s.insert(1);
  s.insert(3);
  s.insert(2);
  s.insert(1);

  for (auto i = s.begin(); i != s.end(); ++i) {
    std::cout << *i << std::endl;
  }
}