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
    binary_tree_t *a = binary_tree_node(NULL, 'A');
    binary_tree_t *b = binary_tree_node(a, 'B');
    binary_tree_t *c = binary_tree_node(a, 'C');
    binary_tree_t *d = binary_tree_node(b, 'D');
    binary_tree_t *e = binary_tree_node(b, 'E');
    binary_tree_t *f = binary_tree_node(c, 'F');
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    
    printf("Hauteur : %lu\n", binary_tree_height(a));
    
    return 0;
}