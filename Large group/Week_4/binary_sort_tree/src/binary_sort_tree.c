//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_C
#define BINARYSORTTREE_BINARY_SORT_TREE_C

#define _CRT_SECURE_NO_WARNINGS 1

#include"binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>


Status visit(NodePtr node) {
    if (node != NULL) {
        printf("%d ", node->value);
        return 1;
    }
    return 0;
}


/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr BST) {
    if (BST == NULL) return 0;
    BST->root = NULL;
    return 1;
}

static void insert_helper(NodePtr* node, ElemType value) {
    if (*node == NULL) {
        *node = (NodePtr)malloc(sizeof(Node));
        if (*node != NULL) {
            (*node)->value = value;
            (*node)->left = NULL;
            (*node)->right = NULL;
        }
    }
    else if (value < (*node)->value) {
        insert_helper(&((*node)->left), value);
    }
    else if (value > (*node)->value) {
        insert_helper(&((*node)->right), value);
    }
    // 如果值相等，则不插入，因为BST不允许重复值
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr BST, ElemType value) {
    if (BST == NULL) return 0;
    insert_helper(&(BST->root), value);
    return 1;
}



static NodePtr find_minimum(NodePtr node) {
    if (node == NULL) return NULL;
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

static NodePtr delete_node(NodePtr root, ElemType value) {
    if (root == NULL) return root;
    if (value < root->value) {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->value) {
        root->right = delete_node(root->right, value);
    }
    else {
        if (root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }

        NodePtr temp = find_minimum(root->right);
        root->value = temp->value;
        root->right = delete_node(root->right, temp->value);
    }
    return root;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr BST, ElemType value) {
    if (BST == NULL || BST->root == NULL) return 0;
    BST->root = delete_node(BST->root, value);
    return 1;
}


/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr BST, ElemType value) {
    NodePtr current = BST->root;
    while (current != NULL) {
        if (value == current->value) {
            return 1; // 找到了
        }
        else if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return 0; // 没找到
}


/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    NodePtr stack[100]; // 假设栈足够大
    int top = -1;
    NodePtr node = BST->root;

    while (node != NULL || top != -1) {
        while (node != NULL) {
            visit(node);
            stack[++top] = node;
            node = node->left;
        }
        if (top != -1) {
            node = stack[top--];
            node = node->right;
        }
    }
    return 1;
}



void BST_preorderR_helper(NodePtr node, void (*visit)(NodePtr)) {
    if (node != NULL) {
        visit(node);
        BST_preorderR_helper(node->left, visit);
        BST_preorderR_helper(node->right, visit);
    }
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    if (BST == NULL || visit == NULL) return 0;
    BST_preorderR_helper(BST->root, visit);
    return 1;
}


/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
 // 递归实现
void BST_inorderR_helper(NodePtr node, void (*visit)(NodePtr)) {
    if (node != NULL) {
        BST_inorderR_helper(node->left, visit);
        visit(node);
        BST_inorderR_helper(node->right, visit);
    }
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    if (BST == NULL || visit == NULL) return 0;
    BST_inorderR_helper(BST->root, visit);
    return 1;
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    NodePtr stack[100];
    int top = -1;
    NodePtr node = BST->root;

    while (node != NULL || top != -1) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }
        if (top != -1) {
            node = stack[top--];
            visit(node);
            node = node->right;
        }
    }
    return 1;
}



 // 递归实现
void BST_postorderR_helper(NodePtr node, void (*visit)(NodePtr)) {
    if (node != NULL) {
        BST_postorderR_helper(node->left, visit);
        BST_postorderR_helper(node->right, visit);
        visit(node);
    }
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    if (BST == NULL || visit == NULL) return 0;
    BST_postorderR_helper(BST->root, visit);
    return 1;
}

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->elements = (NodePtr*)malloc(queue->capacity * sizeof(NodePtr));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity); 
}

int isEmpty(Queue* queue) {
    return (queue->size == 0); 
}

void enqueue(Queue* queue, NodePtr item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
    queue->size = queue->size + 1;
}

NodePtr dequeue(Queue* queue) {
    if (isEmpty(queue)) return NULL;
    NodePtr item = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    if (BST == NULL || BST->root == NULL) return 0;
    Queue* queue = createQueue(100); // 假设100足够大
    enqueue(queue, BST->root);
    while (!isEmpty(queue)) {
        NodePtr current = dequeue(queue);
        visit(current);
        if (current->left != NULL) enqueue(queue, current->left);
        if (current->right != NULL) enqueue(queue, current->right);
    }
    free(queue->elements);
    free(queue);
    return 1;
}


#endif //BINARYSORTTREE_BINARY_SORT_TREE_H