#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

PrefixMatcher::~PrefixMatcher() {
    // Implement destructor to free memory
}

void PrefixMatcher::insert(string address, int routerNumber) {
    TrieNode* node = root;
    for (char ch : address) {
        if (!node->children.count(ch)) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;
}

int PrefixMatcher::longestMatch(string address) {
    TrieNode* node = root;
    for (char ch : address) {
        if (!node->children.count(ch)) {
            return -1;
        }
        node = node->children[ch];
    }
    // Implement logic to find longest match
}

void PrefixMatcher::dfs(TrieNode* node, string address, vector<string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(address);
    }
    for (auto it : node->children) {
        dfs(it.second, address + it.first, suggestions);
    }
}
