#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll int seg1[500005];
ll int seg2[500005];
ll int a[100005];

ll int query1(int node,int x,ll int y,int st,int end){
    //cout<<"called with"<<st<<" "<<end<<endl;
    if(y<st||x>end){
        return 0;
    }
    if(x<=st&&y>=end){
        //full
        return seg1[node];
    }
    else{
        //partial
        int  mid=(st+end)/2;
        return(query1(node*2,x,y,st,mid)+query1(node*2+1,x,y,mid+1,end));
    }
    return 0;
}
ll int query2(int node,int x,int y,int st,int end){
    if(y<st||x>end){
        return 0;
    }
    if(x<=st&&y>=end){
        //full
        return seg2[node];
    }else{
        //partial
        int  mid=(st+end)/2;
        return(query2(node*2,x,y,st,mid)+query2(node*2+1,x,y,mid+1,end));
    }
}
void update1(int node,int x,ll int y,int st,int end){
   // cout<<"update1 with st end"<<st<<" "<<end<<endl;
    if(st==end){
        a[st]=y;
        seg1[node]=a[st]%2==0?1:0;
        return;
    }
        int mid=(st+end)/2;
        if(x>=st&&x<=mid)
    update1(2*node,x,y,st,mid);
    if(x>=mid+1&&x<=end)
    update1(2*node+1,x,y,mid+1,end);
    seg1[node]=seg1[2*node]+seg1[2*node+1];
  ////  cout<<"node and value "<<node<<" "<<seg1[node]<<endl;    
    
    
}
void update2(int node,int x,ll int y,int st,int end){
    //cout<<"update2 with st end"<<st<<" "<<end<<endl;
    if(st==end){
        a[st]=y;
        seg2[node]=a[st]%2==1?1:0;
        return;
    }
        int mid=(st+end)/2;
    if(x>=st&&x<=mid)
    update2(2*node,x,y,st,mid);
    if(x>=mid+1&&x<=end)
    update2(2*node+1,x,y,mid+1,end);
    seg2[node]=seg2[2*node]+seg2[2*node+1];
    //cout<<"node and value "<<node<<" "<<seg2[node]<<endl;    
    
}
void build1(int node,int st,int end){
    //cout<<"build with st end"<<st<<" "<<end<<endl;
    if(st==end){
        seg1[node]=a[st]%2==0?1:0;
        return;
    }
    int mid=(st+end)/2;
    build1(2*node,st,mid);
    build1(2*node+1,mid+1,end);
    seg1[node]=seg1[2*node]+seg1[2*node+1];
    //cout<<"node and value "<<node<<" "<<seg1[node]<<endl;
}
void build2(int node,int st,int end){

    if(st==end){
        seg2[node]=a[st]%2==1?1:0;
        return;
    }
    int mid=(st+end)/2;
    build2(2*node,st,mid);
    build2(2*node+1,mid+1,end);
    seg2[node]=seg2[2*node]+seg2[2*node+1];
    //cout<<"node and value "<<node<<" "<<seg2[node]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    //cout<<"AAAA\n"<<n<<endl;
    for(int i=1;i<=n;i++){
      //  cout<<"ander\n"<<endl;
        cin>>a[i];
    //    cout<<"data "<<a[i]<<endl;
        //cout<<"BBBB\n"<<i<<endl;
    }
//    cout<<"ccccc";
    build1(1,1,n);
  //  cout<<"betwenn\n";
    build2(1,1,n);
    
    int q;
    cin>>q;
    while(q--){
    	
        int w;
        cin>>w;
        if(w==0){
            int x;ll int y;
            cin>>x>>y;
            update1(1,x,y,1,n);
            update2(1,x,y,1,n);
        }else if(w==1){
            int x,y;
            cin>>x>>y;
            cout<<query1(1,x,y,1,n)<<endl;
        }else{
            int x,y;
            cin>>x>>y;
            cout<<query2(1,x,y,1,n)<<endl;
        }
            
    }
    return 0;
}
