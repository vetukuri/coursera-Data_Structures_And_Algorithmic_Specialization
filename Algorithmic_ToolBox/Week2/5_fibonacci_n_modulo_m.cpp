#include<iostream>
#include<vector>
using namespace std;


// Given n and m, this program to compute the nth fibonacci number modulus m 
int fibonacci_fast_n_mod_m(const long long& n, const long long& m){

  vector<long long> fmodm;
  
  long long ff0 = 0; 
  fmodm.push_back(ff0);
  long long ff1 = 1; 
  fmodm.push_back(ff1);

  //compute Picano period
  long long nperiod = 2; // m*m is the UB on Picano period
  for(long long i = 2; i <= m*m; i++){
    
    long long temp = ff1;
    // remainder is same as sum of remainder of f[i-1] and f[i-2] mod m
    ff1 = (ff0 + ff1) % m ; 
    ff0 = temp;
    fmodm.push_back(ff1);
    
    if ((ff0 == 0) && (ff1 == 1)){
      nperiod = i - 1;
      fmodm.resize(nperiod); 
      break;
    }
  }
  
  // find remainder of n divided by nperiod
  long long frem = (n % nperiod);
  return fmodm[frem];

}


int main(){

  long long n, m, fmodm;
  
  cin >> n >> m;
  
  fmodm = fibonacci_fast_n_mod_m(n, m);
  cout << fmodm << endl;

  return 0;
}
