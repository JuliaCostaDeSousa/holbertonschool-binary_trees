#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least 1 child
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes with at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count, gauche, droite;

	if (tree == NULL)
		return (0);

	count = 0;
	if (tree->left || tree->right)
		count = 1;

	gauche = binary_tree_nodes(tree->left);
	droite = binary_tree_nodes(tree->right);

	return (count + gauche + droite);
}
