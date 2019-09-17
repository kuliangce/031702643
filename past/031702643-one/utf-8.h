#pragma once
#include"pretreatment.h"
wstring Utf82Gbk(const char *src_str) {
	int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	string str(szGBK);
	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
	size_t cnt = 0;
	setlocale(LC_ALL, "chs");
	const char* pts = str.c_str();
	size_t ns = str.size() + 1;
	wchar_t *ptd = new wchar_t[ns];
	wmemset(ptd, 0, ns);
	mbstowcs_s(&cnt, ptd, ns, pts, ns);
	wstring res = ptd;
	delete[] ptd;
	setlocale(LC_ALL, "C");
	return res;
}