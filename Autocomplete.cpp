#include "Autocomplete.h"

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

Autocomplete::~Autocomplete() {
}

void Autocomplete::insert(std::string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c - 'a']) {
            node->children[c - 'a'] = new TrieNode();
        }
        node = node->children[c - 'a'];
        node->words.push_back(word);
    }
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    TrieNode* node = root;
    for (char c : partialWord) {
        node = node->children[c - 'a'];
        if (!node) return {};
    }
    std::vector<std::string> res;
    dfs(node, res, partialWord);
    return res;
}

void Autocomplete::dfs(TrieNode* node, std::vector<std::string>& res, const std::string& prefix) {
    if (!node) return;
    for (std::string word : node->words) {
        if (word.substr(0, prefix.size()) == prefix) {
            res.push_back(word);
        }
    }
    for (int i = 0; i < 26; i++) {
        dfs(node->children[i], res, prefix);
    }
}
