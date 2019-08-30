#include <iostream>
using namespace std;

void urlify(char *str, int len)
{
	//count white spaces
	int spc = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ')
			spc++;
	}
	int t_len = len + 2 * spc;
	for (int j = len - 1; j > 0; j--) {//copy the letters to new locations
		if (str[j] != ' ') {
			str[t_len - 1] = str[j];
			t_len--;
		}
		else {
			str[t_len-1] = '0';
			str[t_len-2] = '2';
			str[t_len-3] = '%';
			t_len -= 3;
		}
	}
}

void urlify2(string& str)//string implementation
{
	int i = 0;
	while (i < str.length()) {
		if (str[i] == ' ') {
			str.erase(i,1);
			str.insert(i, "%20");
			i += 2;
		}
		else
		{
			i++;
		}
	}
}

int main()
{	
	//pointer to character array implementation
    char str[] = "Mr John Smith    ";  
    std::cout << "Actual string   : " << str << std::endl;
    urlify(str, 13);                                        
    std::cout << "URLified string : " << str << std::endl;

	//string implentation
	string str1 = "Mr John Smith"; 
	std::cout << "Actual string   : " << str1 << std::endl;
	urlify2(str1);                                        //Length of "Mr John Smith" = 13
	std::cout << "URLified string : " << str1 << std::endl;
    return 0;
}
