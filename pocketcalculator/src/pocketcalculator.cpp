#include "src/calculator.h"
#include "src/display.h"
#include "pocketcalculator.h"
#include <ostream>
#include <sstream>
#include <istream>

void pocketcalculator(std::istream & in, std::ostream & out){
	while (in) {
			std::string s{};
			std::getline(in,s);
			std::stringstream ss{s};
			int result = calc(ss);
				if (result == -1){
					printError(out);
				}
				printLargeNumber(result, out);
			// std::cout << '\n';
		}
	int result = calc(in);
	if (result == -1){
		printError(out);
		return;
	}
	printLargeNumber(result, out);

}