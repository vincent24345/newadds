#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>

class TrieNode {
public:
    TrieNode* children[26]; 
    std::vector<std::string> words;

    TrieNode();
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

#endif