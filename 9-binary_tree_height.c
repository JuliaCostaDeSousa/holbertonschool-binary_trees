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
	{
		left_height = 1 + binary_tree_height(tree->left);
	}

	if (tree->right != NULL)
	{
		right_height = 1 +binary_tree_height(tree->right);
	}

	if (left_height >= right_height)
	return left_height;
	else
	return right_height;
}
