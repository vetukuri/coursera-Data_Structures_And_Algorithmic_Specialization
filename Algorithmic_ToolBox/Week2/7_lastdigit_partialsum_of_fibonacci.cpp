#include<iostream>
#include<vector>
using namespace std;

// Program to compute last digit of sum of n Fibonacci numbers
// Sn = F(n+2) - 1
int fibonacci_fast(const long long& n){

  int a = 0;
  int b = 1;
  for(long long i = 2; i <= n; i++){
    int tmp = b;
    b = (a + b) % 10;
    a = tmp;
  }

  return b;
}


int main(){

  long long m, n;
  int Smn;
  cin >> m >> n;

  // Sum of Fibonacci numbers from m to n = F(n+2) - F(m+1)
  // F(m+1) not to include mth Fibonacci
  Smn = 10 + (fibonacci_fast(n+2) - fibonacci_fast(m+1)) ; // added 10 since the 2nd term could be > the 1st term
  // last digit in sum
  int ld = Smn % 10;
  
  cout << ld << endl;

  return 0;
}
