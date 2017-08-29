#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string x;
        cin>>x;
        int a[26];int b[26];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int s1=s.length();
        int x1=x.length();
        for(int i=0;i<s1;i++){
            //cout<<"char is "<<s[i]<<endl;
            a[s[i]-'a']++;
        }
        for(int i=0;i<x1;i++){
            //cout<<"char is "<<x[i]<<endl;
            b[x[i]-'a']++;
        }
        //array a b finished
        for(int i=0;i<26;i++){
            if(b[i]!=0){
                a[i]=a[i]/b[i];
            }else{
                a[i]=0;
            }
        }
        int mn=INT32_MAX;
        for(int i=0;i<26;i++){
            //cout<<"char is "<<(char)(i+'a')<<" "<<a[i]<<endl;
            if(a[i]!=0&&a[i]<mn){
                mn=a[i];
            }
        }
        if(mn==INT32_MAX){
            cout<<"0\n";
        }else{
        cout<<mn<<endl;
            
        }
    }
	//code
	return 0;
}