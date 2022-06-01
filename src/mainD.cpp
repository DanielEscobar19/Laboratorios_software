#include "Doble.h"
#include <iostream>
using namespace std;
int main () {
  Doble x(6);
  Doble y(3);
  Doble r = x+y; 
  cout << r.toString() << endl;;
  return 0;
}