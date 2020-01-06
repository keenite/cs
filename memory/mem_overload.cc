#include <iostream>
#include <cstdlib>

void* operator new(size_t sz)
{
   void* m = malloc(sz);
   std::cout << "User defined Operator::new " << sz << std::endl;

   return m;
}

void operator delete(void* m)
{
   std::cout << "User defined Operator::delete\n";
   free(m);
}

void* operator new[](size_t sz)
{
   void* m = malloc(sz);
   std::cout << "User defined Operator::new[] " << sz << std::endl;
   return m;
}

void operator delete[](void* m)
{
   std::cout << "User defined Operator::delete[]\n";
   free(m);
}

class Dummy
{
public:
   Dummy() {
      std::cout << "Dummy :: constructor" << std::endl;
   }
   ~Dummy() {
      std::cout << "Dummy :: deconstructor" << std::endl;
   }
};

int main()
{
   int* ptr = new int;
   delete ptr;

   Dummy* dummyPtr = new Dummy;
   delete dummyPtr;

   int* ptrArr = new int[5];
   delete[] ptrArr;

   return 0;
}
