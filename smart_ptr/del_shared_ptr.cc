#include <iostream>
#include <memory>

struct Sample
{
   Sample() {
      std::cout << "Construct\n";
   }
   ~Sample() {
      std::cout << "Destruct\n";
   }
};

void deleter(Sample* x)
{
   std::cout << "Delete function called\n";
   delete[] x;
}

int main()
{
   //Creating shared+ptr with custom deleter
   std::shared_ptr<Sample> p3(new Sample[12], deleter);
   return 0;
   //Destruct first called deleter, then Sample
   //destruct one by one
}
