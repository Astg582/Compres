#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Huff{

struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

Node* getNode(char ch, int freq, Node* left, Node* right);

struct comp
{
	bool operator()(Node* l, Node* r)
	{
				return l->freq > r->freq;
	}
};

void encode(Node* root, string str, unordered_map<char, string> &huffmanCode);
void decode(Node* root, int &index, string str);
void buildHuffmanTree(string text);
}
