#include "binary_trees.h"

/**
 * binary_tree_sibling - Retourne le frère ou la sœur d'un nœud
 * @node: pointeur vers le nœud dont on veut le frère/la sœur
 *
 * Return: pointeur vers le frère ou la sœur
 * ou NULL si pas de frère ou de sœur
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}
