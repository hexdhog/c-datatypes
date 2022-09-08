#ifndef __LINKED_LIST_SINGLY_H__
#define __LINKED_LIST_SINGLY_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct dt_linked_list_singly_t {
	uint8_t value;
	struct dt_linked_list_singly_t *next;
} dt_linked_list_singly_t;

dt_linked_list_singly_t *lls_alloc();
dt_linked_list_singly_t *lls_insert(dt_linked_list_singly_t *root, size_t offset, uint8_t value);
dt_linked_list_singly_t *lls_remove(dt_linked_list_singly_t *root, size_t offset);
dt_linked_list_singly_t *lls_append(dt_linked_list_singly_t *root);
dt_linked_list_singly_t *lls_pop(dt_linked_list_singly_t *node);

#endif

