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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <algorithm>\n#include\
    \ <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n#include\
    \ <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include <memory>\n\
    #include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n#include <array>\n#include <atomic>\n#include\
    \ <chrono>\n#include <codecvt>\n#include <condition_variable>\n#include <forward_list>\n\
    #include <future>\n#include <initializer_list>\n#include <mutex>\n#include <random>\n\
    #include <ratio>\n#include <regex>\n#include <scoped_allocator>\n#include <system_error>\n\
    #include <thread>\n#include <tuple>\n#include <typeindex>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\nusing namespace std;\n#define\
    \ ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n#define REP(i,\
    \ n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i = n - 1; i >= 0;\
    \ i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define all(v) v.begin(),\
    \ v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n#define len(s) (int)s.size()\n\
    #define compress(v) sort(all(v)); v.erase(unique(all(v)),v.end());\n#define comid(v,x)\
    \ lower_bound(all(v),x)-v.begin()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"math/extgcd.cpp\"\n\
    \nll extGCD(ll a, ll b, ll &x, ll &y) {\n    if (!b) {\n        x = 1;\n     \
    \   y = 0;\n        return a;\n    }\n    ll d = extGCD(b, a % b, y, x);\n   \
    \ y -= a / b * x;\n    return d;\n}\n\nll modinv(ll a, ll m) {\n    ll x, y;\n\
    \    extGCD(a, m, x, y);\n    return (x % m + m) % m;\n}\n#line 4 \"math/modint.cpp\"\
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
    \ mod int\n@docs docs/modint.md\n*/\n#line 4 \"math/matrix.cpp\"\n\ntemplate<int\
    \ MOD>\nstruct Matrix{\n    using modint=mint<MOD>;\n\tvector<vector<modint>>mat;\n\
    \tMatrix(int x,int y){\n\t\tmat.resize(x);\n\t\trep(i,x)mat[i].resize(y);\n\t\t\
    rep(i,x)rep(j,y)mat[i][j]=0;\n\t}\n\tMatrix operator*(Matrix a){\n\t\tassert(mat[0].size()==a.mat.size());\n\
    \t\tMatrix<MOD> res(mat.size(),a.mat[0].size());\n\t\trep(i,mat.size()){\n\t\t\
    \trep(j,a.mat[0].size()){\n\t\t\t\trep(k,a.mat.size()){\n\t\t\t\t\tres.mat[i][j]+=mat[i][k]*a.mat[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tMatrix pow(ll x){\n\t\tassert(mat.size()==mat[0].size());\n\
    \t\tMatrix<MOD> res(mat.size(),mat.size()),me(mat.size(),mat.size());\n\t\trep(i,mat.size())res.mat[i][i]=1;\n\
    \t\tme.mat=mat;\n\t\twhile(x>0){\n\t\t\tif(x&1)res=res*me;\n\t\t\tme=me*me;\n\t\
    \t\tx>>=1;\n\t\t}\n\t\treturn res;\n\t}\n    vector<modint>& operator[](int x){\n\
    \        return mat[x];\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"modint.cpp\"\
    \n\ntemplate<int MOD>\nstruct Matrix{\n    using modint=mint<MOD>;\n\tvector<vector<modint>>mat;\n\
    \tMatrix(int x,int y){\n\t\tmat.resize(x);\n\t\trep(i,x)mat[i].resize(y);\n\t\t\
    rep(i,x)rep(j,y)mat[i][j]=0;\n\t}\n\tMatrix operator*(Matrix a){\n\t\tassert(mat[0].size()==a.mat.size());\n\
    \t\tMatrix<MOD> res(mat.size(),a.mat[0].size());\n\t\trep(i,mat.size()){\n\t\t\
    \trep(j,a.mat[0].size()){\n\t\t\t\trep(k,a.mat.size()){\n\t\t\t\t\tres.mat[i][j]+=mat[i][k]*a.mat[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tMatrix pow(ll x){\n\t\tassert(mat.size()==mat[0].size());\n\
    \t\tMatrix<MOD> res(mat.size(),mat.size()),me(mat.size(),mat.size());\n\t\trep(i,mat.size())res.mat[i][i]=1;\n\
    \t\tme.mat=mat;\n\t\twhile(x>0){\n\t\t\tif(x&1)res=res*me;\n\t\t\tme=me*me;\n\t\
    \t\tx>>=1;\n\t\t}\n\t\treturn res;\n\t}\n    vector<modint>& operator[](int x){\n\
    \        return mat[x];\n    }\n};"
  dependsOn:
  - template/template.cpp
  - math/modint.cpp
  - math/extgcd.cpp
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:11:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: math/matrix.cpp
---
