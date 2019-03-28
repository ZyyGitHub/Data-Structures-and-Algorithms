#include <iostream>
#include <string.h>
#include <string>

using namespace std;

bool strcmp1(const char * str1, const char * str2) {
	cout << "strcmp(char * str1, char * str2)" << endl;
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] == str2[i])
			i++;
		else
			return false;
	}
	if (str1[i] == str2[i]) {
		return true;
	}
	else
	{
		return false;
	}
}
bool strcmp2(const char *str1, const char *str2) {
	cout << "strcmp2(const char *str1, const char *str2)" << endl;
	int i;
	for ( i = 0; str1[i] == str2[i]; i++)
	{
		if (str1[i] == '\0' && str2[2] == '\0') {
			return true;
		}
	}
	return false;
}

int findPat_1(string S, string P, int startindex) {
	cout << "findPat_1(string S, string P, int startindex)" << endl;
	int Lastindex = S.length() - P.length();
	int count = P.length();
	if (Lastindex < startindex) {
		return -1;
	}
	for (int i = startindex; i <= Lastindex; i++)
	{
		if (P == S.substr(i, count))
			return i;
	}
	return -1;
}
int findPat_2(string S, string P, int startindex) {
	cout << "findPat_2(string S, string P, int startindex)" << endl;
	int Lastindex = S.length() - P.length();    //模板倒数匹配模板个财产的长度
	if (Lastindex < startindex)
		return -1;
	int i = startindex, j = 0;
	while ((i < S.length()) && (j < P.length())) {
		if (P[j] == S[i]) {
			i++;
			j++;
		}
		else {
			j = 0;
			i = i - j + 1;
		}
	}
	if (j >= P.length())
		return (i - j);
	else
		return -1;
}
int findPat_3(string S, string P, int startindex)
{
	int i, j;
	cout << "findPat_3(string S, string P, int startindex)" << endl;
	for (i = startindex; i <= (S.length()-P.length()); i++)
	{
		for (j = 0; ((j < P.length()) && (S[i + j] == P[j])); j++);
			if (j == P.length())
				return i;
	}
	return -1;
}

int KMPStrMatching(string T, string P, int *N,int start) {
	int j = 0;     //P的下标
	int i = start;   //S的下标
	int plen = P.length();
	int tlen = T.length();
	if (tlen - plen < start) {
		return -1;
	}
	while (j < plen&&i < tlen) {
		if (j == -1 || T[i] == P[j]) {
			i++;
			j++;
		}
		else {
			j = N[j];
		}
	}
	if (j >= plen) {
		return i - plen;
	}
	else return -1;
}
int* findNext(string P) {
	int j, k;
	int m = P.length();
	if (m < 0) {
		cout << "m should big than 0" << endl;
		return NULL;
	}
	int *next = new int[m];
	next[0] = -1;
	j = 0;
	k = -1;
	while (j < m - 1) {
		while (k >= 0 && P[k] != P[j])
		{
			k = next[k];
		}
		j++;
		k++;
		if (P[k] = P[j]) {
			next[j] = next[k];
		}
		else
			next[j] = k;
	}
	return next;
}

int main()
{
	bool res = strcmp2("1", "1");
	cout << res << endl; 
	res = strcmp2("12", "1");
	cout << res << endl;
	res = strcmp2("12", "123");
	cout << res << endl;
	int find = findPat_1("13456789023", "23", 0);
	cout << find << endl;
	find = findPat_2("13456789023", "23", 0);
	cout << find << endl;
	find = findPat_3("13456789023", "23", 0);
	cout << find << endl;
	string str = "12";
	int *N = findNext(str);
	find = KMPStrMatching("13445638585612", str, N, 0);
	cout << find << endl;
}