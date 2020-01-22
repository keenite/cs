#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class MyClass{
   int val_;
public:
   MyClass(int val) : val_(val) {}
   void inc(int add_up) {
      val_ += add_up;
   }
   int get_val() {return val_;}
};

class MyClassTest : public testing::TestWithParam<int> {};

TEST_P(MyClassTest, MyTest) {
   std::cout << "Example Test Param: " << GetParam() << std::endl;
}

INSTANTIATE_TEST_SUITE_P(MyGroup, MyClassTest, testing::Values(1,2,3,4,5));
