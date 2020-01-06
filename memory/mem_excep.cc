#include <iostream>
#include <new>

int main()
{
   try {
      while(true) {
         int* ptr = new int[1000000];
      }
   } catch (std::bad_alloc& excepObj) {
      std::cout << "Bad alloc exception: Out of memory " << excepObj.what() << '\n';
   }
   return 0;
}
