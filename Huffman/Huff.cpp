#include "Huff.h"

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

Huff* Huff::root(std::unordered_map<char, unsigned int> m) {
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


