---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.cpp
    title: Union Find
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    #define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i =\
    \ n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define\
    \ all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int, int>\n\
    #define pi acos(-1)\n#define len(s) (int)s.size()\n#define compress(v) \\\n  \
    \  sort(all(v));   \\\n    v.erase(unique(all(v)), v.end());\n#define comid(v,\
    \ x) lower_bound(all(v), x) - v.begin()\n\ntemplate<class T>\nusing prique=priority_queue<T,vector<T>,greater<>>;\n\
    \ntemplate <class T, class U>\ninline bool chmin(T &a, U b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b) {\n     \
    \   a = b;\n        return true;\n    }\n    return false;\n}\nconstexpr ll inf\
    \ = 3e18;\n#line 3 \"structure/UnionFind.cpp\"\n\nclass UnionFind {\n    int N;\n\
    \    vector<int> par, siz;\n\n   public:\n    int find(int x) {\n        assert(x\
    \ < N);\n        return (par[x] == x ? x : par[x] = find(par[x]));\n    }\n  \
    \  void merge(int x, int y) {\n        assert(x < N && y < N);\n        x = find(x);\n\
    \        y = find(y);\n        if (x == y) return;\n        if (siz[x] > siz[y])\
    \ swap(x, y);\n        par[x] = y;\n        siz[y] += siz[x];\n    }\n    bool\
    \ same(int x, int y) {\n        return find(x) == find(y);\n    }\n    int size(int\
    \ x) {\n        return siz[find(x)];\n    }\n    UnionFind(int N) : N(N), siz(N,\
    \ 1), par(N) {\n        iota(all(par), 0);\n    }\n};\n\n/*\n@brief Union Find\n\
    @docs docs/UnionFind.md\n*/\n#line 4 \"test/UnionFind.test.cpp\"\n\nint N,Q;\n\
    int main(){\n    cin>>N>>Q;\n    UnionFind uf(N);\n    while(Q--){\n        int\
    \ t,u,v;cin>>t>>u>>v;\n        if(!t)uf.merge(u,v);\n        else cout<<uf.same(u,v)<<\"\
    \\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../structure/UnionFind.cpp\"\n\nint N,Q;\nint main(){\n    cin>>N>>Q;\n  \
    \  UnionFind uf(N);\n    while(Q--){\n        int t,u,v;cin>>t>>u>>v;\n      \
    \  if(!t)uf.merge(u,v);\n        else cout<<uf.same(u,v)<<\"\\n\";\n    }\n}"
  dependsOn:
  - structure/UnionFind.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:44:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/UnionFind.test.cpp
- /verify/test/UnionFind.test.cpp.html
title: test/UnionFind.test.cpp
---
