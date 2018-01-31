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

  long long n, Sn;
  
  cin >> n;

  // Sum of n Fibonacci = F(n+2) - 1
  Sn =  fibonacci_fast(n+2) - 1;
  // last digit in sum
  int ld = 10 + (Sn % 10);
  
  cout << ld << endl;

  return 0;
}
