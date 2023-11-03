#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push_to_levelorder(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop_levelorder(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 *create_node - Creates a new levelorder_queue_t node.
 * @node: Binary tree node for the new node to contain.
 * Return: If an error occurs, NULL.else, pointer to the new node.
 * korir codes
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *n;

	n = malloc(sizeof(levelorder_queue_t));
	if (n == NULL)
	{
		return (NULL);
	}

	n->node = node;
	n->next = NULL;

	return (n);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *x;

	while (head != NULL)
	{
		x = head->next;
		free(head);
		head = x;
	}
}

/**
 * push_to_levelorder - Runs a function on a given binary tree node and
 * pushes its children into a levelorder_queue_t queue.
 * @node: Binary tree node to print and push.
 * @head: Double pointer to the head of the queue.
 * @tail: Double pointer to the tail of the queue.
 * @func: pointer to the function to call on @node.
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push_to_levelorder(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop_levelorder - Pops the head of a levelorder_queue_t queue.
 * @head: double pointer to the head of the queue.
 */
void pop_levelorder(levelorder_queue_t **head)
{
	levelorder_queue_t *y;

	y = (*head)->next;
	free(*head);
	*head = y;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
{
		return;
}
	while (head != NULL)
	{
		push_to_levelorder(head->node, head, &tail, func);
		pop_levelorder(&head);
	}
}
