#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0, if node is NULL, return 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	return 0;

	if (node->left == NULL && node->right == NULL)
	return 1;
	else
	return 0;
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: If tree is NULL return 0, else return height of a binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL || binary_tree_is_leaf(tree) == 1)
	return 0;

	if (tree->left != NULL)
	left_height = 1 + binary_tree_height(tree->left);

	if (tree->right != NULL)
	right_height = 1 + binary_tree_height(tree->right);

	if (left_height >= right_height)
	return left_height;
	else
	return right_height;
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree
 * Return: If tree is NULL return 0, else return balance factor of a BT
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_depth = 0, right_depth = 0;

	if (tree == NULL)
	return 0;

	left_depth = binary_tree_height(tree->left);
	right_depth = binary_tree_height(tree->right);

	return (left_depth - right_depth);
}
