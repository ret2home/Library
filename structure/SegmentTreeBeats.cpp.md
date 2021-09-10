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
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SegmentTreeBeats.cpp\"\
    \n\ntemplate<typename T,T INF>\nstruct SegtreeBeats {\n    int size = 1;\n\n \
    \  private:\n    vector<T> mx, smx, mxc;\n    vector<T> mn, smn, mnc;\n    vector<T>\
    \ sum, lazy;\n    vector<bool> flag;\n\n    void update(int k) {\n        sum[k]\
    \ = sum[k * 2 + 1] + sum[k * 2 + 2];\n\n        mx[k] = max(mx[2 * k + 1], mx[2\
    \ * k + 2]);\n        if (mx[2 * k + 1] < mx[2 * k + 2]) {\n            mxc[k]\
    \ = mxc[2 * k + 2];\n            smx[k] = max(mx[2 * k + 1], smx[2 * k + 2]);\n\
    \        } else if (mx[2 * k + 1] > mx[2 * k + 2]) {\n            mxc[k] = mxc[2\
    \ * k + 1];\n            smx[k] = max(smx[2 * k + 1], mx[2 * k + 2]);\n      \
    \  } else {\n            mxc[k] = mxc[2 * k + 1] + mxc[2 * k + 2];\n         \
    \   smx[k] = max(smx[2 * k + 1], smx[2 * k + 2]);\n        }\n\n        mn[k]\
    \ = min(mn[2 * k + 1], mn[2 * k + 2]);\n        if (mn[2 * k + 1] < mn[2 * k +\
    \ 2]) {\n            mnc[k] = mnc[2 * k + 1];\n            smn[k] = min(smn[2\
    \ * k + 1], mn[2 * k + 2]);\n        } else if (mn[2 * k + 1] > mn[2 * k + 2])\
    \ {\n            mnc[k] = mnc[2 * k + 2];\n            smn[k] = min(mn[2 * k +\
    \ 1], smn[2 * k + 2]);\n        } else {\n            mnc[k] = mnc[2 * k + 1]\
    \ + mnc[2 * k + 2];\n            smn[k] = min(smn[2 * k + 1], smn[2 * k + 2]);\n\
    \        }\n    }\n    void updateNodeMax(int k, T x) {\n        sum[k] += (x\
    \ - mx[k]) * mxc[k];\n        if (mx[k] == mn[k]) {\n            mx[k] = mn[k]\
    \ = x;\n        } else if (mx[k] == smn[k]) {\n            mx[k] = smn[k] = x;\n\
    \        } else {\n            mx[k] = x;\n        }\n    }\n    void updateNodeMin(int\
    \ k, T x) {\n        sum[k] += (x - mn[k]) * mnc[k];\n        if (mx[k] == mn[k])\
    \ {\n            mx[k] = mn[k] = x;\n        } else if (smx[k] == mn[k]) {\n \
    \           smx[k] = mn[k] = x;\n        } else {\n            mn[k] = x;\n  \
    \      }\n    }\n    void updateNodeAdd(int k, int len, T x) {\n        mx[k]\
    \ += x;\n        if (smx[k] != -INF) smx[k] += x;\n        mn[k] += x;\n     \
    \   if (smn[k] != INF) smn[k] += x;\n        sum[k] += x * len;\n        lazy[k]\
    \ += x;\n    }\n    void updateNodeAssign(int k, int len, T x) {\n        mx[k]\
    \ = x;\n        smx[k] = -INF;\n        mxc[k] = len;\n        mn[k] = x;\n  \
    \      smn[k] = INF;\n        mnc[k] = len;\n        sum[k] = x * len;\n     \
    \   lazy[k] = x;\n        flag[k] = true;\n    }\n    void push(int k, int len)\
    \ {\n        if (k >= size - 1) return;\n        if (flag[k] || lazy[k] != 0)\
    \ {\n            if (flag[k]) {\n                updateNodeAssign(k * 2 + 1, len\
    \ / 2, lazy[k]);\n                updateNodeAssign(k * 2 + 2, len / 2, lazy[k]);\n\
    \            } else {\n                updateNodeAdd(k * 2 + 1, len / 2, lazy[k]);\n\
    \                updateNodeAdd(k * 2 + 2, len / 2, lazy[k]);\n            }\n\
    \            lazy[k] = 0;\n            flag[k] = false;\n        }\n        if\
    \ (mx[k * 2 + 1] > mx[k]) updateNodeMax(k * 2 + 1, mx[k]);\n        if (mx[k *\
    \ 2 + 2] > mx[k]) updateNodeMax(k * 2 + 2, mx[k]);\n        if (mn[k * 2 + 1]\
    \ < mn[k]) updateNodeMin(k * 2 + 1, mn[k]);\n        if (mn[k * 2 + 2] < mn[k])\
    \ updateNodeMin(k * 2 + 2, mn[k]);\n    }\n\n   public:\n    void updateMin(int\
    \ a, int b, T x, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r =\
    \ size;\n        if (r <= a || b <= l || mx[k] <= x) return;\n        if (a <=\
    \ l && r <= b && smx[k] < x) {\n            updateNodeMax(k, x);\n           \
    \ return;\n        }\n        push(k, r - l);\n        updateMin(a, b, x, k *\
    \ 2 + 1, l, (l + r) / 2);\n        updateMin(a, b, x, k * 2 + 2, (l + r) / 2,\
    \ r);\n        update(k);\n    }\n    void updateMax(int a, int b, T x, int k\
    \ = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n        if (r\
    \ <= a || b <= l || mn[k] >= x) return;\n        if (a <= l && r <= b && smn[k]\
    \ > x) {\n            updateNodeMin(k, x);\n            return;\n        }\n \
    \       push(k, r - l);\n        updateMax(a, b, x, k * 2 + 1, l, (l + r) / 2);\n\
    \        updateMax(a, b, x, k * 2 + 2, (l + r) / 2, r);\n        update(k);\n\
    \    }\n    void updateAdd(int a, int b, T x, int k = 0, int l = 0, int r = -1)\
    \ {\n        if (r == -1) r = size;\n        if (r <= a || b <= l) return;\n \
    \       if (a <= l && r <= b) {\n            updateNodeAdd(k, r - l, x);\n   \
    \         return;\n        }\n        push(k, r - l);\n        updateAdd(a, b,\
    \ x, k * 2 + 1, l, (l + r) / 2);\n        updateAdd(a, b, x, k * 2 + 2, (l + r)\
    \ / 2, r);\n        update(k);\n    }\n    void updateAssign(int a, int b, T x,\
    \ int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n      \
    \  if (r <= a || b <= l) return;\n        if (a <= l && r <= b) {\n          \
    \  updateNodeAssign(k, r - l, x);\n            return;\n        }\n        push(k,\
    \ r - l);\n        updateAssign(a, b, x, k * 2 + 1, l, (l + r) / 2);\n       \
    \ updateAssign(a, b, x, k * 2 + 2, (l + r) / 2, r);\n        update(k);\n    }\n\
    \n    void set(int k, T x) {\n        k += size - 1;\n        mx[k] = x;\n   \
    \     mn[k] = x;\n        sum[k] = x;\n    }\n    void init() {\n        for (T\
    \ i = size - 2; i >= 0; i--) update(i);\n    }\n    T queryMin(int a, int b, int\
    \ k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n        if\
    \ (r <= a || b <= l) return INF;\n        if (a <= l && r <= b) return mn[k];\n\
    \        push(k, r - l);\n        T lv = queryMin(a, b, k * 2 + 1, l, (l + r)\
    \ / 2);\n        T rv = queryMin(a, b, k * 2 + 2, (l + r) / 2, r);\n        return\
    \ min(lv, rv);\n    }\n    T queryMax(int a, int b, int k = 0, int l = 0, int\
    \ r = -1) {\n        if (r == -1) r = size;\n        if (r <= a || b <= l) return\
    \ -INF;\n        if (a <= l && r <= b) return mx[k];\n        push(k, r - l);\n\
    \        T lv = queryMax(a, b, k * 2 + 1, l, (l + r) / 2);\n        T rv = queryMax(a,\
    \ b, k * 2 + 2, (l + r) / 2, r);\n        return max(lv, rv);\n    }\n    T querySum(int\
    \ a, int b, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n\
    \        if (r <= a || b <= l) return 0;\n        if (a <= l && r <= b) return\
    \ sum[k];\n        push(k, r - l);\n        T lv = querySum(a, b, k * 2 + 1, l,\
    \ (l + r) / 2);\n        T rv = querySum(a, b, k * 2 + 2, (l + r) / 2, r);\n \
    \       return lv + rv;\n    }\n    SegtreeBeats(int x) {\n        while (size\
    \ < x) size *= 2;\n        mx.resize(size * 2 - 1, -INF + 1);\n        smx.resize(size\
    \ * 2 - 1, -INF);\n        mxc.resize(size * 2 - 1, 1);\n        mn.resize(size\
    \ * 2 - 1, INF - 1);\n        smn.resize(size * 2 - 1, INF);\n        mnc.resize(size\
    \ * 2 - 1, 1);\n        sum.resize(size * 2 - 1);\n        lazy.resize(size *\
    \ 2 - 1);\n        flag.resize(size * 2 - 1);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<typename\
    \ T,T INF>\nstruct SegtreeBeats {\n    int size = 1;\n\n   private:\n    vector<T>\
    \ mx, smx, mxc;\n    vector<T> mn, smn, mnc;\n    vector<T> sum, lazy;\n    vector<bool>\
    \ flag;\n\n    void update(int k) {\n        sum[k] = sum[k * 2 + 1] + sum[k *\
    \ 2 + 2];\n\n        mx[k] = max(mx[2 * k + 1], mx[2 * k + 2]);\n        if (mx[2\
    \ * k + 1] < mx[2 * k + 2]) {\n            mxc[k] = mxc[2 * k + 2];\n        \
    \    smx[k] = max(mx[2 * k + 1], smx[2 * k + 2]);\n        } else if (mx[2 * k\
    \ + 1] > mx[2 * k + 2]) {\n            mxc[k] = mxc[2 * k + 1];\n            smx[k]\
    \ = max(smx[2 * k + 1], mx[2 * k + 2]);\n        } else {\n            mxc[k]\
    \ = mxc[2 * k + 1] + mxc[2 * k + 2];\n            smx[k] = max(smx[2 * k + 1],\
    \ smx[2 * k + 2]);\n        }\n\n        mn[k] = min(mn[2 * k + 1], mn[2 * k +\
    \ 2]);\n        if (mn[2 * k + 1] < mn[2 * k + 2]) {\n            mnc[k] = mnc[2\
    \ * k + 1];\n            smn[k] = min(smn[2 * k + 1], mn[2 * k + 2]);\n      \
    \  } else if (mn[2 * k + 1] > mn[2 * k + 2]) {\n            mnc[k] = mnc[2 * k\
    \ + 2];\n            smn[k] = min(mn[2 * k + 1], smn[2 * k + 2]);\n        } else\
    \ {\n            mnc[k] = mnc[2 * k + 1] + mnc[2 * k + 2];\n            smn[k]\
    \ = min(smn[2 * k + 1], smn[2 * k + 2]);\n        }\n    }\n    void updateNodeMax(int\
    \ k, T x) {\n        sum[k] += (x - mx[k]) * mxc[k];\n        if (mx[k] == mn[k])\
    \ {\n            mx[k] = mn[k] = x;\n        } else if (mx[k] == smn[k]) {\n \
    \           mx[k] = smn[k] = x;\n        } else {\n            mx[k] = x;\n  \
    \      }\n    }\n    void updateNodeMin(int k, T x) {\n        sum[k] += (x -\
    \ mn[k]) * mnc[k];\n        if (mx[k] == mn[k]) {\n            mx[k] = mn[k] =\
    \ x;\n        } else if (smx[k] == mn[k]) {\n            smx[k] = mn[k] = x;\n\
    \        } else {\n            mn[k] = x;\n        }\n    }\n    void updateNodeAdd(int\
    \ k, int len, T x) {\n        mx[k] += x;\n        if (smx[k] != -INF) smx[k]\
    \ += x;\n        mn[k] += x;\n        if (smn[k] != INF) smn[k] += x;\n      \
    \  sum[k] += x * len;\n        lazy[k] += x;\n    }\n    void updateNodeAssign(int\
    \ k, int len, T x) {\n        mx[k] = x;\n        smx[k] = -INF;\n        mxc[k]\
    \ = len;\n        mn[k] = x;\n        smn[k] = INF;\n        mnc[k] = len;\n \
    \       sum[k] = x * len;\n        lazy[k] = x;\n        flag[k] = true;\n   \
    \ }\n    void push(int k, int len) {\n        if (k >= size - 1) return;\n   \
    \     if (flag[k] || lazy[k] != 0) {\n            if (flag[k]) {\n           \
    \     updateNodeAssign(k * 2 + 1, len / 2, lazy[k]);\n                updateNodeAssign(k\
    \ * 2 + 2, len / 2, lazy[k]);\n            } else {\n                updateNodeAdd(k\
    \ * 2 + 1, len / 2, lazy[k]);\n                updateNodeAdd(k * 2 + 2, len /\
    \ 2, lazy[k]);\n            }\n            lazy[k] = 0;\n            flag[k] =\
    \ false;\n        }\n        if (mx[k * 2 + 1] > mx[k]) updateNodeMax(k * 2 +\
    \ 1, mx[k]);\n        if (mx[k * 2 + 2] > mx[k]) updateNodeMax(k * 2 + 2, mx[k]);\n\
    \        if (mn[k * 2 + 1] < mn[k]) updateNodeMin(k * 2 + 1, mn[k]);\n       \
    \ if (mn[k * 2 + 2] < mn[k]) updateNodeMin(k * 2 + 2, mn[k]);\n    }\n\n   public:\n\
    \    void updateMin(int a, int b, T x, int k = 0, int l = 0, int r = -1) {\n \
    \       if (r == -1) r = size;\n        if (r <= a || b <= l || mx[k] <= x) return;\n\
    \        if (a <= l && r <= b && smx[k] < x) {\n            updateNodeMax(k, x);\n\
    \            return;\n        }\n        push(k, r - l);\n        updateMin(a,\
    \ b, x, k * 2 + 1, l, (l + r) / 2);\n        updateMin(a, b, x, k * 2 + 2, (l\
    \ + r) / 2, r);\n        update(k);\n    }\n    void updateMax(int a, int b, T\
    \ x, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n   \
    \     if (r <= a || b <= l || mn[k] >= x) return;\n        if (a <= l && r <=\
    \ b && smn[k] > x) {\n            updateNodeMin(k, x);\n            return;\n\
    \        }\n        push(k, r - l);\n        updateMax(a, b, x, k * 2 + 1, l,\
    \ (l + r) / 2);\n        updateMax(a, b, x, k * 2 + 2, (l + r) / 2, r);\n    \
    \    update(k);\n    }\n    void updateAdd(int a, int b, T x, int k = 0, int l\
    \ = 0, int r = -1) {\n        if (r == -1) r = size;\n        if (r <= a || b\
    \ <= l) return;\n        if (a <= l && r <= b) {\n            updateNodeAdd(k,\
    \ r - l, x);\n            return;\n        }\n        push(k, r - l);\n      \
    \  updateAdd(a, b, x, k * 2 + 1, l, (l + r) / 2);\n        updateAdd(a, b, x,\
    \ k * 2 + 2, (l + r) / 2, r);\n        update(k);\n    }\n    void updateAssign(int\
    \ a, int b, T x, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r =\
    \ size;\n        if (r <= a || b <= l) return;\n        if (a <= l && r <= b)\
    \ {\n            updateNodeAssign(k, r - l, x);\n            return;\n       \
    \ }\n        push(k, r - l);\n        updateAssign(a, b, x, k * 2 + 1, l, (l +\
    \ r) / 2);\n        updateAssign(a, b, x, k * 2 + 2, (l + r) / 2, r);\n      \
    \  update(k);\n    }\n\n    void set(int k, T x) {\n        k += size - 1;\n \
    \       mx[k] = x;\n        mn[k] = x;\n        sum[k] = x;\n    }\n    void init()\
    \ {\n        for (T i = size - 2; i >= 0; i--) update(i);\n    }\n    T queryMin(int\
    \ a, int b, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n\
    \        if (r <= a || b <= l) return INF;\n        if (a <= l && r <= b) return\
    \ mn[k];\n        push(k, r - l);\n        T lv = queryMin(a, b, k * 2 + 1, l,\
    \ (l + r) / 2);\n        T rv = queryMin(a, b, k * 2 + 2, (l + r) / 2, r);\n \
    \       return min(lv, rv);\n    }\n    T queryMax(int a, int b, int k = 0, int\
    \ l = 0, int r = -1) {\n        if (r == -1) r = size;\n        if (r <= a ||\
    \ b <= l) return -INF;\n        if (a <= l && r <= b) return mx[k];\n        push(k,\
    \ r - l);\n        T lv = queryMax(a, b, k * 2 + 1, l, (l + r) / 2);\n       \
    \ T rv = queryMax(a, b, k * 2 + 2, (l + r) / 2, r);\n        return max(lv, rv);\n\
    \    }\n    T querySum(int a, int b, int k = 0, int l = 0, int r = -1) {\n   \
    \     if (r == -1) r = size;\n        if (r <= a || b <= l) return 0;\n      \
    \  if (a <= l && r <= b) return sum[k];\n        push(k, r - l);\n        T lv\
    \ = querySum(a, b, k * 2 + 1, l, (l + r) / 2);\n        T rv = querySum(a, b,\
    \ k * 2 + 2, (l + r) / 2, r);\n        return lv + rv;\n    }\n    SegtreeBeats(int\
    \ x) {\n        while (size < x) size *= 2;\n        mx.resize(size * 2 - 1, -INF\
    \ + 1);\n        smx.resize(size * 2 - 1, -INF);\n        mxc.resize(size * 2\
    \ - 1, 1);\n        mn.resize(size * 2 - 1, INF - 1);\n        smn.resize(size\
    \ * 2 - 1, INF);\n        mnc.resize(size * 2 - 1, 1);\n        sum.resize(size\
    \ * 2 - 1);\n        lazy.resize(size * 2 - 1);\n        flag.resize(size * 2\
    \ - 1);\n    }\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SegmentTreeBeats.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:11:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/SegmentTreeBeats.cpp
layout: document
redirect_from:
- /library/structure/SegmentTreeBeats.cpp
- /library/structure/SegmentTreeBeats.cpp.html
title: structure/SegmentTreeBeats.cpp
---
