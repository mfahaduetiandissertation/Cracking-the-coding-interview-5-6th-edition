#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

bool isunq(const string& str) {
	//check each character in a set and sees if each new character being checked
	//is already there. If not, then add it and repeat till the whole string is checked
	set<char> letters;
	set<char>:iterator it;
	if (str.length() > 128) {
		return false;
	}
	for (int i = 0; i < str.length(); i++) {
		it = find(letters.begin(), letters.end(), str[i]);
		if (it != letters.end())
			return false;
		letters.insert(str[i]);
	}
	return true;
}
bool isUniqueChars(const string& str) {
	//makes a vector of 128 booleans and sets the position to 1
	//if it is found again, then returns false
	if (str.length() > 128) {
		return false;
	}
	vector<bool> char_set(128);
	for (int i = 0; i < str.length(); i++) {
		int val = str[i];
		if (char_set[val]) {
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

bool isUniqueChars_bitvector(const string& str) {
	//Reduce space usage by a factor of 8 using bitvector. 
	//Each boolean otherwise occupies a size of 8 bits.
	bitset<256> bits(0);
	for (int i = 0; i < str.length(); i++) {
		int val = str[i];
		if (bits.test(val) > 0) {
			return false;
		}
		bits.set(val);
	}
	return true;
}
bool isUniqueChars_noDS(const string& str) {
	for (int i = 0; i < str.length() - 1; i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] == str[j]) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	vector<string> words = { "abcde", "hello", "apple", "kite", "padle" };
	for (auto word : words)
	{
		cout << word << string(": ") << boolalpha << isunq(word) << endl;
	}
	cout << endl << "Using bit vector" << endl;
	for (auto word : words)
	{
		cout << word << string(": ") << boolalpha << isUniqueChars_bitvector(word) << endl;
	}
	cout << endl << "Using no Data Structures" << endl;
	for (auto word : words)
	{
		cout << word << string(": ") << boolalpha << isUniqueChars_bitvector(word) << endl;
	}
	return 0;
}