#include <iostream>

void fun3() {
   int v3 = 3;
   std::cout << v3 << std::endl;
}

void fun2() {
   int v2 = 2;
   std::cout << v2 << std::endl;
   fun3();
}

void fun1() {
   int v1 = 1;
   std::cout << v1 << std::endl;
   fun2();
}

int main() {
   int v0 = 10;
   std::cout << v0 << std::endl;
   fun1();
   return 0;
}
