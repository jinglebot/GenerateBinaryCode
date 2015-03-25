/*
 * File: GenerateBinaryCode.cpp
 * -------------------------------
 * Name: jinglebot
 * Date started: March 24, 2015
 * Date finished: March 25, 2015
 *
 * This program prints all possible unique n-digit
 * binary numbers.
 *
 * Note: Add the line to your .pro file if using Qt
 *          Creator for the 'for' loop
 *      CONFIG += c++11
 *
 */


#include <iostream>
#include <set>
using namespace std;


/* Prototypes */

set <string> setBinaries( string, int, set <string> & );
void generateBinaryCode( int );


/* Main Program */

int main() {
    int nBits = 4;

    generateBinaryCode( nBits );

    return 0;
}


/* Function: generateBinaryCode
 * Usage: generateBinaryCode (nBits)
 * ----------------------------------
 * This function initializes a string with n-number
 * of digits and is wrapper function for setBinaries.
 */

void generateBinaryCode( int nBits )
{
    string zero = "0";
    string bits = "";
    set <string> binaries;

    for (int j = 0; j < nBits; ++j) bits += zero;
    binaries.insert(bits);

    setBinaries( bits, nBits, binaries );
    for (string str : binaries) {
        cout << str << endl;
    }
    cout << endl;
}


/* Function: setBinaries
 * Usage: setBinaries (bits, nBits, binaries)
 * --------------------------------------------
 * This is a recursion function that shows the
 * permutation of n-digit binary numbers.
 */

set <string> setBinaries( string bits, int nBits, set <string> &binaries )
{
    char one = '1';

    if (nBits <= 0) return binaries;

    for (int i = 0; i < bits.size(); ++i) {
        string bits2 = bits.substr(0, i) + one + bits. substr(i+1);
        binaries.insert(bits2);
        setBinaries(bits2, nBits-1, binaries);
    }

    return binaries;
}


