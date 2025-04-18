#include "binary_trees.h"
/**
 * binary_tree_inorder - traverse un arbre en parcours in-order
 * @tree: racine de l’arbre
 * @func: fonction à appeler pour chaque valeur
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
