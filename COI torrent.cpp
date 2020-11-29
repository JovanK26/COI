#include <bits/stdc++.h>

using namespace std;
int n,a,b,x,y;
vector<int> v[300001];
int prt[300001];
int f[300001];
void dfs(int start)
{
    for(int j : v[start])
    {
        if(j==prt[start])
        {
            continue;
        }
        prt[j]=start;
        dfs(j);
    }
}
int solve(int start,int prev,int cutx,int cuty)
{
    f[start]=0;
    vector<int> temp;
    for(int j : v[start])
    {
        if(j==prev)continue;
        if(start==cutx && j==cuty)continue;
        if(j==cutx && start==cuty)continue;
        solve(j,start,cutx,cuty);
        temp.push_back(f[j]);
    }
    sort(temp.rbegin(),temp.rend());
    for(int i=0;i<temp.size();i++)
    {
        f[start]=max(f[start],temp[i]+i+1);
    }
    return f[start];
}
int delta(int cur)
{
    return solve(a,0,cur,prt[cur])-solve(b,0,cur,prt[cur]);
}
int comp(int cur)
{
    return max(solve(a,0,cur,prt[cur]),solve(b,0,cur,prt[cur]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    for(int i=0;i<n-1;i++)
    {
       cin >> x >> y;
       v[x].push_back(y);
       v[y].push_back(x);
    }
    vector<int> parents;
    dfs(a);
    for(int i=b;i!=a;i=prt[i])
    {
        parents.push_back(i);
    }
    int l=0;
    int r=parents.size();
    int m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(delta(parents[m])>0)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    cout << l <<' '<<r<<endl;
    int rez=comp(parents[l]);
    if(l)rez=min(rez,comp(parents[l-1]));
    //if(l+1<parents.size())rez=min(rez,comp(parents[l+1]));
    cout << rez;
    return 0;
}
