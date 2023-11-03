#include "binary_trees.h"

nodet *append(nodet *head, const binary_tree_t *btnode);
void free_list(nodet *head);
nodet *get_children(nodet *head, const binary_tree_t *parent);
void recursive_levels(nodet *head, void (*func)(int));

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: Points to the next node
 * korir codes
 */
 typedef struct node_s
 {
         const binary_tree_t *node;
         struct node_s *next;
 } nodet;

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * korir codes
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	nodet *child = NULL;

	func(tree->n);
	child = get_children(child, tree);
	recursive_levels(child, func);

	free_list(child);
}

/**
 * recursive_levels - Calls func on all nodes at each level.
 * @head: Pointer to head of linked list with nodes at one level.
 * @func: Pointer to a function to call for each node.
 * korir codes
 */
void recursive_levels(nodet *head, void (*func)(int))
{
	nodet *child = NULL, *c = NULL;

	if (!head)
	{
		return;
	}
	for (c = head; c != NULL; c = c->next)
	{
		func(c->node->n);
		child = get_children(child, c->node);
	}
	recursive_levels(child, func);
	free_list(child);
}

/**
 * get_children - Append children of parent to linked list.
 * @head: Pointer to head of linked list where children will be appended.
 * @parent: Pointer to node whose children we want to append.
 * Return: Pointer to head of linked list of children.
 * korir codes
 */
nodet *get_children(nodet *head, const binary_tree_t *parent)
{
	if (parent->left)
	{
		head = append(head, parent->left);
	}
	if (parent->right)
	{
		head = append(head, parent->right);
	}
	return (head);
}

/**
 * append - adds a new node at the end of a linkedlist
 * @head: pointer to head of linked list
 * @btnode: const binary tree node to append
 * Return: pointer to head, NULL on failure
 */
nodet *append(nodet *head, const binary_tree_t *btnode)
{
	nodet *new = NULL, *prev = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			prev = head;
			while (prev->next)
				prev = prev->next;
			prev->next = new;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes of a linked list
 * @head: pointer to the head of list_t linked list
 * korir codes
 */
void free_list(nodet *head)
{
	nodet *pt = NULL;

	while (head)
	{
		pt = head->next;
		free(head);
		head = pt;
	}
}
