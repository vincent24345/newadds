#include "Autocomplete.h"

TrieNode::TrieNode() {
    for (int i = 0; i < 26; ++i)
        childNodes[i] = nullptr;
}

Autocomplete::Autocomplete() {
    rootNode = new TrieNode();
}

Autocomplete::~Autocomplete() {
    delete rootNode; 
}

void Autocomplete::insert(std::string word) {
    TrieNode* currentNode = rootNode;
    for (char character : word) {
        if (!currentNode->childNodes[character - 'a']) {
            currentNode->childNodes[character - 'a'] = new TrieNode();
        }
        currentNode = currentNode->childNodes[character - 'a'];
    }
    currentNode->wordList.push_back(word);
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    TrieNode* currentNode = rootNode;
    for (char character : partialWord) {
        currentNode = currentNode->childNodes[character - 'a'];
        if (!currentNode) return {};
    }
    std::vector<std::string> result;
    traverseTrie(currentNode, result);
    return result;
}

void Autocomplete::traverseTrie(TrieNode* currentNode, std::vector<std::string>& result) {
    if (!currentNode) return;
    for (const std::string& word : currentNode->wordList) {
        result.push_back(word);
    }
    for (int i = 0; i < 26; i++) {
        traverseTrie(currentNode->childNodes[i], result);
    }
}
