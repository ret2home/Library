---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/SparseTable.cpp
    title: Sparse Table
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/SparseTable.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 2 \"template/template.cpp\"\n#include <algorithm>\n#include <bitset>\n\
    #include <complex>\n#include <deque>\n#include <exception>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <stdexcept>\n#include <streambuf>\n\
    #include <string>\n#include <typeinfo>\n#include <utility>\n#include <valarray>\n\
    #include <vector>\n#include <array>\n#include <atomic>\n#include <chrono>\n#include\
    \ <codecvt>\n#include <condition_variable>\n#include <forward_list>\n#include\
    \ <future>\n#include <initializer_list>\n#include <mutex>\n#include <random>\n\
    #include <ratio>\n#include <regex>\n#include <scoped_allocator>\n#include <system_error>\n\
    #include <thread>\n#include <tuple>\n#include <typeindex>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\nusing namespace std;\n#define\
    \ ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n#define REP(i,\
    \ n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i = n - 1; i >= 0;\
    \ i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define all(v) v.begin(),\
    \ v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n#define len(s) (int)s.size()\n\
    #define compress(v) sort(all(v)); v.erase(unique(all(v)),v.end());\n#define comid(v,x)\
    \ lower_bound(all(v),x)-v.begin()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SparseTable.cpp\"\
    \n\ntemplate <class T, T (*f)(T, T)>\nstruct SparseTable {\n    vector<T> table[20];\n\
    \    vector<int> log;\n    SparseTable(vector<T> v)\n        : log(v.size() +\
    \ 1) {\n        int mx = 0;\n        while (1 << (mx + 1) <= len(v)) ++mx;\n \
    \       rep(i, mx + 1) {\n            table[i].resize(len(v));\n            rep(j,\
    \ v.size() - (1 << i) + 1) {\n                if (i)\n                    table[i][j]\
    \ = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n                else\n\
    \                    table[i][j] = v[j];\n            }\n        }\n        for\
    \ (int i = 2; i <= len(v); i++) log[i] = log[i >> 1] + 1;\n    }\n    T query(int\
    \ l, int r) {\n        return f(table[log[r - l]][l], table[log[r - l]][r - (1\
    \ << log[r - l])]);\n    }\n};\n/*\n@brief Sparse Table\n@docs docs/SparseTable.md\n\
    */\n#line 4 \"test/SparseTable.test.cpp\"\n\nauto f=[](int a,int b)->int{return\
    \ min(a,b);};\nint main(){\n\tint N,Q;cin>>N>>Q;\n\tvector<int>V(N);\n\tfor(int\
    \ &i:V)cin>>i;\n\tSparseTable<int,f>ST(V);\n\twhile(Q--){\n\t\tint l,r;cin>>l>>r;\n\
    \t\tcout<<ST.query(l,r)<<\"\\n\";\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../structure/SparseTable.cpp\"\n\nauto f=[](int a,int b)->int{return min(a,b);};\n\
    int main(){\n\tint N,Q;cin>>N>>Q;\n\tvector<int>V(N);\n\tfor(int &i:V)cin>>i;\n\
    \tSparseTable<int,f>ST(V);\n\twhile(Q--){\n\t\tint l,r;cin>>l>>r;\n\t\tcout<<ST.query(l,r)<<\"\
    \\n\";\n\t}\n}"
  dependsOn:
  - structure/SparseTable.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:11:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/SparseTable.test.cpp
- /verify/test/SparseTable.test.cpp.html
title: test/SparseTable.test.cpp
---
