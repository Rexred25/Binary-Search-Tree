#ifndef LINK_LIST_H_INCLUDED
#define LINK_LIST_H_INCLUDED
#include <string>
using namespace std;
class linkedList
{
    public:
        linkedList()
        {
            root = NULL;
        }

        void addItem(string &value, ofstream& myfile);
        void isEmpty(ofstream &myfile);
        void isFull(ofstream &myfile);
        void traversalPrint(ofstream& myfile);


    private:
        struct node
        {
            string data;
            node *next;
            node *left;
            node *right;
        }
        *root;
        void preorder(node *, ofstream &myfile);
        void postorder(node *, ofstream &myfile);
        void inorder(node *, ofstream &myfile);
        int heightCalc(node *);

};
#endif // LINK_LIST_H_INCLUDED
