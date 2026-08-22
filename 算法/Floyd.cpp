#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 3; // 避免溢出，设置为比 ll_MAX/2 更小的值
void floyd_basic(ll n, vector<vector<ll>>& dist) {
    // Floyd 核心算法
    for (ll k = 1; k <= n; ++k) {         // 中间节点
        for (ll i = 1; i <= n; ++i) {     // 起点
            for (ll j = 1; j <= n; ++j) { // 终点
                // 防止溢出：确保 dist[i][k] 和 dist[k][j] 都不是 INF
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}
ll main() {
    ll n, m; // n: 节点数, m: 边数
    cin >> n >> m;    
    // 初始化距离矩阵
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));    
    for (ll i = 1; i <= n; ++i) {
        dist[i][i] = 0;// 从i到i距离为0
    }    
    for (ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); // 处理重边，取最小值
        // 如果是无向图，加上下面这句：dist[b][a] = min(dist[b][a], c);
    }
    floyd_basic(n, dist);
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

// 记录路径
#include <bits/stdc++.h>
using namespace std;
const ll INF = LLONG_MAX / 3;
void floyd_with_path(ll n, vector<vector<ll>>& dist, vector<vector<ll>>& next) {
    // 初始化 next 矩阵
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (i != j && dist[i][j] != INF) {
                next[i][j] = j; // 如果 i 和 j 直接相连，则 i 的下一个节点是 j
            } else {
                next[i][j] = -1; // 不可达
            }
        }
    }
    for (ll k = 1; k <= n; ++k) {
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k]; // 更新路径
                    }
                }
            }
        }
    }
}
// 获取从 u 到 v 的路径
vector<ll> get_path(ll u, ll v, const vector<vector<ll>>& next) {
    vector<ll> path;   
    // 如果不可达，返回空路径
    if (next[u][v] == -1) {
        return path;
    }
    // 逐步添加路径上的节点
    path.push_back(u);
    while (u != v) {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    vector<vector<ll>> next(n + 1, vector<ll>(n + 1, -1));
    for (ll i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] > c) { // 处理重边
            dist[a][b] = c;
        }
        // 如果是无向图，加上下面这句：
        // if (dist[b][a] > c) dist[b][a] = c;
    }
    floyd_with_path(n, dist, next);
    cout << "最短距离矩阵：" << endl;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "从节点1到节点" << n << "的路径：" << endl;
    vector<ll> path = get_path(1, n, next);
    if (path.empty()) {
        cout << "不可达" << endl;
    } else {
        cout << "路径: ";
        for (size_t i = 0; i < path.size(); ++i) {
            if (i > 0) cout << " -> ";
            cout << path[i];
        }
        cout << endl;
        cout << "距离: " << dist[1][n] << endl;
    }
    
    return 0;
}	
