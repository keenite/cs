#include <iostream>
#include <list>
#include <iterator>

void print_list(std::list<int>& ln)
{
   for (auto& num: ln) {
      std::cout << num << " ";
   }
   std::cout << std::endl;
}

int main()
{
   std::list<int> ln;

   ln.push_back(5);
   ln.push_back(6);

   ln.push_front(2);
   ln.push_front(1);

   print_list(ln);

   std::list<int>::iterator it = ln.begin();
   it++;
   it++;

   ln.insert(it, 4);
   print_list(ln);

   it = ln.begin();
   it++;
   it++;
   ln.erase(it);
   print_list(ln);

   //Remove all number larger 3
   ln.remove_if([](int elem){
                  if (elem > 3)
                     return true;
                  else
                     return false;
                });
   print_list(ln);
}
