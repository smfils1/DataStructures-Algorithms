#include <iostream>
#include <string>
using namespace std;

//Assignment 2: Samuel Fils

// Method 2:
// Move over the expression, read the numbers.
// Read operators, calculate the sum at the same time.

int calculate_sum( char *expr_ptr); 
char reading_operator( char *&expr_ptr, string &num);
int reading_operand( char *&expr_ptr, string &num);
int arithmetic(char opr, int operand, int sum);
char* user_input(string &str);


int main() {
	string str;	
	char *expr_ptr = user_input(str);
	int answer = calculate_sum(expr_ptr);
	cout << answer <<endl;
	system("pause");
	return 0;
}

char* user_input(string &str) {
	cout << "ENTER YOUR EXPRESSION" << endl;
	cin >> str;
	str += '\0';	
	return &str[0]  ;
}

int calculate_sum(char *expr_ptr) {
	char opr = '+';
	int sum = 0;
	string whole_number = "";
	while (*expr_ptr != '\0') {
		if (*expr_ptr == '-' || *expr_ptr == '+') {
			opr = reading_operator(expr_ptr, whole_number);
		}
		int  operand = reading_operand(expr_ptr, whole_number);
		sum = arithmetic(opr, operand, sum);
	}
	return sum;
}

char reading_operator(char *&expr_ptr, string &whole_num) {
	if (*expr_ptr == '-') {
		expr_ptr++;
		return '-';
	}
	else if (*expr_ptr == '+') {
		expr_ptr++;
		return '+';
	}
	return '+';
}

int reading_operand(char *&expr_ptr, string &whole_number) {
	whole_number += (int)*expr_ptr;
	expr_ptr++;
	if (*expr_ptr == '-' || *expr_ptr == '+' || *expr_ptr == '\0') {
		string num_copy = whole_number;
		whole_number = "";
		return stoi(num_copy);

	}
	return 0;
}

int arithmetic(char opr, int operand, int sum) {
	if (opr == '-') {		
		sum -= operand;
	}
	else {
		sum += operand;
	}
	return sum;
}


