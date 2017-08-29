#include <bits/stdc++.h>
#define l long 
using namespace std;
int maxx(int a,int b,int c){
    if(a>=b&&a>=c){
        return a;
    }else if(b>=a&&b>=c){
        return b;
    }else{
        return c;
    }
}
int main()
{
int n;
cin>>n;
int sum1=0;
int sum2=0;
int c=6;
vector<int> v;

while(c--){
    int r=n%10;
    v.push_back(r);
    //cout<<"pushing p "<<r<<endl;
    n/=10;
}
c=0;
sum1=v[0]+v[1]+v[2];
sum2=v[3]+v[4]+v[5];
if(sum1!=sum2){
    int diff=abs(sum1-sum2);
    if(sum1<sum2){
        while(diff){
        int c1=9-v[0];
        int c2=9-v[1];
        int c3=9-v[2];
        int m1=maxx(c1,c2,c3);
        if(m1<diff){
            c++;
            diff-=m1;
            if(c1==m1){
                v[0]=9;
            }else if(c2==m1){
                v[1]=9;
            }else{
                v[2]=9;
            }
            
        }else{
            c++;
            diff=0;
        }
        }
    }else{
        while(diff){
        int c1=9-v[3];
        int c2=9-v[4];
        int c3=9-v[5];
        int m1=maxx(c1,c2,c3);
        if(m1<diff){
            c++;
            diff-=m1;
            if(c1==m1){
                v[3]=9;
            }else if(c2==m1){
                v[4]=9;
            }else{
                v[5]=9;
            }
            
        }else{
            c++;
            diff=0;
        }
        }
    }
    
}
cout<<c;
return 0;
}
