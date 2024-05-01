// haff.h
#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <bitset>

using namespace std;

class Huff {
	struct Node {
		char ch;
		int freq;
		Node* left;
		Node* right;
	};
	struct comp {
		bool operator()(Node* l, Node* r) {
			return l->freq > r->freq;
		}
	};
	Node* insert(char ch, int freq, Node* left, Node* right);
	void encode(Node* root, const string &str, unordered_map<char, string>& huffmanCode);
	
	unordered_map<char, string> huffcode(Node* root);
	void print(Node* root, unordered_map<char, string>& huffmanCode, const string &text);

	public:
	std::bitset<256> code(const string &text,  unordered_map<char, string>& huffmanCode);
	char decode(Node* root, int& index, const string &str);
	string dec(Node* root, string &str);
	void buildHuffmanTree(string &text);
};

