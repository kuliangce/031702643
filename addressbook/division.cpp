#include"division.h"
void border(wstring y, int & start) {
	if (y[start] == L'市' || y[start] == L'区' || y[start] == L'县' || y[start] == L'镇' || y[start] == L'乡') {
		start++;
	}
	else if (y[start] == L'街' && y[start + 1] == L'道') {
		start += 2;
	}
}
void KMP_pre(wchar_t x[], int m, int next[]) {
	int i, j;
	j = next[0] = -1;
	i = 0;
	while (i < m) {
		while (-1 != j && x[i] != x[j])j = next[j];
		next[++i] = ++j;
	}
}
int KMP_count(wchar_t x[], int m, wstring y, int n, int next[]) {
	int i, j;
	int ans = 0;
	KMP_pre(x, m, next);
	i = j = 0;
	while (i < n) {
		while (-1 != j && y[i] != x[j])j = next[j];
		i++, j++;
		if (j >= m) {
			return i;
		}
	}
	return 0;
}
void Level_five(wstring y, wchar_t s[], int start) {
	int len = (int)y.length();
	for (int i = start, j = 0; i < len; i++, j++) {
		if (y[i] == 0)
			break;
		s[j] = y[i];
	}
}
void Level_seven(wstring y, wchar_t s1[], wchar_t s2[], wchar_t s3[], int start) {
	int ed, len = (int)y.length(), mark = start;
	for (int i = start; i < len; i++) {
		if (y[i] == 0) {
			ed = i;
			break;
		}
	}
	for (int i = start; i < ed; i++) {
		if (y[i] == L'路' || y[i] == L'道' || y[i] == L'巷'/* || y[i] == L'里'*/ || y[i] == L'街') {
			for (int j = start; j <= i; j++) {
				s1[j - start] = y[j];
			}
			mark = i + 1;
		}
		else if (y[i] == L'胡' && y[i + 1] == L'同') {
			for (int j = start; j <= i + 1; j++) {
				s1[j - start] = y[j];
			}
			mark = i + 2;
		}
		else if (y[i] == L'号') {
			uint cha = (uint)y[i - 1];
			if (cha < 48 || cha > 57)continue;
			for (int j = mark; j <= i; j++) {
				s2[j - mark] = y[j];
			}
			mark = i + 1;
		}
	}
	for (int i = mark; i < ed; i++) {
		s3[i - mark] = y[i];
	}
}
void name_and_phonenumber(wstring & text, wchar_t name[], wchar_t phone[]) {
	int len = (int)text.length(), cnt;
	text[len - 1] = 0;
	for (int i = 0; i < len - 2; i++) {
		text[i] = text[i + 2];
	}
	text[len - 1] = text[len - 2] = 0;
	uint cha;
	cnt = 0;
	for (int i = 0; i < len; i++) {
		cha = text[i];
		if (cha == 44) {
			for (int j = i + 1; j < len; j++) {
				text[j - i - 1] = text[j];
			}
			break;
		}
		else {
			name[cnt++] = text[i];
		}
	}
	for (int i = 0; i < len; i++) {
		cha = text[i];
		if (cha >= 48 && cha <= 57) {
			bool flag = 1;
			for (int j = 0; j < 11; j++) {
				cha = text[i + j];
				if (cha < 48 || cha > 57) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < 11; j++) {
					phone[j] = text[i + j];
				}
				for (int j = 0; i + j < len; j++) {
					if (i + j + 11 < len) {
						text[i + j] = text[i + j + 11];
					}
					else {
						text[i + j] = 0;
					}
				}
				break;
			}
		}
	}
}