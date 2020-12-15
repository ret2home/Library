#pragma once
#include "../template/template.cpp"

template <class T, T (*f)(T, T)>
struct SparseTable {
    vector<T> table[20];
    vector<int> log;
    SparseTable(vector<T> v)
        : log(v.size() + 1) {
        int mx = 0;
        while (1 << (mx + 1) <= len(v)) ++mx;
        rep(i, mx + 1) {
            table[i].resize(len(v));
            rep(j, v.size() - (1 << i) + 1) {
                if (i)
                    table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
                else
                    table[i][j] = v[j];
            }
        }
        for (int i = 2; i <= len(v); i++) log[i] = log[i >> 1] + 1;
    }
    T query(int l, int r) {
        return f(table[log[r - l]][l], table[log[r - l]][r - (1 << log[r - l])]);
    }
};
/*
@brief Sparse Table
@docs docs/SparseTable.md
*/
