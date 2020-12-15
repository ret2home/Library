---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/BIT.cpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/BIT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i, n) for (ll i = 0; i < n; i++)\n#define\
    \ REP(i, n) for (ll i = 1; i < n; i++)\n#define rev(i, n) for (ll i = n - 1; i\
    \ >= 0; i--)\n#define all(v) v.begin(), v.end()\n#define P pair<ll, ll>\n#define\
    \ len(s) (ll) s.size()\n\ntemplate <class T, class U>\ninline bool chmin(T &a,\
    \ U b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate <class T, class U>\ninline bool chmax(T &a, U b) {\n   \
    \ if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BIT.cpp\"\n\ntemplate <class\
    \ T>\nclass BIT {\n    ll N;\n    vector<T> bit;\n    void add_(ll x, T y) {\n\
    \        while (x <= N) {\n            bit[x] += y;\n            x += x & -x;\n\
    \        }\n    }\n    T sum_(ll x) {\n        T res = 0;\n        while (x >\
    \ 0) {\n            res += bit[x];\n            x -= x & -x;\n        }\n    \
    \    return res;\n    }\n\n   public:\n    ll lower_bound(T w) {\n        if (w\
    \ <= 0) return -1;\n        ll x = 0;\n        ll k = 1;\n        while (k * 2\
    \ <= N) k *= 2;\n        for (; k > 0; k /= 2) {\n            if (x + k <= N &&\
    \ bit[x + k] < w) {\n                w -= bit[x + k];\n                x += k;\n\
    \            }\n        }\n        return x;\n    }\n    void add(ll x, T y) {\
    \ add_(x + 1, y); }\n    T sum(ll l, ll r) { return sum_(r) - sum_(l); }\n   \
    \ BIT(ll x) : N(x), bit(x + 1) {}\n};\n/*\n@brief Binary Indexed Tree\n@docs docs/BIT.md\n\
    */\n#line 3 \"test/BIT.test.cpp\"\n\nint main(){\n    int N,Q;\n    cin>>N>>Q;\n\
    \    BIT<ll>bit(N);\n    rep(i,N){\n        int a;cin>>a;\n        bit.add(i,a);\n\
    \    }\n    while(Q--){\n        int t;cin>>t;\n        if(!t){\n            int\
    \ p,x;cin>>p>>x;\n            bit.add(p,x);\n        }else {\n            int\
    \ l,r;cin>>l>>r;\n            cout<<bit.sum(l,r)<<\"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../structure/BIT.cpp\"\n\nint main(){\n    int N,Q;\n    cin>>N>>Q;\n\
    \    BIT<ll>bit(N);\n    rep(i,N){\n        int a;cin>>a;\n        bit.add(i,a);\n\
    \    }\n    while(Q--){\n        int t;cin>>t;\n        if(!t){\n            int\
    \ p,x;cin>>p>>x;\n            bit.add(p,x);\n        }else {\n            int\
    \ l,r;cin>>l>>r;\n            cout<<bit.sum(l,r)<<\"\\n\";\n        }\n    }\n\
    }"
  dependsOn:
  - structure/BIT.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/BIT.test.cpp
  requiredBy: []
  timestamp: '2020-12-15 15:31:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BIT.test.cpp
layout: document
redirect_from:
- /verify/test/BIT.test.cpp
- /verify/test/BIT.test.cpp.html
title: test/BIT.test.cpp
---
