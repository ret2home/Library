---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Combination.cpp
    title: Combination (nCk)
  - icon: ':question:'
    path: math/modint.cpp
    title: mod int
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
  bundledCode: "#line 1 \"test/Combination.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n\n#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n#define REP(i,n)\
    \ for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n#define all(v)\
    \ v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n \ntemplate<class\
    \ T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return true;}\n\treturn\
    \ false;\n}\ntemplate<class T,class U> inline bool chmax(T &a, U b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"math/modint.cpp\"\
    \n\ntemplate<int MOD>\nstruct mint{\n\tint32_t n;\n\tmint():n(0){}\n\tmint(ll\
    \ x):n(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD){}\n\n\tmint &operator+=(const mint &p){\n\
    \t\tif((n+=p.n)>=MOD)n-=MOD;\n\t\treturn *this;\n\t}\n\tmint &operator-=(const\
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
    @brief mod int\n@docs docs/modint.md\n*/\n#line 3 \"math/Combination.cpp\"\n\n\
    template<int MOD>\nstruct Combination{\n\tusing modint=mint<MOD>;\n\tvector<modint>perm,inv;\n\
    \t\n \tCombination(int x=1e6){\n\t\tperm.resize(x);inv.resize(x);\n\t\tperm[0]=modint(1);\n\
    \t\tREP(i,x+1)perm[i]=perm[i-1]*i;\n\t\tinv[x]=perm[x].pow(MOD-2);\n\t\tfor(int\
    \ i=x-1;i>=0;i--){\n\t\t\tinv[i]=inv[i+1]*(i+1);\n\t\t}\n\t}\n\tmodint nCk(int\
    \ x,int y){\n\t\tif(x<y)return modint(0);\n\t\treturn perm[x]*inv[x-y]*inv[y];\n\
    \t}\n};\n/*\n@brief Combination (nCk)\n@docs docs/Combination.md\n*/\n#line 4\
    \ \"test/Combination.test.cpp\"\n\nint main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \tconst int mod=1e9+7;\n\tCombination<mod>C;\n\tint n,k;cin>>n>>k;\n\tcout<<C.nCk(k,n)<<\"\
    \\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n\n#include \"math/Combination.cpp\"\n\nint main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \tconst int mod=1e9+7;\n\tCombination<mod>C;\n\tint n,k;cin>>n>>k;\n\tcout<<C.nCk(k,n)<<\"\
    \\n\";\n}"
  dependsOn:
  - math/Combination.cpp
  - math/modint.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/Combination.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Combination.test.cpp
layout: document
redirect_from:
- /verify/test/Combination.test.cpp
- /verify/test/Combination.test.cpp.html
title: test/Combination.test.cpp
---
