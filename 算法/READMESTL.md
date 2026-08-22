# C++ STL 容器用法示例代码

## 📌 项目简介

本项目提供了一份**完整的 C++ STL（标准模板库）容器用法示例代码**，涵盖了一维容器、二维容器、`pair` 绑定等常见数据结构的增删改查操作。代码注释详尽，适合作为 STL 入门学习参考、面试复习笔记或日常开发速查手册。

---

## 📂 文件说明

| 文件名 | 说明 |
|--------|------|
| `main.cpp` | 包含全部 STL 容器用法示例的完整源码 |

---

## 🛠️ 编译与运行

### 环境要求
- **编译器**：GCC 7+ / Clang 6+ / MSVC 2019+（推荐支持 C++17）
- **标准**：C++11 及以上（部分特性需 C++17）

### 编译命令
```bash
# 使用 g++
g++ -std=c++17 -o stl_demo main.cpp

# 使用 Clang
clang++ -std=c++17 -o stl_demo main.cpp

# 运行
./stl_demo
```

---

## 📋 代码内容总览

### 一、一维容器（共 9 个）

| 序号 | 容器 | 核心特性 | 涵盖操作 |
|------|------|---------|----------|
| 1 | `vector` | 动态数组，随机访问 | `push_back`、`insert`、`pop_back`、`erase`、`clear`、`find`、`operator[]`、正向/反向遍历、`size`、`capacity`、`empty` |
| 2 | `set` | 自动升序去重 | `insert`、`erase`、`count`、`find`、`lower_bound`、`upper_bound`、遍历 |
| 3 | `queue` | 先进先出（FIFO） | `push`、`pop`、`front`、`back`、`empty`、遍历（复制法） |
| 4 | `deque` | 双端队列，随机访问 | `push_front`、`push_back`、`pop_front`、`pop_back`、`insert`、`erase`、`operator[]` |
| 5 | `stack` | 后进先出（LIFO） | `push`、`pop`、`top`、`empty`、遍历（复制法） |
| 6 | `map` | 键值对，按键升序 | `operator[]`、`insert`、`emplace`、`erase`、`find`、`count`、遍历 |
| 7 | `unordered_map` | 哈希表，无序 | 同 map + `bucket_count`、`load_factor` |
| 8 | `unordered_set` | 哈希集合，无序去重 | `insert`、`erase`、`count`、遍历 |
| 9 | `multiset` | 允许重复元素的有序集合 | `insert`、`erase`（单删/全删）、`count`、遍历 |

### 二、二维容器（共 3 个）

| 序号 | 容器 | 说明 |
|------|------|------|
| 1 | `vector<vector<int>>` | 二维动态数组，支持动态增删行列、随机访问、嵌套遍历 |
| 2 | `set<set<int>>` | 集合的集合，自动排序去重 |
| 3 | `map<string, map<string, int>>` | 嵌套映射，如"学生→科目→成绩"的三级结构 |

### 三、pair 绑定用法（共 8 个场景）

| 序号 | 场景 | 说明 |
|------|------|------|
| 1 | 基本创建 | `pair<T1,T2>`、`make_pair`、`{}` 初始化列表 |
| 2 | 比较运算 | 先比 `first`，再比 `second` |
| 3 | `vector<pair<int,string>>` | pair 列表的增删改查与遍历 |
| 4 | 自定义排序 | 按 `first` 或 `second` 升/降序排列 |
| 5 | `map<pair<int,int>, string>` | pair 作为复合键 |
| 6 | `set<pair<int,int>>` | pair 元素自动字典序排序 |
| 7 | `priority_queue<pair<...>>` | 优先队列中按 pair 排序 |
| 8 | C++17 结构化绑定 | `auto [a, b] = p` 解构赋值 |

---

## 📊 各容器操作速查表

| 容器 | 增 | 删 | 改 | 查 | 特殊操作 |
|------|-----|-----|-----|-----|----------|
| **vector** | `push_back`, `insert` | `pop_back`, `erase` | `operator[]` | `find`, `at` | `capacity`, `reserve` |
| **set** | `insert` | `erase(val/it)` | 不可直接改 | `count`, `find` | `lower_bound`, `upper_bound` |
| **queue** | `push` | `pop` | 不可直接改 | `front`, `back` | FIFO 结构 |
| **deque** | `push_front/back`, `insert` | `pop_front/back`, `erase` | `operator[]` | 随机访问 | 双端操作 |
| **stack** | `push` | `pop` | 不可直接改 | `top` | LIFO 结构 |
| **map** | `operator[]`, `insert`, `emplace` | `erase(key/it)` | `operator[]` | `count`, `find` | 按键排序 |
| **unordered_map** | 同上 | 同上 | 同上 | 同上 | O(1) 平均查找 |
| **unordered_set** | `insert` | `erase` | 不可直接改 | `count`, `find` | O(1) 平均查找 |
| **multiset** | `insert` | `erase(val/it)` | 不可直接改 | `count`, `find` | 允许重复，有序 |

---

## 🎯 使用建议

1. **学习阶段**：按序号从上到下阅读代码，每个容器独立成段，便于逐个理解。
2. **速查阶段**：直接搜索关键字（如 `queue`、`pair`、`二维`）定位到对应代码段。
3. **面试复习**：重点关注 `vector` 的 `capacity` 机制、`map` 与 `unordered_map` 的区别、`pair` 的排序规则。
4. **实际开发**：可将本文件作为代码片段库，复制粘贴后按需修改即可。

---

## 📝 注意事项

- 部分容器（如 `queue`、`stack`）**没有迭代器**，遍历时需借助临时副本。
- `set` / `map` 中的元素为 `const`，**不能直接修改**，需先删除再插入。
- `multiset::erase(value)` 会删除**所有**匹配元素，只想删一个需用 `erase(find(value))`。
- `unordered_*` 系列容器**不保证顺序**，遍历结果每次可能不同。
- C++17 结构化绑定（`auto [a, b] = p`）需要编译器开启 `-std=c++17` 或更高。

---

## 📄 License

MIT License — 可自由用于学习、教学和个人项目。
