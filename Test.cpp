
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	cout<<input<<"\n";
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@',  '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));


	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													 "@-----------@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-----------@\n"
													 "@@@@@@@@@@@@@"));


	CHECK(nospaces(mat(3, 5,  '@', '-')) == nospaces("@@@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
													 "@@@"));


	CHECK(nospaces(mat(5, 3 , '@', '-')) == nospaces("@@@@@\n"
													 "@---@\n"
													 "@@@@@"));


	CHECK(nospaces(mat(19, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@\n"
													 "@-----------------@\n"
													 "@-@@@@@@@@@@@@@@@-@\n"
													 "@-----------------@\n"
													 "@@@@@@@@@@@@@@@@@@@"));


	CHECK(nospaces(mat(19, 5, '$', '+')) == nospaces("$$$$$$$$$$$$$$$$$$$\n"
													 "$+++++++++++++++++$\n"
													 "$-$$$$$$$$$$$$$$$-$\n"
													 "$+++++++++++++++++$\n"
													 "$$$$$$$$$$$$$$$$$$$"));


	CHECK(nospaces(mat(3, 3 , '@', '-')) == nospaces("@@@\n"
													 "@-@\n"
													 "@@@"));


	CHECK(nospaces(mat(5, 5 , '@', '-')) == nospaces("@@@@@\n"
													 "@---@\n"
													 "@-@-@\n"
													 "@---@\n"
													 "@@@@@"));


	CHECK(nospaces(mat(3, 3 , '$', '+')) == nospaces("$$$\n"
													 "$+$\n"
													 "$$$"));

	CHECK(nospaces(mat(5, 5 , '-', '@')) == nospaces("-----\n"
													 "-@@@-\n"
													 "-@-@-\n"
													 "-@@@-\n"
													 "-----"));                                                                                                                                        
    }

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    
    CHECK_THROWS(mat(5, 10, '$', '%'));

    CHECK_THROWS(mat(10, 10, '$', '%'));

    CHECK_THROWS(mat(8, 2, '$', '%'));

    CHECK_THROWS(mat(2, 8, '$', '%'));

    CHECK_THROWS(mat(0, 2, '$', '%'));

    CHECK_THROWS(mat(2, 0, '$', '%'));

    CHECK_THROWS(mat(8, 8, '$', '%'));

    CHECK_THROWS(mat(6, 4, '$', '%'));

    CHECK_THROWS(mat(12, 5, '$', '%'));

}


/* Add more test cases here */
