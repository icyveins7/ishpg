// gcc test_gdb.cpp -o bin/test_gdb

#include <iostream>

int func1(int x){
  return x + 1;
}

int main(){
  printf("sup\n");

  int x = 10;

  printf("x = %d\n", func1(x));

  return 0;
}
