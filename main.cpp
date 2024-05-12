#include "Autocomplete.h"
#include <iostream>
using namespace std;
int main() {
    Autocomplete autocomplete;
    autocomplete.insert("win");
    autocomplete.insert("winning");
    autocomplete.insert("wine");
    autocomplete.insert("winnable");

    vector<string> suggestions = autocomplete.getSuggestions("wi");
    for (string word : suggestions) {
        cout << word << endl;
    }

    return 0;
}
