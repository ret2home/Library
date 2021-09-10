---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.cpp
    title: Rolling Hash (mod 2^61-1)
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"test/RollingHash.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\
    \n\n#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    #define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i =\
    \ n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define\
    \ all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n#define compress(v) sort(all(v)); v.erase(unique(all(v)),v.end());\n\
    #define comid(v,x) lower_bound(all(v),x)-v.begin()\n\ntemplate <class T, class\
    \ U>\ninline bool chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n     \
    \   return true;\n    }\n    return false;\n}\ntemplate <class T, class U>\ninline\
    \ bool chmax(T &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"string/RollingHash.cpp\"\
    \n\ntemplate <class T>\nstruct RollingHash {\n    ll Base = 283;\n    const ll\
    \ MASK30 = (1ll << 30) - 1;\n    const ll MASK31 = (1ll << 31) - 1;\n    const\
    \ ll MOD = (1ll << 61) - 1;\n    vector<ll> hash, power;\n    ll calcmod(ll v)\
    \ {\n        v = (v & MOD) + (v >> 61);\n        if (v > MOD) v -= MOD;\n    \
    \    return v;\n    }\n    ll mul(ll x, ll y) {\n        ll xu = x >> 31, xd =\
    \ x & MASK31;\n        ll yu = y >> 31, yd = y & MASK31;\n        ll mid = xd\
    \ * yu + xu * yd, midu = mid >> 30, midd = mid & MASK30;\n        return calcmod(xu\
    \ * yu * 2 + midu + (midd << 31) + xd * yd);\n    }\n    RollingHash(T s) {\n\
    \        ll sz = s.size();\n        hash.resize(sz + 1, 0);\n        power.resize(sz\
    \ + 1, 1);\n        rep(i, sz) {\n            hash[i + 1] = calcmod(mul(hash[i],\
    \ Base) + s[i]);\n            power[i + 1] = calcmod(mul(power[i], Base));\n \
    \       }\n    }\n    ll get(ll l, ll r) {\n        return calcmod(hash[r] - mul(hash[l],\
    \ power[r - l]) + MOD);\n    }\n    ll lcp(ll x, ll y) {\n        ll len = min(hash.size()\
    \ - 1 - y, hash.size() - 1 - x);\n        ll ok = 0, ng = len + 1;\n        while\
    \ (ng - ok > 1) {\n            ll mid = (ok + ng) / 2;\n            if (get(x,\
    \ x + mid) == get(y, y + mid))\n                ok = mid;\n            else\n\
    \                ng = mid;\n        }\n        return ok;\n    }\n};\n/*\n@brief\
    \ Rolling Hash (mod 2^61-1)\n@docs docs/RollingHash.md\n*/\n#line 4 \"test/RollingHash.test.cpp\"\
    \n\nint main(){\n    string S,T;\n    cin>>S>>T;\n    RollingHash<string>RH1(S),RH2(T);\n\
    \    rep(i,len(S)-len(T)+1){\n        if(RH1.get(i,i+len(T))==RH2.hash[len(T)])cout<<i<<\"\
    \\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    \n#include \"../string/RollingHash.cpp\"\n\nint main(){\n    string S,T;\n   \
    \ cin>>S>>T;\n    RollingHash<string>RH1(S),RH2(T);\n    rep(i,len(S)-len(T)+1){\n\
    \        if(RH1.get(i,i+len(T))==RH2.hash[len(T)])cout<<i<<\"\\n\";\n    }\n}"
  dependsOn:
  - string/RollingHash.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/RollingHash.test.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:00:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RollingHash.test.cpp
layout: document
redirect_from:
- /verify/test/RollingHash.test.cpp
- /verify/test/RollingHash.test.cpp.html
title: test/RollingHash.test.cpp
---
