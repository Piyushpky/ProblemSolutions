/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

#include<bits/stdc++.h>
/*You are required to complete this method*/
int fun(int *a,int m){
    stack<int> s;
    int i=0;
    int ma=0;
    while(i<m){
        if(s.empty()||a[s.top()]<=a[i]){
            s.push(i++);
        //    cout<<"Push \n";
        }else{
            int t=s.top();
            //cout<<"t is "<<a[t]<<endl;
            s.pop();
            int area=0;
            if(s.empty()){
                area=a[t]*(i);
            }else{
                area=a[t]*(i-s.top()-1);
            }
        //    cout<<"area "<<area<<endl;
            if(ma<area){
                ma=area;
            }
        }
    }
    while(!(s.empty())){
            int t=s.top();
            s.pop();
            int area=0;
            if(s.empty()){
                area=a[t]*(i);
            }else{
                area=a[t]*(i-s.top()-1);
            }
      //      cout<<"area "<<area<<endl;
            if(ma<area){
                ma=area;
            }
    }
  //  cout<<"max area is "<<ma<<endl;
    return ma;
}
int maxArea(int M[MAX][MAX],int n,int m)
{
    int maxa=0;
    for(int i=0;i<n;i++){
        if(i!=0){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0)
                M[i][j]+=M[i-1][j];
            }
        }
        int res=fun(M[i],m);
        if(res>maxa){
            maxa=res;
        }
    }
    return maxa;
}
