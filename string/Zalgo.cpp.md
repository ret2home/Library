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
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"string/Zalgo.cpp\"\n\
    \ntemplate <class T>\nvector<ll> zalgo(T v) {\n    vector<ll> res(v.size());\n\
    \    ll c = 0;\n    REP(i, (ll)v.size()) {\n        if (i + res[i - c] < c + res[c])\n\
    \            res[i] = res[i - c];\n        else {\n            ll j = max(0ll,\
    \ c + res[c] - i);\n            while (i + j < (ll)v.size() && v[j] == v[i + j])\
    \ ++j;\n            res[i] = j;\n            c = i;\n        }\n    }\n    res[0]\
    \ = v.size();\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate <class T>\n\
    vector<ll> zalgo(T v) {\n    vector<ll> res(v.size());\n    ll c = 0;\n    REP(i,\
    \ (ll)v.size()) {\n        if (i + res[i - c] < c + res[c])\n            res[i]\
    \ = res[i - c];\n        else {\n            ll j = max(0ll, c + res[c] - i);\n\
    \            while (i + j < (ll)v.size() && v[j] == v[i + j]) ++j;\n         \
    \   res[i] = j;\n            c = i;\n        }\n    }\n    res[0] = v.size();\n\
    \    return res;\n}"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: string/Zalgo.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:11:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Zalgo.cpp
layout: document
redirect_from:
- /library/string/Zalgo.cpp
- /library/string/Zalgo.cpp.html
title: string/Zalgo.cpp
---
