#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <vector>

class TrieNode {
public:
    TrieNode* children[2]; //binary IP addresses
    int routerNumber;
};

class PrefixMatcher {
private:
    TrieNode* root;
    int longestPrefixMatch(TrieNode* node, const std::string& networkAddress, int index);
public:
    PrefixMatcher();
    ~PrefixMatcher();
    void insert(const std::string& address, int routerNumber);
    int selectRouter(const std::string& networkAddress);
};

#endif