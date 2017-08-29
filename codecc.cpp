#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> al[105];
bool v[105];
int n,m;
int ans;

int dfs(int node)
{
    v[node]=true;
    int nv=0;
    for(int i=0;i<al[node].size();i++)
    {
        if(!v[al[node][i]])
        {
            int n_n=dfs(al[node][i]);
            if(n_n%2==0)
                ans++;
            else
                nv+=n_n;
        }
    }
    return nv+1;
}

int main() {
    int x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        al[x].push_back(y);
        al[y].push_back(x);
    }
    dfs(1);
    cout<<ans;
    return 0;
}