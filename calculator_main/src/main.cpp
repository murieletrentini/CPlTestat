#include <iostream>
#include "src/pocketcalculator.h"
#include "src/display.h"
#include "src/calculator.h"

int main() {
	while (std::cin) {
		pocketcalculator(std::cin, std::cout);
		std::cout << '\n';
	}

}
