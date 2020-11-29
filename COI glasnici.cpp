#include <bits/stdc++.h>

using namespace std;
double k;
int n;
double dist[100001];
bool check(double t)
{
    double pos=dist[0]+t;
    for(int i=1;i<n;i++)
    {
        if(pos+k<dist[i]-t)return 0;
        pos=min(pos+k,dist[i]+t);
    }
    return 1;
}
int main()
{
    cout << fixed;
    cout << setprecision(4);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> dist[i];
    }
    double l=0.0;
    double r=1000000000.0;
    double m;
    for(int i=0;i<=100;i++)
    {
        m=(l+r)/2.0;
        if(check(m))
        {
            r=m;
        }
        else
        {
            l=m;
        }
    }
    cout << r;
    return 0;
}
