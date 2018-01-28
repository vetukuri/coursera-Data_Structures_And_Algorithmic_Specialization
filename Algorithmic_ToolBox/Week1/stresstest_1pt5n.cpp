// code contains naive, O(2n) and O(1.5n) implementations to find the max pair-wise product of n integers
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

// naive implementation
long long maxpairprod(vector<int>& num){
  int n = num.size();
  long long maxprod = -1;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if (((long long) num[i])*num[j] > maxprod)
	maxprod = ((long long) num[i])*num[j];
    }
  }
  return maxprod;
}

// O(2n) version
long long maxpairprodfast(vector<int>& num){
  
  int n = num.size();
  
  long long maxprod = -1;
  
  // find largest number
  int maxindx1 = -1;
  for(int i = 0; i < n; i++){
      if ((maxindx1 == -1) || (num[i] > num[maxindx1]))
	maxindx1 = i;
  }

  // find second largest number
  int maxindx2 = -1;
  for(int j = 0; j < n; j++){
    if (((maxindx2 == -1) || num[j] > num[maxindx2]) && (j != maxindx1))
      maxindx2 = j;
  }
 
  maxprod = ((long long) num[maxindx1])*num[maxindx2];
  return maxprod;
}

// algorithm with O(1.5n)
long long maxpairprodfast_1pt5n(vector<int>& num){
  
  int n = num.size();
  vector<int> high;
  vector<int> low;

  // check if n is odd
  int n1 = n;
  if ((n % 2) ==  1){
    n1 = n-1;
  }
    
  long long maxprod = -1;  
  // min/max pairs 
  for(int i = 0; i < n1 - 1; i += 2){
    if (num[i] > num[i+1]){
      high.push_back(num[i]);
      low.push_back(num[i+1]);
    }
    else {
      high.push_back(num[i+1]);
      low.push_back(num[i]);
    }
  }
  
  // initialize maxnum1 and maxnum2 to high[0] and low[0] -> for n==2
  int maxnum1 = high[0];
  int maxnum2 = low[0];

  // n > 3 cases
  if (n > 3) {
    // first largest number
    int maxindx1  = 0;
    for (int i = 1; i < high.size(); i++){
      if (high[i] > maxnum1){
	maxnum1 = high[i];
	maxnum2 = low[i];
	maxindx1 = i;
      }
    }
    
    // find second largest number
    for(int i = 0; i < high.size(); i++){
      if ((i != maxindx1) && (high[i] > maxnum2)){
	maxnum2 = high[i];
      }
    }
  }
  
  // if n == odd, check the last number with maxnum1 and maxnum2
  if ((n % 2) == 1){
    if (num[n-1] > maxnum1){
      maxnum2 = maxnum1;
      maxnum1 = num[n-1];
    }
    else if (num[n-1] > maxnum2){
      maxnum2 = num[n-1];
    }
  }

  //  cout << maxnum1 << ' ' << maxnum2 << endl;
 
  maxprod = ((long long) maxnum1) * maxnum2;
  return maxprod;
}

// main function
int main(){
  // stress testing code commented out.
  /*
  while(true){

    int n1 = rand() % 1000 + 2;
    cout << n1 << endl;
    
    vector<int> num;  
    for(int i = 0; i < n1; ++i){
      num.push_back(rand() % 10000);
    }

    for(int i = 0; i < n1; ++i){
      cout <<  num[i] << ' ';
    }
    cout << endl;
    
    long long maxprod, maxprodfast; 
    maxprod = maxpairprod(num);    
    maxprodfast = maxpairprodfast_1pt5n(num);    

    if (maxprod != maxprodfast){
      cout << "No match: " << maxprod << ' ' << maxprodfast << endl;
      break;
    }
    else {
      cout << "OK!!" << endl;
    }
  }
  */

  int n;

  //  cout << "Enter no. of integers: "; // commented out to adhere to online submission process to grade HW
  cin >> n;
  
  vector<int> num(n);  
  //cout << "Enter non-negative integers (separated by spaces): ";
  
  for(int i = 0; i < n; i++)
    cin >> num[i];
  
  long long maxprod; 
  maxprod = maxpairprodfast_1pt5n(num);
  //cout << "Max pair-wise product: " << maxprod << endl;
  cout << maxprod << endl;
}
