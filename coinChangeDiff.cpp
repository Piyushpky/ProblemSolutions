#include <bits/stdc++.h>
using namespace std;
int a[100005];
int coin(int sum,int n){
    
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
        //cout<<" ij "<<i<<" "<<"0"<<" "<<dp[i][0]<<" \n";
    }
    for(int i=0;i<=sum;i++){
        dp[0][i]=sum+2;
        //cout<<" ij "<<"0"<<" "<<i<<" "<<dp[0][i]<<" \n";
    }
    for(int i=0;i<=sum;i++){
        dp[1][i]=i;
        //cout<<" ij "<<"1"<<" "<<i<<" "<<dp[1][i]<<" \n";
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
        //    cout<<"s "<<dp[i][j-a[i-1]]<<endl; 
            dp[i][j]=min(dp[i-1][j],dp[i][j-a[i-1]]+1);//seg fault
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
           // cout<<" "<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    return dp[n][sum];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int sum,n;
	    cin>>sum>>n;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    
	    cout<<coin(sum,n)<<endl;
	}
	return 0;
}