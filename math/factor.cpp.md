---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/factor.test.cpp
    title: test/factor.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/factor.md
    document_title: Fast Prime Factorization
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define all(v) v.begin(), v.end()\n#define P pair<ll,\
    \ ll>\n#define len(s) (ll) s.size()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"math/factor.cpp\"\n\
    \nll pow128(ll x, ll y, ll m) {\n    ll res = 1;\n    while (y > 0) {\n      \
    \  if (y & 1) res = (__int128_t(res) * x) % m;\n        y >>= 1;\n        x =\
    \ (__int128_t(x) * x) % m;\n    }\n    return res;\n}\n\nbool prime(ll n) {\n\
    \    if (n < 2 || n % 2 == 0) return n == 2;\n    ll d = n - 1;\n    while (d\
    \ % 2 == 0) d >>= 1;\n    for (ll x : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n        if (n <= x) break;\n        ll t = d, y = pow128(x, t, n);\n    \
    \    while (t != n - 1 && y != 1 && y != n - 1) {\n            y = (__int128_t(y)\
    \ * y) % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t % 2\
    \ == 0) return false;\n    }\n    return true;\n}\nll rho(ll n) {\n    if (n %\
    \ 2 == 0) return 2;\n    ll MOD = n;\n    auto f = [&](ll x) -> ll { return ((__int128_t)x\
    \ * x + 1) % MOD; };\n    auto g = [](ll x, ll y) -> ll {\n        if (x < y)\
    \ return y - x;\n        return x - y;\n    };\n    for (ll x1 = 0;; x1++) {\n\
    \        for (ll x = x1, y = f(x);; x = f(x), y = f(f(y))) {\n            ll d\
    \ = gcd(g(y, x), n);\n            if (1 < d && d < n) return d;\n            if\
    \ (d == n) break;\n        }\n    }\n}\nvector<ll> factor(ll n) {\n    if (n ==\
    \ 1) return {};\n    if (prime(n)) return {n};\n    ll d = rho(n);\n    vector<ll>\
    \ res = factor(d);\n    for (ll i : factor(n / d)) res.push_back(i);\n    return\
    \ res;\n}\n/*\n@brief Fast Prime Factorization\n@docs docs/factor.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nll pow128(ll x, ll\
    \ y, ll m) {\n    ll res = 1;\n    while (y > 0) {\n        if (y & 1) res = (__int128_t(res)\
    \ * x) % m;\n        y >>= 1;\n        x = (__int128_t(x) * x) % m;\n    }\n \
    \   return res;\n}\n\nbool prime(ll n) {\n    if (n < 2 || n % 2 == 0) return\
    \ n == 2;\n    ll d = n - 1;\n    while (d % 2 == 0) d >>= 1;\n    for (ll x :\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n        if (n <= x) break;\n\
    \        ll t = d, y = pow128(x, t, n);\n        while (t != n - 1 && y != 1 &&\
    \ y != n - 1) {\n            y = (__int128_t(y) * y) % n;\n            t <<= 1;\n\
    \        }\n        if (y != n - 1 && t % 2 == 0) return false;\n    }\n    return\
    \ true;\n}\nll rho(ll n) {\n    if (n % 2 == 0) return 2;\n    ll MOD = n;\n \
    \   auto f = [&](ll x) -> ll { return ((__int128_t)x * x + 1) % MOD; };\n    auto\
    \ g = [](ll x, ll y) -> ll {\n        if (x < y) return y - x;\n        return\
    \ x - y;\n    };\n    for (ll x1 = 0;; x1++) {\n        for (ll x = x1, y = f(x);;\
    \ x = f(x), y = f(f(y))) {\n            ll d = gcd(g(y, x), n);\n            if\
    \ (1 < d && d < n) return d;\n            if (d == n) break;\n        }\n    }\n\
    }\nvector<ll> factor(ll n) {\n    if (n == 1) return {};\n    if (prime(n)) return\
    \ {n};\n    ll d = rho(n);\n    vector<ll> res = factor(d);\n    for (ll i : factor(n\
    \ / d)) res.push_back(i);\n    return res;\n}\n/*\n@brief Fast Prime Factorization\n\
    @docs docs/factor.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: math/factor.cpp
  requiredBy: []
  timestamp: '2020-12-20 09:59:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/factor.test.cpp
documentation_of: math/factor.cpp
layout: document
redirect_from:
- /library/math/factor.cpp
- /library/math/factor.cpp.html
title: Fast Prime Factorization
---
## 概要

ミラーラビン素数判定法と、ロー法による高速な素因数分解

- ```prime(n)``` : ```n``` が素数かどうか
- ```factor(n)``` : ```n``` の素因数分解の結果 (**再帰の関係でソートはしていない**)

## 計算量

詳しくは知らないけど、$10^{18}$ の素因数分解 $1000$ 個くらいは余裕ってレベル