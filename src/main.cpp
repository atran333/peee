#include <iostream>

using namespace std;

#define DEBUG 1

#if DEBUG
  #define LOG(x) (cout << x << endl)
#else
  #define LOG(x) 
#endif


int main() {
  LOG("hello world.");
  return 0;
}