#include <iostream>
#include <map>
#include <string>
#include <iterator>

int main()
{
   std::map<std::string, int> words_map;
   words_map.insert(std::make_pair("earth", 1));
   words_map.insert(std::make_pair("moon", 2));
   words_map["sun"] = 3;
   words_map["earth"] = 4;

//   std::map<std::string, int>::iterator it = words_map.begin();
//   while(it != words_map.end()) {
//      std::cout << it->first << "::" << it->second << std::endl;
//      it++;
//   }
   for (auto& it: words_map) {
      std::cout << it.first << "::" << it.second << std::endl;
   }

   //The insert return first is iterator, second is bool
   if (words_map.insert(std::make_pair("earth", 1)).second == false) {
      std::cout << "Error: key existed" << std::endl;
   }

   if (words_map.find("sun") != words_map.end()) {
      std::cout << "word sun found" << std::endl;
   }

   if (words_map.find("mars") == words_map.end()) {
      std::cout << "word mars not found" << std::endl;
   }

   return 0;
}
