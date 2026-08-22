#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    //find
    string s = "sggdkmdsdj";
    size_t g = s.find("kmd");//g=4;
    size_t k = s.find("ggg");//k=-1
    if(g != string::npos) 
    {
        cout << g << endl;
    }
    if(k != string::npos) 
    {
        cout << k << endl;
    }
    else cout << -1 << endl;

    //substr
    string x = s.substr(3, 6);//从下标3开始往后走6个字符
    cout << x << endl;//x = dkmdsd;

    //insert
    string y = s.insert(1, "hello");//0~1位之间
    string z = s.insert(0, 4, '!');//在最前面插入4个！
    cout << y << endl;//shelloggdkmdsdj
    cout << z << endl;//!!!!shelloggdkmdsdj

    //erase
    string p = s.erase(2,5);//从角标2开始（包括2）向后删除5个字符
    cout << p << endl;//!!lloggdkmdsdj
    //删除某一字符 eg:log
    string t = "log";
    ll len = t.length();
    size_t a = s.find(t);
    s.erase(a, len);
    cout << s << endl;//!!lgdkmdsdj

    //数组中删除元素
    vector<ll> vec = {1,44,0,2};
    auto it = find(vec.begin(), vec.end(), 2);
    if(it != vec.end())
    {
        vec.erase(it);
    }// 1 44 0

    //查找所有出现的位置
    string text, pattern;
    cin >> text >> pattern;
    vector<size_t> positions;
    size_t pos = text.find(pattern, 0);  // 从位置0开始查找
    while (pos != string::npos) 
    {
        positions.push_back(pos);
        pos = text.find(pattern, pos + 1);  // 从下一个位置继续查找
    }

    string c1, c2, s4;
    cin >> c1 >> c2 >> s4;
    string h = c1 + c2; //要查找的字符串
    size_t pos0 = 0;
    pos0 = s.find(h, pos0);
    while (pos0 != string::npos)
    {
        s.insert(pos0 + c1.length(), s4);//find(str, begin)从begin位置开始,查找str
        // 更新位置，跳过刚插入的部分
        pos0 += (c1.length() + s4.length() + c2.length());
    }
    cout << s <<endl;//把所有均替换

    //replace
    size_t pos1 = 2;
    s.replace(s.begin() + pos1, s.begin() + 3, "NOI");
    cout << s << endl;//!!NOIlgdkmdsdj

    //字符转数字
    string s1 = "45676";
    for(char c : s1)
    {
        cout << c - '0' << endl;
    }
    ll num = stoi(s1);
    cout << num << endl;  
    //数字转字符
    ll w=1;
    cout << w+'0';
    return 0;
}