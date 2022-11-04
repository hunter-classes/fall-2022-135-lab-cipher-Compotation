#include <iostream>


#include "funcs.h"

int main()
{
  std::string encrypted = "N++ td ly zmupne zctpyepo wlyrflrp lyo dzxp nzynpaed xlj mp yph. Elvp mcplvd hspy yppopo, lyo rz zgpc esp pilxawpd ld xlyj etxpd ld yppopo.";
  std::string answer = "C++ is an object oriented language and some concepts may be new. Take breaks when needed, and go over the examples as many times as needed.";
  std::cout << "encrypted: " << encrypted << "\n";
  std::cout << "answer: " << answer << "\n";
  std::cout << "decrypted: " << solve(encrypted) << std::endl;
  return 0;
}
