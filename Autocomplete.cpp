#include "Autocomplete.h"

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

Autocomplete::~Autocomplete() {
    // TODO: Implement destructor to free memory
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
    dfs(node, res);
    return res;
}

void Autocomplete::dfs(TrieNode* node, std::vector<std::string>& res) {
    if (!node) return;
    for (std::string word : node->words) {
        res.push_back(word);
    }
    for (int i = 0; i < 26; i++) {
        dfs(node->children[i], res);
    }
}
