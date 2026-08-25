#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll INF = 1e18;
//状态压缩 二进制压缩
        /*
    一共有n个点 编号0~n-1 用一个n位二进制数来记录走过哪些点
    第i位为0 第i位还未被走过 ( 1 >> n ) - 1
    F[state][j] 表示 经过了state这些点 目前在j位置 0 <= state <= ( 1 >> n ) - 1
    F[][]的值表示最短路径长度
    初始化：F[1][0] = 0; F[state][j] 初始为INF 2的无穷次幂100……00可看作全为0
    最终结果：F[(1 << n) - 1][n - 1];

    具体实现 w[k][j] 表示从k到j的直接距离
        for(ll state = 0;;) F[state][j] = min(F[state ^ (1 << j)][k] + w[k][j]);
        state ^ (1 << j) 将第j位按位取反 去除state中j点
    举例 F[6][2] = F[2][1] + w[1][2];
    6:110 经过了点1 点2 6^(1<<2)=2;
        */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>>w(n,vector<ll>(n));
    for(ll i = 0; i < n; i++) 
    {
        for(ll j = 0; j < n; j++) 
        {
            cin >> w[i][j];
        }
    }
    ll states = 1 << n;  // 总状态数
    vector<vector<ll>> F(states, vector<ll>(n, INF));
    F[1][0] = 0;  // 只经过了点0，目前在点0，代价为0
    for(ll state = 0; state < (1 << n); state++)
    {
        for(ll j = 0; j < n; j++)
        {
            if(state & (1 << j))//j在当前路径中
            {
                for(ll k = 0; k < n; k++)
                {
                    if(k != j && (state & (1 << k)))
                    {
                        F[state][j] = min(F[state][j], F[state ^ (1 << j)][k] + w[k][j]);
                    }
                }
            }
        }
    }
    ll ans = INF;
    int full_state = (1 << n) - 1;
    for(int j = 1; j < n; j++) 
    {
        if(F[full_state][j] == INF || w[j][0] == INF) continue;
        ans = min(ans, F[full_state][j] + w[j][0]);
    }
    
    if(ans == INF) 
    {
        cout << -1 << endl;
    } 
    else 
    {
        cout << ans << endl;
    }
    return 0;
}

/*
新学期，3n名新生来到校队试训。正式参加ICPC/CCPC之前，他们得先组成队伍。组队必须满足两条规则：
每支队伍恰好有三名队员；每名队员恰好加入一支队伍。规则只有两条，麻烦却不少：要组队
每两名队员之间都有一个整数默契值；如果两个人实在合不来，这个值甚至可以是负数。
一支队伍的得分是队内三对队员之间的默契值之和。求所有合法组队方案中，队伍总得分的最大值。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int m = 3 * n;
    vector<vector<long long>> a(m, vector<long long>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int totalStates = 1 << m;
    vector<long long> dp(totalStates, -1e18);
    dp[0] = 0;
    for (int mask = 0; mask < totalStates; mask++) {
        if (dp[mask] == -1e18) continue;
        int cnt = __builtin_popcount(mask);// 已选人数
        if (cnt % 3 != 0) continue;
        if (cnt == m) continue; // 已经完成分组
        int first = -1;// 找到第一个未选的人
        for (int i = 0; i < m; i++) {
            if (!(mask & (1 << i))) {
                first = i;
                break;
            }
        }
        // 从剩余的人中选另外两个
        for (int j = first + 1; j < m; j++) {
            if (mask & (1 << j)) continue;
            for (int k = j + 1; k < m; k++) {
                if (mask & (1 << k)) continue;
                int newMask = mask | (1 << first) | (1 << j) | (1 << k);
                long long addScore = a[first][j] + a[first][k] + a[j][k];
                dp[newMask] = max(dp[newMask], dp[mask] + addScore);
            }
        }
    }
    cout << dp[totalStates - 1] << "\n";
    return 0;
}

*/