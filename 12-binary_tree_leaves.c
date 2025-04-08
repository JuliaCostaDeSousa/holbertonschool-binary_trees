#include "binary_trees.h"

/**
 * count_leaves - count leaves going through a BT using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: 1 if node is leaf, other 0
 */

int count_leaves(const binary_tree_t *tree, int (*func)(const binary_tree_t *))
{
	int is_leaf = 0;

	if (tree == NULL || func == NULL)
	return (is_leaf);

	is_leaf += count_leaves(tree->left, func);
	is_leaf += count_leaves(tree->right, func);
	is_leaf += (*func)(tree);
	return (is_leaf);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0, if node is NULL, return 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	return (0);

	if (node->left == NULL && node->right == NULL)
	return (1);
	else
	return (0);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: If tree is NULL must return 0, else return depth of node
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
	return (0);

	count += count_leaves(tree, &binary_tree_is_leaf);
	return (count);
}
