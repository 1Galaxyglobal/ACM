#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 辅助函数：打印分隔线
void printSeparator(const string& title) {
    cout << "\n========== " << title << " ==========\n";
}

int main() {
    // ==================== 1. vector ====================
    printSeparator("vector");
    vector<int> vec;
    
    // 增
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.insert(vec.begin(), 5);          // 头部插入
    vec.insert(vec.end() - 1, 25);       // 倒数第二个位置插入
    
    // 删
    vec.pop_back();                       // 删除最后一个元素
    vec.erase(vec.begin());               // 删除第一个元素
    // vec.clear();                       // 清空所有元素
    
    // 改
    if (!vec.empty()) vec[0] = 15;        // 修改指定位置元素
    
    // 查
    auto it = find(vec.begin(), vec.end(), 20);
    if (it != vec.end()) cout << "找到20，位置：" << distance(vec.begin(), it) << endl;
    
    // 遍历
    cout << "vector遍历: ";
    for (int val : vec) cout << val << " ";
    cout << "\n反向遍历: ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) cout << *rit << " ";
    
    // 其他常用操作
    cout << "\n大小: " << vec.size() << ", 容量: " << vec.capacity();
    cout << ", 是否为空: " << (vec.empty() ? "是" : "否") << endl;
    
    // ==================== 2. set ====================
    printSeparator("set");
    set<int> st = {5, 3, 8, 1, 3, 5};    // 自动去重排序
    
    // 增
    st.insert(10);
    st.insert(7);
    st.insert(1);                         // 重复元素不会插入
    
    // 删
    st.erase(3);                          // 删除值为3的元素
    // st.clear();                        // 清空
    
    // 查
    if (st.count(8)) cout << "8存在\n";
    auto sit = st.find(5);
    if (sit != st.end()) cout << "找到5\n";
    
    // 遍历
    cout << "set遍历(升序): ";
    for (int val : st) cout << val << " ";
    
    // lower_bound / upper_bound
    auto low = st.lower_bound(5);
    auto up = st.upper_bound(5);
    cout << "\nlower_bound(5): " << *low << ", upper_bound(5): " << *up;
    cout << "\n大小: " << st.size() << ", 是否为空: " << (st.empty() ? "是" : "否") << endl;
    
    // ==================== 3. queue ====================
    printSeparator("queue");
    queue<int> q;
    
    // 入队
    q.push(100);
    q.push(200);
    q.push(300);
    
    // 访问队首/队尾
    cout << "队首: " << q.front() << ", 队尾: " << q.back() << endl;
    
    // 出队
    q.pop();                              // 移除队首
    cout << "出队后队首: " << q.front() << endl;
    
    // 遍历（注意：queue没有迭代器，只能通过pop遍历）
    queue<int> temp_q = q;                // 复制一份
    cout << "queue遍历: ";
    while (!temp_q.empty()) {
        cout << temp_q.front() << " ";
        temp_q.pop();
    }
    cout << "\n大小: " << q.size() << ", 是否为空: " << (q.empty() ? "是" : "否") << endl;
    
    // ==================== 4. deque ====================
    printSeparator("deque");
    deque<int> dq = {1, 2, 3};
    
    // 增（两端均可）
    dq.push_front(0);
    dq.push_back(4);
    dq.insert(dq.begin() + 2, 99);       // 任意位置插入
    
    // 删
    dq.pop_front();
    dq.pop_back();
    dq.erase(dq.begin() + 1);            // 删除指定位置
    
    // 改
    dq[0] = 100;                         // 随机访问并修改
    
    // 查（随机访问）
    cout << "dq[0]: " << dq[0] << ", dq[1]: " << dq[1] << endl;
    
    // 遍历
    cout << "deque遍历: ";
    for (int val : dq) cout << val << " ";
    cout << "\n大小: " << dq.size() << ", 是否为空: " << (dq.empty() ? "是" : "否") << endl;
    
    // ==================== 5. stack ====================
    printSeparator("stack");
    stack<int> stk;
    
    // 入栈
    stk.push(10);
    stk.push(20);
    stk.push(30);
    
    // 取栈顶
    cout << "栈顶: " << stk.top() << endl;
    
    // 出栈
    stk.pop();
    cout << "出栈后栈顶: " << stk.top() << endl;
    
    // 遍历（同样无迭代器，需复制）
    stack<int> temp_stk = stk;
    cout << "stack遍历(从顶到底): ";
    while (!temp_stk.empty()) {
        cout << temp_stk.top() << " ";
        temp_stk.pop();
    }
    cout << "\n大小: " << stk.size() << ", 是否为空: " << (stk.empty() ? "是" : "否") << endl;
    
    // ==================== 6. map ====================
    printSeparator("map");
    map<string, int> mp;
    
    // 增
    mp["apple"] = 5;
    mp["banana"] = 3;
    mp.insert({"cherry", 7});
    mp.emplace("date", 2);
    
    // 删
    mp.erase("banana");                  // 按键删除
    // mp.clear();                        // 清空
    
    // 改
    mp["apple"] = 10;                    // 直接赋值修改
    
    // 查
    if (mp.count("apple")) cout << "apple存在，值: " << mp["apple"] << endl;
    auto mit = mp.find("cherry");
    if (mit != mp.end()) cout << "找到cherry: " << mit->first << "=" << mit->second << endl;
    
    // 遍历
    cout << "map遍历(按键升序):\n";
    for (const auto& p : mp) {
        cout << "  " << p.first << " -> " << p.second << endl;
    }
    
    // ==================== 7. unordered_map ====================
    printSeparator("unordered_map");
    unordered_map<string, int> ump;
    
    // 增删改查同map，但无序
    ump["one"] = 1;
    ump["two"] = 2;
    ump["three"] = 3;
    
    cout << "unordered_map遍历(无序): ";
    for (const auto& p : ump) {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << "\n桶数: " << ump.bucket_count() << ", 负载因子: " << ump.load_factor() << endl;
    
    // ==================== 8. unordered_set ====================
    printSeparator("unordered_set");
    unordered_set<int> us = {5, 3, 8, 1, 3, 5};  // 去重但无序
    
    us.insert(10);
    us.erase(3);
    
    cout << "unordered_set遍历(无序): ";
    for (int val : us) cout << val << " ";
    cout << "\n大小: " << us.size() << endl;
    
    // ==================== 9. multiset ====================
    printSeparator("multiset");
    multiset<int> ms = {1, 2, 2, 3, 3, 3, 4};
    
    // 允许重复元素
    ms.insert(2);
    ms.insert(5);
    
    // 删除（注意：erase(value)会删除所有匹配的元素）
    ms.erase(ms.find(3));                // 只删除一个3
    // ms.erase(3);                      // 会删除所有3
    
    cout << "multiset遍历(升序，允许重复): ";
    for (int val : ms) cout << val << " ";
    cout << "\n2出现的次数: " << ms.count(2) << endl;
    
    // ==================== 10. 二维容器 ====================
    printSeparator("二维容器");

    // 10.1 二维vector
    cout << "--- 二维vector ---\n";
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // 增：添加新行
    matrix.push_back({10, 11, 12});
    // 增：在某行添加新列
    matrix[0].push_back(13);
    // 增：在指定位置插入行
    matrix.insert(matrix.begin() + 1, {14, 15, 16});
    
    // 删：删除最后一行
    matrix.pop_back();
    // 删：删除指定行
    matrix.erase(matrix.begin() + 1);
    // 删：删除某行的指定列
    matrix[0].erase(matrix[0].begin() + 1);
    
    // 改：修改元素
    matrix[1][1] = 99;
    
    // 遍历二维vector
    cout << "二维vector遍历:\n";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "  行" << i << ": ";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // 10.2 二维set（set的set）
    cout << "\n--- 二维set ---\n";
    set<set<int>> setOfSets;
    setOfSets.insert({3, 1, 2});  // 内部自动排序为{1,2,3}
    setOfSets.insert({5, 4});
    setOfSets.insert({6, 7, 8});
    
    cout << "二维set遍历:\n";
    for (const auto& innerSet : setOfSets) {
        cout << "  { ";
        for (int val : innerSet) cout << val << " ";
        cout << "}\n";
    }
    
    // 10.3 二维map（map嵌套）
    cout << "\n--- 二维map (map<string, map<string, int>>) ---\n";
    map<string, map<string, int>> nestedMap;
    nestedMap["student"]["math"] = 90;
    nestedMap["student"]["english"] = 85;
    nestedMap["teacher"]["salary"] = 5000;
    
    cout << "二维map遍历:\n";
    for (const auto& outer : nestedMap) {
        cout << "  " << outer.first << ":\n";
        for (const auto& inner : outer.second) {
            cout << "    " << inner.first << " -> " << inner.second << endl;
        }
    }
    
    // ==================== 11. pair绑定用法 ====================
    printSeparator("pair绑定用法");

    // 11.1 pair的基本创建
    cout << "--- pair的基本创建 ---\n";
    pair<int, string> p1(1, "one");
    pair<int, string> p2 = make_pair(2, "two");
    pair<int, string> p3 = {3, "three"};  // C++11初始化列表
    
    cout << "p1: (" << p1.first << ", " << p1.second << ")\n";
    cout << "p2: (" << p2.first << ", " << p2.second << ")\n";
    cout << "p3: (" << p3.first << ", " << p3.second << ")\n";
    
    // 11.2 pair的比较
    cout << "\n--- pair比较 ---\n";
    pair<int, int> a(1, 2), b(1, 3), c(2, 1);
    cout << "(1,2) < (1,3): " << (a < b) << endl;  // 先比较first，相等再比较second
    cout << "(1,2) < (2,1): " << (a < c) << endl;
    
    // 11.3 vector<pair<T1, T2>> 常见用法
    cout << "\n--- vector<pair<int, string>> ---\n";
    vector<pair<int, string>> vp;
    
    // 增
    vp.push_back({1, "apple"});
    vp.push_back(make_pair(2, "banana"));
    vp.emplace_back(3, "cherry");      // emplace_back效率更高
    vp.insert(vp.begin(), {0, "zero"});
    
    // 删
    vp.pop_back();                     // 删除最后一个
    vp.erase(vp.begin());              // 删除第一个
    
    // 改
    if (!vp.empty()) vp[0] = {10, "ten"};
    
    // 查（按first查找）
    auto pairIt = find_if(vp.begin(), vp.end(),
                          [](const pair<int, string>& p) { return p.first == 2; });
    if (pairIt != vp.end())
        cout << "找到first=2: (" << pairIt->first << ", " << pairIt->second << ")\n";
    
    // 遍历
    cout << "vector<pair>遍历:\n";
    for (const auto& p : vp) {
        cout << "  (" << p.first << ", " << p.second << ")\n";
    }
    
    // 11.4 对vector<pair>排序（按second降序）
    cout << "\n--- 按second降序排序 ---\n";
    sort(vp.begin(), vp.end(),
         [](const pair<int, string>& x, const pair<int, string>& y) {
             return x.second > y.second;  // 字符串降序
         });
    cout << "排序后:\n";
    for (const auto& p : vp) {
        cout << "  (" << p.first << ", " << p.second << ")\n";
    }
    
    // 11.5 pair在map/unordered_map中的应用
    cout << "\n--- pair在map中的应用 ---\n";
    map<pair<int, int>, string> pairMap;
    pairMap[{1, 2}] = "point A";
    pairMap[{3, 4}] = "point B";
    pairMap.insert({{5, 6}, "point C"});
    
    cout << "pair作为key的map遍历:\n";
    for (const auto& entry : pairMap) {
        cout << "  (" << entry.first.first << "," << entry.first.second
             << ") -> " << entry.second << endl;
    }
    
    // 11.6 pair与set结合
    cout << "\n--- set<pair> ---\n";
    set<pair<int, int>> pairSet;
    pairSet.insert({3, 1});
    pairSet.insert({1, 2});
    pairSet.insert({2, 3});
    pairSet.insert({1, 2});  // 重复，不会插入
    
    cout << "set<pair>遍历(自动排序):\n";
    for (const auto& p : pairSet) {
        cout << "  (" << p.first << ", " << p.second << ")\n";
    }
    
    // 11.7 pair与priority_queue结合
    cout << "\n--- priority_queue<pair> (最大堆) ---\n";
    priority_queue<pair<int, string>> pq;
    pq.push({3, "three"});
    pq.push({1, "one"});
    pq.push({2, "two"});
    
    cout << "优先队列遍历(按first降序):\n";
    while (!pq.empty()) {
        cout << "  (" << pq.top().first << ", " << pq.top().second << ")\n";
        pq.pop();
    }
    
    // 11.8 C++17结构化绑定（如果编译器支持C++17）
    cout << "\n--- C++17结构化绑定 ---\n";
    pair<int, double> structuredPair = {42, 3.14};
    auto [id, value] = structuredPair;  // 解构绑定
    cout << "id = " << id << ", value = " << value << endl;
    
    // 在遍历中应用结构化绑定
    vector<pair<string, int>> studentScores = {{"Alice", 95}, {"Bob", 87}, {"Charlie", 92}};
    cout << "结构化绑定遍历:\n";
    for (const auto& [name, score] : studentScores) {
        cout << "  " << name << ": " << score << endl;
    }
    
    return 0;
}