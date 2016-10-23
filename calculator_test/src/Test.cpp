#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <src/calc.h>
#include <src/sevensegment.h>
#include "src/pocketcalculator.h"

#include <istream>
#include <ostream>
#include <sstream>

std::string const error {
			" -             \n"
			"|              \n"
			" -  -  -  -  - \n"
			"|  |  |  | ||  \n"
			" -        -    \n" };

//--- test calculator.cpp ---
void testCalculator_plus() {
	ASSERT_EQUAL(2, calc(1, 1, '+'));
}

void testCalculator_minus_valid() {
	ASSERT_EQUAL(1, calc(2, 1, '-'));
}

void testCalculator_minus_invalid() {
	ASSERT_EQUAL(-1, calc(1, 2, '-'));
}

void testCalculator_multiplication() {
	ASSERT_EQUAL(10, calc(2, 5, '*'));
}

void testCalculator_evenDivision() {
	ASSERT_EQUAL(3, calc(6, 2, '/'));
}

void testCalculator_oddDivision() {
	ASSERT_EQUAL(2, calc(5, 2, '/'));
}

void testCalculator_div_by_zero() {
	ASSERT_EQUAL(-1, calc(1, 0, '/'));
}

void testCalculator_modulo() {
	ASSERT_EQUAL(0, calc(4, 2, '%'));
}

void testCalculator_modulo_by_zero() {
	ASSERT_EQUAL(-1, calc(1, 0, '%'));
}

void testCalculator_invalid_operator() {
	ASSERT_EQUAL(-1,calc(1, 1, ':'));
}

void testCalculator_calcstream() {
	std::stringstream ss {"1+2"};
	ASSERT_EQUAL(3, calc(ss));
}

void testCalculator_calcstream_invalidOperator() {
	std::stringstream ss { "1:2"};
	ASSERT_EQUAL(-1, calc(ss));
}

void testCalculator_calcstream_nonsenseInput() {
	std::stringstream ss { "Hello"};
	ASSERT_EQUAL(-1, calc(ss));
}

