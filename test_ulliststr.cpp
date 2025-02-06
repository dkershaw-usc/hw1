#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
void printItem(ULListStr*&);
void printList(ULListStr*&);
void printLine(int);
void debugPrint(std::string);
void initializeFromFile(std::string, ULListStr*&);
bool debugMode;

void printListIndex(ULListStr*& ulist, size_t idx);

int main(int argc, char* argv[])
{
    if(argc < 2) debugMode = true;

    ULListStr* a = new ULListStr();
    initializeFromFile("ulliststr", a); 
    printList(a);
    a->pop_front();
    printList(a);
    a->push_front("barnacle");
    printList(a);
    a->pop_back();
    // printList(a);
    debugPrint("line");

    while(!a->empty())
    {
        // printList(a);
        printListIndex(a, a->size()-1);
        a->pop_front();
    }


    return 0;
}

void initializeFromFile(std::string name, ULListStr*& ulist)
{
    std::ifstream ifs;
    ifs.open("selftest_" + name + ".txt");
    debugPrint("Reading from file: selftest_" + name + ".txt...");

    std::string temp;

    int i = 0;

    while(ifs.good())
    {
        std::getline(ifs,temp);
        ulist->push_back(temp);
        // debugPrint(ulist->front());
        // debugPrint(ulist->back());
        // //debugPrint(ulist->get(i));
        i++;
    }
    ifs.close();

    debugPrint("Initialized ulliststr from file.");
}

void debugPrint(std::string message)
{
    if(debugMode) 
    {
        if(message == "line")
        {
            printLine(40);
        }
        else std::cout << message << std::endl;
    }
}

void printLine(int width)
{
    for(int i = 0; i < width; i++)
    {
        std::cout << "_";
    }
    std::cout << std::endl;
}

void printList(ULListStr*& ulist)
{
    if(!debugMode) return;
    debugPrint((std::string) ulist->front());
    debugPrint(ulist->back());
}

void printListIndex(ULListStr*& ulist, size_t idx)
{
    debugPrint(ulist->get(idx));
}