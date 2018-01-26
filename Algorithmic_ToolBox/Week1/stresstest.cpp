#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

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


int main(){
  /*
  while(true){

    int n1 = rand() % 1000 + 2;
    cout << n1 << endl;
    
    vector<int> num;  
    for(int i = 0; i < n1; ++i){
      num.push_back(rand() % 100000);
    }

    for(int i = 0; i < n1; ++i){
      cout <<  num[i] << ' ';
    }
    cout << endl;
    
    long long maxprod, maxprodfast; 
    maxprod = maxpairprod(num);    
    maxprodfast = maxpairprodfast(num);    

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
  maxprod = maxpairprodfast(num);
  //cout << "Max pair-wise product: " << maxprod << endl;
  cout << maxprod << endl;
}
