---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \ false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"math/FFT.cpp\"\n\nvoid dft(vector<complex<double>>&\
    \ func, ll inv) {\n    ll sz = func.size();\n    if (sz == 1) return;\n    vector<complex<double>>\
    \ va, vb;\n    rep(i, sz / 2) {\n        va.push_back(func[2 * i]);\n        vb.push_back(func[2\
    \ * i + 1]);\n    }\n    dft(va, inv);\n    dft(vb, inv);\n    complex<double>\
    \ now = 1, zeta = polar(1.0, inv * 2.0 * acos(-1) / sz);\n    rep(i, sz) {\n \
    \       func[i] = va[i % (sz / 2)] + now * vb[i % (sz / 2)];\n        now *= zeta;\n\
    \    }\n}\ntemplate <class T>\nvector<double> fft(vector<T> f, vector<T> g) {\n\
    \    vector<complex<double>> nf, ng;\n    ll sz = 1;\n    while (sz < len(f) +\
    \ len(g)) sz *= 2;\n    nf.resize(sz);\n    ng.resize(sz);\n    rep(i, len(f))\
    \ {\n        nf[i] = f[i];\n    }\n    rep(i, len(g)) {\n        ng[i] = g[i];\n\
    \    }\n    dft(nf, 1);\n    dft(ng, 1);\n    rep(i, sz) nf[i] *= ng[i];\n   \
    \ dft(nf, -1);\n    vector<double> res;\n    rep(i, sz) res.push_back(nf[i].real()\
    \ / sz);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nvoid dft(vector<complex<double>>&\
    \ func, ll inv) {\n    ll sz = func.size();\n    if (sz == 1) return;\n    vector<complex<double>>\
    \ va, vb;\n    rep(i, sz / 2) {\n        va.push_back(func[2 * i]);\n        vb.push_back(func[2\
    \ * i + 1]);\n    }\n    dft(va, inv);\n    dft(vb, inv);\n    complex<double>\
    \ now = 1, zeta = polar(1.0, inv * 2.0 * acos(-1) / sz);\n    rep(i, sz) {\n \
    \       func[i] = va[i % (sz / 2)] + now * vb[i % (sz / 2)];\n        now *= zeta;\n\
    \    }\n}\ntemplate <class T>\nvector<double> fft(vector<T> f, vector<T> g) {\n\
    \    vector<complex<double>> nf, ng;\n    ll sz = 1;\n    while (sz < len(f) +\
    \ len(g)) sz *= 2;\n    nf.resize(sz);\n    ng.resize(sz);\n    rep(i, len(f))\
    \ {\n        nf[i] = f[i];\n    }\n    rep(i, len(g)) {\n        ng[i] = g[i];\n\
    \    }\n    dft(nf, 1);\n    dft(ng, 1);\n    rep(i, sz) nf[i] *= ng[i];\n   \
    \ dft(nf, -1);\n    vector<double> res;\n    rep(i, sz) res.push_back(nf[i].real()\
    \ / sz);\n    return res;\n}\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: math/FFT.cpp
  requiredBy: []
  timestamp: '2021-05-15 13:43:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT.cpp
layout: document
redirect_from:
- /library/math/FFT.cpp
- /library/math/FFT.cpp.html
title: math/FFT.cpp
---
