---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/BIT.cpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/BIT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma GCC optimization\
    \ (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\nusing namespace std;\n\
    #define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n#define REP(i,n) for(ll\
    \ i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n#define all(v) v.begin(),v.end()\n\
    #define P pair<ll,ll>\n#define len(s) (ll)s.size()\n \ntemplate<class T> inline\
    \ bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\treturn false;\n}\ntemplate<class\
    \ T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n\
    }\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BIT.cpp\"\n\ntemplate<class T>\n\
    class BIT{\n\tll N;\n\tvector<T>bit;\n\tvoid add_(ll x,T y){\n\t\twhile(x<=N){\n\
    \t\t\tbit[x]+=y;x+=x&-x;\n\t\t}\n\t}\n\tT sum_(ll x){\n\t\tT res=0;\n\t\twhile(x>0){\n\
    \t\t\tres+=bit[x];x-=x&-x;\n\t\t}\n\t\treturn res;\n\t}\npublic:\n\tll lower_bound(T\
    \ w){\n\t\tif(w<=0)return -1;\n\t\tll x=0;\n\t\tll k=1;while(k*2<=N)k*=2;\n\t\t\
    for(;k>0;k/=2){\n\t\t\tif(x+k<=N&&bit[x+k]<w){\n\t\t\t\tw-=bit[x+k];\n\t\t\t\t\
    x+=k;\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\tvoid add(ll x,T y){add_(x+1,y);}\n\
    \tT sum(ll l,ll r){return sum_(r)-sum_(l);}\n\tBIT(ll x):N(x),bit(x+1){}\n};\n\
    /*\n@brief Binary Indexed Tree\n@docs docs/BIT.md\n*/\n#line 3 \"test/BIT.test.cpp\"\
    \n\nint main(){\n    int N,Q;\n    cin>>N>>Q;\n    BIT<ll>bit(N);\n    rep(i,N){\n\
    \        int a;cin>>a;\n        bit.add(i,a);\n    }\n    while(Q--){\n      \
    \  int t;cin>>t;\n        if(!t){\n            int p,x;cin>>p>>x;\n          \
    \  bit.add(p,x);\n        }else {\n            int l,r;cin>>l>>r;\n          \
    \  cout<<bit.sum(l,r)<<\"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../structure/BIT.cpp\"\n\nint main(){\n    int N,Q;\n    cin>>N>>Q;\n\
    \    BIT<ll>bit(N);\n    rep(i,N){\n        int a;cin>>a;\n        bit.add(i,a);\n\
    \    }\n    while(Q--){\n        int t;cin>>t;\n        if(!t){\n            int\
    \ p,x;cin>>p>>x;\n            bit.add(p,x);\n        }else {\n            int\
    \ l,r;cin>>l>>r;\n            cout<<bit.sum(l,r)<<\"\\n\";\n        }\n    }\n\
    }"
  dependsOn:
  - structure/BIT.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/BIT.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BIT.test.cpp
layout: document
redirect_from:
- /verify/test/BIT.test.cpp
- /verify/test/BIT.test.cpp.html
title: test/BIT.test.cpp
---
