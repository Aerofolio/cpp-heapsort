#pragma once
#include <iostream>

enum navigationType{
    INFIX = 0,
    POSTFIX = 1,
    PREFIX = 2
};

struct treeNodeValue
{
    int info;
};

struct treeNode
{
    treeNodeValue * value;
    treeNode * left;
    treeNode * right;
};

treeNodeValue * createTreeNodeValue(int info){
    treeNodeValue * newNodeValue = (treeNodeValue *)malloc(sizeof(treeNodeValue));
    newNodeValue->info = info;

    return newNodeValue;
}

treeNode * createNode(treeNodeValue * treeNodeValue){
    treeNode * newNode = (treeNode *) malloc(sizeof(treeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = treeNodeValue;

    return newNode;
}

void insertNode(treeNode ** treeRoot, treeNodeValue * treeNodeValue){
    if(*treeRoot == NULL){
        *treeRoot = createNode(treeNodeValue);
    }else{
        if(treeNodeValue->info < (*treeRoot)->value->info){
            insertNode(&(*treeRoot)->left, treeNodeValue);
        }else if(treeNodeValue->info > (*treeRoot)->value->info){
            insertNode(&(*treeRoot)->right, treeNodeValue);
        }
    }
}

void printTree(treeNode * treeNode, navigationType navigationType = INFIX, bool ignoreFirst = false){
    if(treeNode != NULL){
        if(navigationType == PREFIX && !ignoreFirst) std::cout << treeNode->value->info << std::endl;

        if(treeNode->left != NULL){
            printTree(treeNode->left, navigationType);
        }

        if(navigationType == INFIX && !ignoreFirst) std::cout << treeNode->value->info << std::endl;

        if(treeNode->right != NULL){
            printTree(treeNode->right, navigationType);   
        }

        if(navigationType == POSTFIX && !ignoreFirst) std::cout << treeNode->value->info << std::endl;
    }
}

void freeTree(treeNode * treeNode){
    if(treeNode != NULL){
        if(treeNode->left != NULL){
            freeTree(treeNode->left);
        }

        if(treeNode->right != NULL){
            freeTree(treeNode->right);
        }

        free(treeNode->value);
        free(treeNode);
    }
}

treeNode * findNode(treeNode * treeRoot, int key){
    if(treeRoot != NULL){
        if(treeRoot->value->info == key)
            return treeRoot;
        else{
            if(treeRoot->value->info > key){
                findNode(treeRoot->left, key);
            }else{
                findNode(treeRoot->right, key);
            }
        }
    }else{
        return NULL;
    }
}

int treeHeight(treeNode * treeNode){
    if(treeNode == NULL)
        return 0;
    else{
        int leftHeight = treeHeight(treeNode->left);
        int rightHeight = treeHeight(treeNode->right);

        if(leftHeight >= rightHeight)
            return ++leftHeight;
        else
            return ++rightHeight;
    }
}

int treeLevel(treeNode * treeNode){//?
    return treeHeight(treeNode) - 1;
}

/// @brief print all children nodes
/// @param treeNode 
void treeChildren(treeNode * treeNode){
    int childrenCount = 0;
    std::cout << "Nodo raiz: " << treeNode->value->info << std::endl;

    if(treeNode->left != NULL){
        std::cout << "Filho " << ++childrenCount << ": " << treeNode->left->value->info << std::endl;
    }

    if(treeNode->right != NULL){
        std::cout << "Filho " << ++childrenCount << ": " << treeNode->right->value->info << std::endl;
    }
}

/// @brief 
/// @param treeRoot node to tree level 0
/// @param key searching value
/// @return parent node of first node with the key value
treeNode * treeParent(treeNode * treeRoot, int key){
    if(treeRoot != NULL){
        if((treeRoot->left != NULL && treeRoot->left->value->info == key)
            || (treeRoot->right != NULL && treeRoot->right->value->info == key))
            return treeRoot;
        else{
            if(treeRoot->value->info > key){
                treeParent(treeRoot->left, key);
            }else{
                treeParent(treeRoot->right, key);
            }
        }
    }else{
        return NULL;
    }
}

int treeDegree(treeNode * treeRoot){
    if(treeRoot == NULL)
        return 0;
    else{
        int rootDegree = 0;

        if(treeRoot->left != NULL)
            rootDegree++;

        if(treeRoot->right != NULL)
            rootDegree++;

        int leftDegree = treeDegree(treeRoot->left);
        int rightDegree = treeDegree(treeRoot->right);

        if(leftDegree > rootDegree)
            rootDegree = leftDegree;

        if(rightDegree > rootDegree)
            rootDegree = rightDegree;

        return rootDegree;
    }
}

int findNodeDepth(treeNode* root, int key)
{
    if (root == NULL)
        return -1;
 
    int dist = -1;
 
    if ((root->value->info == key)
        || (dist = findNodeDepth(root->left, key)) >= 0
        || (dist = findNodeDepth(root->right, key)) >= 0)

        return dist + 1;
 
    return dist;
}

void printAsc(treeNode * treeRoot, treeNode * currentNode, int maxDepth){//rever
    if(currentNode != NULL){
        int currentNodeDepth = findNodeDepth(treeRoot, currentNode->value->info);
        if(currentNodeDepth < maxDepth){
            std::cout << currentNode->value->info << std::endl;
            printAsc(treeRoot, currentNode->left, maxDepth);
            printAsc(treeRoot, currentNode->right, maxDepth);
        }
    }
}