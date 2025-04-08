#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    free(tree);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root = NULL;

    /* 1. Arbre vide */
    printf("Test 1 (arbre vide): %d\n", binary_tree_is_perfect(NULL)); 

    /* 2. Arbre avec un seul nœud */
    root = binary_tree_node(NULL, 1);
    printf("Test 2 (un seul nœud): %d\n", binary_tree_is_perfect(root)); 
    free(root);

    /* 3. Un seul enfant */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    printf("Test 3 (un enfant): %d\n", binary_tree_is_perfect(root)); 
    binary_tree_delete(root);

    /* 4. Parfait à 2 niveaux */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    printf("Test 4 (parfait à 2 niveaux): %d\n", binary_tree_is_perfect(root));
    binary_tree_delete(root);

    /* 5. Complet mais pas parfait */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    printf("Test 5 (complet mais pas parfait): %d\n", binary_tree_is_perfect(root));
    binary_tree_delete(root);

    /* 6. Parfait à 3 niveaux */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    root->left->right = binary_tree_node(root->left, 5);
    root->right->left = binary_tree_node(root->right, 6);
    root->right->right = binary_tree_node(root->right, 7);
    printf("Test 6 (parfait à 3 niveaux): %d\n", binary_tree_is_perfect(root)); 
    binary_tree_delete(root);

    /* 7. Presque parfait, un seul enfant */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    root->left->right = binary_tree_node(root->left, 5);
    root->right->right = binary_tree_node(root->right, 6);
    printf("Test 7 (un seul enfant quelque part): %d\n", binary_tree_is_perfect(root)); 
    binary_tree_delete(root);

    /* 8. Toutes les feuilles même niveau mais un seul enfant */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    root->right->left = binary_tree_node(root->right, 5);
    root->right->right = binary_tree_node(root->right, 6);
    printf("Test 8 (feuilles au même niveau mais un parent incomplet): %d\n", binary_tree_is_perfect(root)); 
    binary_tree_delete(root);

    /* 9. Arbre parfait plus profond (4 niveaux) */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    root->left->right = binary_tree_node(root->left, 5);
    root->right->left = binary_tree_node(root->right, 6);
    root->right->right = binary_tree_node(root->right, 7);
    root->left->left->left = binary_tree_node(root->left->left, 8);
    root->left->left->right = binary_tree_node(root->left->left, 9);
    root->left->right->left = binary_tree_node(root->left->right, 10);
    root->left->right->right = binary_tree_node(root->left->right, 11);
    root->right->left->left = binary_tree_node(root->right->left, 12);
    root->right->left->right = binary_tree_node(root->right->left, 13);
    root->right->right->left = binary_tree_node(root->right->right, 14);
    root->right->right->right = binary_tree_node(root->right->right, 15);
    printf("Test 9 (parfait à 4 niveaux): %d\n", binary_tree_is_perfect(root)); 
    binary_tree_delete(root);

    return 0;
}