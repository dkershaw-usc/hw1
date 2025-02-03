// CSCI 104: Homework 1 Problem 1

#include "split.h"
#include <fstream>
#include <iostream>
#include <string>

void initializeFromFile(std::string name, Node*& list);
void printNodeList(Node*& list);
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
    initializeFromFile("split", list);

    Node* odds = NULL;
    Node* evens = nullptr;

    printNodeList(list);
    split(list, odds, evens);

    debugPrint("Odds:");
    printNodeList(odds);
    debugPrint("Evens:");
    printNodeList(evens);
    
    deleteNodeList(evens);
    deleteNodeList(odds);
}

void initializeFromFile(std::string name, Node*& list)
{
    std::ifstream ifs;
    ifs.open("selftest_" + name + ".txt");
    debugPrint("Reading from file: selftest_" + name + ".txt...");

    std::string temp;
    Node* ptr = list;
    std::getline(ifs,temp);
    list->value = stoi(temp);
    debugPrint("Value read from file: " + temp);
    debugPrint("Value read from list: " + std::to_string(list->value));
    while(ifs.good())
    {
        std::getline(ifs,temp);
        debugPrint("Value read from file: " + temp);
        ptr->next = new Node(stoi(temp),nullptr);
        debugPrint("Value read from list: " + std::to_string(ptr->next->value));
        ptr = ptr->next;
    }
    ifs.close();

    debugPrint("Initialized node list from file.");
    debugPrint("line");
}

void deleteNodeList(Node*& list)
{
    debugPrint("line");
    debugPrint("Deleting Node list with initial value: " + std::to_string(list->value));
    while(list->next != nullptr)
    {
        debugPrint("Deleting: " + std::to_string(list->value));

        Node* temp = list;
        list = list->next;
        delete temp;
    }
    debugPrint("Deleting: " + std::to_string(list->value));
    delete list;
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

void printBegin()
{
    printLine(40);
    std::cout << "Debug Mode enabled for this Self-Test." << std::endl;
}

void printLine(int width)
{
    for(int i = 0; i < width; i++)
    {
        std::cout << "_";
    }
    std::cout << std::endl;
}

void printNodeList(Node*& list)
{
    if(!debugMode) return;

    printLine(40);

    debugPrint("Printing Node list with initial value: " + std::to_string(list->value));
    Node* ptr = list;
    int i = 0;
    while(ptr != nullptr)
    {
        debugPrint("Node " + std::to_string(i) + ": " + std::to_string(ptr->value));
        ptr = ptr->next;
        i++;
    }
    delete ptr;
}