-// ============================================================
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

void huffmanCoding(vector<char>& chars, vector<int>& freqs) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes
    for (int i = 0; i < chars.size(); i++)
        pq.push(new Node(chars[i], freqs[i]));

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left  = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('$', left->freq + right->freq);
        merged->left  = left;
        merged->right = right;
        pq.push(merged);
    }

    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freqs  = { 5,   9,  12,  13,  16,  45};
    huffmanCoding(chars, freqs);
    return 0;
}
