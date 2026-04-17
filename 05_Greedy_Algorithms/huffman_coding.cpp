// ============================================================
// FILE: huffman_coding.cpp
// TOPIC: Huffman Encoding
// TIME:  O(n log n)
// SPACE: O(n)
// GREEDY CHOICE: Always merge two nodes with lowest frequency
// USE:   Data compression (ZIP, JPEG, MP3)
// ============================================================
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Min heap
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;
    if (!root->left && !root->right)
        cout << root->ch << " → " << code << "\n";
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

