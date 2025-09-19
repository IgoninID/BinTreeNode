#include <iostream>
#include "Node.h"

using namespace std;

void funcadd(BinTreeNode<int>* curr)
{
    if (curr)
    {
        curr->data = curr->data + 1;
    }
}

int main()
{
    test();
    BinTreeNode<int>* root = new BinTreeNode<int>(1);
    /*
    *                   1
    *               2       3
    *             4   5   6   7
    */
    insert(2, root);
    insert(3, root);
    insert(4, root->left);
    insert(5, root->left);
    insert(6, root->right);
    insert(7, root->right);
    path(root, nlr);
    cout << endl;
    NodeFunc<int>(funcadd, root);
    path(root, nlr);
    cout << endl;

    vector<int> vec;
    path(root, iter, vec);
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    deletetree(root);


    BinTreeNode<int>* ro = new BinTreeNode<int>(8);
    /*
    *                    8
    *             3             10
    *          1     6              14
    *              4   7  
    */
    insertintree(3, ro);
    insertintree(1, ro);
    insertintree(6, ro);
    insertintree(7, ro);
    insertintree(10, ro);
    insertintree(14, ro);
    insertintree(4, ro);
    path(ro, lnr);
    cout << endl << "Count: " << count(ro) << endl << "Depth: " << depth(ro) << endl;
    removeNode(ro, 10);
    path(ro, lnr);
    cout << endl;
    deletetree(ro);

    vector<int> vec1{ 8, 3, 1, 6, 7, 10, 14, 4 };
    BinTreeNode<int>* r = treefromvector(vec1);
    path(r, lnr);
}