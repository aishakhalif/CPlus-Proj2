/**
 * @class BST
 * @brief Binary Search tree that stores the prices of all sales objects stored in the vector
 *
 *
 *
 * @author Aisha Khalif
 * @version 04
 * @date
 *
 *
 */

#ifndef TBST_hpp
#define TBST_hpp

#include <stdio.h>
#include <iostream>

template <class T>

class BST
{

public:

    /**
     *@brief default constructor
     */
    BST();

    /**
     *@brief copy constructor
     */
    BST(const BST<T>& otherTree);

    /**
     *@brief default destructor
     */
    virtual ~BST();

    /**
     *@brief function to insert into tree
     *@param the insert item
     */
    void insert(const T& insertItem);

    /**
     *@brief return a specific node
     *@param the insert item
     */
    void returnNode (const T& insertItem);

    /**
	*@brief return the item inside the right most node of the tree
	*/
    T return_highestPrice();

    /**
	*@brief return the item inside the left most node of the tree
	*/
    T return_lowestPrice();

private:

    //creating the node structure
    struct node
    {
        T insertItem;
        node *left;
        node *right;
    };

    //root pointer
    node *root;

    void copyTree(node* copyTreeRoot, node* otherTreeRoot);

    void destroy (node* &Tree);

    node* createLeaf(const T& insertItem);

    void insert(const T& insertItem, node* Ptr);

    node* returnNode (const T& insertItem, node* Ptr); //return a pointer to the node that corresponds to the key (insertItem)

	int bst_size(int bst_count, node *Ptr);

};

//-----------------------------------------------------------------------------------------

template <class T>
BST<T>::BST()

{
    root = NULL;
}

template<class T>
void BST<T>::copyTree(node * copyTreeRoot, node * otherTreeRoot)
{
    if(otherTreeRoot == NULL)
        copyTreeRoot = NULL;
    else
    {
        copyTreeRoot = new node;
        copyTreeRoot->insertItem = otherTreeRoot->insertItem;
        copyTree(copyTreeRoot->left, otherTreeRoot->left);
        copyTree(copyTreeRoot->right, otherTreeRoot->right);
    }
}

template <class T>
BST<T>::BST(const BST<T>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

//-------------------------------

template <class T>
BST<T>::~BST()

{
    delete root;
}


template <class T>
void BST<T>::destroy(node* &Tree)
{
    if (Tree != NULL)
    {
        destroy(Tree->left);
        destroy(Tree->right);
        delete Tree;
        Tree = NULL;
    }
}

//-------------------------------

//Definitions

template <class T>
void BST<T>::insert(const T& insertItem)
{
    insert(insertItem, root);
}

//---------------------------------

//Implementations

template <class T>
typename BST<T>::node* BST<T>::createLeaf(const T& insertItem)
{
    node* newNode = new node;
    newNode -> insertItem = insertItem;

    //make sure left and right are pointing to null
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


//-----------------------------------------------------------------------

template <class T>
void BST<T>::insert(const T& insertItem, node *Ptr)
{

    if (root == NULL)
    {
        root = createLeaf(insertItem);
    }


    /*!
     * left node
     */

    //if tree is not empty
    else if (insertItem < Ptr->insertItem)
    {
        //go left, but check if it's pointing to something first
        if (Ptr->left != NULL)
        {

            //if yes, recursively move down the left side (funtion calls its self)
            insert(insertItem, Ptr->left);
        }
        //else if it's not pointing to anything
        else
        {
            //add mode tree
            Ptr->left = createLeaf(insertItem);
        }
    }




    /*!
     * Right node
     */

    //if tree is not empty
    else if (insertItem > Ptr->insertItem)
    {
        //go right, but check if it's pointing to something first
        if (Ptr->right != NULL)
        {
            //if yes, recursively move down the left side
            insert(insertItem, Ptr->right);
        }
        //else if it's not pointing to anything
        else
        {
            //add mode tree
            Ptr->right = createLeaf(insertItem);
        }

    }


    else
    {
        //std::cout << insertItem << " has already been added once\n" << std::endl;
    }

}

//---------------------------------------------------------------------------------------------
template <class T>
T BST<T>::return_highestPrice()
{
        node *Ptr; //node pointer

        if(root == NULL)
        {
            std::cout << "Tree is empty!";
        }

        Ptr = root;

        do
        {
            Ptr = Ptr->right;

            if(Ptr->right == NULL)
            {
			break;
            }

        } while(Ptr != NULL);

        return Ptr -> insertItem;
}

template <class T>
T BST<T>::return_lowestPrice()
{
        node *Ptr; //node pointer

        if(root == NULL)
        {
            std::cout << "Tree is empty!";
        }

        Ptr = root;

        do
        {
            Ptr = Ptr->left;

            if(Ptr->left == NULL)
            {
			break;
            }

        } while(Ptr != NULL);

        return Ptr -> insertItem;
}
#endif
