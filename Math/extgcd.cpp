#pragma once
#include "../template/template.cpp"

int extGCD(int a,int b,int &x,int &y){
	if(!b){
		x=1;y=0;return a;
	}
	int d=extGCD(b,a%b,y,x);
	y-=a/b*x;
	return d;
}