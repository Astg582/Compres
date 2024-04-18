#include "Huff.h"
#include <iostream>
Node::Node(): data(), fraq(), left(nullptr), right(nullptr) {}
Node::Node(char d, unsigned int f) : data(d), fraq(f), left(nullptr), right(nullptr) {}

Huff::Huff() : head(nullptr) {}

Huff::Huff(Huff&& rhv) : head(rhv.head) {
    rhv.head = nullptr;
}

Huff& Huff::operator=(Huff&& rhv) {
    if (this != &rhv) {
        head = rhv.head;
        rhv.head = nullptr;
    }
    return *this;
}

void Huff::clear(Node* cur) {
    if (cur) {
        clear(cur->left);
        clear(cur->right);
        delete cur;
    }
}

Huff::~Huff() {
    if (head) {
        Node* cur = head;
        clear(cur);
        head = nullptr;
    }
}

void Huff::insert(char newData, unsigned int newFraq) {
    Node* newNode = new Node(newData, newFraq);

    if (!head) {
        head = newNode;
        return;
    }

    if (newNode->fraq < head->fraq || (newNode->fraq == head->fraq && newNode->data < head->data)) {
        newNode->right = head;
        head = newNode;
        return;
    }

    Node* cur = head;

    while (cur->right && (newNode->fraq > cur->right->fraq || (newNode->fraq == cur->right->fraq && newNode->data > cur->right->data))) {
        cur = cur->right;
    }

    newNode->right = cur->right;
    cur->right = newNode;
}

Huff* Huff::rootf(std::unordered_map<char, unsigned int> m) {
    Huff* res = new Huff();
    for (const auto& pair : m) {
        res->insert(pair.first, pair.second);
    }
    return res;
}

std::unordered_map<char, unsigned int> Huff::caunt(const std::string& str) {
    std::unordered_map<char, unsigned int> m;
    for (char c : str) {
        m[c] += 1;
    }
    return m;
}

void Huff::print_leaves(Node* n, int depth){
    if (!n) {
        return;
    }

    if (!n->left && !n->right) {
        std::cout << "Leaf: " << n->data << std::endl;
    }
	
    print_leaves(n->left, depth + 1);
    print_leaves(n->right, depth + 1);
}


void Huff::create_tree() {
    if (!this->head) {
        return; 
    }
	unordered_map<char, string> m;
	for(Node* i; i != nullptr; i = i->right){
	m[i->data] = 0;
	} 

    Node* cur = this->head;
    while (cur) {
        Node* ptr = new Node(); 

        if (cur->right) {
            if (cur->right->right) {
                ptr->left = cur;
                ptr->right = cur->right;
	
                if (!this->root) {
                    this->root = new Node();
                }
                this->root->left = ptr;
		
                cur = cur->right->right;
            } else {
                if (!this->root->left) {
                    this->root->left = cur;
                    this->root->right = cur->right;
                } else if (!this->root->right) {
                    ptr->left = cur;
                    ptr->right = cur->right;
                    this->root->right = ptr;
                } else {
                    cur->left = this->root;
                    cur->right = ptr;
                    this->root = cur;
                }
                cur = nullptr; 
            }
        } else {
            return ;
        }
    }
	
}












