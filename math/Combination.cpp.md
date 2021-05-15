---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: mod int
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Combination.test.cpp
    title: test/Combination.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Combination.md
    document_title: Combination (nCk)
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n\ntemplate <class T, class U>\ninline bool chmin(T\
    \ &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T &a, U\
    \ b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"math/extgcd.cpp\"\n\nll extGCD(ll\
    \ a, ll b, ll &x, ll &y) {\n    if (!b) {\n        x = 1;\n        y = 0;\n  \
    \      return a;\n    }\n    ll d = extGCD(b, a % b, y, x);\n    y -= a / b *\
    \ x;\n    return d;\n}\n\nll modinv(ll a, ll m) {\n    ll x, y;\n    extGCD(a,\
    \ m, x, y);\n    return (x % m + m) % m;\n}\n#line 4 \"math/modint.cpp\"\n\ntemplate\
    \ <int MOD>\nstruct mint {\n    int32_t n;\n    mint() : n(0) {}\n    mint(ll\
    \ x) : n(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD) {}\n\n    mint &operator+=(const\
    \ mint &p) {\n        if ((n += p.n) >= MOD) n -= MOD;\n        return *this;\n\
    \    }\n    mint &operator-=(const mint &p) {\n        if ((n += MOD - p.n) >=\
    \ MOD) n -= MOD;\n        return *this;\n    }\n    mint &operator*=(const mint\
    \ &p) {\n        n = 1ll * n * p.n % MOD;\n        return *this;\n    }\n    mint\
    \ &operator/=(const mint &p) {\n        *this *= p.inverse();\n        return\
    \ *this;\n    }\n    mint operator-() const { return mint(-n); }\n    mint operator+(const\
    \ mint &p) const { return mint(*this) += p; }\n    mint operator-(const mint &p)\
    \ const { return mint(*this) -= p; }\n    mint operator*(const mint &p) const\
    \ { return mint(*this) *= p; }\n    mint operator/(const mint &p) const { return\
    \ mint(*this) /= p; }\n    bool operator==(const mint &p) const { return n ==\
    \ p.n; }\n    bool operator!=(const mint &p) const { return n != p.n; }\n\n  \
    \  friend ostream &operator<<(ostream &os, const mint &p) {\n        return os\
    \ << p.n;\n    }\n    friend istream &operator>>(istream &is, mint &p) {\n   \
    \     int x;\n        is >> x;\n        p = mint(x);\n        return is;\n   \
    \ }\n    mint pow(int64_t x) const {\n        mint res(1), mul(n);\n        while\
    \ (x > 0) {\n            if (x & 1) res *= mul;\n            mul *= mul;\n   \
    \         x >>= 1;\n        }\n        return res;\n    }\n    mint inverse()\
    \ const {\n        return mint(modinv(n,MOD));\n    }\n};\n/*\n@brief mod int\n\
    @docs docs/modint.md\n*/\n#line 3 \"math/Combination.cpp\"\n\ntemplate <int MOD>\n\
    struct Combination {\n    using modint = mint<MOD>;\n    vector<modint> perm,\
    \ inv;\n\n    Combination(int x = 1e6) {\n        perm.resize(x);\n        inv.resize(x);\n\
    \        perm[0] = modint(1);\n        REP(i, x + 1)\n        perm[i] = perm[i\
    \ - 1] * i;\n        inv[x] = perm[x].pow(MOD - 2);\n        for (int i = x -\
    \ 1; i >= 0; i--) {\n            inv[i] = inv[i + 1] * (i + 1);\n        }\n \
    \   }\n    modint nCk(int x, int y) {\n        if (x < y) return modint(0);\n\
    \        return perm[x] * inv[x - y] * inv[y];\n    }\n};\n/*\n@brief Combination\
    \ (nCk)\n@docs docs/Combination.md\n*/\n"
  code: "#pragma once\n#include \"modint.cpp\"\n\ntemplate <int MOD>\nstruct Combination\
    \ {\n    using modint = mint<MOD>;\n    vector<modint> perm, inv;\n\n    Combination(int\
    \ x = 1e6) {\n        perm.resize(x);\n        inv.resize(x);\n        perm[0]\
    \ = modint(1);\n        REP(i, x + 1)\n        perm[i] = perm[i - 1] * i;\n  \
    \      inv[x] = perm[x].pow(MOD - 2);\n        for (int i = x - 1; i >= 0; i--)\
    \ {\n            inv[i] = inv[i + 1] * (i + 1);\n        }\n    }\n    modint\
    \ nCk(int x, int y) {\n        if (x < y) return modint(0);\n        return perm[x]\
    \ * inv[x - y] * inv[y];\n    }\n};\n/*\n@brief Combination (nCk)\n@docs docs/Combination.md\n\
    */"
  dependsOn:
  - math/modint.cpp
  - template/template.cpp
  - math/extgcd.cpp
  isVerificationFile: false
  path: math/Combination.cpp
  requiredBy: []
  timestamp: '2021-05-15 13:43:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Combination.test.cpp
documentation_of: math/Combination.cpp
layout: document
redirect_from:
- /library/math/Combination.cpp
- /library/math/Combination.cpp.html
title: Combination (nCk)
---
## 概要

二項係数 $nCk$ を求める。ただし、$n \leq 10^7$ 程度が限度（前計算をするため）。

- ```nCk(x,y)``` : $xCy$ を返す

## 計算量

- 前計算(コンストラクタがやる) : $O(N)$
- クエリ : $O(1)$