#include <iostream>
#include "BSTSet.h"
#include "BSTMap.h"
#include "FileOperation.h"
#include "LinkedListMap.h"

void demo1();
void demo2();
void demo3();
void demo4();


int main()
{
    demo4();
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
//void demo2()
//{
//    std::cout << "a-tale-of-two-cities.txt" << std::endl;
//    vector<string> words;
//    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words)) {
//        std::cout << "Total words: " << words.size() << std::endl;
//        LinkedListSet<string> *bstSet = new LinkedListSet<string>();
//        for(string word : words) {
//            bstSet->add(word);
//        }
//        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
//        bstSet = nullptr;
//        delete bstSet;
//    }
//
//    std::cout << "pride-and-prejudice.txt" << std::endl;
//    vector<string> words1;
//    if (FileOps::readFile(".././pride-and-prejudice.txt", words1)) {
//        std::cout << "Total words: " << words1.size() << std::endl;
//        LinkedListSet<string> *bstSet = new LinkedListSet<string>();
//        for(string word : words1)
//        {
//            bstSet->add(word);
//        }
//        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
//        bstSet = nullptr;
//        delete bstSet;
//    }
//}
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
//void demo3()
//{
//    std::cout << "pride-and-prejudice.txt" << std::endl;
//    string filename = ".././pride-and-prejudice.txt";
//    BSTSet<string> *bstSet = new BSTSet<string>();
//    LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
//    double time1 = testSet(bstSet, filename);
//    std::cout << "BST Set : " << time1 << " s " << std::endl;
//    std::cout << "pride-and-prejudice.txt" << std::endl;
//    double time2 = testSet(linkedListSet, filename);
//    std::cout << "LinkedList Set : " << time2 << " s " << std::endl;
//}

void demo3()
{
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTMap<string,int> *bstMap = new BSTMap<string, int>();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words) {
            if (bstMap->contains(word)) {
                bstMap->set(word, bstMap->get(word) + 1);
            } else {
                bstMap->add(word, 1);
            }
        }
        std::cout << "Total different words: " << bstMap->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << bstMap->get("pride") << std::endl;
        std::cout << "Frequency of PREJUDICE: " << bstMap->get("prejudice") << std::endl;
    }
}
template<typename T>
double testMap(T *map, string filename) {
    clock_t startTime = clock();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for(string word : words) {
            if (map->contains(word)) {
                map->set(word, (map->get(word)) + 1);
            } else {
                map->add(word, 1);
            }
        }
        std::cout << "Total different words: " << map->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << (map->get("pride")) << std::endl;
        std::cout << "Frequency of PREJUDICE: " << (map->get("prejudice")) << std::endl;
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}
void demo4()
{
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTMap<string, int> *bstMap = new BSTMap<string, int>();
    float time1 = testMap(bstMap, filename);
    std::cout << "BSTMap time : " << time1 << " s " << std::endl;
    std::cout << "pride-and-prejudice.txt" << std::endl;
    LinkedListMap<string, int> *linkedListMap = new LinkedListMap<string, int>();
    float time2 = testMap(linkedListMap,filename);
    std::cout << "LinkedListMap time : " << time2 << " s " << std::endl;
}