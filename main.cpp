#include "Autocomplete.h"
#include <iostream>

int main() {
    Trie trie;
    trie.insert("bin");
    trie.insert("ball");
    trie.insert("ballet");

    std::vector<std::string> suggestions = trie.getSuggestions("ba");
    for (const std::string& word : suggestions) {
        std::cout << word << std::endl;
    }

    return 0;
}
