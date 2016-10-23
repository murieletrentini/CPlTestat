#include "sevensegment.h"

#include <ostream>
#include <vector>
#include <string>
#include <algorithm>

const std::vector<std::vector<std::string>> DIGITS{
{" - ", "   ", " - ", " - ", "   ", " - ", " - ", " - ", " - ", " - ", " - ", "   ", "   "},
{"| |", "  |", "  |", "  |", "| |", "|  ", "|  ", "  |", "| |", "| |", "|  ", "   ", "   "},
{"   ", "   ", " - ", " - ", " - ", " - ", " - ", "   ", " - ", " - ", " - ", " - ", " - "},
{"| |", "  |", "|  ", "  |", "  |", "  |", "| |", "  |", "| |", "  |", "|  ", "|  ", "| |"},
{" - ", "   ", " - ", " - ", "   ", " - ", " - ", "   ", " - ", " - ", " - ", "   ", " - "}
};

int const displayWidth{8};

void printError(std::ostream &out){
	std::vector<int> error{10,11,11,12,11};
	std::for_each(begin(DIGITS),end(DIGITS),
				[&out, error](auto x){
				std::for_each(begin(error), end(error), [&out, x](auto y){
					out << x.at(y);
				});
				out << '\n';
		});
}

void printLargeNumber(int i, std::ostream &out){
	//zugriff wie arr von char   "264"
	//'1'-'0'=1
	std::string number = std::to_string(i);
	if (number.length() > displayWidth){
		printError(out);
		return;
	}
	std::for_each(begin(DIGITS),end(DIGITS),
			[&out, number](auto x){
			std::for_each(begin(number), end(number), [&out, x](auto y){
				out << x.at(y-'0');
			});
			out << '\n';
	});
}

void printLargeDigit(int i, std::ostream &out){
	std::for_each(begin(DIGITS),end(DIGITS),
			[i, &out](auto x){out << x.at(i)<<'\n';});
}