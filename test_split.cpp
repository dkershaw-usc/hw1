// CSCI 104: Homework 1 Problem 1

#include "split.h"
#include <fstream>
#include <iostream>
#include <string>

void initializeFromSelfTest(std::string name, Node*& list);
void deleteNodeList(Node*& list);
void printBegin();
void printLine(int);
void debugPrint(std::string);
bool debugMode = false;

int main(int argc, char* argv[])
{
    if(argv[1] != nullptr && *argv[1] == '1')
    {
        debugMode = true;
        printBegin();
    }

    Node* list = new Node(0,nullptr);
    initializeFromSelfTest("split", list);
    deleteNodeList(list);
}

void initializeFromSelfTest(std::string name, Node*& list)
{
    std::ifstream ifs;
    ifs.open("selftest_" + name + ".txt");
    debugPrint("Reading from file: selftest_" + name + ".txt...");

    std::string temp;
    while(ifs.good())
    {
        std::getline(ifs,temp);
        debugPrint("Value read from file: " + temp);
        list->next = new Node(stoi(temp),nullptr);
        debugPrint("Value read from list: " + list->next->value);
    }
    ifs.close();

    debugPrint("Initialized node list from file.");
    debugPrint("line");
}

void deleteNodeList(Node*& list)
{
    debugPrint("Deleting Node list with initial value: " + list->value);
    while(list->next != nullptr)
    {
        debugPrint("Deleting: " + list->value);

        Node* temp = new Node(0,nullptr);
        temp = list;
        list = list->next;
        delete temp->next;
        delete temp;
    }
    delete list;
}

void debugPrint(std::string message)
{
    if(debugMode) 
    {
        if(message == "line")
        {
            printLine(40);
            return;
        }
        std::cout << message << std::endl;
    }
}

void printBegin()
{
    printLine(40);
    std::cout << "Debug Mode enabled for this Test." << std::endl;
    printLine(40);
}

void printLine(int width)
{
    for(int i = 0; i < width; i++)
    {
        std::cout << "_";
    }
    std::cout << std::endl;
}