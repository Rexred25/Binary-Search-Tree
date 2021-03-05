#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "BinaryTree.h"
using namespace std;

int leftNodeCounter;
int rightNodeCounter;

void linkedList::addItem(string &value, ofstream &myfile) //This adds an item to the list
{
    node *temp = new node; //creates new node temp
    node *parent = NULL;   //creates new node parent
    temp->data = value;    //puts the data from text file into temp
    temp->left = NULL;     //sets left branch to null
    temp->right = NULL;    //sets right branch to null

    if (root == NULL) //incase BST is empty
    {
        root = temp;
    }
    else
    {
        node *curr;
        curr = root;
        while (curr)
        {
            parent = curr;
            if (temp->data > curr->data)
            {
                curr = curr->right; //sets current to right
                //rightNodeCounter++;
                //cout << rightNodeCounter << " this is the height" << endl;
            }
            else
            {
                curr = curr->left; //sets current to left
                //leftNodeCounter++;
            }
        }
        if (parent->data > temp->data)
        {
            parent->left = temp; //sets parent left to temp
        }
        else
        {
            parent->right = temp; //sets parent right to temp
        }
    }
}
void linkedList::traversalPrint(ofstream &myfile)
{
    myfile << "-----------------------------------------" << endl;
    cout << "Preorder:" << endl;
    myfile << "Preorder:" << endl;
    preorder(root, myfile);
    cout << endl;
    myfile << endl;
    myfile << "-----------------------------------------" << endl;

    cout << "Postorder:" << endl;
    myfile << "Postorder:" << endl;
    postorder(root, myfile);
    cout << endl;
    myfile << endl;
    myfile << "-----------------------------------------" << endl;

    cout << "Inorder:" << endl;
    myfile << "Inorder:" << endl;
    inorder(root, myfile);
    cout << endl;
    myfile << endl;
    myfile << "-----------------------------------------" << endl;

    cout << "Height of tree is " << linkedList::heightCalc(root) << endl;
    myfile << "Height of tree is " << linkedList::heightCalc(root) << endl;
}

void linkedList::preorder(node *p, ofstream &myfile) //NLR
{

    if (p != NULL)
    {
        cout << " " << p->data << " "; //Prints out node
        myfile << " " << p->data << " ";
        preorder(p->left, myfile);  //goes to left
        preorder(p->right, myfile); //goes to right
    }
}

void linkedList::postorder(node *p, ofstream &myfile) //LRN
{

    if (p != NULL)
    {
        postorder(p->left, myfile);    //Prints out left
        postorder(p->right, myfile);   //prints out right
        cout << " " << p->data << " "; //prints out node
        myfile << " " << p->data << " ";
    }
}
void linkedList::inorder(node *p, ofstream &myfile) //LNR
{
    if (p != NULL)
    {
        inorder(p->left, myfile);      //prints out left
        cout << " " << p->data << " "; //prints out node
        myfile << " " << p->data << " ";
        inorder(p->right, myfile); //prints out right
    }
}

int linkedList::heightCalc(node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth = heightCalc(p->left);   //figures out depth of right
        int rightDepth = heightCalc(p->right); //figures out depth of left

        if (leftDepth > rightDepth)
        {
            return (leftDepth + 1);
        }
        else
        {
            return (rightDepth + 1);
        }
    }
}
void linkedList::isEmpty(ofstream &myfile) //basically this checks the first value, head, and if its null it will tell
{                                          //you the list is empty, cause if head is null then every other value is
    cout << "-----------------------------------------" << endl;
    if (root == NULL)
    {
        cout << "The list is empty" << endl;
        myfile << "The list is empty" << endl;
    }
    else
    {
        cout << "The list is not empty" << endl;
        myfile << "The list is not empty" << endl;
    }
    cout << "-----------------------------------------" << endl;
}
void linkedList::isFull(ofstream &myfile) //if the head isnt null, then the list is full
{
    cout << "-----------------------------------------" << endl;
    if (root != NULL) //this is one or more item in the list
    {
        cout << "This list is full" << endl;
        myfile << "This list is full" << endl;
    }
    else
    {
        cout << "The list is not empty" << endl;
        myfile << "The list is not empty" << endl;
    }

    cout << "-----------------------------------------" << endl;
    //cout << rightNodeCounter << " right, left: " << leftNodeCounter << endl;
}
