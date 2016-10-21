#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "src/calculator.h"
#include "src/pocketcalculator.h"
#include "src/display.h"

#include <iostream>

void test_one_plus_one() {
	auto result = calc(1, 1, '+');
	ASSERT_EQUAL(2, result);
}

void test_div_by_zero() {
	ASSERT_EQUAL(calc(1, 0, '/'), -1);
}

void test_invalid_operator() {
	ASSERT_EQUAL(calc(1, 1, ':'), -1);
}

void test_calcstream() {
	std::stringstream ss { };
	ss.str("1+2");
	auto result = calc(ss);
	ASSERT_EQUAL(3, result);
}

void test_calcstream_fail() {
	std::stringstream ss { };
	ss.str("1:2");
	ASSERT_EQUAL(-1, calc(ss));
}

void testDisplay_printDigit() {
	std::stringstream ss { };
	printLargeDigit(8, ss);
	ASSERT_EQUAL(
			" - \n"
			"| |\n"
			" - \n"
			"| |\n"
			" - \n", ss.str());
}

void testDisplay_printNumber() {
	std::stringstream ss { };
	printLargeNumber(12, ss);
	std::string result {
			"    - \n"
			"  |  |\n"
			"    - \n"
			"  ||  \n"
			"    - \n" };
	ASSERT_EQUAL(result, ss.str());
}

void pocketcalculator_validInput(){
	std::stringstream in {"2*6"};
	std::stringstream out {};
	pocketcalculator(in, out);
	std::string result {
				"    - \n"
				"  |  |\n"
				"    - \n"
				"  ||  \n"
				"    - \n" };
	ASSERT_EQUAL(result, out.str());
}

void pocketcalculator_invalidInput(){
	std::stringstream in {"3:5"};
	std::stringstream out {};
	std::string error{
			" -             \n"
			"|              \n"
			" -  -  -  -  - \n"
			"|  |  |  | ||  \n"
			" -        -    \n"
		};
	pocketcalculator(in, out);
	ASSERT_EQUAL(error, out.str());
}

void pocketcalculator_printTooLargeNumber(){
	std::stringstream in {"99999998+2"};
	std::stringstream out {};
	std::string error{
			" -             \n"
			"|              \n"
			" -  -  -  -  - \n"
			"|  |  |  | ||  \n"
			" -        -    \n"
		};
	pocketcalculator(in, out);
	ASSERT_EQUAL(error, out.str());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_div_by_zero));
	s.push_back(CUTE(test_one_plus_one));
	s.push_back(CUTE(test_invalid_operator));
	s.push_back(CUTE(test_calcstream));
	s.push_back(CUTE(test_calcstream_fail));
	s.push_back(CUTE(testDisplay_printDigit));
	s.push_back(CUTE(testDisplay_printNumber));
	s.push_back(CUTE(pocketcalculator_validInput));
	s.push_back(CUTE(pocketcalculator_invalidInput));
	s.push_back(CUTE(pocketcalculator_printTooLargeNumber));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
