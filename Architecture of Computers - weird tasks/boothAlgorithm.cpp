#include<iostream>
#include<string>
#include<cmath>
#define number_of_bytes 8
using namespace std;
string dec2binu2(char num){
	string str = string(number_of_bytes, '0');
	for(int i = number_of_bytes - 1; i >= 0; str[i] = (num&1) + '0', num>>=1, --i);
	return str;
}
double u2bin2dec(const string& num){
	double x = 0; int bytes = num.length(), is_minus = num[0] == '1' ? -1 : 1;
	for(int i =0; i < bytes;  (num[i] == '1' ? x += is_minus * pow(2, bytes - 1 - i) : false), is_minus = 1, ++i);
	return x;
}
string negate_u2(string str){
	for(int i = number_of_bytes - 1, logic = 0; i >= 0; !logic && str[i] == '0'? --i : (!logic ? (logic = 1, i -= 1) : ((str[i] = str[i] == '1' ? '0' : '1'), --i)));
	return str;
}
void shift(string& A, string& Q, bool& zero){
	for(int i = number_of_bytes - 1, set = 0, end = A[number_of_bytes - 1]; i >= 1; !set ? (zero = !(Q[number_of_bytes - 1] - '0'),	set = 1) : 1, (A[i] = A[i - 1]), (Q[i] = Q[i - 1]),
	 --i, (!i ? (Q[0] = char(end)) : 1));
}
void sum(string& dest, const string& src){
	for(int i = number_of_bytes - 1, carry = 0, logic1, logic2; i >= 0; logic1 = dest[i] - '0', logic2 = src[i] - '0', dest[i] = ((logic1 + logic2 + carry) % 2) + '0', 
	carry = (logic1 + logic2 + carry) > 1, --i);
}
void print_op(const string& num1, const string& num2, const string& operation, bool zero){
	cout << num1 << "|" <<num2 << (zero ? "| 0 " : "| 1 ") << "|" << operation << endl;
}
void booth_algorithm(char num1, char num2){
	string M = dec2binu2(num1), Q = dec2binu2(num2), A = string(number_of_bytes, '0'); bool zero = true, end_Q = (Q[Q.length() - 1] == '0');
	cout << (int)num1 << " * " << (int)num2 << " = " << num1 * num2 << endl << "M = " << M << endl << "Q = " << Q << endl <<"   A    " << "    Q    "<< " Q-1 " << " op" << endl;
	print_op(A,Q, "", zero);
	for(unsigned char shifts = 0; shifts < number_of_bytes; !(zero^end_Q) ? (shift(A,Q,zero),print_op(A, Q, "->", zero), 1) : (sum(A, zero ? negate_u2(M) : M),
	print_op(A, Q, zero ? "-M" : "+M", zero),shift(A,Q,zero),  print_op(A, Q, "->", zero) , 0), end_Q = (Q[Q.length() - 1] == '0'), ++shifts);
 	cout << A + Q << " = " << u2bin2dec(A + Q) << endl;
}
int main(){
	booth_algorithm(8,-13);
	return 0;
}