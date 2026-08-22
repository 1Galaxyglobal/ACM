#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> w(n);
    for(ll i = 0; i < n; i++) {
        cin >> w[i];
    }
/*学校里有一个水房，水房里一共装有 m 个龙头可供同学们打开水，每个龙头每秒钟的供水量相等，均为 1。
    现在有 n 名同学准备接水，他们的初始接水顺序已经确定。将这些同学按接水顺序从 1 到 n 编号，
    i 号同学的接水量为 wi。接水开始时，1 到 m 号同学各占一个水龙头，并同时打开水龙头接水。
    当其中某名同学 j 完成其接水量要求 wj后，下一名排队等候接水的同学k马上接替j同学的位置开始接水。
    这个换人的过程是瞬间完成的，且没有任何水的浪费。即 j 同学第 x 秒结束时完成接水，
    则 k 同学第 x+1 秒立刻开始接水。若当前接水人数n不足m,则只有n个龙头供水，其它 m−n 个龙头关闭。
    现在给出 n 名同学的接水量，按照上述接水规则，问所有同学都接完水需要多少秒。*/
    // 如果人数少于等于龙头数，直接取最大值
    if(n <= m) {
        ll max_w = 0;
        for(ll i = 0; i < n; i++) {
            max_w = max(max_w, w[i]);
        }
        cout << max_w << '\n';
        return 0;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;// 小根堆：存储每个龙头的预计结束时间
    for(ll i = 0; i < m; i++) {// 初始化：前 m 个同学开始接水
        pq.push(w[i]);
    }
    // 从第 m+1 个同学开始
    for(ll i = m; i < n; i++) {
        ll earliest_end = pq.top(); // 最早结束的龙头
        pq.pop();
        pq.push(earliest_end + w[i]); // 当前同学接替，更新结束时间
    }
    ll ans = 0;
    while(!pq.empty()) 
    {
        ans = max(ans, pq.top());
        pq.pop();
    }
    cout << ans << '\n';
    priority_queue<ll>q1; //q1 = q2
    priority_queue<ll, vector<ll>, less<ll>> q2; // 大根堆 top为最大
    priority_queue<ll, vector<ll>, greater<ll>> q3; // 小根堆 top为最小
    for(ll i = 0; i < 7; i++)
    {
        ll _;
        cin >> _;
        q1.push(_);q2.push(_);q3.push(_);
    }
    cout << q1.top() << ' ' << q2.top() << ' ' << q3.top() << endl;
    while(!q3.empty())
    {
        cout << q3.top() << ' ';
        q3.pop();
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
using pll = pair<long, long>;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> vec(n + 1 ,0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;//小根堆 堆顶最小值
    for(ll i = 1; i <= n; i++) 
    {
        cin >> vec[i];//已经所用时间，每一件生产时间
        pq.push({vec[i], vec[i]});//按完成时间排序
    }
    ll ans = 0;
    for(ll i = 1; i <= m; i++)
    {
        auto [finish, exceed] = pq.top();//取队列首元
        pq.pop();//出队
        ans = finish;
        pq.push({finish + exceed, exceed});
    }
    cout << ans;
    return 0;
}

给定一个长度为 N 的非负整数序列 A，对于前奇数项求中位数。
#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int>>q1;
priority_queue<int,vector<int>,greater<int>>q2;
int main()
{
    int n;
    int a[100100];
    int mid;
    cin>>n;
    cin>>a[1]; 
    mid=a[1];
    cout<<mid<<endl;
    for(int i=2;i<=n;i++)
    {
        cin >> a[i];
        if(a[i] > mid) q2.push(a[i]);
        else q1.push(a[i]);
        if(i%2==1)
        {
            while(q1.size()!=q2.size())
            {
                if(q1.size()>q2.size())
                {
                    q2.push(mid);
                    mid=q1.top();
                    q1.pop();
                }
                else
                {
                    q1.push(mid);
                    mid=q2.top();
                    q2.pop();
                }
            }
            cout<<mid<<endl;
        }
    }
    return 0;
}
一个集合有如下元素：1 是集合元素；若 P 是集合的元素，则 2×P+1，4×P+5 也是集合的元素。
取出此集合中最小的 k 个元素，按从小到大的顺序组合成一个多位数，现要求从中删除 m 个数位上的数字，
使得剩下的数字最大，输出删除前和删除后的多位数字。
#include<bits/stdc++.h>
using namespace std;
int k,m;
priority_queue<int,vector<int>,greater<int> > cre;
string s;
int main()
{
    cin>>k>>m;
    cre.push(1);
    for(int i=1;i<=k;i++)
    {
        int x=cre.top();
        s+=to_string(x);
        cre.pop();
        cre.push(2*x+1);
        cre.push(4*x+5);
    }
    cout<<s<<endl;
    int cnt=0;
    while(1)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]<s[i+1])
            {
                cnt++;
                s.erase(i,1);
                if(cnt>=m)
                {
                    cout<<s<<endl;
                    return 0;
                }
                break;
            }
        }
    }
	return 0;
}
一个含有 n 项的数列，求出每一项前的 m 个数到它这个区间内的最小值。
若前面的数不足 m 项则从第 1 个数开始，若前面没有数则输出 0。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (ll i = 0; i < n; i++) 
    {
        ll x;
        cin >> x;

        if (i == 0) 
        {
            cout << 0 << '\n';
        } 
        else 
        {
            ll left = max(0LL, i - m);
            while (!pq.empty() && pq.top().second < left) 
            {
                pq.pop();
            }
            cout << pq.top().first << '\n';
        }
        pq.push({x, i});
    }
    return 0;
}
*/