/*联通问题 1把0围起来 求块数
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
  ll x, y;  
};
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
bool vis[1001][1001] = { 0 };
ll vec[1001][1001] = { 0 };
ll n, m;
ll check(ll x, ll y)
{
    if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && vec[x][y] == 1) return 1;
    else return 0;
}
ll ans = 0;
void bfs(ll x, ll y)
{
    queue<node> q;
    q.push({x, y});
    vis[x][y] = 1;
    while(!q.empty())
    {
        node p = q.front();
        q.pop();
        ll px = p.x;
        ll py = p.y;
        for(ll i = 0; i < 4; i++)
        {
            ll nx = px + dx[i];
            ll ny = py + dy[i];
            if(check(nx, ny))
            {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            char l;
            cin >> l;
            if(l == 'R') vec[i][j] = 1;
            else vec[i][j] = 0;
        }
    }
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            if(vec[i][j] == 1 && vis[i][j] == 0)
            {
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
*/
//从某到某的最短路
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll inf=1e18;
ll n,m,t;
bool flag = 0;
ll sx,sy,fx,fy;
ll dx[4] = { 0 , 0 , 1 , -1 };
ll dy[4] = { 1 , -1 , 0 , 0 };
bool vec[1001][1001] = { 0 };
bool vis[1001][1001] = { 0 };
struct palce {
    ll x, y, step;
};
bool check(ll x,ll y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m && vec[x][y] != 1 && vis[x][y] != 1)
    {
        return 1;
    }
    else return 0;
}
int bfs(ll a,ll b)
{
    queue<palce>st;
    st.push({a, b, 0});
    vis[a][b] = 1;
    while(!st.empty()) {
        palce p = st.front();
        st.pop();
        ll px = p.x;
        ll py = p.y;
        for(ll i = 0; i < 4; i++) {
            ll nx = px + dx[i];
            ll ny = py + dy[i];
            if(check(nx, ny))
            {
                if(nx == fx && ny == fy)
                {
                    return p.step + 1;
                    flag = 1;
                    break;
                }
                else
                {
                    st.push({nx, ny, p.step + 1});
                    vis[nx][ny] = 1; 
                }
            } 
        }
        if(flag == 1) break;
    }
}
void solve()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for(ll i = 0; i < t; i++) {
        ll tmpx,tmpy;
        cin >> tmpx >> tmpy;
        vec[tmpx][tmpy] = 1;
    }
    cout << bfs(sx,sy) << endl;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
/*马走日
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
struct place {
    ll x, y, step = 0;
};
ll n,m,x,y;
bool vis[401][401] = { 0 };
ll step[401][401] = { 0 };
int ax[8] = {1, -1, 1, -1, -2, -2, 2, 2};
int ay[8] = {2, -2, -2, 2, 1, -1, -1, 1};
bool check(ll x,ll y) 
{
    if(vis[x][y] == 0 && x < n && y < m && x >= 0 && y >= 0)
    {
        return 1;
    }
    else return 0;
}
void bfs(ll x,ll y)
{
    queue<place>st;
    st.push({x, y, 0});
    vis[x][y] = 1;
    while (!st.empty())
    {
        place q = st.front();
        ll px = q.x;
        ll py = q.y;
        st.pop();
        for(ll i = 0; i < 8; i++ )
        {
            ll nx = px + ax[i];
            ll ny = py + ay[i];
            if(check(nx, ny))
            {
                step[nx][ny] = q.step+1;
                vis[nx][ny] = 1;
                st.push({nx, ny, q.step+1});
            }
        }
    }
    
}
void solve()
{
    ll x1,y1;
    cin >> n >> m >> x1 >> y1;
    ll x = x1 - 1 , y = y1 - 1;
    step[x][y] = 0;
    bfs(x,y);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(vis[i][j] == 0) {
                step[i][j] = -1;
            }
        }
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cout << step[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
    */


    /*
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int inf=5e5;
struct place{
    ll x, y, step;
};
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};
ll n, m, q, fx, fy;
bool vis[1001][1001] = { 0 };
bool check(ll x, ll y)
{
    if(x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == 0)
    {
        return 1;
    }
    else return 0;
}
bool bfs(ll x, ll y)
{
    if (x == fx && y == fy) {
        return 1;
    }
    if (vis[fx][fy]) {
        return 0;
    }
    queue<place>st;
    st.push({x, y, 0});
    vis[x][y] = 1;
    while(!st.empty()) {
        place p = st.front();
        st.pop();
        ll px = p.x;
        ll py = p.y;
        for(ll i = 0; i < 4; i++) {
            ll nx = px + dx[i];
            ll ny = py + dy[i];
            if(check(nx, ny)) {
                if(nx == fx && ny == fy) {
                    return 1;
                }
                else 
                {
                    st.push({nx, ny, p.step+1});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    cin >> fx >> fy;
    cin >> q;
    while(q--) {
        ll tx, ty;
        cin >> tx >> ty;
        vis[tx][ty] = 1;
    }
    if(bfs(0,0)) {
        cout << "Yes" << endl;
    }
    else cout << "No" <<endl;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
    

有一个仅由数字 0 与 1 组成的n×n格迷宫。若你位于一格 0 上，那么你可以移动到相邻4格中的某一格1上，
同样若你位于一格 1 上，那么你可以移动到相邻 4 格中的某一格 0 上。
你的任务是：对于给定的迷宫，询问从某一格开始能移动到多少个格子（包含自身）。
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
    ll x, y;  
};
ll n, m;
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
ll vis[1001][1001];
ll vec[1001][1001];
ll num[1001][1001];

ll bfs(ll x, ll y, ll id)
{
    queue<node> q;
    vector<pair<ll,ll>> path;  // 记录路径
    q.push({x, y});
    vis[x][y] = id;
    path.push_back({x, y});
    
    while(!q.empty())
    {
        node p = q.front();
        q.pop();
        ll px = p.x;
        ll py = p.y;
        for(ll i = 0; i < 4; i++)
        {
            ll nx = px + dx[i];
            ll ny = py + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && vis[nx][ny] == 0 && (vec[px][py] + vec[nx][ny] == 1))
            {
                vis[nx][ny] = id;
                q.push({nx, ny});
                path.push_back({nx, ny});
            }
        }
    }   
    // 统一赋值
    ll cnt = path.size();
    for(auto [x, y] : path)
        num[x][y] = cnt;
    
    return cnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    
    vector<string> str(n);
    for(ll i = 0; i < n; i++)
        cin >> str[i];
    
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            vec[i][j] = str[i][j] - '0';
    memset(vis, 0, sizeof(vis));
    ll id = 0;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            if(vis[i][j] == 0) 
                bfs(i, j, ++id);
    
    for(ll i = 0; i < m; i++)
    {
        ll L, R;
        cin >> L >> R;
        L--; R--;
        cout << num[L][R] << '\n';
    }
    return 0;
}
    */