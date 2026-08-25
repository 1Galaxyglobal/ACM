#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 3;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    // 邻接表存图
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    // Prim 算法求最小瓶颈路
    // max_edge[i] 表示从 s 到 i 的当前最小瓶颈值
    vector<ll> max_edge(n + 1, INF);
    vector<bool> vis(n + 1, false);
    // 优先队列：{当前路径上的最大边权, 节点编号}
    // 按最大边权从小到大排序
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    max_edge[s] = 0;
    pq.push({0, s});
    ll ans = 0;
    while (!pq.empty())
    {
        auto [cur_max, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        // 到达终点，记录答案
        if (u == t)
        {
            ans = cur_max;
            break;
        }
        // 用 u 更新相邻节点
        for (auto [v, w] : g[u])
        {
            if (!vis[v])
            {
                // 经过 u 到达 v 的瓶颈值 = max(到 u 的瓶颈值, 边 uv 的权值)
                ll new_bottleneck = max(cur_max, w);
                if (new_bottleneck < max_edge[v])
                {
                    max_edge[v] = new_bottleneck;
                    pq.push({new_bottleneck, v});
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using PII = pair<int, int>;  // {weight, node}

ll prim(int n, vector<vector<PII>>& graph) {
    vector<bool> visited(n + 1, false);
    vector<int> minDist(n + 1, INT_MAX);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    
    ll totalWeight = 0;
    int vertexCount = 0;
    
    // 从节点1开始
    minDist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty() && vertexCount < n) {
        auto [w, u] = pq.top();
        pq.pop();
        
        if(visited[u]) continue;
        
        visited[u] = true;
        totalWeight += w;
        vertexCount++;
        
        for(const auto& [v, weight] : graph[u]) {
            if(!visited[v] && weight < minDist[v]) {
                minDist[v] = weight;
                pq.push({weight, v});
            }
        }
    }
    
    return (vertexCount == n) ? totalWeight : -1;
}
*/