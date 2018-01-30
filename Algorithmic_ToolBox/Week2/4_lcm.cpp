#include<iostream>
#include<vector>
using namespace std;


// Program to compute the least common multiple of two integers
// using GCD
// LCM(a,b) = (a*b)/GCD(a,b) = (a/GCD(a,b))*b -> efficient no overflows when a, b are karge

int gcd_euclidean(const int& a, const int& b){

  if (b == 0) return a;

  int aprime = a % b;
  return gcd_euclidean(b, aprime);
}


int main(){

  int a, b, gcd;
  long long lcm;

  cin >> a >> b;
  
  gcd = gcd_euclidean(a, b);
  lcm = (long long)(a/gcd)*b;

  cout << lcm << endl;

  return 0;
}
