/*
有一个邮递员要送东西，邮局在节点 1。他总共要送 n−1 样东西，其目的地分别是节点 2 到节点 n。
由于这个城市的交通比较繁忙，因此所有的道路都是单行的，共有 m 条道路。这个邮递员每次只能带一样东西，
并且运送每件物品过后必须返回邮局。求送完这 n−1 样东西并且最终回到邮局最少需要的时间。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<pll>> graph1(n + 1), graph2(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph1[u].push_back({v, w});
        graph2[v].push_back({u, w});
    }

    vector<ll> dist(n + 1, 999999999);
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq1;
    pq1.push({1, 0});
    while (!pq1.empty()) 
    {
        auto [d, u] = pq1.top();
        pq1.pop();
        for (auto [v, w] : graph1[d]) {
            if (dist[d] + w < dist[v]) {
                dist[v] = dist[d] + w;
                pq1.push({v, dist[v]});
            }
        }
    }
    ll total_time = 0;
    for (int i = 2; i <= n; i++) {
        total_time += dist[i];
    }

    // 因为是单向路所以反向建图
    vector<ll> dis(n + 1, 999999999);
    dis[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq2;
    pq2.push({1, 0});
    while (!pq2.empty()) {
        auto [d, u] = pq2.top();
        pq2.pop();

        for (auto [v, w] : graph2[d]) {
            if (dis[d] + w < dis[v]) {
                dis[v] = dis[d] + w;
                pq2.push({v, dis[v]});
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        total_time += dis[i];
    }
    cout << total_time << '\n';
    return 0;
}

/*
1.	不记录路径
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX / 2; // 避免溢出，设为比INT_MAX小的值
// Dijkstra 算法（不记录路径）
void dijkstra_no_path(const vector<vector<int>>& graph, int start, vector<int>& dist) {
    int N = graph.size();
    dist.assign(N, INF);      // 初始化距离为无穷大
    vector<bool> visited(N, false); // 标记是否已确定最短距离
    dist[start] = 0;          // 源点到自身的距离为0
    for (int i = 0; i < N; ++i) { // 共需N次循环，确定N个点的最短距离
        // 步骤1：找到未访问且距离最小的点u
        int u = -1, min_dist = INF;
        for (int j = 0; j < N; ++j) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // 剩余点不可达，提前退出
        visited[u] = true;  // 标记u为已访问
        for (int v = 0; v < N; ++v) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int N, M; // N: 节点数, M: 边数
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) graph[i][i] = 0; // 自身到自身距离为0
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // 假设是无向图则加 graph[v][u] = w;
    }
    int start;
    cin >> start;
    vector<int> dist;
    dijkstra_no_path(graph, start, dist);
    // 输出结果
    for (int i = 0; i < N; ++i) {
        if (dist[i] == INF) cout << "∞ ";
        else cout << dist[i] << " ";
    }
    return 0;
}
2.  
struct Edge {// 边的结构体
    int v, w; // v: 目标节点，w: 边权
};
// Dijkstra 算法（不记录路径）
void dijkstra_no_path(int n, int s, const vector<vector<Edge>>& graph, vector<int>& dist) {
    dist.assign(n + 1, INF); // 初始化距离为无穷大（节点从1开始）
    vector<bool> visited(n + 1, false); // 标记节点是否已确定最短距离
    dist[s] = 0; // 源点到自身的距离为0
    for (int i = 0; i < n; ++i) { // 共需n次循环，确定n个节点的最短距离
        // 步骤1：找到未访问且距离最小的节点u
        int u = -1, min_dist = INF;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // 剩余节点不可达，提前结束
        visited[u] = true;   // 标记u为已访问
        // 步骤2：松弛操作（更新u的邻接节点距离）
        for (const Edge& ed : graph[u]) {
            int v = ed.v, w = ed.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
}
int main() {
    int n, m, s;
    cin >> n >> m >> s; // 输入节点数、边数、源点
    vector<vector<Edge>> graph(n + 1); // 邻接表，graph[u]存储u的所有出边
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c; // 输入边：a->b，权值c
        graph[a].push_back({b, c});
        // 若图为无向图，需加上：graph[b].push_back({a, c});
    }
    vector<int> dist;
    dijkstra_no_path(n, s, graph, dist);
    // 输出结果（从s到各点的最短距离）
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            cout << "INF "; // 不可达
        } else {
            cout << dist[i] << " ";
        }
    }
    return 0;
}
*/
const int INF = INT_MAX / 2;
struct Edge {
    int v, w;
};

// Dijkstra 算法（记录路径）
void dijkstra_with_path(int n, int s, const vector<vector<Edge>>& graph, 
                        vector<int>& dist, vector<int>& pre) {
    dist.assign(n + 1, INF);
    pre.assign(n + 1, -1); // 初始化前驱为-1（表示无前驱）
    vector<bool> visited(n + 1, false);
    dist[s] = 0;

    for (int i = 0; i < n; ++i) {
        // 找到未访问且距离最小的节点u
        int u = -1, min_dist = INF;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        // 松弛操作 + 记录前驱
        for (const Edge& ed : graph[u]) {
            int v = ed.v, w = ed.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u; // 更新v的前驱为u
            }
        }
    }
}

// 回溯打印从s到t的路径
void print_path(int t, const vector<int>& pre) {
    vector<int> path;
    while (t != -1) { // 从t回溯到源点（pre[s] = -1）
        path.push_back(t);
        t = pre[t];
    }
    // 逆序输出（从源点到t）
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        // 无向图需加：graph[b].push_back({a, c});
    }

    vector<int> dist, pre;
    dijkstra_with_path(n, s, graph, dist, pre);

    // 输出距离和路径（示例：输出到节点n的路径）
    cout << "最短距离：" << dist[n] << endl;
    cout << "路径：";
    print_path(n, pre);

    return 0;
}
