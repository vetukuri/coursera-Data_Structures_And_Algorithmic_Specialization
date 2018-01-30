#include<iostream>
#include<vector>
using namespace std;

// Program to compute nth fibonacci number using both recursive and iterative algos

int fibonacci_naive(const int& n){
  
  if (n == 0) return 0;
  else if (n == 1) return 1;
  else return fibonacci_naive(n-1) + fibonacci_naive(n-2);

}

long long fibonacci_fast(const int& n){

  vector<long long> ff(n+1);
  
  ff[0] = 0;
  ff[1] = 1;
  for(int i = 2; i <= n; i++){
    ff[i] = ff[i-1] + ff[i-2];
  }

  return ff[n];

}


int main(){

  int n, fn;
  long long ff;
  cin >> n;

  //fn = fibonacci_naive(n);
  ff = fibonacci_fast(n);
  cout << ff << endl;

  return 0;
}
