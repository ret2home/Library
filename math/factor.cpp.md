---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"math/factor.cpp\"\
    \n\nll pow128(ll x,ll y,ll m){\n\tll res=1;\n\twhile(y>0){\n\t\tif(y&1)res=(__int128_t(res)*x)%m;\n\
    \t\ty>>=1;x=(__int128_t(x)*x)%m;\n\t}\n\treturn res;\n}\n\nbool prime(ll n){\n\
    \tif(n<2||n%2==0)return n==2;\n\tll d=n-1;while(d%2==0)d>>=1;\n\tfor(ll x:{2,325,9375,28178,450775,9780504,1795265022}){\n\
    \t\tif(n<=x)break;\n\t\tll t=d,y=pow128(x,t,n);\n\t\twhile(t!=n-1&&y!=1&&y!=n-1){\n\
    \t\t\ty=(__int128_t(y)*y)%n;t<<=1;\n\t\t}\n\t\tif(y!=n-1&&t%2==0)return false;\n\
    \t}return true;\n}\nll rho(ll n){\n\tif(n%2==0)return 2;\n\tll MOD=n;\n\tauto\
    \ f=[&](ll x)->ll{return ((__int128_t)x*x+1)%MOD;};\n\tauto g=[](ll x,ll y)->ll{\n\
    \t\tif(x<y)return y-x;\n\t\treturn x-y;\n\t};\n\tfor(ll x1=0;;x1++){\n\t\tfor(ll\
    \ x=x1,y=f(x);;x=f(x),y=f(f(y))){\n\t\t\tll d=gcd(g(y,x),n);\n\t\t\tif(1<d&&d<n)return\
    \ d;\n\t\t\tif(d==n)break;\n\t\t}\n\t}\n}\nvector<ll>factor(ll n){\n\tif(n==1)return\
    \ {};\n\tif(prime(n))return {n};\n\tll d=rho(n);\n\tvector<ll>res=factor(d);\n\
    \tfor(ll i:factor(n/d))res.push_back(i);\n\treturn res;\n}\n/*\n@brief Fast Prime\
    \ Factorization\n@docs docs/factor.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nll pow128(ll x,ll\
    \ y,ll m){\n\tll res=1;\n\twhile(y>0){\n\t\tif(y&1)res=(__int128_t(res)*x)%m;\n\
    \t\ty>>=1;x=(__int128_t(x)*x)%m;\n\t}\n\treturn res;\n}\n\nbool prime(ll n){\n\
    \tif(n<2||n%2==0)return n==2;\n\tll d=n-1;while(d%2==0)d>>=1;\n\tfor(ll x:{2,325,9375,28178,450775,9780504,1795265022}){\n\
    \t\tif(n<=x)break;\n\t\tll t=d,y=pow128(x,t,n);\n\t\twhile(t!=n-1&&y!=1&&y!=n-1){\n\
    \t\t\ty=(__int128_t(y)*y)%n;t<<=1;\n\t\t}\n\t\tif(y!=n-1&&t%2==0)return false;\n\
    \t}return true;\n}\nll rho(ll n){\n\tif(n%2==0)return 2;\n\tll MOD=n;\n\tauto\
    \ f=[&](ll x)->ll{return ((__int128_t)x*x+1)%MOD;};\n\tauto g=[](ll x,ll y)->ll{\n\
    \t\tif(x<y)return y-x;\n\t\treturn x-y;\n\t};\n\tfor(ll x1=0;;x1++){\n\t\tfor(ll\
    \ x=x1,y=f(x);;x=f(x),y=f(f(y))){\n\t\t\tll d=gcd(g(y,x),n);\n\t\t\tif(1<d&&d<n)return\
    \ d;\n\t\t\tif(d==n)break;\n\t\t}\n\t}\n}\nvector<ll>factor(ll n){\n\tif(n==1)return\
    \ {};\n\tif(prime(n))return {n};\n\tll d=rho(n);\n\tvector<ll>res=factor(d);\n\
    \tfor(ll i:factor(n/d))res.push_back(i);\n\treturn res;\n}\n/*\n@brief Fast Prime\
    \ Factorization\n@docs docs/factor.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: math/factor.cpp
  requiredBy: []
  timestamp: '2020-10-25 14:09:40+09:00'
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