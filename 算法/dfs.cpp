#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
inline ll read()
{
	ll s = 0,w = 1;char ch = getchar();
	while(ch<'0'||ch>'9') { if(ch == '-') w = -1; ch = getchar();}
	while(ch>='0'&&ch<='9') { s = s * 10 + ch - '0'; ch = getchar();}
	return s*w;
}
void write(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
ll ans = 0;
ll dx[8] = {-1,-2,-1,-2,1,2,1,2};
ll dy[8] = {2,1,-2,-1,2,1,-2,-1};
ll ax[2] = {0 , 1};
ll ay[2] = {1, 0};
vector<vector<ll>>vec(1001, vector<ll>(1001, 0));
ll mx, my, ex, ey;
ll check(ll x, ll y)
{
    if(x >= 0 && x <= ex && y >= 0 && y <= ey && vec[x][y] == 0) return 1;
    else return 0;
}
void solve()
{
    ex = read();ey = read(); 
    mx = read();my = read();
    vec[mx][my] = 1;
    for(ll i = 0; i < 8; i++)
    {
        ll nx = mx + dx[i];
        ll ny = my + dy[i];
        if(check(nx, ny))
        {
            vec[nx][ny] = 1;
        } 
    }
}
void dfs(ll x, ll y)
{
    if(x == ex && y == ey)
    {
        ans++;
        return ;
    }
    for(ll i = 0; i < 2; i++)
    {
        ll tx = x + ax[i];
        ll ty = y + ay[i];
        if(check(tx, ty))
        {
            dfs(tx, ty); 
        }
    }
}
int main()
{
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
    dfs(0, 0);
    write(ans);
    return 0;
}