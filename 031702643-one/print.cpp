#include"print.h"
int print_four(int id, Addr addr[], wchar_t s[], int level, wchar_t suf[][20]) {
	for (int i = 0; i < 50; i++)s[i] = 0;
	int len = (int)wcsnlen_s(addr[id].name, 50), t;
	for (int i = 0; i < len; i++) {
		s[i] = addr[id].name[i];
	}
	if (level == 1) {
		ll num = addr[id].num;
		if (num == 15 || num == 54)	t = 1;
		else if (num == 45)	t = 4;
		else if (num == 65)	t = 2;
		else if (num == 64) t = 3;
		else if (num == 11 || num == 12 || num == 31 || num == 50) t = 0;
		else t = 5;
	}
	else if (level == 2) {
		ll num = addr[id].num % 100;
		if ((num >= 1 && num <= 20) || (num >= 51 && num <= 70)) t = 6;
		else if (num >= 21 && num <= 50) t = 7;
		else t = 0;
	}
	else if (level == 3) {
		ll num = addr[id].num % 100;
		if (num >= 1 && num <= 18) t = 8;
		else if (num >= 21 && num <= 80) t = 9;
		else if (num >= 81 && num <= 99) t = 6;
		else if (num == 0)	s[0] = 0, t = 0;
		else t = 0;
	}
	else if (level == 4) {
		ll num = addr[id].num % 1000;
		if (num >= 1 && num <= 99) t = 10;
		else if (num >= 100 && num <= 199) t = 11;
		else if (num >= 200 && num <= 299) t = 12;
		else t = 0;
	}
	return t;
//	fcout << L'"' << s << suf[t]<< L"\",";
}