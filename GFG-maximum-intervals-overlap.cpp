#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int res[100005];
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    memset(a,0,sizeof(a));
	    memset(b,0,sizeof(b));
	    memset(res,0,sizeof(res));
	    int mx=0;
	    for(int i=0;i<n;i++){
	        int x ;
	        cin>>x;
	        a[x]++;
	    }
	    for(int i=0;i<n;i++){
	        int x ;cin>>x;
	        b[x]++;
	        if(x>mx) mx=x;
	    }
	    res[0]=0;
	    mx;int ind=0,mxx=0;
	    for(int i=1;i<=mx+1;i++){
	        //cout<<"time is "<<i<<endl;
	        //cout<<"a[i] b[i]=> "<<a[i]<<" "<<b[i-1]<<endl;
	        
	        res[i]=res[i-1]+a[i]-b[i-1];
	        if(res[i]>mxx){
	            mxx=res[i];
	            ind=i;
	        }
	      //  cout<<"res "<<res[i]<<endl;
	    }
	    cout<<mxx<<" "<<ind<<endl;
	}
	return 0;
}