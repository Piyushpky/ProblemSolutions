#include <iostream>
using namespace std;
int egg(int n,int k){
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=k;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=k;i++){
        dp[1][i]=i;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            int mn=INT32_MAX;
            for(int x=1;x<=j;x++){
                int res=max(dp[i-1][x-1],dp[i][j-x])+1;
                if(res<mn){
                    mn=res;
                }
            }
            dp[i][j]=mn;
          //  cout<<" dp "<<dp[i][j];
        }
        //cout<<endl;
    }
    return dp[n][k];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<egg(n,k)<<endl;
    }
	//code
	return 0;
}