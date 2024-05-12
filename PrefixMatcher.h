#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
};

class PrefixMatcher {
public:
    PrefixMatcher();
    ~PrefixMatcher();
    void insert(string address, int routerNumber);
    int longestMatch(string address);

private:
    TrieNode* root;
    void dfs(TrieNode* node, string address, vector<string>& suggestions);
};
