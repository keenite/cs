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

TEST(Mytest, inc5) {
   MyClass mc(100);
   mc.inc(5);
   ASSERT_EQ(mc.get_val(), 105);
}

struct MyClassTest: public testing::Test {
   MyClass *mc;
   void SetUp() {
      cout << "Set up...\n";
      mc = new MyClass(100);
   }
   void TearDown() {
      cout << "Tear down...\n";
      delete mc;
   }
};

//Fixture class test
TEST_F(MyClassTest, inc_5) {
   mc->inc(5);
   ASSERT_EQ(mc->get_val(), 105);
}

TEST_F(MyClassTest, inc_10) {
   mc->inc(10);
   ASSERT_EQ(mc->get_val(), 110);
}
