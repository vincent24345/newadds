#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>

class TrieNode {
public:
    TrieNode* children[26]; // Assuming only lowercase English letters
    std::vector<std::string> words;
};

class Autocomplete {
private:
    TrieNode* root;
    void dfs(TrieNode* node, std::vector<std::string>& res);
public:
    Autocomplete();
    ~Autocomplete();
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);
};


#endif // AUTOCOMPLETE_H
