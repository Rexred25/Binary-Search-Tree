#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "BinaryTree.h"
//#include "BinaryTreeImp.cpp"
using namespace std;

int main()
{
    linkedList names;
    ifstream file;
    ofstream myfile;
    myfile.open ("output.txt");
    int choice = 1;
    int variableChoice = 0;
    string variableType = "String";
    while(variableChoice == 0)
    {
        cout << "1: Use Strings" << endl;
        cout << "2: Use Integers" << endl;
        cin >> variableChoice;
        if(variableChoice == 1)
        {
            variableChoice = 1;
            file.open ("stringData.txt");
            string word;
            while (file >> word)
            {
                names.addItem(word, myfile);
            }
        }
        if(variableChoice == 2)
        {
            variableChoice = 2;
            file.open ("integerData.txt");
            string word;
            while (file >> word)
            {
                names.addItem(word, myfile);
            }
            variableType = "Integer";
        }
    }
    while(choice!=0)
    {
        cout << "Please select an option:" << endl;
        cout << "1: Print Traversals (" << variableType << ")" << endl;
        cout << "2: Check to see if list is empty" << endl;
        cout << "3: Check to see if the list is full" << endl;
        cout << "0: Exit" << endl;
        cin >> choice;
        if(choice == 1)
        {

            names.traversalPrint(myfile);
            cout << endl;
        }
        if(choice == 2)
        {
            myfile << "-----------------------------------------" << endl;
            names.isEmpty(myfile);
            myfile << "-----------------------------------------" << endl;
        }
        if(choice ==3)
        {
            myfile << "-----------------------------------------" << endl;
            names.isFull(myfile);
            myfile << "-----------------------------------------" << endl;
        }
    }
    cout << "please seek out output.txt for the results!" << endl;
    myfile.close();
    return 0;
}
