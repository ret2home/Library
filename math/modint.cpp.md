---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/Combination.cpp
    title: Combination (nCk)
  - icon: ':warning:'
    path: math/combination_big.cpp
    title: math/combination_big.cpp
  - icon: ':warning:'
    path: math/matrix.cpp
    title: math/matrix.cpp
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
    _deprecated_at_docs: docs/modint.md
    document_title: mod int
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
    \ % m + m) % m;\n}\n#line 4 \"math/modint.cpp\"\n\ntemplate <int MOD>\nstruct\
    \ mint {\n    int32_t n;\n    mint() : n(0) {}\n    mint(ll x) : n(x >= 0 ? x\
    \ % MOD : (MOD - (-x) % MOD) % MOD) {}\n\n    mint &operator+=(const mint &p)\
    \ {\n        if ((n += p.n) >= MOD) n -= MOD;\n        return *this;\n    }\n\
    \    mint &operator-=(const mint &p) {\n        if ((n += MOD - p.n) >= MOD) n\
    \ -= MOD;\n        return *this;\n    }\n    mint &operator*=(const mint &p) {\n\
    \        n = 1ll * n * p.n % MOD;\n        return *this;\n    }\n    mint &operator/=(const\
    \ mint &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n  \
    \  mint operator-() const { return mint(-n); }\n    mint operator+(const mint\
    \ &p) const { return mint(*this) += p; }\n    mint operator-(const mint &p) const\
    \ { return mint(*this) -= p; }\n    mint operator*(const mint &p) const { return\
    \ mint(*this) *= p; }\n    mint operator/(const mint &p) const { return mint(*this)\
    \ /= p; }\n    bool operator==(const mint &p) const { return n == p.n; }\n   \
    \ bool operator!=(const mint &p) const { return n != p.n; }\n\n    friend ostream\
    \ &operator<<(ostream &os, const mint &p) {\n        return os << p.n;\n    }\n\
    \    friend istream &operator>>(istream &is, mint &p) {\n        int x;\n    \
    \    is >> x;\n        p = mint(x);\n        return is;\n    }\n    mint pow(int64_t\
    \ x) const {\n        mint res(1), mul(n);\n        while (x > 0) {\n        \
    \    if (x & 1) res *= mul;\n            mul *= mul;\n            x >>= 1;\n \
    \       }\n        return res;\n    }\n    mint inverse() const {\n        return\
    \ mint(modinv(n,MOD));\n    }\n};\n/*\n@brief mod int\n@docs docs/modint.md\n\
    */\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"math/extgcd.cpp\"\
    \n\ntemplate <int MOD>\nstruct mint {\n    int32_t n;\n    mint() : n(0) {}\n\
    \    mint(ll x) : n(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD) {}\n\n    mint\
    \ &operator+=(const mint &p) {\n        if ((n += p.n) >= MOD) n -= MOD;\n   \
    \     return *this;\n    }\n    mint &operator-=(const mint &p) {\n        if\
    \ ((n += MOD - p.n) >= MOD) n -= MOD;\n        return *this;\n    }\n    mint\
    \ &operator*=(const mint &p) {\n        n = 1ll * n * p.n % MOD;\n        return\
    \ *this;\n    }\n    mint &operator/=(const mint &p) {\n        *this *= p.inverse();\n\
    \        return *this;\n    }\n    mint operator-() const { return mint(-n); }\n\
    \    mint operator+(const mint &p) const { return mint(*this) += p; }\n    mint\
    \ operator-(const mint &p) const { return mint(*this) -= p; }\n    mint operator*(const\
    \ mint &p) const { return mint(*this) *= p; }\n    mint operator/(const mint &p)\
    \ const { return mint(*this) /= p; }\n    bool operator==(const mint &p) const\
    \ { return n == p.n; }\n    bool operator!=(const mint &p) const { return n !=\
    \ p.n; }\n\n    friend ostream &operator<<(ostream &os, const mint &p) {\n   \
    \     return os << p.n;\n    }\n    friend istream &operator>>(istream &is, mint\
    \ &p) {\n        int x;\n        is >> x;\n        p = mint(x);\n        return\
    \ is;\n    }\n    mint pow(int64_t x) const {\n        mint res(1), mul(n);\n\
    \        while (x > 0) {\n            if (x & 1) res *= mul;\n            mul\
    \ *= mul;\n            x >>= 1;\n        }\n        return res;\n    }\n    mint\
    \ inverse() const {\n        return mint(modinv(n,MOD));\n    }\n};\n/*\n@brief\
    \ mod int\n@docs docs/modint.md\n*/"
  dependsOn:
  - template/template.cpp
  - math/extgcd.cpp
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy:
  - math/combination_big.cpp
  - math/matrix.cpp
  - math/Combination.cpp
  timestamp: '2021-09-12 23:44:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SegmentTree.test.cpp
  - test/Combination.test.cpp
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: mod int
---
## 概要

演算で全て mod を取る整数型。mod の除算などで何も考えないで済む。

- 四則演算 , 代入 ( +, -, \*, /, +=, -=, \*=, /=)
- ```pow(x)``` : ```x``` 乗
- ```inverse()``` : mod上の逆元

## 計算量

- 除算 : $O(log\ mod)$
- ```pow(x)``` : $O(log\ n)$
- ```inverse()``` : $O(log\ mod)$
- その他 : $O(1)$