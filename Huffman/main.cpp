#include "Huff.h"
#include <iostream>
#include <unordered_map>
#include <string>




int main() {
    Huff* tree = new Huff();
    std::string str = "sdfffrrrrhagjhyyysds";
    std::unordered_map<char, unsigned int> m = tree->caunt(str);
    Huff* root = Huff::root(m);
    for(Node* i = root->head; i != nullptr; i = i->right) {
        std::cout << i->data << ":" << i->fraq << std::endl;
    }
    delete tree;
    delete root;
    return 0;
}

