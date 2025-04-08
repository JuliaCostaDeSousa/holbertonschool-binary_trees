#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = NULL;

    if (parent == NULL)
    return NULL;

    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
    return NULL;

    new_node->n = value;
    new_node->parent = parent;
    new_node->right = NULL;
    if (parent->left == NULL)
    new_node->left = NULL;
    else
    {
        parent->left->parent = new_node;
        new_node->left = parent->left;
    }

    parent->left = new_node;
    return (new_node);
}
 
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root->left, 50);
    binary_tree_insert_left(root->left->left, 10);
    binary_tree_insert_left(root->left->left->left, 8);
    binary_tree_print(root);


    height = binary_tree_height(root);
    printf("Height of %d: %+ld\n", root->n, height);
    height = binary_tree_height(root->right);
    printf("Height of %d: %+ld\n", root->right->n, height);
    height = binary_tree_height(root->left->left->right);
    printf("Height of %d: %+ld\n", root->left->left->right->n, height);

    return (0);
}