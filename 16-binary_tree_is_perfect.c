#include "binary_trees.h"

unsigned char is_a_leaf(const binary_tree_t *node);
size_t node_depth(const binary_tree_t *tree);
const binary_tree_t *ret_leaf(const binary_tree_t *tree);
int perfectly_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_a_leaf - Check if a node is the leaf of a binary tree.
 * @node: Pointer to the node to check.
 * Return: If the node is a leaf, 1, otherwise, 0.
 * korir codes
 */
unsigned char is_a_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * node_depth - Return depth of a given node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 * Return: Depth of node.
 * korir codes
 */
size_t node_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + node_depth(tree->parent) : 0);
}

/**
 * ret_leaf - Returns the leaf of a binary tree.
 * @tree: Pointer to the root node of the tree to find a leaf in.
 * Return: Pointer to the first encountered leaf.
 * korir codes
 */
const binary_tree_t *ret_leaf(const binary_tree_t *tree)
{
	if (is_a_leaf(tree) == 1)
		return (tree);
	return (tree->left ? ret_leaf(tree->left) : ret_leaf(tree->right));
}

/**
 * is_perfect_recursive - Check if a binary tree is perfectly recursively.
 * @tree: Pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int perfectly_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_a_leaf(tree))
	{
		return (level == leaf_depth ? 1 : 0);
	}
	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}
	return (perfectly_recursive(tree->left, leaf_depth, level + 1) &&
		perfectly_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: If tree is NULL or not perfect, 0.else, 1.
 * korir codes
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (perfectly_recursive(tree, node_depth(ret_leaf(tree)), 0));
}
