#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    set<string> st;
	    int x;
	    cin>>x;
	    string s[x];
	    for(int i=0;i<x;i++){
	        cin>>s[i];
	    }
	    sort(s,s+x);
	    int n,m;
	    cin>>n>>m;
	    //cout<<"n m "<<n<<" "<<m<<endl;
	    char c[n][m];
	    int v[n][m];
	    memset(v,0,4*n*m);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>c[i][j];
	         
	        }
	        
	    }
	    for(int i=0;i<x;i++){
	        string t=s[i];
	        //cout<<"string is "<<t<<endl;
	        memset(v,0,4*n*m);
	        int ind=0;
	        char ch=t[ind];
	        char pc=ch;
	        int sl=t.length();
	        for(int p=0;p<n;p++){
	            int f=0;
	            for(int q=0;q<m;q++){
	                ind=0;
	                if(c[p][q]==pc){
	                  //  cout<<"found at  pq "<<p<<" "<<q<<endl;
	                   // cout<<"char is "<<pc<<" pq "<<c[p][q]<<endl;
	                    ch=t[ind];
	                    int a=p,b=q;
	                    v[a][b]=1;//cout<<"bbind is "<<ind<<endl;
	                    ind++;//cout<<"bb2ind is "<<ind<<endl;
	                    while(ind!=sl){
	                        //cout<<"sl "<<sl<<endl;
	                     //   cout<<"ind is "<<ind<<endl;
	                        ch=t[ind];
	                     // cout<<"char to be found is "<<ch<<endl;
	                        int tr=0;
	                        if(a-1>=0&&b-1>=0&&c[a-1][b-1]==ch&&v[a-1][b-1]==0){
	                            tr=1;a--;b--;v[a][b]=1;
	                        }else if(b-1>=0&&c[a][b-1]==ch&&v[a][b-1]==0){
	                            tr=1;b--;v[a][b]=1;
	                        }
	                        else if(a-1>=0&&c[a-1][b]==ch&&v[a-1][b]==0){
	                            a--;tr=1;v[a][b]=1;
	                        }else if(a+1<n&&b+1<m&&c[a+1][b+1]==ch&&v[a+1][b+1]==0){
	                            tr=1;a++;b++;v[a][b]=1;
	                        }else if(b+1<m&&c[a][b+1]==ch&&v[a][b+1]==0){
	                            tr=1;b++;v[a][b]=1;
	                        }else if(a+1<n&&c[a+1][b]==ch&&v[a+1][b]==0){tr=1;
	                            a++;v[a][b]=1;
	                        }else if(a-1>=0&&b+1<m&&c[a-1][b+1]==ch&&v[a-1][b+1]==0){
	                            tr=1;
	                            a--;
	                            b++;v[a][b]=1;
	                        }else if(a+1<n&&b-1>=0&&c[a+1][b-1]==ch&&v[a+1][b-1]==0){
	                            tr=1;
	                            a++;
	                            b--;v[a][b]=1;
	                        }
	                        
	                        if(tr==0)
	                        break;
	                        ind++;
	       //                 cout<<"OUTind is "<<ind<<endl;
	                    }
	                    if(ind==sl){
	                        st.insert(t);
	                        f=1;
	                    }else{
	                    
	                 }
	                }
	                
	            }
	        }
	    }
	    if(st.empty()){
	        cout<<"-1\n";
	    }else{
	    for(set<string> ::iterator it=st.begin();it!=st.end();it++)
	    cout<<*it<<" ";
	    cout<<endl;}
	}
	return 0;
}