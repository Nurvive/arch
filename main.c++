#include "architech.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
  int a = 0;
  int b = 0;
  int c = 0;
  int *value = &a;
  int *comm = &b;
  int *oper = &c;
  int command = 0x33;
  int operand = 0x59;
  sc_commandEncode(command, operand, value);
  cout<<*value<<endl<<endl;
  sc_commandDecode(*value, comm, oper);
  cout<<*comm<<endl<<*oper<<endl<<endl;
  int value1 = 26623;
  cout<<sc_commandDecode(value1, comm, oper);
  cout<<*comm<<endl<<*oper<<endl<<endl;

  sc_memorySet(10, 10);
  sc_memoryGet(10, value);
  cout<<*value<<endl;
  return 0;
}
