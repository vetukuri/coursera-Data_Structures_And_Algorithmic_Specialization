#include<iostream>
#include<vector>
using namespace std;


// Program to compute the greatest common divisior of two integers
// using the Euclidean algorithm

int gcd_euclidean(const int& a, const int& b){

  if (b == 0) return a;

  int aprime = a % b;
  return gcd_euclidean(b, aprime);
}


int main(){

  int a, b, gcd;
  cin >> a >> b;
  
  gcd = gcd_euclidean(a, b);
  cout << gcd << endl;

  return 0;
}
