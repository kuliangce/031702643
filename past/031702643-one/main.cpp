#include"pretreatment.h"
#include"division.h"
#include"print.h"
#include"utf-8.h"
const int N = int(1e5) + 7;
int head[N], nex[205], cnt = 1, id, l;
wstring text, pro[100];
wchar_t name[20], phone[20], level_five[210], level_six[105], level_seven[105], suf[20][20], ss[210];
char buf[505];
Edge edge[N];
Addr addr[N];
int level_one, level_two, level_three, level_four;
int find_next_level(int now) {
	for (int i = head[now]; i != 0; i = edge[i].next) {
		memset(nex, 0, sizeof nex);
		int son = edge[i].to;
		int n = text.length();
		int m = wcsnlen_s(addr[son].name, 50);
		int flag = KMP_count(addr[son].name, m, text, n, nex);
		l = max(l, flag);
		if (flag) return son;
	}
	return 0;
}
void init() {
	level_one = level_two = level_three = level_four = l = 0;
	memset(level_five, 0, sizeof level_five);
	memset(level_six, 0, sizeof level_six);
	memset(level_seven, 0, sizeof level_seven);
	memset(phone, 0, sizeof phone);
	memset(name, 0, sizeof name);
}
int main() {
	int flag = 0;
	wcout.imbue(locale("chs"));
	pretreatment(addr, edge, head);
	suffix(suf);
	ifstream fin("1.txt");
	wofstream fout("2.txt", ios::ate);
	fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::little_endian>));
	fout << L'[';
	while (fin >> buf) {
		if (flag)fout << L',';
		fout << L'{';
		init();
		text = Utf82Gbk(buf);
		uint type = text[0] - 48;
		name_and_phonenumber(text, name, phone);
		level_one = find_next_level(0);
		level_two = find_next_level(level_one);
		level_three = find_next_level(level_two);
		level_four = find_next_level(level_three);
		fout << L'"' << L"����" << L'"' << L":\""<< name << L"\",";
		fout << L'"' << L"�ֻ�" << L'"' << L":\"" << phone << L"\",";
		fout << L'"' << L"��ַ" << L'"' << L":[";
		int t;
		t = print_four(level_one, addr, ss, 1, suf);
		fout << L'"' << addr[level_one].name << suf[t] << L"\",";
		t = print_four(level_two, addr, ss, 2, suf);
		fout << L'"' << addr[level_two].name << suf[t] << L"\",";
		t = print_four(level_three, addr, ss, 3, suf);
		fout << L'"' << addr[level_three].name << suf[t] << L"\",";
		t = print_four(level_four, addr, ss, 4, suf);
		fout << L'"' << addr[level_four].name << suf[t] << L"\",";
		border(text, l);
		if (type == 1) {
			Level_five(text, level_five, l);
			fout << L'"' << level_five << L"\"]";
		}
		else {
			Level_seven(text, level_five, level_six, level_seven, l);
			fout << L'"' << level_five << L"\",";
			fout << L'"' << level_six << L"\",";
			fout << L'"' << level_seven << L"\"]";
		}
		
		fout << L"}";
		flag = 1;
	}
	fout << L']';
	return 0;
}