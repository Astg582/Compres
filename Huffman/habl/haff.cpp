// haff.cpp
#include "haff.h"

Huff::Node* Huff::insert(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

void Huff::encode(Huff::Node* root, const string &str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

char Huff::decode(Huff::Node* root, int& index, const string &str) {
	if (root == nullptr) return '0';

	if (!root->left && !root->right) {
		//cout << root->ch;
		return root->ch;
	}

	index++;

	if (str[index] == '0') {
		decode(root->left, index, str);
	} else {
		decode(root->right, index, str);
	}

}

string Huff::dec(Node* root, string &str){
	string res;
    int index = -1;
    while (index < (int)str.size() - 2) {
        res += decode(root, index, str);
    }
	return res;	
}



unordered_map<char, string> Huff::huffcode(Node* root){
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);
	return huffmanCode;
}
/*
std::bitset<256> Huff::code(const string &text,  unordered_map<char, string>& huffmanCode){
	std::bitset<256> bitsetStr;

	string str = "";
	for (const char ch : text) {
		str += huffmanCode[ch];
	}

	size_t j = str.length() - 1;
	size_t i = 254;
	while ( i >= 0) {
		if (str[j] == '1') {
			bitsetStr.set(i); 
		}
		--i;
		--j;
	}
	return bitsetStr;
}
*/
std::bitset<256> Huff::code(const std::string &text, std::unordered_map<char, std::string>& huffmanCode) {
    std::bitset<256> bitsetStr;

    std::string str = "";
    for (const char ch : text) {
        str += huffmanCode[ch];
    }

    // Устанавливаем биты в соответствии с битами из строки str
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '1') {
            bitsetStr.set(i);
        }
    }

    return bitsetStr;
}

void Huff::print(Node* root, unordered_map<char, string>& huffmanCode, const string &text){
    cout << "Huffman Codes are :\n"
         << '\n';
    for (const auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }
	 cout << "\nOriginal string was :\n"
         << text << '\n';

/*    string str = "";
    for (const char ch : text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n"
         << str << '\n';

 */

	
	 
	std::bitset<256> hcode = code(text, huffmanCode); 

	std::cout << hcode << std::endl; // str i poxaren 
/*	 cout << "\nDecoded string is: \n";
	 std::cout << dec(root, str) << std::endl; */
}



void Huff::buildHuffmanTree(string &text) {
	unordered_map<char, int> freq;
	for (const char ch : text) {
		freq[ch]++;
	}

	priority_queue<Node*, vector<Node*>, comp> pq;

	for (const auto pair : freq) {
		pq.push(insert(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1) {
		Node* left = pq.top();
		pq.pop();
		Node* right = pq.top();
		pq.pop();
		int sum = left->freq + right->freq;
		pq.push(insert('\0', sum, left, right));
	}
	
	Node* root = pq.top();
	unordered_map<char, string> huffmanCode = huffcode(root);    
	print(root, huffmanCode, text); 
}
//caunter avelacnel huffman classi mej ev hashvel da code functioni mej vorpeszi imanam ichqan e im code stacvel
