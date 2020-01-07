#include <iostream>
#include "absl/strings/str_format.h"
#include "absl/strings/str_split.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "absl/strings/substitute.h"
#include "absl/strings/numbers.h"

#include "gtest/gtest.h"

void print_vec(std::vector<absl::string_view>& v)
{
   for (unsigned i = 0; i < v.size(); i++) {
      absl::PrintF("(%d)[%s] ", i, v[i]);
   }
   std::cout << std::endl;
}

void str_format()
{
   //TODO: StrFormat usage
   std::string s = absl::StrFormat("Welcome to %s, Number %d!", "The town", 6);
   EXPECT_EQ("Welcome to The town, Number 6!", s);

   //TODO: FPrintF usage
   FILE* fp;
   fp = fopen("/home/wenji/cpp/abseil_strings/testfile.txt", "w+");
   if (fp != nullptr) {
      absl::FPrintF(fp, "%s", "This is an apple!\n");
   } else {
      std::cout << "No such file found\n";
   }

   //TODO: StrAppendFormat
   std::cout << absl::StrAppendFormat(&s, "This is %s home\n", "wenji's");
}

void str_split()
{
   //TODO: StrSplit() usage
   std::vector<absl::string_view> v = absl::StrSplit("a12,b345,c67890", ",");
   print_vec(v);

   //TODO: StrSplit will split to empty also
   std::vector<absl::string_view> v1 = absl::StrSplit("a,b,,c", ',');
   print_vec(v1);
   //If delimiter is "", Split string one by one

   std::vector<absl::string_view> v2 = absl::StrSplit("a,b;c", absl::ByAnyChar(",;"));
   print_vec(v2);

   std::vector<absl::string_view> v3 = absl::StrSplit("a,b,c", absl::MaxSplits(',', 1));
   print_vec(v3);

   std::vector<absl::string_view> v4 = absl::StrSplit("1234567", absl::ByLength(2));
   print_vec(v4);

   std::vector<absl::string_view> v5 = absl::StrSplit(",a, ,b,", ",", absl::SkipEmpty());
   print_vec(v5);

   std::vector<absl::string_view> v6 = absl::StrSplit(",a, ,b,", ",", absl::SkipWhitespace());
   print_vec(v6);
}

void str_append()
{
   std::string s1 = "A string ";
   std::string another = "and another string ";
   absl::StrAppend(&s1, "and some other string ", another);
   std::cout << s1 << std::endl;
}

void str_cat()
{
   std::string s1;
   //Strcat can merge arbitrary number of strings
   s1 = absl::StrCat("A String ", "another string ", "yet another string");
   //StrCat() also can mix types, including std::string, string_view, literals
   std::string s2;
   std::string s3 = "Foo";
   absl::string_view sv1 = " new";
   //StrCat can add integer, boolean, hex values too
   s2 = absl::StrCat(s3, sv1, " a literal", 5, " ", absl::Hex(4096));
   std::cout << s2 << std::endl;
}

struct MyFormatter {
   void operator()(std::string *out, int i) const {
      out->append(std::to_string(i));
   }
};

void str_join()
{
   std::vector<std::string> v = {"foo", "bar", "baz"};
   std::string s = absl::StrJoin(v, "-");
   std::cout << s << std::endl;

   std::string s1 = absl::StrJoin({"This", "is", "an", "apple"}, "-");
   std::cout << s1 << std::endl;

   std::string s2 = absl::StrJoin({1,2,3,-4}, "-");
   std::cout << s2 << std::endl;

   int x = 1, y = 2, z = 3;
   std::vector<int *> v1 = {&x, &y, &z};
   std::string s3 = absl::StrJoin(v1, "-");
   std::cout << s3 << std::endl;

   std::map<std::string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};
   std::string s4 = absl::StrJoin(m, ",", absl::PairFormatter("="));
   std::cout << s4 << std::endl;

   std::vector<int> v2 = {1,2,3,4};
   //The default formmater is AlphaNumFormatter()
   std::string s5 = absl::StrJoin(v2, "-", MyFormatter());
}


//substitute support types: string, integer, float, bool, pointer(print as
//0x<addr>)
void str_substitute() {
   //FIXME: Bad because need to worry buffer size and null-termination
   //std::string GetErrorMessage(char *op, char *user, int id) {
   //     char buffer[50];
   //       sprintf(buffer, "Error in %s for user %s (id %i)", op, user, id);
   //         return buffer;
   //}
   absl::string_view op = "main()";
   absl::string_view user = "wenji";
   int id = 10;

   //Better way: avoid pitfalls but hard to read
   std::cout << absl::StrCat("Error in ", op, "for user ", user, " (", id, ") ") << std::endl;

   //Best way
   std::cout << absl::Substitute("Error in $0 for user $1 ($2)", op, user, id) << std::endl;
}

int main() {
   absl::PrintF("##############StrFormat#############\n");
   str_format();

   absl::PrintF("\n##############StrSplit#############\n");
   str_split();

   absl::PrintF("\n##############StrAppend#############\n");
   str_append();

   absl::PrintF("\n##############StrCat#############\n");
   str_cat();

   absl::PrintF("\n##############StrJoin#############\n");
   str_join();

   absl::PrintF("\n##############StrSubstitute#############\n");
   str_substitute();

   absl::PrintF("\n##############StrContains#############\n");
   absl::string_view msg = "Error in the context!";
   if (absl::StrContains(msg, "Error")) {
      std::cout << "Found match string\n";
   } else {
      std::cout << "Not found match string\n";
   }

   absl::PrintF("\n##############SimpleAtox#############\n");
   absl::string_view val = "100";
   int res;
   std::cout << absl::SimpleAtoi(val, &res) << std::endl;


   return 0;
}
