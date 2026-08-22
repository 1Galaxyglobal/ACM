#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);  
    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<ll> les, gre;
    deque<ll> dq_min, dq_max;//存下表  
    for (ll i = 0; i < n; i++) {
        // 维护最小值单调队列（递增）
        while (!dq_min.empty() && vec[dq_min.back()] >= vec[i]) {
            dq_min.pop_back();
        }
        dq_min.push_back(i);
        // 维护最大值单调队列（递减）
        while (!dq_max.empty() && vec[dq_max.back()] <= vec[i]) {
            dq_max.pop_back();
        }
        dq_max.push_back(i);
        // 移出窗口外的元素
        while (!dq_min.empty() && dq_min.front() <= i - k) {
            dq_min.pop_front();
        }
        while (!dq_max.empty() && dq_max.front() <= i - k) {
            dq_max.pop_front();
        }
        if (i >= k - 1) {
            les.push_back(vec[dq_min.front()]);
            gre.push_back(vec[dq_max.front()]);
        }
    }
    for (auto ele : les) cout << ele << ' ';
    cout << '\n';
    for (auto ele : gre) cout << ele << ' ';
    return 0;
}