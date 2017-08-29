#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int szz=s.length();
    char cs[szz];
    int i;
    for( i=0;i<s.length();i++){
        cs[i]=s[i];
    }
    cs[i]=NULL;
    //cout<<"replacement array is ->"<<s<<endl;
    string a[100];
    int pos=0;
    char *arr=strtok(cs," ");
    while (arr != NULL)
    {
    a[pos++]=arr;
    arr = strtok (NULL, " ");
    }
    int ars=sizeof(a);
    string input;
    getline(cin,input);
    int sz=input.length();
    int c=0;
    for(int i=0;i<sz;i++){
        if(input[i]=='{'){
            if(input[i+1]=='}'){
                cout<<a[c++];
                i++;
            }else{
                if(input[i+1]<='9'&&input[i+1]>='0'){
                    int num=input[i+1]-'0';
                    if(num<ars){
                        cout<<a[num];
                        i+=2;
                    }else{
                        i++;
                        while(input[i]!='}'){
                            cout<<input[i];
                            i++;
                        }
                        
                    }
                }else{
                    i++;
                        while(input[i]!='}'){
                            cout<<input[i];
                            i++;
                        }
                }
            }
        }else{
            cout<<input[i];
        }
    }
    
    return 0;
}