#include<iostream>
#include"matrix.h"
using namespace std;

int main()
{
  int m, n, x, y;
  cin >> m >> n >> x >> y;
  Matrix a(m, n), b(m, n);
  cin >> a >> b;
  Matrix c = a+b;
  cout << c;
  a = b+c;
  // print element at row-x column-y of Matrix a, row and column count from 0
  cout << a(x, y) << endl; 
  return 0;
}
