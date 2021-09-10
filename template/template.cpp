#pragma once
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, n) for (int i = 1; i < n; i++)
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define REV(i, n) for (int i = n - 1; i > 0; i--)
#define all(v) v.begin(), v.end()
#define PL pair<ll, ll>
#define PI pair<int,int>
#define len(s) (int)s.size()
#define compress(v) sort(all(v)); v.erase(unique(all(v)),v.end());
#define comid(v,x) lower_bound(all(v),x)-v.begin()

template <class T, class U>
inline bool chmin(T &a, U b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T, class U>
inline bool chmax(T &a, U b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
constexpr ll inf = 3e18;