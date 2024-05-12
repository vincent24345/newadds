#include "Trie.h"
#include <iostream>

// Constructor
Trie::Trie() {
    root = new TrieNode();
}

// Destructor
Trie::~Trie() {
    delete root;
}

// Insert a word into the Trie
void Trie::insert(const std::string &word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children[c - 'a'] == nullptr) {
            node->children[c - 'a'] = new TrieNode();
        }
        node = node->children[c - 'a'];
    }
    node->isEndOfWord = true;
}

// Get suggestions that start with a partial word
std::vector<std::string> Trie::getSuggestions(const std::string &partialWord) {
    std::vector<std::string> suggestions;
    TrieNode* node = root;
    for (char c : partialWord) {
        if (node->children[c - 'a'] == nullptr) {
            return suggestions;
        }
        node = node->children[c - 'a'];
    }
    getSuggestionsHelper(node, partialWord, suggestions);
    return suggestions;
}

// Helper function to get suggestions
void Trie::getSuggestionsHelper(TrieNode* node, std::string current, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(current);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            getSuggestionsHelper(node->children[i], current + (char)(i + 'a'), suggestions);
        }
    }
}
