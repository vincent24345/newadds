#include <iostream>
#include "PrefixMatcher.h"

int main() {
    PrefixMatcher prefixMatcher;

    //Addresses and their corresponding router numbers
    prefixMatcher.insert("192.168.1.1", 1);
    prefixMatcher.insert("192.168.1.2", 2);
    prefixMatcher.insert("192.168.2.1", 3);

    //Find the longest match for an address
    int routerNumber = prefixMatcher.longestMatch("192.168.1.1");
    if (routerNumber != -1) {
        cout << "The longest match for 192.168.1.1 is router number " << routerNumber << endl;
    } else {
        cout << "No match found for 192.168.1.1" << endl;
    }

    return 0;
}
