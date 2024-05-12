#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() {
    Root_Node = new TrieNode();
}

PrefixMatcher::~PrefixMatcher() {
}

void PrefixMatcher::insert(const std::string& address, int routerNumber) {
    TrieNode* node = Root_Node;
    for (char c : address) {
        int index = c - '0';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->Router_Number = routerNumber;
}

int PrefixMatcher::selectRouter(const std::string& networkAddress) {
    return longestPrefixMatch(Root_Node, networkAddress, 0);
}

int PrefixMatcher::longestPrefixMatch(TrieNode* node, const std::string& networkAddress, int index) {
    if (!node) return -1;
    if (index == networkAddress.size()) return node->Router_Number;
    int childIndex = networkAddress[index] - '0';
    if (node->children[childIndex]) {
        int routerNumber = longestPrefixMatch(node->children[childIndex], networkAddress, index + 1);
        if (routerNumber != -1) return routerNumber;
    }
    return node->Router_Number;
}
