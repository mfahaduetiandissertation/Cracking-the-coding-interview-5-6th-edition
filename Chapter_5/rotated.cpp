#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool isRotated(string s1, string s2) {
	int i1 = 1;
	string sb1, sb2, tstr;
	if (s1.length() != s2.length())
		return false;
	while (i1 < s2.length()) {
		tstr = s2.substr(i1, s2.length() - i1) + s2.substr(0, i1);
		if (s1.compare(tstr) == 0)
			return true;
		i1++;
	}

	return false;
}

int main() {

	cout << "Rotated" << endl;

	string str1 = "testest";
	string str2 = "esttest";

	if (isRotated(str1, str2))
		cout << "String 2 is rotated version of String 1" << endl;
	else
		cout << "String 2 is NOT rotated version of String 1" << endl;

	return 0;

}