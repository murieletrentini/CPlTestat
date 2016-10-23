#include "pocketcalculator.h"

#include <src/calc.h>
#include <src/sevensegment.h>
#include <ostream>
#include <sstream>
#include <istream>

void pocketcalculator(std::istream & in, std::ostream & out) {
	std::string s { };
	while (std::getline(in, s)) {
		std::stringstream ss { s };
		int result = calc(ss);
		if (result == -1) {
			printError(out);
		} else {
			printLargeNumber(result, out);
		}
	}
}
