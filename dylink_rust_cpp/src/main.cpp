#include <iostream>
using namespace std;

extern "C" int foo(int i);
extern "C" int fib(int i);

int main() {
  int a = foo(12);
  cout << a << endl;
  int b = fib(10);
  cout << b << endl;
  return 0;
}
