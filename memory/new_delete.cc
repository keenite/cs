#include <iostream>
#include <memory>

class Sample {
public:
   Sample() {
      std::cout << "Construct Sample\n";
   }
   ~Sample() {
      std::cout << "Deconstruct Sample\n";
   }
};

int main()
{
//   Sample *ptr = new Sample();
//   delete ptr;
   Sample* ptrArr = new Sample[5];
   delete[] ptrArr;
   return 0;
}
