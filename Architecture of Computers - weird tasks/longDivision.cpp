//CA task3; disclaimer: all numbers are signed!!!!
#include<iostream>
#include<string>
#define precision 100
using namespace std;
void negate_u2(string& str){
	for(int i = str.length() - 1, logic = 0; i >= 0; !logic && str[i] == '0'? --i : (!logic ? (logic = 1, i -= 1) : ((str[i] = str[i] == '1' ? '0' : '1'), --i)));
}
void add_extra_zero(string& str){
	for(int i = 4, len = str.length(); i < len ? 1 : (str.insert(0, i - len, '0'), 0); i <<= 2);
}
void equalite_fraternite_liberte(string& str, string& other){
	int len1 = str.length(), len2 = other.length(), diff = len1 - len2, which = diff > 0 ? 1 : (diff ? ((diff = -diff), -1) : 0);
	which == 1 ? (other.insert(0, diff, '0'), 1) : (!which ? 0 : str.insert(0, diff, '0'), 1);
}
void sum(string& dest, const string& src){
	for(int i = dest.length() - 1, carry = 0, logic1, logic2; i >= 0; logic1 = dest[i] - '0', logic2 = src[i] - '0', dest[i] = ((logic1 + logic2 + carry) % 2) + '0', 
	carry = (logic1 + logic2 + carry) > 1, --i);
}
string div(string dividend, string divisor){
	bool neg = (dividend[0] == '1' ? negate_u2(dividend), 1 : 0) ^ (divisor[0] == '1' ? negate_u2(divisor), 1 : 0), comma = false, end = false;
	add_extra_zero(dividend); add_extra_zero(divisor);
	int index = 0, pos = 0, len1 = dividend.length(), len2 = divisor.length(), greater = len1 > len2;
	string res = "", tmp = greater ? dividend.substr(pos, len2) : dividend.substr(pos, len1), n_divisor = divisor.substr(0, len2);
	negate_u2(n_divisor); equalite_fraternite_liberte(tmp, divisor);
	for(int i = 0; !end && i < precision; (tmp >= divisor ? sum(tmp, n_divisor), true : false), tmp.erase(0,1), (tmp += (pos + len2 < len1 ? dividend[pos + len2] : '0'),
	res += '1' : res += '0'), tmp.find('1') == string::npos ? end = true : (pos + len2 >= len1 ? (!comma ? comma = true) : true) ,comma ? (++i, 1) : (++pos, 0));
	comma ? res.insert(index, 1, ','), 1 : 0;
	neg ? negate_u2(res), 1 : 0;
	return res;
}
void main(){
	cout << div("01010",
	"010") << endl;
}