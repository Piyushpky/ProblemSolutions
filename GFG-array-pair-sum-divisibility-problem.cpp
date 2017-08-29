#include <bits/stdc++.h>
using namespace std;
bool fun(int *a ,int n,int k){
    map<int,int > m;
    for(int i=0;i<n;i++){
        m[a[i]%k]++;
    }
    for(int i=0;i<n;i++){
        int rem=a[i]%k;
        if(rem==0||rem==k/2){
            if(m[rem]%2!=0){
                return false;
            }
        }else{
            if(m[rem]!=m[k-rem]){
                return false;
            }
        }
            
    }
    return true;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	  int n;
	  cin>>n;
	  int a[n];
	  for(int i=0;i<n;i++){
	      cin>>a[i];
	  }
	  int k;cin>>k;
	  if(fun(a,n,k)){
	      cout<<"True\n";
	  }else{
	      cout<<"False\n";
	  }
	}
	return 0;
}