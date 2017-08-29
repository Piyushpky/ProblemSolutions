#include <bits/stdc++.h>
using namespace std;
struct node{
    string st;
    struct node *next;
};

int main()
{   
    char initial;
    map<char,struct node*> m;
    string s;
    int c=0;
    while(getline(cin,s)){
        c++;
        if(c==1){
            initial=s[0];
        }
        char ch=s[0];
        struct node * nl=NULL;
        if(m[ch]==nl){
            node * ptr=new node();
            ptr->st=s;
            ptr->next=NULL;
            m[ch]=ptr;
        }else{
            node * ptr=m[ch];
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            node * nn=new node();
            nn->st=s;
            nn->next=NULL;
            ptr->next=nn;
            
        }
    }
    //input over
    for(map<char, node*> :: iterator it=m.begin();it!=m.end();it++){
    //    cout<<"char value equals "<<it->first<<endl;
      //  cout<<"string(s) attached is/are \n";
        node * ptr=it->second;
        while(ptr!=NULL){
         //   cout<<ptr->st<<endl;
            ptr=ptr->next;
        }
        
    }
    //cout<<"deletion phase\n"<<endl;
    map<char, node*> :: iterator it=m.begin();
    //cout<<"initial "<<initial<<endl;
    node * ptr=m[initial];
    while(c!=0){
      //  cout<<"c"<<c<<endl;
        cout<<ptr->st;
        char fs=(ptr->st)[0];
        int sz=(ptr->st).length();
        char ch=(ptr->st)[sz-1];
        ptr=ptr->next;
        m[fs]=ptr;
      //  cout<<"ptr and itsecond "<<ptr<<" "<<m[fs]<<endl;
        ptr=m[ch];
        
        c--;
    }

    return 0;
}
