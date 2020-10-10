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
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SegmentTreeBeats.cpp\"\
    \n\nstruct SegtreeBeats{\n\tvector<ll>mx,smx,mxc;\n\tvector<ll>mn,smn,mnc;\n\t\
    vector<ll>sum,lazy;\n\tll size=1;\n\tvoid update_node_max(ll k,ll x){\n\t\tsum[k]+=(x-mx[k])*mxc[k];\n\
    \t\tif(mx[k]==mn[k]){\n\t\t\tmx[k]=mn[k]=x;\n\t\t}else if(mx[k]==smn[k]){\n\t\t\
    \tmx[k]=smn[k]=x;\n\t\t}else {\n\t\t\tmx[k]=x;\n\t\t}\n\t}\n\tvoid update_node_min(ll\
    \ k,ll x){\n\t\tsum[k]+=(x-mn[k])*mnc[k];\n\t\tif(mx[k]==mn[k]){\n\t\t\tmx[k]=mn[k]=x;\n\
    \t\t}else if(smx[k]==mn[k]){\n\t\t\tsmx[k]=mn[k]=x;\n\t\t}else {\n\t\t\tmn[k]=x;\n\
    \t\t}\n\t}\n\tvoid update_node_add(ll k,ll len,ll x){\n\t\tmx[k]+=x;\n\t\tif(smx[k]!=-inf)smx[k]+=x;\n\
    \t\tmn[k]+=x;\n\t\tif(smn[k]!=inf)smn[k]+=x;\n\t\tsum[k]+=x*len;\n\t\tlazy[k]+=x;\n\
    \t}\n\tvoid push(ll k,ll len){\n\t\tif(k>=size-1)return;\n\t\tif(lazy[k]!=0){\n\
    \t\t\tupdate_node_add(k*2+1,len/2,lazy[k]);\n\t\t\tupdate_node_add(k*2+2,len/2,lazy[k]);\n\
    \t\t\tlazy[k]=0;\n\t\t}\n\t\tif(mx[k*2+1]>mx[k])update_node_max(k*2+1,mx[k]);\n\
    \t\tif(mx[k*2+2]>mx[k])update_node_max(k*2+2,mx[k]);\n\t\tif(mn[k*2+1]<mn[k])update_node_min(k*2+1,mn[k]);\n\
    \t\tif(mn[k*2+2]<mn[k])update_node_min(k*2+2,mn[k]);\n\t}\n\tvoid update(ll k){\n\
    \t\tsum[k]=sum[k*2+1]+sum[k*2+2];\n\t\tif(mx[2*k+1]<mx[2*k+2]){\n\t\t\tmx[k]=mx[2*k+2];\n\
    \t\t\tmxc[k]=mxc[2*k+2];\n\t\t\tsmx[k]=max(mx[2*k+1],smx[2*k+2]);\n\t\t}else if(mx[2*k+1]>mx[2*k+2]){\n\
    \t\t\tmx[k]=mx[2*k+1];\n\t\t\tmxc[k]=mxc[2*k+1];\n\t\t\tsmx[k]=max(smx[2*k+1],mx[2*k+2]);\n\
    \t\t}else {\n\t\t\tmx[k]=mx[2*k+1];\n\t\t\tmxc[k]=mxc[2*k+1]+mxc[2*k+2];\n\t\t\
    \tsmx[k]=max(smx[2*k+1],smx[2*k+2]);\n\t\t}\n\t\tif(mn[2*k+1]<mn[2*k+2]){\n\t\t\
    \tmn[k]=mn[2*k+1];\n\t\t\tmnc[k]=mnc[2*k+1];\n\t\t\tsmn[k]=min(smn[2*k+1],mn[2*k+2]);\n\
    \t\t}else if(mn[2*k+1]>mn[2*k+2]){\n\t\t\tmn[k]=mn[2*k+2];\n\t\t\tmnc[k]=mnc[2*k+2];\n\
    \t\t\tsmn[k]=min(mn[2*k+1],smn[2*k+2]);\n\t\t}else {\n\t\t\tmn[k]=mn[2*k+1];\n\
    \t\t\tmnc[k]=mnc[2*k+1]+mnc[2*k+2];\n\t\t\tsmn[k]=min(smn[2*k+1],smn[2*k+2]);\n\
    \t\t}\n\t}\n\tvoid update_min(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){\n\t\tif(r==-1)r=size;\n\
    \t\tif(r<=a||b<=l||mx[k]<=x)return;\n\t\tif(a<=l&&r<=b&&smx[k]<x){\n\t\t\tupdate_node_max(k,x);\n\
    \t\t\treturn;\n\t\t}\n\t\tpush(k,r-l);\n\t\tupdate_min(a,b,x,k*2+1,l,(l+r)/2);\n\
    \t\tupdate_min(a,b,x,k*2+2,(l+r)/2,r);\n\t\tupdate(k);\n\t}\n\tvoid update_max(ll\
    \ a,ll b,ll x,ll k=0,ll l=0,ll r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l||mn[k]>=x)return;\n\
    \t\tif(a<=l&&r<=b&&smn[k]>x){\n\t\t\tupdate_node_min(k,x);\n\t\t\treturn;\n\t\t\
    }\n\t\tpush(k,r-l);\n\t\tupdate_max(a,b,x,k*2+1,l,(l+r)/2);\n\t\tupdate_max(a,b,x,k*2+2,(l+r)/2,r);\n\
    \t\tupdate(k);\n\t}\n\tvoid update_add(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){\n\
    \t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return;\n\t\tif(a<=l&&r<=b){\n\t\t\tupdate_node_add(k,r-l,x);\n\
    \t\t\treturn;\n\t\t}\n\t\tpush(k,r-l);\n\t\tupdate_add(a,b,x,k*2+1,l,(l+r)/2);\n\
    \t\tupdate_add(a,b,x,k*2+2,(l+r)/2,r);\n\t\tupdate(k);\n\t}\n\tvoid set(ll k,ll\
    \ x){\n\t\tk+=size-1;\n\t\tmx[k]=x;mn[k]=x;sum[k]=x;\n\t}\n\tvoid init(){\n\t\t\
    for(ll i=size-2;i>=0;i--)update(i);\n\t}\n\tll query_sum(ll a,ll b,ll k=0,ll l=0,ll\
    \ r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return 0;\n\t\tif(a<=l&&r<=b)return\
    \ sum[k];\n\t\tpush(k,r-l);\n\t\tll lv=query_sum(a,b,k*2+1,l,(l+r)/2);\n\t\tll\
    \ rv=query_sum(a,b,k*2+2,(l+r)/2,r);\n\t\treturn lv+rv;\n\t}\n\tSegtreeBeats(ll\
    \ x){\n\t\twhile(size<x)size*=2;\n\t\tmx.resize(size*2-1);smx.resize(size*2-1,-inf);mxc.resize(size*2-1,1);\n\
    \t\tmn.resize(size*2-1);smn.resize(size*2-1,inf);mnc.resize(size*2-1,1);\n\t\t\
    sum.resize(size*2-1);lazy.resize(size*2-1);\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct SegtreeBeats{\n\
    \tvector<ll>mx,smx,mxc;\n\tvector<ll>mn,smn,mnc;\n\tvector<ll>sum,lazy;\n\tll\
    \ size=1;\n\tvoid update_node_max(ll k,ll x){\n\t\tsum[k]+=(x-mx[k])*mxc[k];\n\
    \t\tif(mx[k]==mn[k]){\n\t\t\tmx[k]=mn[k]=x;\n\t\t}else if(mx[k]==smn[k]){\n\t\t\
    \tmx[k]=smn[k]=x;\n\t\t}else {\n\t\t\tmx[k]=x;\n\t\t}\n\t}\n\tvoid update_node_min(ll\
    \ k,ll x){\n\t\tsum[k]+=(x-mn[k])*mnc[k];\n\t\tif(mx[k]==mn[k]){\n\t\t\tmx[k]=mn[k]=x;\n\
    \t\t}else if(smx[k]==mn[k]){\n\t\t\tsmx[k]=mn[k]=x;\n\t\t}else {\n\t\t\tmn[k]=x;\n\
    \t\t}\n\t}\n\tvoid update_node_add(ll k,ll len,ll x){\n\t\tmx[k]+=x;\n\t\tif(smx[k]!=-inf)smx[k]+=x;\n\
    \t\tmn[k]+=x;\n\t\tif(smn[k]!=inf)smn[k]+=x;\n\t\tsum[k]+=x*len;\n\t\tlazy[k]+=x;\n\
    \t}\n\tvoid push(ll k,ll len){\n\t\tif(k>=size-1)return;\n\t\tif(lazy[k]!=0){\n\
    \t\t\tupdate_node_add(k*2+1,len/2,lazy[k]);\n\t\t\tupdate_node_add(k*2+2,len/2,lazy[k]);\n\
    \t\t\tlazy[k]=0;\n\t\t}\n\t\tif(mx[k*2+1]>mx[k])update_node_max(k*2+1,mx[k]);\n\
    \t\tif(mx[k*2+2]>mx[k])update_node_max(k*2+2,mx[k]);\n\t\tif(mn[k*2+1]<mn[k])update_node_min(k*2+1,mn[k]);\n\
    \t\tif(mn[k*2+2]<mn[k])update_node_min(k*2+2,mn[k]);\n\t}\n\tvoid update(ll k){\n\
    \t\tsum[k]=sum[k*2+1]+sum[k*2+2];\n\t\tif(mx[2*k+1]<mx[2*k+2]){\n\t\t\tmx[k]=mx[2*k+2];\n\
    \t\t\tmxc[k]=mxc[2*k+2];\n\t\t\tsmx[k]=max(mx[2*k+1],smx[2*k+2]);\n\t\t}else if(mx[2*k+1]>mx[2*k+2]){\n\
    \t\t\tmx[k]=mx[2*k+1];\n\t\t\tmxc[k]=mxc[2*k+1];\n\t\t\tsmx[k]=max(smx[2*k+1],mx[2*k+2]);\n\
    \t\t}else {\n\t\t\tmx[k]=mx[2*k+1];\n\t\t\tmxc[k]=mxc[2*k+1]+mxc[2*k+2];\n\t\t\
    \tsmx[k]=max(smx[2*k+1],smx[2*k+2]);\n\t\t}\n\t\tif(mn[2*k+1]<mn[2*k+2]){\n\t\t\
    \tmn[k]=mn[2*k+1];\n\t\t\tmnc[k]=mnc[2*k+1];\n\t\t\tsmn[k]=min(smn[2*k+1],mn[2*k+2]);\n\
    \t\t}else if(mn[2*k+1]>mn[2*k+2]){\n\t\t\tmn[k]=mn[2*k+2];\n\t\t\tmnc[k]=mnc[2*k+2];\n\
    \t\t\tsmn[k]=min(mn[2*k+1],smn[2*k+2]);\n\t\t}else {\n\t\t\tmn[k]=mn[2*k+1];\n\
    \t\t\tmnc[k]=mnc[2*k+1]+mnc[2*k+2];\n\t\t\tsmn[k]=min(smn[2*k+1],smn[2*k+2]);\n\
    \t\t}\n\t}\n\tvoid update_min(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){\n\t\tif(r==-1)r=size;\n\
    \t\tif(r<=a||b<=l||mx[k]<=x)return;\n\t\tif(a<=l&&r<=b&&smx[k]<x){\n\t\t\tupdate_node_max(k,x);\n\
    \t\t\treturn;\n\t\t}\n\t\tpush(k,r-l);\n\t\tupdate_min(a,b,x,k*2+1,l,(l+r)/2);\n\
    \t\tupdate_min(a,b,x,k*2+2,(l+r)/2,r);\n\t\tupdate(k);\n\t}\n\tvoid update_max(ll\
    \ a,ll b,ll x,ll k=0,ll l=0,ll r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l||mn[k]>=x)return;\n\
    \t\tif(a<=l&&r<=b&&smn[k]>x){\n\t\t\tupdate_node_min(k,x);\n\t\t\treturn;\n\t\t\
    }\n\t\tpush(k,r-l);\n\t\tupdate_max(a,b,x,k*2+1,l,(l+r)/2);\n\t\tupdate_max(a,b,x,k*2+2,(l+r)/2,r);\n\
    \t\tupdate(k);\n\t}\n\tvoid update_add(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){\n\
    \t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return;\n\t\tif(a<=l&&r<=b){\n\t\t\tupdate_node_add(k,r-l,x);\n\
    \t\t\treturn;\n\t\t}\n\t\tpush(k,r-l);\n\t\tupdate_add(a,b,x,k*2+1,l,(l+r)/2);\n\
    \t\tupdate_add(a,b,x,k*2+2,(l+r)/2,r);\n\t\tupdate(k);\n\t}\n\tvoid set(ll k,ll\
    \ x){\n\t\tk+=size-1;\n\t\tmx[k]=x;mn[k]=x;sum[k]=x;\n\t}\n\tvoid init(){\n\t\t\
    for(ll i=size-2;i>=0;i--)update(i);\n\t}\n\tll query_sum(ll a,ll b,ll k=0,ll l=0,ll\
    \ r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return 0;\n\t\tif(a<=l&&r<=b)return\
    \ sum[k];\n\t\tpush(k,r-l);\n\t\tll lv=query_sum(a,b,k*2+1,l,(l+r)/2);\n\t\tll\
    \ rv=query_sum(a,b,k*2+2,(l+r)/2,r);\n\t\treturn lv+rv;\n\t}\n\tSegtreeBeats(ll\
    \ x){\n\t\twhile(size<x)size*=2;\n\t\tmx.resize(size*2-1);smx.resize(size*2-1,-inf);mxc.resize(size*2-1,1);\n\
    \t\tmn.resize(size*2-1);smn.resize(size*2-1,inf);mnc.resize(size*2-1,1);\n\t\t\
    sum.resize(size*2-1);lazy.resize(size*2-1);\n\t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SegmentTreeBeats.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/SegmentTreeBeats.cpp
layout: document
redirect_from:
- /library/structure/SegmentTreeBeats.cpp
- /library/structure/SegmentTreeBeats.cpp.html
title: structure/SegmentTreeBeats.cpp
---
