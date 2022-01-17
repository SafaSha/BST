#ifndef BST_H
#define BST_H

#include <iostream>

using std::cout;
using std::endl;

    /**
	 * @class Bst
	 * @brief  template Binary search tree
	 *
	 *
	 * @author Safa Shavandi
	 * @version 01
	 * @date 25/05/2020 started
	 *
	 *
	 *
	 * @todo Lets to creat, insert, search and print data on binary search tree
	 *
	 */

template<class T>
class Bst
{
public:
        /** \brief defualt constructor
         *
         *
         */
    Bst();

        /** \brief deconstructor
         *
         *
         */
    ~Bst();

        /** \brief insert data into BST
         *
         * \param T, the data which is insert to tree
         *
         * \return void
         *
         */
    void insert (const T& insertItem);

        /** \brief search data in BST, preint suitable message
         *
         * \param target T, the itme which is searched in tree
         * \return void
         *
         */
    void searchItem(T target);

        /** \brief print inorder all data in the tree
         *
         * \return void
         *
         */
    void inorderTraversal(void(*pointerFunc)(T&)) const;

        /** \brief print preorder all data in the tree
         *
         * \return void
         *
         */
    void preorderTraversal(void(*pointerFunc)(T&)) const;

        /** \brief print postorder all data in the tree
         *
         * \return void
         *
         */
    void postorderTraversal(void(*pointerFunc)(T&)) const;


        /** \brief copy constructor
         *
         *
         */
    Bst (const Bst<T>& otherTree);


        /** \brief Overload the assignment operator
         *
         * \param otherTree const Bst&, the tree which its nodes will be assigned
         * \return const Bst& ,the assigned tree
         *
         */
    const Bst& operator=(const Bst& otherTree);


protected:

private:

        /** \brief the struct which store node's properties
         */
    struct nodeType
    {
        T data;
        nodeType *lLink=nullptr;
        nodeType *rLink=nullptr;
    } ;

        /** \brief root of the tree
         *
         *
         */
    nodeType *root;

        /** \brief insert data into BST (recursive)
         *
         * \param target T, the data which is searched in the tree
         * \param &node nodeType*, the node which is compared with target
         * \return void
         *
         */
    void insertIn( T target,nodeType *&node);

        /** \brief delet entire tree
         *
         * \param &node nodeType*, the node which is root of tree which is deleted
         * \return void
         *
         */
    void deleteTree(nodeType *&node);

        /** \brief copty one tree to another one
         *
         * \param &copiedTreeRoot nodeType*, the tree which nodes of other one is copied on it.
         * \param otherTreeRoot nodeType*, the tree which nodes of it is copied into another tree.
         * \return void
         *
         */
    void copyTree(nodeType *&copiedTreeRoot, nodeType *otherTreeRoot);

        /** \brief search data in the tree(recursive)
         *
         * \param target const T&, the data which is searched for in tree.
         * \param node nodeType*, the node which is compared with target.
         * \return bool, return true if item is found
         *
         */
    bool search(const T &target, nodeType *node) const;

        /** \brief check a tree to see if it is empty
         *
         * \param &root nodeType*, root of tree
         * \return bool, return true if tree is empty
         *
         */
    bool isTreeEmpty(nodeType *&root);

        /** \brief print inorder all data in the tree
         *
         * \param nodeType, node which is used to traverse
         * \return
         *
         */
    void inorder (nodeType *node,void(*pointerFunc)(T&)) const;

        /** \brief print preorder all data in the tree
         *
         * \param nodeType, node which is used to traverse
         * \return
         *
         */
    void preorder (nodeType *node,void(*pointerFunc)(T&)) const;

        /** \brief print postorder all data in the tree
         *
         * \param nodeType, node which is used to traverse
         * \return
         *
         */
    void postorder (nodeType *node,void(*pointerFunc)(T&)) const;
};//end class

//////////////////////////////

    //default constructor
template<class T>
Bst<T>::Bst()
{
    root=nullptr;
}

    //deconstructor
template<class T>
Bst<T>::~Bst()
{
    deleteTree(root);
}

    //insert data into BST (recursive)
