#include <bits/stdc++.h>
#define l long
using namespace std;

int main()
{
    int n;
    cin>>n;
    l int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=0;
    sort(a+0,a+n);
    l int mn=LONG_MAX;
    for(int i=0;i<n-1;i++){
        //cout<<mn<<" "<<c<<endl;
        if(abs(a[i]-a[i+1])==mn){
            mn=abs(a[i]-a[i+1]);
            c++;
        }
        if(abs(a[i]-a[i+1])<mn){
            mn=abs(a[i]-a[i+1]);
            c=1;
        }
    }
    cout<<mn<<" "<<c<<endl;
    return 0;
}
