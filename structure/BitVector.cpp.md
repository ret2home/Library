---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/FM_index.cpp
    title: FM Index
  - icon: ':heavy_check_mark:'
    path: structure/WaveletMatrix.cpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FM_index.test.cpp
    title: test/FM_index.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/BitVector.md
    document_title: Bit Vector
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
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BitVector.cpp\"\
    \n\nclass BitVector {\n    vector<ll> sum;\n    vector<uint64_t> bit;\n\n   public:\n\
    \    ll rank(bool val, ll idx) {\n        uint64_t mask = ((uint64_t)1 << (idx\
    \ & ((1 << 6) - 1))) - 1;\n        ll res = sum[idx >> 6] + __builtin_popcountll(bit[idx\
    \ >> 6] & mask);\n        return (val ? res : idx - res);\n    }\n    BitVector(vector<bool>&\
    \ v) {\n        ll sz = (len(v) >> 6) + 1;\n        bit.assign(sz, 0);\n     \
    \   sum.assign(sz, 0);\n        rep(i, len(v)) {\n            bit[i >> 6] |= (uint64_t)(v[i])\
    \ << (i & ((1 << 6) - 1));\n        }\n        rep(i, sz - 1) {\n            sum[i\
    \ + 1] = sum[i] + __builtin_popcountll(bit[i]);\n        }\n    }\n};\n/*\n@brief\
    \ Bit Vector\n@docs docs/BitVector.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nclass BitVector {\n\
    \    vector<ll> sum;\n    vector<uint64_t> bit;\n\n   public:\n    ll rank(bool\
    \ val, ll idx) {\n        uint64_t mask = ((uint64_t)1 << (idx & ((1 << 6) - 1)))\
    \ - 1;\n        ll res = sum[idx >> 6] + __builtin_popcountll(bit[idx >> 6] &\
    \ mask);\n        return (val ? res : idx - res);\n    }\n    BitVector(vector<bool>&\
    \ v) {\n        ll sz = (len(v) >> 6) + 1;\n        bit.assign(sz, 0);\n     \
    \   sum.assign(sz, 0);\n        rep(i, len(v)) {\n            bit[i >> 6] |= (uint64_t)(v[i])\
    \ << (i & ((1 << 6) - 1));\n        }\n        rep(i, sz - 1) {\n            sum[i\
    \ + 1] = sum[i] + __builtin_popcountll(bit[i]);\n        }\n    }\n};\n/*\n@brief\
    \ Bit Vector\n@docs docs/BitVector.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/BitVector.cpp
  requiredBy:
  - string/FM_index.cpp
  - structure/WaveletMatrix.cpp
  timestamp: '2021-09-10 20:11:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FM_index.test.cpp
  - test/WaveletMatrix.test.cpp
documentation_of: structure/BitVector.cpp
layout: document
redirect_from:
- /library/structure/BitVector.cpp
- /library/structure/BitVector.cpp.html
title: Bit Vector
---
## 概要

ビットベクトル。64bitに畳み込んでいる。

- ```rank(c,x)``` : ```c``` が $[0,x)$ に何回登場したか

## 計算量

$O(1)$

```__builtin_popcountll``` の部分は QCFium法をすると速くなる。