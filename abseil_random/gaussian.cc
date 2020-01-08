#include <iostream>
#include "absl/random/random.h"
#include "absl/random/gaussian_distribution.h"

int main()
{
   absl::BitGen gen;
   absl::gaussian_distribution<float> test(10.0, 5.0);
   for (int i = 0; i < 100; i++) {
      std::cout << test(gen) << std::endl;
   }
   return 0;
}
