#ifndef _HUFF_H_
#define _HUFF_H_

#include <unordered_map>
#include <string>

class Node {
public:
    char data;
    unsigned int fraq;
    Node* left;
    Node* right;

    Node(char d, unsigned int f);
};

class Huff {
public:
    Node* head;

    Huff();
    Huff(const Huff&) = delete;
    Huff(Huff&& rhv);
    Huff& operator=(Huff&& rhv);
    ~Huff();

    void insert(char newData, unsigned int newFraq);
    static Huff* root(std::unordered_map<char, unsigned int> m);
    std::unordered_map<char, unsigned int> caunt(const std::string& str);
};

#include "Huff.cpp"
#endif // _HUFF_H_

