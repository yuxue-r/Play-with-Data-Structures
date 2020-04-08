#include <iostream>
#include "BSTSet.h"
#include "LinkedListSet.h"
#include "FileOperation.h"

void demo1();
void demo2();
void demo3();


int main()
{
    demo3();
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
template<typename T>
double testSet(T *set, string filename) {
    clock_t startTime = clock();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for(string word : words) {
            set->add(word);
        }
        std::cout << "Total different words: " << set->getSize() << std::endl;
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}
void demo3()
{
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTSet<string> *bstSet = new BSTSet<string>();
    LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
    double time1 = testSet(bstSet, filename);
    std::cout << "BST Set : " << time1 << " s " << std::endl;
    std::cout << "pride-and-prejudice.txt" << std::endl;
    double time2 = testSet(linkedListSet, filename);
    std::cout << "LinkedList Set : " << time2 << " s " << std::endl;
}