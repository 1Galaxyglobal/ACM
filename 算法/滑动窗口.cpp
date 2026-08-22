/*
m 位画家所画的图画。游客在购买门票时必须说明两个数字，x 和 y，代表他要看展览中的第 x 幅至第 y 幅画
（包含 x,y）之间的所有图画，而门票的价钱就是一张图画一元。我希望入场后可以看到所有名师的图画。
当然，他想最小化购买门票的价格。请求出他购买门票时应选择的 x,y。若存在多组解，输出 x 最小的那组。
样例：Input：12 5
2 5 3 1 3 2 4 1 1 5 4 3
Output：2 7
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
bool cmp(const pair<pll, ll>&a, const pair<pll, ll>&b)
{
    if(a.second != b.second) return a.second < b.second;
    return a.first.first < b.first.first;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    deque<ll> dq;
    ll vis[1000001] = {0};
    vector<pair<pll, ll>> vec;
    ll _;
    for(ll i = 0; i < n; i++)
    {
        cin >> _;
        dq.push_back(_);
    }
    ll le = 0, rig = 0;
    ll ans = 0;
    while(rig < n && le <= rig)
    {
        if(ans < m) 
        {
            if(vis[dq[rig]] == 0)
            {
                ans++;
            }
            vis[dq[rig]]++;
            rig++;
        }
        if(ans == m)
        {
            vec.push_back({{le + 1, rig}, rig - le});
            vis[dq[le]]--;
            if(vis[dq[le]] == 0)
            {
                ans--;
            }
            le++;
        }
        
    }
    sort(vec.begin(), vec.end(), cmp);
    cout << vec[0].first.first << ' ' << vec[0].first.second;
    return 0;
}