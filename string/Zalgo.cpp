#pragma once
#include "../template/template.cpp"

template <class T>
vector<ll> zalgo(T v) {
    vector<ll> res(v.size());
    ll c = 0;
    REP(i, (ll)v.size()) {
        if (i + res[i - c] < c + res[c])
            res[i] = res[i - c];
        else {
            ll j = max(0ll, c + res[c] - i);
            while (i + j < (ll)v.size() && v[j] == v[i + j]) ++j;
            res[i] = j;
            c = i;
        }
    }
    res[0] = v.size();
    return res;
}