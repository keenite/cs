#include <iostream>
#include  <memory> // We need to include this for shared_ptr
int main()
{
   //Creating a shared ptr through make_shared
   std::shared_ptr<int> p1 = std::make_shared<int>();

   //The ref count is 1 at beginning
   std::cout << "The ref count is = " << p1.use_count() << std::endl;

   //At beginning *p1 is 0
   std::cout << "p1 = " << *p1 << std::endl;

   *p1 = 100;
   std::cout << "p1 = " << *p1 << std::endl;

   //Shows the reference count
   std::cout << "The ref count is = " << p1.use_count() << std::endl;

   //Second shared ptr will point to the same ptr too but ref + 1
   std::shared_ptr<int> p2(p1);

   //After p2 point to p1, the ref count all 2
   std::cout << "p1 Reference count = " << p1.use_count() << std::endl;
   std::cout << "p2 Reference count = " << p2.use_count() << std::endl;

   std::cout << "Reset p1" << std::endl;
   p1.reset();

   //After reset p1, p1 ref count is 0 and p2 is 1
   std::cout << "p1 Reference count = " << p1.use_count() << std::endl;
   std::cout << "p2 Reference count = " << p2.use_count() << std::endl;

   //reset p1 pointer with number 200 make the reference become 1 again
   p1.reset(new int(200));
   std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

   //mark a shared_ptr as nullptr will de-atach
   p1 = nullptr;
   std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

   if (!p1) {
      std::cout << "p1 is NULL" << std::endl;
   }

   return 0;
}
