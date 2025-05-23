#include "binary_trees.h"

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
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: If tree is NULL return 0, else return height of a binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	return (0);

	if (tree->left != NULL)
	{
		left_height = 1 + binary_tree_height(tree->left);
	}

	if (tree->right != NULL)
	{
		right_height = 1 + binary_tree_height(tree->right);
	}

	if (left_height >= right_height)
	return (left_height);
	else
	return (right_height);
}

/**
 * BT_is_perfect_PO - going through a binary tree with post order traversal
 * using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @level: level of node
 * @height: height of binary tree
 * Return: 1 if BT is perfect, otherwise 0
 */

int BT_is_perfect_PO(const binary_tree_t *tree, int level, int height)
{
	int left_perfect = 1, right_perfect = 1;

	if (tree == NULL)
	return (1);

	if (tree->left == NULL && tree->right != NULL)
	return (0);

	if (tree->right == NULL && tree->left != NULL)
	return (0);

	if (binary_tree_is_leaf(tree) == 1 && level != height)
	return (0);

	left_perfect = BT_is_perfect_PO(tree->left, level + 1, height);
	right_perfect = BT_is_perfect_PO(tree->right, level + 1, height);

	if ((left_perfect == right_perfect) && left_perfect != 0)
	return (1);
	else
	return (0);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL return 0 else return 1
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0, is_perfect = 0;

	if (tree == NULL)
	return (0);

	height = binary_tree_height(tree);
	is_perfect = BT_is_perfect_PO(tree, 0, height);

	return (is_perfect);
}
