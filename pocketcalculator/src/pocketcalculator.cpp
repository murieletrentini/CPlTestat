#include "src/calculator.h"
#include "src/display.h"
#include "pocketcalculator.h"
#include <iostream>

void pocketcalculator(std::istream & in, std::ostream & out){

	int result = calc(in);
	if (result == -1){
		printError(out);
		return;
	}
	printLargeNumber(result, out);

}