#include <cstdlib>
#include "intStr.h"

char* intToStr(int num) {
  char* s;
  int digit = 0;
  int n = num;

    while(n != 0) {
      n /= 10;
      digit++;
    }

  if(num >= 0) {
    s = (char*)malloc(sizeof(char) * (digit));

    for(int i = digit-1 ; i >= 0 ; i--) {
      s[i] = char('0' + num % 10);
      num /= 10;
    }
  }
  else {
    digit++;
    num *= -1;

    s = (char*)malloc(sizeof(char) * (digit));

    for(int i = digit-1 ; i >= 1 ; i--) {
      s[i] = char('0' + num % 10);
      num /= 10;
    }
    s[0] = '-';
  }
  return s;
}

int strToInt(char* s) {
  int num, nowdig = 1;
  int digit = 0;

    while(s[digit]) {
      digit++;
    }


  if(s[0] == '-') {
    for(int i = digit-1 ; i >= 1 ; i--) {
      num += (int)((s[i]-'0') * nowdig);
      nowdig *= 10;
    }
    num *= -1;
  }
  else {
    for(int i = digit-1 ; i >= 0 ; i--) {
      num += (int)((s[i]-'0') * nowdig);
      nowdig *= 10;
    }
  }
  return num;
}