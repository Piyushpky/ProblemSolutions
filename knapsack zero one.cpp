#include <bits/stdc++.h>
using namespace std;
int maxx;
int v[100000];
int w[100000];

int ks(int n,int wt){
//    if()
  //  cout<<"called with n and wt"<<n<<" "<<wt<<endl;
//    cout<<"current max is "<<maxx<<endl;
    if(n==0||wt==0){
        return 0;
    }
    int dp[n+1][wt+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<wt+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<wt+1;j++){
          //  cout<<"if j"<<i<<" "<<j<<endl;
            if(j-w[i-1]>=0){
                dp[i][j]=max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        //    cout<<"dp"<<dp[i][j]<<endl;
        }
    }
    return dp[n][wt];
}
int main() {
int t;
cin>>t;
while(t--){
    maxx=0;
int n;
cin>>n;

int wt;
cin>>wt;
for(int i=0;i<n;i++){
	cin>>v[i];
}
for(int i=0;i<n;i++){
	cin>>w[i];
}
int ans=ks(n,wt);
cout<<ans<<endl;
}
return 0;
}
