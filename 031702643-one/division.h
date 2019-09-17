#pragma once
#include"pretreatment.h"
void border(wstring y, int & start);
void KMP_pre(wchar_t x[], int m, int next[]);
void Level_five(wstring y, wchar_t s[], int start);
int KMP_count(wchar_t x[], int m, wstring y, int n, int next[]);
void name_and_phonenumber(wstring & text, wchar_t name[], wchar_t phone[]);
void Level_seven(wstring y, wchar_t s1[], wchar_t s2[], wchar_t s3[], int start);