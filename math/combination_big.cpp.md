---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: mod int
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return\
    \ true;}\n\treturn false;\n}\ntemplate<class T,class U> inline bool chmax(T &a,\
    \ U b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n\
    #line 3 \"math/modint.cpp\"\n\ntemplate<int MOD>\nstruct mint{\n\tint32_t n;\n\
    \tmint():n(0){}\n\tmint(ll x):n(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD){}\n\n\tmint &operator+=(const\
    \ mint &p){\n\t\tif((n+=p.n)>=MOD)n-=MOD;\n\t\treturn *this;\n\t}\n\tmint &operator-=(const\
    \ mint &p){\n\t\tif((n+=MOD-p.n)>=MOD)n-=MOD;\n\t\treturn *this;\n\t}\n\tmint\
    \ &operator*=(const mint &p){\n\t\tn=1ll*n*p.n%MOD;\n\t\treturn *this;\n\t}\n\t\
    mint &operator/=(const mint &p){\n\t\t*this*=p.inverse();\n\t\treturn *this;\n\
    \t}\n\tmint operator-()const{return mint(-n);}\n\tmint operator+(const mint &p)const{return\
    \ mint(*this)+=p;}\n\tmint operator-(const mint &p)const{return mint(*this)-=p;}\n\
    \tmint operator*(const mint &p)const{return mint(*this)*=p;}\n\tmint operator/(const\
    \ mint &p)const{return mint(*this)/=p;}\n\tbool operator==(const mint &p)const{return\
    \ n==p.n;}\n\tbool operator!=(const mint &p)const{return n!=p.n;}\n\n\tfriend\
    \ ostream &operator<<(ostream &os,const mint &p){\n\t\treturn os<<p.n;\n\t}\n\t\
    friend istream &operator>>(istream &is,mint &p){\n\t\tint x;is>>x;\n\t\tp=mint(x);\n\
    \t\treturn is;\n\t}\n\tmint pow(int64_t x)const{\n\t\tmint res(1),mul(n);\n\t\t\
    while(x>0){\n\t\t\tif(x&1)res*=mul;\n\t\t\tmul*=mul;\n\t\t\tx>>=1;\n\t\t}\n\t\t\
    return res;\n\t}\n\tmint inverse()const{\n\t\treturn pow(MOD-2);\n\t}\n};\n/*\n\
    @brief mod int\n@docs docs/modint.md\n*/\n#line 3 \"math/combination_big.cpp\"\
    \n\ntemplate<int MOD>\nstruct BigCombination{\n\tusing modint=mint<MOD>;\n\tmodint\
    \ perm(ll x,ll y){\n\t\tmodint res=1;\n\t\tfor(ll i=x-y+1;i<=x;i++)res*=i;\n\t\
    \treturn res;\n\t}\n\tmodint comb(ll x,ll y){\n\t\tif(y>x)return 0;\n\t\treturn\
    \ perm(x,y)*perm(y,y).pow(MOD-2);\n\t}\n};\n"
  code: "#pragma once\n#include \"modint.cpp\"\n\ntemplate<int MOD>\nstruct BigCombination{\n\
    \tusing modint=mint<MOD>;\n\tmodint perm(ll x,ll y){\n\t\tmodint res=1;\n\t\t\
    for(ll i=x-y+1;i<=x;i++)res*=i;\n\t\treturn res;\n\t}\n\tmodint comb(ll x,ll y){\n\
    \t\tif(y>x)return 0;\n\t\treturn perm(x,y)*perm(y,y).pow(MOD-2);\n\t}\n};\n"
  dependsOn:
  - math/modint.cpp
  - template/template.cpp
  isVerificationFile: false
  path: math/combination_big.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination_big.cpp
layout: document
redirect_from:
- /library/math/combination_big.cpp
- /library/math/combination_big.cpp.html
title: math/combination_big.cpp
---
