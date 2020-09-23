---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"string/RollingHash.cpp\"\
    \n\ntemplate<class T>\nstruct RollingHash{\n\tll Base=283;\n\tconst ll MASK30=(1ll<<30)-1;\n\
    \tconst ll MASK31=(1ll<<31)-1;\n\tconst ll MOD=(1ll<<61)-1;\n\tvector<ll>hash,power;\n\
    \tll calcmod(ll v){\n\t\tv=(v&MOD)+(v>>61);\n\t\tif(v>MOD)v-=MOD;\n\t\treturn\
    \ v;\n\t}\n\tll mul(ll x,ll y){\n\t\tll xu=x>>31,xd=x&MASK31;\n\t\tll yu=y>>31,yd=y&MASK31;\n\
    \t\tll mid=xd*yu+xu*yd,midu=mid>>30,midd=mid&MASK30;\n\t\treturn calcmod(xu*yu*2+midu+(midd<<31)+xd*yd);\n\
    \t}\n\tRollingHash(T s){\n\t\tll sz=s.size();\n\t\thash.resize(sz+1,0);power.resize(sz+1,1);\n\
    \t\trep(i,sz){\n\t\t\thash[i+1]=calcmod(mul(hash[i],Base)+s[i]);\n\t\t\tpower[i+1]=calcmod(mul(power[i],Base));\n\
    \t\t}\n\t}\n\tll get(ll l,ll r){\n\t\treturn calcmod(hash[r]-mul(hash[l],power[r-l])+MOD);\n\
    \t}\n\tll lcp(ll x,ll y){\n\t\tll len=min(hash.size()-1-y,hash.size()-1-x);\n\t\
    \tll ok=0,ng=len+1;\n\t\twhile(ng-ok>1){\n\t\t\tll mid=(ok+ng)/2;\n\t\t\tif(get(x,x+mid)==get(y,y+mid))ok=mid;\n\
    \t\t\telse ng=mid;\n\t\t}\n\t\treturn ok;\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    struct RollingHash{\n\tll Base=283;\n\tconst ll MASK30=(1ll<<30)-1;\n\tconst ll\
    \ MASK31=(1ll<<31)-1;\n\tconst ll MOD=(1ll<<61)-1;\n\tvector<ll>hash,power;\n\t\
    ll calcmod(ll v){\n\t\tv=(v&MOD)+(v>>61);\n\t\tif(v>MOD)v-=MOD;\n\t\treturn v;\n\
    \t}\n\tll mul(ll x,ll y){\n\t\tll xu=x>>31,xd=x&MASK31;\n\t\tll yu=y>>31,yd=y&MASK31;\n\
    \t\tll mid=xd*yu+xu*yd,midu=mid>>30,midd=mid&MASK30;\n\t\treturn calcmod(xu*yu*2+midu+(midd<<31)+xd*yd);\n\
    \t}\n\tRollingHash(T s){\n\t\tll sz=s.size();\n\t\thash.resize(sz+1,0);power.resize(sz+1,1);\n\
    \t\trep(i,sz){\n\t\t\thash[i+1]=calcmod(mul(hash[i],Base)+s[i]);\n\t\t\tpower[i+1]=calcmod(mul(power[i],Base));\n\
    \t\t}\n\t}\n\tll get(ll l,ll r){\n\t\treturn calcmod(hash[r]-mul(hash[l],power[r-l])+MOD);\n\
    \t}\n\tll lcp(ll x,ll y){\n\t\tll len=min(hash.size()-1-y,hash.size()-1-x);\n\t\
    \tll ok=0,ng=len+1;\n\t\twhile(ng-ok>1){\n\t\t\tll mid=(ok+ng)/2;\n\t\t\tif(get(x,x+mid)==get(y,y+mid))ok=mid;\n\
    \t\t\telse ng=mid;\n\t\t}\n\t\treturn ok;\n\t}\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: string/RollingHash.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/RollingHash.cpp
layout: document
redirect_from:
- /library/string/RollingHash.cpp
- /library/string/RollingHash.cpp.html
title: string/RollingHash.cpp
---