//--- test Display.cpp ---
void testDisplay_zero() {
	std::stringstream ss{};
	printLargeNumber(0, ss);
	std::string const result{
		" - \n"
		"| |\n"
		"   \n"
		"| |\n"
		" - \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_one() {
	std::stringstream ss{};
	printLargeNumber(1, ss);
	std::string const result{
		"   \n"
		"  |\n"
		"   \n"
		"  |\n"
		"   \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_two() {
	std::stringstream ss{};
	printLargeNumber(2, ss);
	std::string const result{
		" - \n"
		"  |\n"
		" - \n"
		"|  \n"
		" - \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_three() {
	std::stringstream ss{};
	printLargeNumber(3, ss);
	std::string const result{
		" - \n"
		"  |\n"
		" - \n"
		"  |\n"
		" - \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_four() {
	std::stringstream ss{};
	printLargeNumber(4, ss);
	std::string const result{
		"   \n"
		"| |\n"
		" - \n"
		"  |\n"
		"   \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_five() {
	std::stringstream ss{};
	printLargeNumber(5, ss);
	std::string const result{
		" - \n"
		"|  \n"
		" - \n"
		"  |\n"
		" - \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_six() {
	std::stringstream ss{};
	printLargeNumber(6, ss);
	std::string const result{
		" - \n"
		"|  \n"
		" - \n"
		"| |\n"
		" - \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_seven() {
	std::stringstream ss{};
	printLargeNumber(7, ss);
	std::string const result{
		" - \n"
		"  |\n"
		"   \n"
		"  |\n"
		"   \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_eight() {
	std::stringstream ss{};
	printLargeNumber(8, ss);
	std::string const result{
		" - \n"
		"| |\n"
		" - \n"
		"| |\n"
		" - \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_nine() {
	std::stringstream ss{};
	printLargeNumber(9, ss);
	std::string const result{
		" - \n"
		"| |\n"
		" - \n"
		"  |\n"
		" - \n"
	};
	ASSERT_EQUAL(result, ss.str());
}

void testDisplay_printError() {
	std::stringstream ss{};
	printError(ss);
	ASSERT_EQUAL(error, ss.str());
}

void testDisplay_validNumber() {
	std::stringstream ss {};
	printLargeNumber(1207, ss);
	std::string const result {
			"    -  -  - \n"
			"  |  || |  |\n"
			"    -       \n"
			"  ||  | |  |\n"
			"    -  -    \n" };
	ASSERT_EQUAL(result, ss.str());
}


//--- test pocketcalculator.cpp ---
void testPocketCalculator_plus() {
	std::stringstream in{"1+1"};
	std::stringstream out{};
	pocketcalculator(in, out);
	std::string const result{
			" - \n"
			"  |\n"
			" - \n"
			"|  \n"
			" - \n"
		};
	ASSERT_EQUAL(result, out.str());
}
void testPocketCalculator_minus_valid() {
	std::stringstream in{"3-1"};
	std::stringstream out{};
	pocketcalculator(in, out);
	std::string const result{
			" - \n"
			"  |\n"
			" - \n"
			"|  \n"
			" - \n"
		};
	ASSERT_EQUAL(result, out.str());
}

void testPocketCalculator_minus_invalid() {
	std::stringstream in{"1-2"};
	std::stringstream out{};
	pocketcalculator(in, out);
	ASSERT_EQUAL(error, out.str());
}

void testPocketCalculator_multiplication() {
	std::stringstream in{"1*2"};
	std::stringstream out{};
	pocketcalculator(in, out);
	std::string const result{
			" - \n"
			"  |\n"
			" - \n"
			"|  \n"
			" - \n"
		};
	ASSERT_EQUAL(result, out.str());
}

void testPocketCalculator_EvenDivision() {
	std::stringstream in{"8/4"};
	std::stringstream out{};
	pocketcalculator(in, out);
	std::string const result{
			" - \n"
			"  |\n"
			" - \n"
			"|  \n"
			" - \n"
		};
	ASSERT_EQUAL(result, out.str());
}

void testPocketCalculator_OddDivision() {
	std::stringstream in{"5/2"};
	std::stringstream out{};
	pocketcalculator(in, out);
	std::string const result{
			" - \n"
			"  |\n"
			" - \n"
			"|  \n"
			" - \n"
		};
	ASSERT_EQUAL(result, out.str());
}

void testPocketCalculator_div_by_zero() {
	std::stringstream in{"1/0"};
	std::stringstream out{};
	pocketcalculator(in, out);
	ASSERT_EQUAL(error, out.str());
}

void testPocketCalculator_modulo() {
	std::stringstream in{"8%3"};
	std::stringstream out{};
	pocketcalculator(in, out);
	std::string const result{
			" - \n"
			"  |\n"
			" - \n"
			"|  \n"
			" - \n"
		};
	ASSERT_EQUAL(result, out.str());
}

void testPocketCalculator_modulo_by_zero() {
	std::stringstream in{"1%0"};
	std::stringstream out{};
	pocketcalculator(in, out);
	ASSERT_EQUAL(error, out.str());
}

void testPocketCalculator_invalid_operator() {
	std::stringstream in{"1:0"};
	std::stringstream out{};
	pocketcalculator(in, out);
	ASSERT_EQUAL(error, out.str());
}

void testPocketCalculator_nonsenseInput() {
	std::stringstream in{"Hello"};
	std::stringstream out{};
	pocketcalculator(in, out);
	ASSERT_EQUAL(error, out.str());
}

void pocketcalculator_printTooLargeNumber() {
	std::stringstream in { "99999998+2" };
	std::stringstream out { };
	pocketcalculator(in, out);
	ASSERT_EQUAL(error, out.str());
}

void testPocketCalculator_testMultipleLines() {
	std::stringstream in{
			"1*2\n"
			"2%0\n"
			"12-10"};
	std::stringstream out{};
	pocketcalculator(in, out);
	std::stringstream const result{
		" - \n"
		"  |\n"
		" - \n"
		"|  \n"
		" - \n"
		" -             \n"
		"|              \n"
		" -  -  -  -  - \n"
		"|  |  |  | ||  \n"
		" -        -    \n"
		" - \n"
		"  |\n"
		" - \n"
		"|  \n"
		" - \n"
	};
	ASSERT_EQUAL(result.str(), out.str());
}


//--- run Tests ---
bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testCalculator_div_by_zero));
	s.push_back(CUTE(testCalculator_plus));
	s.push_back(CUTE(testCalculator_invalid_operator));
	s.push_back(CUTE(testCalculator_calcstream));
	s.push_back(CUTE(testCalculator_calcstream_invalidOperator));
	s.push_back(CUTE(pocketcalculator_printTooLargeNumber));
	s.push_back(CUTE(testCalculator_minus_valid));
	s.push_back(CUTE(testCalculator_minus_invalid));
	s.push_back(CUTE(testCalculator_multiplication));
	s.push_back(CUTE(testCalculator_modulo));
	s.push_back(CUTE(testCalculator_modulo_by_zero));
	s.push_back(CUTE(testCalculator_calcstream_nonsenseInput));
	s.push_back(CUTE(testCalculator_oddDivision));
	s.push_back(CUTE(testCalculator_evenDivision));
	s.push_back(CUTE(testDisplay_zero));
	s.push_back(CUTE(testDisplay_one));
	s.push_back(CUTE(testDisplay_two));
	s.push_back(CUTE(testDisplay_three));
	s.push_back(CUTE(testDisplay_four));
	s.push_back(CUTE(testDisplay_five));
	s.push_back(CUTE(testDisplay_six));
	s.push_back(CUTE(testDisplay_seven));
	s.push_back(CUTE(testDisplay_eight));
	s.push_back(CUTE(testDisplay_nine));
	s.push_back(CUTE(testDisplay_printError));
	s.push_back(CUTE(testDisplay_validNumber));
	s.push_back(CUTE(testPocketCalculator_plus));
	s.push_back(CUTE(testPocketCalculator_minus_valid));
	s.push_back(CUTE(testPocketCalculator_minus_invalid));
	s.push_back(CUTE(testPocketCalculator_multiplication));
	s.push_back(CUTE(testPocketCalculator_EvenDivision));
	s.push_back(CUTE(testPocketCalculator_OddDivision));
	s.push_back(CUTE(testPocketCalculator_div_by_zero));
	s.push_back(CUTE(testPocketCalculator_modulo));
	s.push_back(CUTE(testPocketCalculator_modulo_by_zero));
	s.push_back(CUTE(testPocketCalculator_invalid_operator));
	s.push_back(CUTE(testPocketCalculator_nonsenseInput));
	s.push_back(CUTE(testPocketCalculator_testMultipleLines));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
