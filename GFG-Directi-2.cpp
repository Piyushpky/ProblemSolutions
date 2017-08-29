#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	 int t;
	 cin>>t;
	 while(t--){
	     int n,jump,k;
	     cin>>n>>jump>>k;
	     int a[n],b[n];
	     for(int i=0;i<n;i++){
	         cin>>a[i];
	     }
	     for(int i=0;i<n;i++){
	         cin>>b[i];
	     }
	     int dp1[n+1],dp2[n+1];
	     for(int i=1;i<=n;i++){
	         dp1[i]=INT32_MAX;
	         dp2[i]=INT32_MAX;
	     }
	     dp1[0]=0;dp1[1]=a[0];
	     dp2[0]=0;dp2[1]=b[0];
	     for(int i=2;i<=n;i++){
	         int res1=0,res2=0;;
	         for(int j=1;j<=jump;j++){
	             //cout<<"i-j "<<i<<" "<<j<<" "<<i-j<<endl;
	             if(i-j>0){
	                 //cout<<"i "<<i<<endl;
	                 res1=dp1[i-j]+a[i-1];
	                 res2=dp2[i-j]+a[i-1]+k;
	                 //cout<<"res1 res2 dp1 "<<res1<<" "<<res2<<"\n";
	                 if(res1<dp1[i]) dp1[i]=res1;
	                 if(res2<dp1[i]) dp1[i]=res2;
	                 res1=dp2[i-j]+b[i-1];
	                 res2=dp1[i-j]+b[i-1]+k;
	                 //cout<<"res1 res2 dp1 "<<res1<<" "<<res2<<"\n";
	                 if(res1<dp2[i]) dp2[i]=res1;
	                 if(res2<dp2[i]) dp2[i]=res2;
	             }
	             
	         }
	         //cout<<"dp1 value "<<dp1[i]<<endl;
	         //cout<<"dp2 value "<<dp2[i]<<endl;
	     }
	     //cout<<"dp1 and 2\n";
	     for(int i=0;i<=n;i++){
	        // cout<<" "<<dp1[i];
	     }
	     //cout<<"dp1 and 2\n";
	     for(int i=0;i<=n;i++){
	       //  cout<<" "<<dp2[i];
	     }
	     
	     cout<<min(dp1[n],dp2[n])<<endl;
	 }
	return 0;
}