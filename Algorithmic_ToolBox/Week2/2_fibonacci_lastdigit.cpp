#include<iostream>
#include<vector>
using namespace std;


// Program to compute the last digit of nth fibonacci number

int fibonacci_fast_lastdigit(const int& n){

  vector<int> ff(n+1);
  
  ff[0] = 0;
  ff[1] = 1;
  for(int i = 2; i <= n; i++){
    ff[i] = (ff[i-1] + ff[i-2]) % 10;
  }

  return ff[n];

}


int main(){

  int n, ff;
  cin >> n;
  
  ff = fibonacci_fast_lastdigit(n);
  cout << ff << endl;

  return 0;
}
