---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (ll i = 0; i < n;\
    \ i++)\n#define REP(i, n) for (ll i = 1; i < n; i++)\n#define rev(i, n) for (ll\
    \ i = n - 1; i >= 0; i--)\n#define all(v) v.begin(), v.end()\n#define P pair<ll,\
    \ ll>\n#define len(s) (ll) s.size()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"math/extgcd.cpp\"\n\
    \nll extGCD(ll a, ll b, ll &x, ll &y) {\n    if (!b) {\n        x = 1;\n     \
    \   y = 0;\n        return a;\n    }\n    ll d = extGCD(b, a % b, y, x);\n   \
    \ y -= a / b * x;\n    return d;\n}\n#line 4 \"math/CRT.cpp\"\n\nP CRT(vector<ll>\
    \ b, vector<ll> m) {\n    ll r = 0, M = 1;\n    rep(i, len(b)) {\n        ll p,\
    \ q;\n        ll d = extGCD(M, m[i], p, q);\n        if ((b[i] - r) % d) return\
    \ P(0, -1);\n        ll tmp = (b[i] - r) / d * p % (m[i] / d);\n        r += M\
    \ * tmp;\n        M *= m[i] / d;\n    }\n    return P((r % M + M) % M, M);\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"extgcd.cpp\"\
    \n\nP CRT(vector<ll> b, vector<ll> m) {\n    ll r = 0, M = 1;\n    rep(i, len(b))\
    \ {\n        ll p, q;\n        ll d = extGCD(M, m[i], p, q);\n        if ((b[i]\
    \ - r) % d) return P(0, -1);\n        ll tmp = (b[i] - r) / d * p % (m[i] / d);\n\
    \        r += M * tmp;\n        M *= m[i] / d;\n    }\n    return P((r % M + M)\
    \ % M, M);\n}"
  dependsOn:
  - template/template.cpp
  - math/extgcd.cpp
  isVerificationFile: false
  path: math/CRT.cpp
  requiredBy: []
  timestamp: '2020-12-15 15:31:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/CRT.cpp
layout: document
redirect_from:
- /library/math/CRT.cpp
- /library/math/CRT.cpp.html
title: math/CRT.cpp
---
