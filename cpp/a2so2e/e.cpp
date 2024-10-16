#include "static.h"
#include "shared.h"
#include <iostream>

int main(){

  printf("%d\n", sharedaddscale(2,3,4));
  printf("%d\n", notinshared(5,3));

  return 0;
} 
