#include <stdexcept>
#include <regex>
#include <iostream>

int calc(int i, int j, char c) {
	switch (c) {
	case '+':
		return i + j;
	case '-':
		if (j > i){
			return -1;
		}
		return i - j;
	case '*':
		return i * j;
	case '/':
		if (j == 0) {
			return -1;
		}
		return i / j;
	case '%':
		if (j == 0) {
			return -1;
		}
		return i % j;
	default:
		return -1;
	}
}

int calc(std::istream& in) {
	int n1{}, n2{};
	char op{};
	in >> n1 >> op >> n2;
	return calc(n1,n2,op);
}

