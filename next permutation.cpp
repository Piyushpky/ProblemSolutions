//Binary Search Tree
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll int palin(ll int n){
vector<ll int> v;
ll int c=0;
while(n){
//    cout<<"n is "<<n<<endl;
    ll int r=n%10;
    v.push_back(r);
    n=n/10;
    c++;
}
ll int i=0;c--;
ll int f=0;
while(i<c){
   // cout<<v[i]<<" "<<v[c]<<endl;
    if(v[i]!=v[c]){
        f=1;
        break;
    }
    i++;c--;
}

return !f;
}
ll int next_pal(ll int n){
vector<ll int> v;


ll int c=0;
//cout<<"entwr "<<n<<endl;
while(n){
//    cout<<"n is "<<n<<endl;
ll int r=n%10;
    v.push_back(r);
    //cout<<"rem "<<r<<endl;
    n=n/10;
    c++;
}
ll int i=0;c--;
ll int f=0;
ll int carry=0;


while(i<c){
    carry=0;
    ll int x=v[i],y=v[c];
    if(x!=y){
        if(y>x){
            v[i]=y;
        }else{
            carry=1;
            v[i]=y;
        }
    }
    if(carry==1){
        
        v[i+1]++;
        //cout<<"carry ho gya "<<v[i+1]<<endl;
    }
    
    i++;c--;
    
}
ll int num=0;
for(ll int i=v.size();i>=0;i--){
    //cout<<"vi "<<v[i]<<endl;
    num=(num*10)+v[i];
}
//cout<<"nh=um is "<<num<<endl;
if(!palin(num)){
    num=next_pal(num);
    //cout<<"nh=um is "<<num<<endl;
}
return num;
}

int main()
{
    ll int t;
    cin>>t;
    while(t--){
ll int n;
cin>>n;
if(palin(n)){
    n++;
}
cout<<next_pal(n)<<endl;}
return 0;
}