template<class T>
void Bst<T>::insertIn( T target,nodeType *&node)
{
    nodeType *newNode;
    newNode = new nodeType;
    newNode->data = target;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if(node==nullptr)
    {
        (node)=newNode;
    }
    else if(node->data==newNode->data)
    {
        cout<<"Doublicatin!! cannot copy dublicate data"<<endl;
    }
    else if((node->data)>(newNode->data))
    {
        insertIn(target,node->lLink);
    }
    else
    {
        insertIn(target,node->rLink);
    }


}//end insert

    //public method to data element into tree
template<class T>
void Bst<T>::insert (const T& insertItem)
{
    insertIn(insertItem,root);
}

    //copty one tree to another one
template<class T>
void Bst<T>::copyTree(nodeType *&copiedTreeRoot, nodeType *otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType;
        copiedTreeRoot->data = otherTreeRoot->data;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

    //delete entire tree
template<class T>
void Bst<T>::deleteTree(nodeType *&node)
{
    if (node != nullptr)
    {
        deleteTree(node->lLink);
        deleteTree(node->rLink);
        delete node;
        node = nullptr;
    }
}

    //copy constructor
template<class T>
Bst<T>::Bst (const Bst<T>& otherTree)
{
    if (otherTree.root == nullptr)
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

    //Overload the assignment operator
template<class T>
const Bst<T>& Bst<T>:: operator=(const Bst& otherTree)
{
    if (this != &otherTree)
    {
        if (root != nullptr)
        {
            deleteTree(root);
        }

        if (otherTree.root == nullptr)
        {
            root = nullptr;
        }

        else
        {
            copyTree(root, otherTree.root);
        }//end else
    }//end if
    return *this;
}

    //search tree to check if target is there
template<class T>
bool Bst<T>::search(const T& target,nodeType *node) const
{
    nodeType *newNode;
    newNode = new nodeType;
    newNode->data = target;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    bool found=false;
    if(node!=nullptr)
    {
        if(newNode->data==node->data)
        {
            found=true;
        }
        else if(newNode->data<node->data)
        {
            found=search(target,node->lLink);
        }
        else
        {
            found=search(target,node->rLink);
        }


    }
    return found;
}//end search

    //return true if tree is empty
template<class T>
bool Bst<T>::isTreeEmpty(nodeType *&root)
{
    return root==nullptr;
}

    //Print message if item is in the tree
template<class T>
void Bst<T>::searchItem(T target)
{
    if(isTreeEmpty(root))
    {
        cout<<"Tree is empty"<<endl;
    }
    else if(search(target,root))
    {
        cout<<"Item found"<<endl;
    }
    else
    {
        cout<<"Item is not in the tree"<<endl;
    }
}

    //private function to travers inorder
template<class T>
void Bst<T>::inorder (nodeType *node,void(*pointerFunc)(T&)) const
{
    if (node != nullptr)
    {
        inorder(node->lLink,(*pointerFunc));
//        cout << node->data << " ";
        (*pointerFunc)(node->data );
        inorder(node->rLink,(*pointerFunc));
    }
}

    //private function to travers preorder
template<class T>
void Bst<T>::preorder (nodeType *node,void(*pointerFunc)(T&)) const
{
    if (node != nullptr)
    {
//        cout << node->data << " ";
        (*pointerFunc)(node->data );
        preorder(node->lLink,(*pointerFunc));
        preorder(node->rLink,(*pointerFunc));
    }
}

    //private function to travers postorder
template<class T>
void Bst<T>::postorder (nodeType *node,void(*pointerFunc)(T&)) const
{
    if (node != nullptr)
    {
        postorder(node->lLink,(*pointerFunc));
        postorder(node->rLink,(*pointerFunc));
//        cout << node->data << " ";
        (*pointerFunc)(node->data );
    }
}

    //travers inorder
template<class T>
void Bst<T>::inorderTraversal(void(*pointerFunc)(T&)) const
{
    inorder(root,(*pointerFunc));
}

    //travers prestorder
template<class T>
void Bst<T>::preorderTraversal(void(*pointerFunc)(T&)) const
{
    preorder(root,(*pointerFunc));
}

    //travers postorder
template<class T>
void Bst<T>::postorderTraversal(void(*pointerFunc)(T&)) const
{
    postorder(root,(*pointerFunc));
}
#endif // INTBST_H
