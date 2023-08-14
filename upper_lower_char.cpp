#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "abcdefghijklmnopqrstuvwxyz";

  // a^32 -> A
  // A^32 -> a
  // lower case to upper case
  for (int i = 0; i < s.size(); i++) {
    s[i] ^= 32;
    cout << s[i];
  } cout << endl;

  // uppert case to lower case
  for (int i = 0; i < s.size(); i++) {
    s[i] ^= 32;
    cout << s[i];
  } cout << endl;
  
  return 0;
}
