#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    set<int>st;
    auto it = st.lower_bound(x);
    if (it != st.end())
        x++;
    vector<int> nums = { 1, 2, 4, 4, 5, 6 }; 
    auto its = std::lower_bound(nums.begin(), nums.end(), 4);
    if (its != nums.end()) {
        std::cout << "First element >= 4 is at index " << (its - nums.begin())
            << ", value = " << *its << std::endl;
    }
    int num[] = { 1,3,6,4,3,7 };
    sort(num, num + 6);
    int position = lower_bound(num, num + 4, 4) - num;
    int arr[] = { 1, 2, 4, 4, 5, 7, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int num1;
    int* lb = lower_bound(arr, arr + n, num1);
    cout << "lower_bound for " << num1 << " at position " << (lb - arr)<< " with value " << *lb << endl;
    int* ub = upper_bound(arr, arr + n, num1);
    cout << "upper_bound for " << num1 << " at position " << (ub - arr)<< " with value " << *ub << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    //vector<int>vec(t);
    vector<int>a(t+1);
    for(int z=1;z<=t;z++)
    {
        cin>>a[z];
    }
    int n;
    cin>>n;
    vector<int>m(n);
    for(int j=0;j<n;j++)
    {
        cin >> m[j];
        auto ub = lower_bound(a.begin(), a.end(), m[j]);
        cout << (ub - a.begin() - 1) << endl;
    }
    return 0;
}