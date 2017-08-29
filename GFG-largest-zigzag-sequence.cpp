#include <iostream>
using namespace std;
int a[1000][1000];
int zigzag(int n){
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            int mx=0;
            for(int k=1;k<n+1;k++){
                int res=0;
                if(k!=j){
                    //cout<<"i j k "<<i<<" "<<j<<" "<<k<<endl;
                    res=dp[i-1][k]+a[i-1][j-1];
                    //cout<<"ai "<<a[i-1][j-1]<<endl;
                    //cout<<"res is "<<res<<endl;
                }
                if(res>mx){
                    mx=res;
                }
            }
            dp[i][j]=mx;
         //   cout<<"dp ij "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    int mn=0;
    for(int i=1;i<n+1;i++){
        if(dp[n][i]>mn){
            mn=dp[n][i];
        }
    }
    return mn;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	   
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>a[i][j];
	            //cout<<"ai "<<a[i][j]<<endl;
	        }\
	    }
	    cout<<zigzag(n)<<endl;
	}
	return 0;
}