#include<iostream>
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


int main(){

  int n;

  //  cout << "Enter no. of integers: "; // commented out to adhere to online submission process to grade HW
  cin >> n;

  vector<int> num(n);  
  //cout << "Enter non-negative integers (separated by spaces): ";

  for(int i = 0; i < n; i++)
    cin >> num[i];

  long long maxprod; 
  maxprod = maxpairprod(num);
  //cout << "Max pair-wise product: " << maxprod << endl;
  cout << maxprod << endl;
}
