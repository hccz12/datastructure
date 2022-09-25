#include<iostream>
using namespace std;
class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        Trie* node = this;
        for (char c : word)
        {
            if (node->next[c - 'a'] == NULL) return false;
            node = node->next[c - 'a'];
        }
        return node->isEnd;
    }
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix)
        {
            if (node->next[c - 'a'] == NULL) return false;
            node = node->next[c - 'a'];
        }
        return true;
    }
};
//leetcode
class WordDictionary {
private:
    bool isEnd;
    WordDictionary* next[26];
public:
    WordDictionary() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    void addWord(string word) {
        WordDictionary* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new WordDictionary();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        WordDictionary* node = this;
        return backtrace(word, 0, node);
    }
    bool backtrace(string word, int pos, WordDictionary* node) {
        if (pos >= word.size()) 
            return node->isEnd;
        if (word[pos] != '.' && node->next[word[pos] - 'a'] == NULL) 
            return false;
        if (word[pos] != '.') 
            return backtrace(word, pos + 1, node->next[word[pos] - 'a']);
        for (int i = 0; i < 26; i++)
        {
            if (node->next[i])
                if (backtrace(word, pos + 1, node->next[i])) return true;
        }
        return false;
    }
};