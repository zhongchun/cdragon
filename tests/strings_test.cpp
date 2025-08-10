#include <gtest/gtest.h>

#include <iostream>

#include "../src/strings_util.h"

using std::string;

TEST(ExampleTest, BasicAssertions) {
  EXPECT_EQ(1, 1);

  EXPECT_NE(1, 2);

  EXPECT_GT(2, 1);

  EXPECT_TRUE(true);
}

TEST(StringsUtilTest, BasicOperation) {
  EXPECT_TRUE(test_string());
  SUCCEED();
}

// ======================
// 构造函数测试
// ======================
TEST(StringTest, ConstructorWithCString) {
  String s("Hello");
  // 目前没有返回值可以断言，但如果没有崩溃，构造成功
  SUCCEED();  // 明确表示测试通过
}

// ======================
// 拷贝构造函数测试
// ======================
TEST(StringTest, CopyConstructor) {
  String s1("Hello");
  String s2 = s1;  // 调用拷贝构造函数
  (void)s2;        // 避免未使用变量警告
  SUCCEED();
}

// ======================
// 移动构造函数测试（从临时对象）
// ======================
TEST(StringTest, MoveConstructorFromTemporary) {
  String s3 = createString();  // 应该调用移动构造函数
  (void)s3;
  SUCCEED();
}

// ======================
// 移动构造函数测试（显式 std::move）
// ======================
TEST(StringTest, MoveConstructorExplicit) {
  String s1("Temporary");
  String s4 = std::move(s1);  // 应该调用移动构造
  (void)s4;
  SUCCEED();
}

// ======================
// 拷贝赋值运算符测试
// ======================
TEST(StringTest, CopyAssignment) {
  String s5("World");
  String s2("Hello");
  s5 = s2;  // 调用拷贝赋值
  (void)s5;
  SUCCEED();
}

// ======================
// 移动赋值运算符测试
// ======================
TEST(StringTest, MoveAssignment) {
  String s6("Test");
  String s3("Temporary");
  s6 = std::move(s3);  // 调用移动赋值
  (void)s6;
  SUCCEED();
}

// ======================
// 自赋值测试（拷贝）
// ======================
TEST(StringTest, SelfCopyAssignment) {
  String s6("Self");
  s6 = s6;  // 拷贝自赋值
  SUCCEED();
}

// ======================
// 自赋值测试（移动）
// ======================
TEST(StringTest, SelfMoveAssignment) {
  String s6("SelfMove");
  s6 = std::move(s6);  // 移动自赋值
  SUCCEED();
}

TEST(StdStringTest, Initialization) {
  string s1;  // Construction default, ""
  string s2(s1);

  string s3 = "hiya";  // Copy initialization
  string s4(10, 'c');  // Construction directly

  string s5("value");  // Construction directly

  string s6 = string(10, 'c');  // Copy initialization

  SUCCEED();
}
