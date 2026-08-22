#include <bits/stdc++.h>
using namespace std;
vector<int> g[1001];   // 邻接表
bool vis[1001];        // 访问标记
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    // 对每个点暴力 BFS
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(i);
        vis[i] = true;
        int mx = i; // 至少包含自己
        while (!q.empty()) {
            int u = q.front(); q.pop();
            mx = max(mx, u);
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << mx << " ";
    }

    return 0;
}

/*二叉树深度BFS
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
struct node
{
    ll left, right;
};
struct st
{
    ll x, step;
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll ans = 0;
    vector<node> vec(n + 1);
    for(ll i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        vec[i].left = a;
        vec[i].right = b;
    }
    queue<st> q;
    q.push({1, 0});
    while(!q.empty())
    {
        st p = q.front();
        ll px = p.x;
        q.pop();
        if(vec[px].left != 0)
        {
            q.push({vec[px].left, p.step + 1});
        }
        if(vec[px].right != 0)
        {
            q.push({vec[px].right, p.step + 1});
        }
        ans = max(ans, p.step);
    }
    cout << ans + 1;
    return 0;
}
*/
/*图中某一点从一点出发BFS走遍所有点
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> vec[10001];
    for(ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        vec[b].push_back(a);
    }
    
    ll vis[10001] = { 0 };
    for(ll i = 1; i <= n; i++)
    {
        vis[i] = 1;
        queue<ll> q;
        q.push(i);
        while(!q.empty())
        {
            ll nx = q.front();
            q.pop();
            for (int v : vec[i]) {
                if (!vis[v]) 
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        if(q.size() == n - 1)
        {
            cout << i ;
            break;
        }
    }
    return 0;
}

给定一棵包含 n 个结点的树，结点编号为 1∼n。我们约定 1 号结点为这棵树的根。
请你求出这棵树的的广度优先遍历序列，即 BFS 序。要求：对于每个结点扩展下一个结点的状态时，
优先扩展结点编号更小的结点。表示这棵树字典序最小的 BFS 序
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> gra[n + 1];
    for(ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    for(ll i = 1; i <= n; i++)
    {
        sort(gra[i].begin(), gra[i].end());
    }
    vector<bool> vis(n + 1, false); 
    queue<ll> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        ll p = q.front();
        q.pop();
        cout << p << ' ';
        for(auto ele : gra[p])
        {
            if(!vis[ele])
            {
                vis[ele] = true;
                q.push(ele);
            }
        }
    }

    return 0;
}
给出一个 N 个顶点 M 条边的无向无权图，顶点编号为1∼N问从顶点1开始，到其他每个点的最短路有几条。
共 N 行，每行一个非负整数，第i行输出从顶点1到顶点i有多少条不同的最短路，由于答案有可能会很大，
你只需要输出 ans mod100003 后的结果即可。如果无法到达顶点 i 则输出 0。
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 100003;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> gra[n + 1];
    for(ll i = 0;i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    vector<ll> cnt(n + 1, 0), dis(n + 1, -1);
    cnt[1] = 1;
    queue<ll> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty())
    {
        ll p = q.front();
        q.pop();
        for(auto ele : gra[p])
        {
            if(dis[ele] == -1)
            {
                dis[ele] = dis[p] + 1;
                cnt[ele] = cnt[p];
                q.push(ele);
            }
            else if (dis[ele] == dis[p] + 1)
            {
                cnt[ele] = (cnt[ele] + cnt[p]) % mod;
            }
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        cout << cnt[i] << '\n';
    }
    return 0;
}
*/

