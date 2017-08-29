#include <bits/stdc++.h>
#define l long
using namespace std;
int fun(string s){
    int a[26];
    int count=0;
    memset(a,0,sizeof(a));
    int sz=s.length();
    string cb="";
    for(int i=0;i<sz;i++){
       // cout<<"cur character "<<s[i]<<endl;
    //    cout<<"i val "<<i<<endl;
      //  cout<<"cb is "<<cb<<endl;
        if(a[s[i]-'a']!=0){
        //check for it
        int ic=0;
        int f=0;
        int mf=0,mic=0;
        for(int j=0;j<i;j++){
            ic=0;
            if(s[j]==s[i]){
                f=j;
                ic++;
                int jj=j+1;
                int ii=i+1;
                while(jj<i&&ii<sz){//possible bug
                    if(s[jj++]==s[ii++]){
                        ic++;   
                        
                        
                    }else break;
                }
                if(ic>mic){
                    mic=ic;
                    mf=f;
                }
            }
        }
        if(mic==1){
                    count++;
                   // cout<<"count++ "<<count<<endl;
                    
        }else{
            //cout<<"mic is "<<mic<<endl;
            if(s.substr(mf,mic)==cb){
                count++;
                //cout<<"count++ "<<count<<endl;
                
            }else{
                cb="";
                cb+=s.substr(mf,mic);
                count+=2;
              //  cout<<"count+=2 "<<count<<endl;
            }
            i+=mic-1;
        }
        }else{
            a[s[i]-'a']=1;
            count++;
            //cout<<"count++ "<<count<<endl;
        }
    }
    return count;
}
int main() {
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        string s;
        cin>>s;
        cout<<"Case #"<<cs++<<": ";
        cout<<fun(s)<<endl;
        
    }
	return 0;
}