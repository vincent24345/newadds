#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "Trie.h"
#include <string>
#include <vector>

class Autocomplete {
public:
    Autocomplete();
    ~Autocomplete();
    void insert(const std::string &word);
    std::vector<std::string> getSuggestions(const std::string &partialWord);

private:
    Trie* trie;
};

#endif // AUTOCOMPLETE_H
