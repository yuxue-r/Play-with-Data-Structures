#include <iostream>
#include "BSTSet.h"
#include "LinkedListSet.h"
#include "FileOperation.h"

void demo1();
void demo2();


int main()
{
    demo2();
    return 0;
}
void demo1()
{
    std::cout << "a-tale-of-two-cities.txt" << std::endl;
    vector<string> words;
    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        BSTSet<string> *bstSet = new BSTSet<string>();
        for(string word : words) {
            bstSet->add(word);
        }
        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
        bstSet = nullptr;
        delete bstSet;
    }

    std::cout << "pride-and-prejudice.txt" << std::endl;
    vector<string> words1;
    if (FileOps::readFile(".././pride-and-prejudice.txt", words1)) {
        std::cout << "Total words: " << words1.size() << std::endl;
        BSTSet<string> *bstSet = new BSTSet<string>();
        for(string word : words1) {
            bstSet->add(word);
        }
        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
        bstSet = nullptr;
        delete bstSet;
    }
}
void demo2()
{
    std::cout << "a-tale-of-two-cities.txt" << std::endl;
    vector<string> words;
    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        LinkedListSet<string> *bstSet = new LinkedListSet<string>();
        for(string word : words) {
            bstSet->add(word);
        }
        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
        bstSet = nullptr;
        delete bstSet;
    }

    std::cout << "pride-and-prejudice.txt" << std::endl;
    vector<string> words1;
    if (FileOps::readFile(".././pride-and-prejudice.txt", words1)) {
        std::cout << "Total words: " << words1.size() << std::endl;
        LinkedListSet<string> *bstSet = new LinkedListSet<string>();
        for(string word : words1) {
            bstSet->add(word);
        }
        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
        bstSet = nullptr;
        delete bstSet;
    }
}