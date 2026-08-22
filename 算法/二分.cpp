#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x, a, b;

ll shanghai(ll huihe, ll k)
{
    if(k > huihe) return 0;
    if(k < 0) return 0;
    ll bugong = huihe - k;
    ll dusha = a * (1 + k) * k / 2 - (k - 1) * k / 2;
    ll duceng = k * (a - 1);
    ll poison;
    if(duceng >= bugong)
    {
        poison = (duceng + (duceng - bugong + 1)) * bugong / 2;
    }
    else
    {
        poison = duceng * (duceng + 1) / 2;
    }
    return dusha + b * bugong + poison;
}
ll ac(ll huihe)
{
    if(b * huihe >= x) return 1;
    for(ll i = 0; i <= huihe; i++)
    {
        if(shanghai(huihe, i) >= x) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> a >> b;
    ll L = 1, R = x;
    while(L < R)
    {
        ll mid = (L + R) / 2;
        if(ac(mid))
        {
            R = mid;
        }
        else
        {
            L = mid + 1;
        }
    }
    cout << L << '\n';
    return 0;
}
/*
Mirko 的伐木机工作流程如下：Mirko 设置一个高度参数 H（米），伐木机升起一个巨大的锯片到高度 H，
并锯掉所有树比 H 高的部分.Mirko 就得到树木被锯下的部分。如果一排树的高度分别为 20,15,10 和 17，
Mirko 把锯片升到 15 米的高度，切割后树木剩下的高度将是 15,15,10 和 15，
而 Mirko 将从第 1 棵树得到 5 米，从第 4 棵树得到 2 米，共得到 7 米木材。
请帮助 Mirko 找到伐木机锯片的最大的整数高度 H，使得他能得到的木材至少为 M 米。
换句话说，如果再升高 1 米，他将得不到 M 米木材。
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> vec(n, 0);
    ll sum = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }
    sort(vec.begin(), vec.end());
    vector<ll> sumd(n, 0);
    for(ll i = 0; i < n; i++)
    {
        if(i == 0) sumd[i] = vec[i];
        else sumd[i] = sumd[i - 1] + vec[i];
    }
    ll L = vec[0], R = vec[n - 1];
    while(L < R)
    {
        ll mid = (L + R) / 2;
        auto ub = upper_bound(vec.begin(), vec.end(), mid);
        ll ans = sumd[ub - vec.begin() - 1] + (n - (ub - vec.begin())) * mid;
        if(sum - ans < m)
        {
            R = mid;
        }
        else 
        {
            L = mid + 1;
        }
    }
    cout << R - 1;
    return 0;
}
*/