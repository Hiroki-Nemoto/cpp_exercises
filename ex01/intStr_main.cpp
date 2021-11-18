#include "intStr.h"
#include <cstdlib> 
#include <iostream>

int main(void) {
  int i1 = 100;
  char* c1 = intToStr(i1);
  std::cout << c1 << std::endl;
  free(c1);

  char* c2 = (char*)"100";
  int i2 = strToInt(c2);
  std::cout << i2 << std::endl;

  int i3 = -100;
  char* c3 = intToStr(i3);
  std::cout << c3 << std::endl;
  free(c3);

  char* c4 = (char*)"-100";
  int i4 = strToInt(c4);
  std::cout << i4 << std::endl;
}