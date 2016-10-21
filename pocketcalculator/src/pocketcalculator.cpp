#include "src/calculator.h"
#include "src/display.h"
#include "pocketcalculator.h"
#include <ostream>
#include <sstream>
#include <istream>

void pocketcalculator(std::istream & in, std::ostream & out) {
	while (in) {
		std::string s { };
		std::getline(in, s);
		std::stringstream ss { s };
		int result = calc(ss);
		if (result == -1) {
			printError(out);
		} else {
			printLargeNumber(result, out);
		}
		out << '\n';
	}
}
