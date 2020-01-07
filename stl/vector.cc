#include <iostream>
#include <vector>

class Sample
{
public:
   Sample(const Sample& obj) {
      std::cout << "Sample : Copy Constructor" << std::endl;
   }
   Sample(int val):value(val) {
      std::cout << "Sample : Default Constructor" << std::endl;
   }
   Sample(Sample&& obj) {
      std::cout << "Sample : moved Constructor" << std::endl;
   }

   Sample & operator=(const Sample& obj) {
      std::cout << "Sample : Assignment Constructor" << std::endl;
   }
   int value;
};

void stl_push_back_copy()
{
   std::cout << "std::vector<Sample> vec;\n";
   std::vector<Sample> vec;
   std::cout << "Sample obj and obj1\n";
   Sample obj(1);
   std::cout << "vec.push_back(obj)\n";
   vec.push_back(obj);
   std::cout << "vec.emplace(obj)\n";
   vec.emplace_back(2);
}

int main()
{
   std::cout << "###########stl push back etc operations is copy#########\n";
   stl_push_back_copy();
   return 0;
}
