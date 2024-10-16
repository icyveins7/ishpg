#include "shared.h"
#include "static.h"

int sharedaddscale(int a, int b, int c){
  return addstatic(a,b)*c;
}

