---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/CRT.cpp
    title: math/CRT.cpp
  - icon: ':heavy_check_mark:'
    path: math/Combination.cpp
    title: Combination (nCk)
  - icon: ':warning:'
    path: math/combination_big.cpp
    title: math/combination_big.cpp
  - icon: ':warning:'
    path: math/matrix.cpp
    title: math/matrix.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: mod int
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Combination.test.cpp
    title: test/Combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SegmentTree.test.cpp
    title: test/SegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,\
    \ int>\n#define pi acos(-1)\n#define len(s) (int)s.size()\n#define compress(v)\
    \ \\\n    sort(all(v));   \\\n    v.erase(unique(all(v)), v.end());\n#define comid(v,\
    \ x) lower_bound(all(v), x) - v.begin()\n\ntemplate<class T>\nusing prique=priority_queue<T,vector<T>,greater<>>;\n\
    \ntemplate <class T, class U>\ninline bool chmin(T &a, U b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b) {\n     \
    \   a = b;\n        return true;\n    }\n    return false;\n}\nconstexpr ll inf\
    \ = 3e18;\n#line 3 \"math/extgcd.cpp\"\n\nll extGCD(ll a, ll b, ll &x, ll &y)\
    \ {\n    if (!b) {\n        x = 1;\n        y = 0;\n        return a;\n    }\n\
    \    ll d = extGCD(b, a % b, y, x);\n    y -= a / b * x;\n    return d;\n}\n\n\
    ll modinv(ll a, ll m) {\n    ll x, y;\n    extGCD(a, m, x, y);\n    return (x\
    \ % m + m) % m;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nll extGCD(ll a, ll\
    \ b, ll &x, ll &y) {\n    if (!b) {\n        x = 1;\n        y = 0;\n        return\
    \ a;\n    }\n    ll d = extGCD(b, a % b, y, x);\n    y -= a / b * x;\n    return\
    \ d;\n}\n\nll modinv(ll a, ll m) {\n    ll x, y;\n    extGCD(a, m, x, y);\n  \
    \  return (x % m + m) % m;\n}"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy:
  - math/modint.cpp
  - math/combination_big.cpp
  - math/CRT.cpp
  - math/matrix.cpp
  - math/Combination.cpp
  timestamp: '2021-09-12 23:44:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SegmentTree.test.cpp
  - test/Combination.test.cpp
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: math/extgcd.cpp
---
