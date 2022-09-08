#include "singly.h"

dt_linked_list_singly_t *lls_alloc() {
	return (dt_linked_list_singly_t *) malloc(sizeof(dt_linked_list_singly_t));
}

dt_linked_list_singly_t *lls_insert(dt_linked_list_singly_t *root, size_t offset, uint8_t value) {
	dt_linked_list_singly_t *node = root;

	if (root == NULL || offset == 0) {
		root = lls_alloc();
		root->next = node;
		root->value = value;
	} else {
		dt_linked_list_singly_t *last = node;

		size_t index = 0;
		while (index < offset && node->next != NULL) {
			last = node;
			node = node->next;
			index++;
		}

		if (index < offset) last = node;

		last->next = lls_alloc();
		if (last != node) last->next->next = node;
		last->next->value = value;
	}

	return root;
}

dt_linked_list_singly_t *lls_remove(dt_linked_list_singly_t *root, size_t offset) {
	dt_linked_list_singly_t *node = root;

	if (root == NULL) return NULL;

	dt_linked_list_singly_t *last = NULL;
	for (size_t i = 0; i < offset && node->next != NULL; i++) {
		last = node;
		node = node->next;
	}

	dt_linked_list_singly_t *next = node->next;
	free(node);

	if (last == NULL) {
		root = next;
	} else {
		last->next = next;
	}

	return root;
}

dt_linked_list_singly_t *lls_append(dt_linked_list_singly_t *root) {
	if (root == NULL) return NULL;

	while (root->next != NULL)
		root = root->next;

	root->next = lls_alloc();
	root->next->value = 0;
	root->next->next = NULL;

	return root->next;
}

dt_linked_list_singly_t *lls_pop(dt_linked_list_singly_t *node) {
	if (node == NULL) return NULL;

	dt_linked_list_singly_t *last = NULL;
	while (node->next != NULL) {
		last = node;
		node = node->next;
	}

	free(node);

	if (last != NULL)
		last->next = NULL;

	return node;
}
