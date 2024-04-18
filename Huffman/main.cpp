#include "Huff.h"
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string str;
    std::cout << "Enter text: ";
    std::getline(std::cin, str);
    Huff* tree = new Huff();

    std::unordered_map<char, unsigned int> m = tree->caunt(str);
    Huff* ro = Huff::rootf(m);

    for (Node* i = ro->head; i != nullptr; i = i->right) {
        std::cout << i->data << ":" << i->fraq << std::endl;
    }

    ro->create_tree();
   

    ro->print_leaves(ro->root);    
    
delete tree;
    delete ro;
    return 0;
}

