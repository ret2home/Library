---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/LiChaoTree.cpp
    title: Li Chao Tree (Convex Hull Trick)
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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/LiChaoTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \n\n#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    #define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i =\
    \ n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define\
    \ all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n\ntemplate <class T, class U>\ninline bool chmin(T\
    \ &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T &a, U\
    \ b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/LiChaoTree.cpp\"\n\n\
    template <class T>\nstruct LiChaoTree {\n    struct L {\n        T a, b;\n   \
    \     L(T a, T b) : a(a), b(b) {}\n        bool operator==(L l) { return a ==\
    \ l.a && b == l.b; };\n    };\n    T f(L line, T x) {\n        return line.a *\
    \ x + line.b;\n    }\n    ll size = 1;\n    L ini = {0, inf};\n    vector<L> dat;\n\
    \    vector<T> X;\n    void add(ll a, ll b, L li, ll k = 0, ll l = 0, ll r = -1)\
    \ {\n        if (r == -1) r = size;\n        if (r <= a || b <= l) return;\n \
    \       ll m = (l + r) / 2;\n        if (!(a <= l && r <= b)) {\n            add(a,\
    \ b, li, 2 * k + 1, l, m);\n            add(a, b, li, 2 * k + 2, m, r);\n    \
    \        return;\n        }\n        if (dat[k] == ini) {\n            dat[k]\
    \ = li;\n            return;\n        }\n        ll lx = X[l], mx = X[m], rx =\
    \ X[r - 1];\n        bool left = f(li, lx) < f(dat[k], lx);\n        bool mid\
    \ = f(li, mx) < f(dat[k], mx);\n        bool right = f(li, rx) < f(dat[k], rx);\n\
    \n        if (left && right) {\n            dat[k] = li;\n            return;\n\
    \        }\n        if (!left && !right) return;\n        if (mid) swap(li, dat[k]);\n\
    \        if (left != mid) {\n            add(a, b, li, 2 * k + 1, l, m);\n   \
    \     } else {\n            add(a, b, li, 2 * k + 2, m, r);\n        }\n    }\n\
    \    T query(ll a, ll k = 0, ll l = 0, ll r = -1) {\n        if (r == -1) r =\
    \ size;\n        if (r - l == 1) return f(dat[k], X[a]);\n        if (a < (l +\
    \ r) / 2)\n            return min(query(a, k * 2 + 1, l, (l + r) / 2), f(dat[k],\
    \ X[a]));\n        else\n            return min(query(a, k * 2 + 2, (l + r) /\
    \ 2, r), f(dat[k], X[a]));\n    }\n    LiChaoTree(vector<T> v) : X(v) {\n    \
    \    ll N = len(v);\n        while (size < N) size *= 2;\n        dat.resize(size\
    \ * 2 - 1, ini);\n        X.resize(size * 2 - 1, 1e9);\n    }\n};\n/*\n@brief\
    \ Li Chao Tree (Convex Hull Trick)\n@docs docs/LiChaoTree.md\n*/\n#line 4 \"test/LiChaoTree.test.cpp\"\
    \n\nll N,Q;\nll L[200005],R[200005],x[200005],y[200005];\nll l[200005],r[200005],a[200005],b[200005];\n\
    vector<ll>v;\nsigned main(){\n\tcin>>N>>Q;\n\trep(i,N){\n\t\tcin>>L[i]>>R[i]>>x[i]>>y[i];\n\
    \t\tv.push_back(L[i]);v.push_back(R[i]);\n\t}\n\trep(i,Q){\n\t\tint type;cin>>type;\n\
    \t\tif(type==0){\n\t\t\tcin>>l[i]>>r[i]>>a[i]>>b[i];\n\t\t\tv.push_back(l[i]);v.push_back(r[i]);\n\
    \t\t}\n\t\telse {\n\t\t\tcin>>a[i];v.push_back(a[i]);b[i]=inf;\n\t\t}\n\t}\n\t\
    sort(all(v));v.erase(unique(all(v)),v.end());\n\tLiChaoTree<ll>LCT(v);\n\tauto\
    \ idx=[&](ll &x){\n\t\tx=lower_bound(all(v),x)-v.begin();\n\t};\n\trep(i,N){\n\
    \t\tidx(L[i]);idx(R[i]);\n\t\tLCT.add(L[i],R[i],{x[i],y[i]});\n\t}\n\trep(i,Q){\n\
    \t\tif(b[i]!=inf){\n\t\t\tidx(l[i]);idx(r[i]);\n\t\t\tLCT.add(l[i],r[i],{a[i],b[i]});\n\
    \t\t}\n\t\telse {\n\t\t\tidx(a[i]);\n\t\t\tll ans=LCT.query(a[i]);\n\t\t\tif(ans==inf)cout<<\"\
    INFINITY\"<<endl;\n\t\t\telse cout<<ans<<endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"../structure/LiChaoTree.cpp\"\n\nll N,Q;\nll L[200005],R[200005],x[200005],y[200005];\n\
    ll l[200005],r[200005],a[200005],b[200005];\nvector<ll>v;\nsigned main(){\n\t\
    cin>>N>>Q;\n\trep(i,N){\n\t\tcin>>L[i]>>R[i]>>x[i]>>y[i];\n\t\tv.push_back(L[i]);v.push_back(R[i]);\n\
    \t}\n\trep(i,Q){\n\t\tint type;cin>>type;\n\t\tif(type==0){\n\t\t\tcin>>l[i]>>r[i]>>a[i]>>b[i];\n\
    \t\t\tv.push_back(l[i]);v.push_back(r[i]);\n\t\t}\n\t\telse {\n\t\t\tcin>>a[i];v.push_back(a[i]);b[i]=inf;\n\
    \t\t}\n\t}\n\tsort(all(v));v.erase(unique(all(v)),v.end());\n\tLiChaoTree<ll>LCT(v);\n\
    \tauto idx=[&](ll &x){\n\t\tx=lower_bound(all(v),x)-v.begin();\n\t};\n\trep(i,N){\n\
    \t\tidx(L[i]);idx(R[i]);\n\t\tLCT.add(L[i],R[i],{x[i],y[i]});\n\t}\n\trep(i,Q){\n\
    \t\tif(b[i]!=inf){\n\t\t\tidx(l[i]);idx(r[i]);\n\t\t\tLCT.add(l[i],r[i],{a[i],b[i]});\n\
    \t\t}\n\t\telse {\n\t\t\tidx(a[i]);\n\t\t\tll ans=LCT.query(a[i]);\n\t\t\tif(ans==inf)cout<<\"\
    INFINITY\"<<endl;\n\t\t\telse cout<<ans<<endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - structure/LiChaoTree.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/LiChaoTree.test.cpp
  requiredBy: []
  timestamp: '2021-05-15 13:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LiChaoTree.test.cpp
layout: document
redirect_from:
- /verify/test/LiChaoTree.test.cpp
- /verify/test/LiChaoTree.test.cpp.html
title: test/LiChaoTree.test.cpp
---
