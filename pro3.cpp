#include <bits/stdc++.h>
#define l long
using namespace std;
float mnn(int a,int b, int c){
    if(a<=b&&a<=c){
        return a;
    } 
    if(b<=c&&b<=a){
        return b;
    }
    return c;
}
int mxx(int a,int b,int c){
    if(a>=b&&a>=c){
        return a;
    }
    if(b>=c&&b>=a){
        return b;
    }
    return c;
}
int main() {
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        float a,b,c;
        cin>>a>>b>>c;
        cin>>b>>c>>c;
        float x;
        cin>>c>>x>>x;
        float mn=mnn(a,b,c);
        float mx=mxx(a,b,c);
        double res=mx-mn;//corner res =0
        res=res/6;
        cout<<fixed;
        cout<<"Case #"<<setprecision(10)<<cs++<<": ";
        cout<<res<<endl;
        
        
    }
	return 0;
}