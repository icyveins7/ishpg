#include "shared.h"
#include <iostream>

int main(){

  printf("%d\n", sharedaddscale(2,3,4));
  printf("%d\n", notusedbyshared(5,3));
  printf("%f\n", excluded(5.05,3.2));

  return 0;
} 
