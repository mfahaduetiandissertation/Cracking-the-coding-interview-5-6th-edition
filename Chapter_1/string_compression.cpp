
#include <iostream>
#include <string>

using namespace std;

string compress(string& str)
{
	string out{};
	int count = 1;
	int i = 0;
	while (i < str.length()) {
		if (str[i] == str[i + 1]) {
			count++;
			i++;
		}
		else {
			out += str[i];
			out += to_string(count);
			i++;
			count = 1;
		}

	}
	return out;
}

int main()
{

	string str, out;
	cout << "Enter a string:\n";
	cin >> str;

	out = compress(str);

	if (str.compare(out)) {
		cout << str << " can be compressed to " << out << endl;
	}
	else {
		cout << str << " can not be compressed\n";
	}

	return 0;
}
