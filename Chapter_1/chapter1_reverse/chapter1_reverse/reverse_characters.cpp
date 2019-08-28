#include <iostream>

using namespace std;

void reverse(char* s) {
	char *end,*beg;
	char tmp;
	end = s;
	beg = s;
	while (*end != '\0')//find end of the string
		end++;
	end--;//go back from the last character
	while (beg < end) {
		tmp = *beg;
		*beg++ = *end;
		*end-- = tmp;
	}
}

void printReverse(char* s) {
	char* end;
	end = s;
	while (*end != '\0')//find the last character
		end++;
	end--;// go back from the last character
	while (end != s) {
		cout << *end;
		end--;
	}
	cout << *end << endl;
}

int main() {
	char str[] = "reverse";
	char* pt = &str[0];
	reverse(pt);
	cout << str << endl;
	printReverse(pt);
	return 0;
}