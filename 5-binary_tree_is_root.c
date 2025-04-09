#include "binary_trees.h"
/**
 * binary_tree_is_root - Vérifie si un nœud est une racine
 * @node: Pointeur vers le nœud à vérifier
 *
 * Return: 1 si le nœud est une racine (pas de parent), 0 sinon
 */
int binary_tree_is_root(const binary_tree_t *node)

{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}
