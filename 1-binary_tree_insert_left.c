#include "binary_trees.h"

/**
 * binary_tree_insert_left - insère un nœud à gauche d'un parent
 * @parent: pointeur vers le nœud parent
 * @value: valeur à mettre dans le nouveau nœud
 * Return: pointeur vers le nouveau nœud, ou NULL en cas d’erreur
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}
