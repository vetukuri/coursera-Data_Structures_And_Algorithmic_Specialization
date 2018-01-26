#include<iostream>
#include<vector>
using namespace std;

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
    if (((maxindx2 == -1) || num[j] > num[maxindx2]) && (num[j] != num[maxindx1]))
      maxindx2 = j;
  }
 
  maxprod = ((long long) num[maxindx1])*num[maxindx2];
  return maxprod;
}


int main(){
  int n;

  //  cout << "Enter no. of integers: "; // commented out to adhere to online submission process to grade HW
  cin >> n;
  
  vector<int> num(n, 0);  
  //cout << "Enter non-negative integers (separated by spaces): ";
  /*
  for(int i = 0; i < n; i++)
    cin >> num[i];
  */
  long long maxprod; 
  maxprod = maxpairprodfast(num);
  //cout << "Max pair-wise product: " << maxprod << endl;
  cout << maxprod << endl;
}
