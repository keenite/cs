#include <iostream>
#include "absl/strings/str_format.h"
#include "gtest/gtest.h"

int main() {
   std::string s = absl::StrFormat("Welcome to %s, Number %d!", "The town", 6);
   EXPECT_EQ("Welcome to The town, Numb1er 6!", s);
   //ASSERT_EQ("Welcome to The town, Numb1er 6!", s);
   return 0;
}
