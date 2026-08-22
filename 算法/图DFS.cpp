#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll vis[10001] = { 0 };
vector<ll> vec[10001];
void dfs(ll x)
{
    vis[x] = 1;
    for(auto ele : vec[x])
    {
        if(vis[ele] == 0) 
        {
            cout << ele << ' ';
            dfs(ele);
        }
    }
    
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    ll f1;
    for(ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        if(i == 0) f1 = a;
        vec[a].push_back(b);
        sort(vec[a].begin(), vec[a].end());
    }
    cout << f1 << ' ';
    dfs(f1);
    return 0;
}
/*
给定一棵包含 n 个结点的树，结点编号为 1∼n。我们约定 1 号结点为这棵树的根。
请你求出这棵树的 字典序最小 的深度优先遍历序列，即 DFS 序。DFS 序：在深度优先搜索过程中，
第一次访问某个结点时，将其编号加入序列所形成的序列。字典序最小：在 DFS 过程中，
当一个结点有多个子结点未被访问时，必须按照结点编号从小到大的顺序依次遍历这些子结点。
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll vis[1000001];
vector<ll> gra[1000101];
ll n;
void dfs(ll s)
{
    cout << s << ' ';
    vis[s] = 1;
    for(auto ele : gra[s])
    {
        if(vis[ele] == 0)
        {
            dfs(ele);
        }
    }
    vis[s] = 0;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(ll i = 0; i < n - 1; i++)
    {
        ll a,b ;
        cin >> a >> b;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    for(ll i = 1; i <= n; i++)
    {
        sort(gra[i].begin(), gra[i].end());
    }
    dfs(1);
    return 0;
}
*/