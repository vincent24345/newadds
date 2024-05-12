#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
};

class Trie {
public:
    Trie();
    ~Trie();
    void insert(const std::string &word);
    std::vector<std::string> getSuggestions(const std::string &partialWord);

private:
    TrieNode* root;
    void getSuggestionsHelper(TrieNode* node, std::string current, std::vector<std::string>& suggestions);
};

#endif // TRIE_H
