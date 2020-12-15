#pragma once
#include "../template/template.cpp"

class UnionFind {
    int N;
    vector<int> par, siz;

   public:
    int find(int x) {
        assert(x < N);
        return (par[x] == x ? x : par[x] = find(par[x]));
    }
    void merge(int x, int y) {
        assert(x < N && y < N);
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (siz[x] > siz[y]) swap(x, y);
        par[x] = y;
        siz[y] += siz[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return siz[find(x)];
    }
    UnionFind(int N) : N(N), siz(N, 1), par(N) {
        iota(all(par), 0);
    }
};

/*
@brief Union Find
@docs docs/UnionFind.md
*/