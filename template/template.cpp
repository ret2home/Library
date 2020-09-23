#pragma once
#include<bits/stdc++.h>
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define REP(i,n) for(ll i=1;i<n;i++)
#define rev(i,n) for(ll i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<ll,ll>
#define len(s) (ll)s.size()
 
template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr ll inf = 3e18;