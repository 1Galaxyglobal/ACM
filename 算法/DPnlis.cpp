#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10001],dp[10001];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int maxlen;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxlen = max(maxlen, dp[i]);
    }
     cout<<maxlen<<endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }
    vector<int> lis;
    for (int num : nums)
    {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end())
        {
            lis.push_back(num);
        }
        else
        {
            *it = num;
        }
    }
    cout << lis.size() << endl;
    return 0;
}