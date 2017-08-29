#include <bits/stdc++.h>
using namespace std;
#define Row 6
#define Col 6
int main() {
	//code
	 int a[Row][Col] = { 2, 2, 3, 3, 4, 4,
                         5, 5, 7, 7, 7, 4,
                         1, 2, 72, 7, 7, 7,
                         4, 4, 7, 7, 7, 4,
                         5, 5, 5, 1, 7, 7,
                         8, 7, 9, 4, 4, 4
                      };
    int m[7][7];
    int n=7;
    memset(m,0,sizeof(m));
	int mx=0;
	for(int i=1;i<n;i++){
	    for(int j=1;j<n;j++){
	        if(a[i-1][j-1]==a[i][j-1]&&a[i-1][j-1]==a[i-1][j]&&a[i-1][j-1]==a[i][j]){
	          m[i][j]=min(m[i-1][j-1],min(m[i][j-1],m[i-1][j]))+1;
	          
	        }else{
	            m[i][j]=1;
	        }
	        if(mx<m[i][j]){
	              mx=m[i][j];
	          }
	    }
	}
	cout<<endl;
	for(int i=1;i<n;i++){
	    for(int j=1;j<n;j++){
	        cout<<" "<<m[i][j];
	    }
	    cout<<endl;
	}
	cout<<mx<<endl;
	return 0;
}