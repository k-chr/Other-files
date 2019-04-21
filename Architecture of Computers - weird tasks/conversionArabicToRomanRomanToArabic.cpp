//Kamil Chrustowski
#include <string>
#include <iostream>
using namespace std;
#define size_of_lts 13
static 	unsigned int look_up_int[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
static	string look_up_string[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
string convertion_arabic_to_roman(string& str_ar)
{
	unsigned int number = stoi(str_ar, NULL, 10);
	string str_ro = "";
	int i = 0;
	for(; number && i < size_of_lts;)
	{			
		if(number < look_up_int[i])
		{
			++i;
			continue;
		}
		str_ro += look_up_string[i];
		number -= look_up_int[i];
	}
	return str_ro;
}
string convertion_roman_to_arabic(string& str_ro)
{
	int i = size_of_lts - 1;
	int num = 0;
	int len = str_ro.length();
	for(;i > -1 && len >= 0;)
	{
		if(int(len - look_up_string[i].length()) < 0 || (str_ro.compare(len - look_up_string[i].length(), look_up_string[i].length(), look_up_string[i])))
		{
			--i;	
			continue;
		}
		num += look_up_int[i];
		len -= look_up_string[i].length();
	}
	return to_string(num);
}
int main()
{
	string output = "972";
	cout << convertion_arabic_to_roman(output) << endl;
	cout << convertion_roman_to_arabic(output = "MCMXVIII") << endl;
	return 0;
}
