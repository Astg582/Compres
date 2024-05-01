// main.cpp
#include "haff.h"

int main() {
    string text = "Hello how are you 65";

    Huff huff;
    huff.buildHuffmanTree(text);

    return 0;
}

