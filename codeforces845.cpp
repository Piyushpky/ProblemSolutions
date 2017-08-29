#include <bits/stdc++.h>
#define l long 
using namespace std;

int main()
{
int n;
cin>>n;
int a[2*n];
for(int i=0;i<2*n;i++){
    cin>>a[i];
}
sort(a,a+2*n);
if(a[n]==a[n-1]){
    cout<<"NO";
}else{
    cout<<"YES";
}
return 0;
}
