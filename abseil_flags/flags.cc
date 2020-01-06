#include <iostream>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

ABSL_FLAG(int64_t, num, 10, "Parameter can be integer");
ABSL_FLAG(std::string, path, "/home/wenji", "Home folder path");
ABSL_FLAG(std::vector<std::string>, languages,
          std::vector<std::string>({"english","french","german"}), "Languages types");


int main(int argc, char** argv) {
   absl::ParseCommandLine(argc, argv);

   int64_t num = absl::GetFlag(FLAGS_num);
   std::cout << "num = " << num << "\n";

   std::string path = absl::GetFlag(FLAGS_path);
   std::cout << "path = " << path << "\n";

   std::vector<std::string> vec(absl::GetFlag(FLAGS_languages));
   for(auto& s: vec) {printf("%s ", s.c_str());}
   std::cout << std::endl;
   return 0;
}
