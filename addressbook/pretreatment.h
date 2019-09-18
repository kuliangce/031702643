#pragma once
#include<iostream>
#include<cmath>
#include<cstring>
#include <fstream>
#include<string>
#include<cstdio>
#include<fstream>
#include <locale>
#include <codecvt>
#include <Windows.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
struct Addr {
	ll num;
	wchar_t name[50];
};
struct Edge {
	int to, next;
};
void pretreatment(Addr  addr[], Edge  edge[], int head[]);
void suffix(wchar_t sub[][20]);
