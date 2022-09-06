#ifndef __DT_STACK_H__
#define __DT_STACK_H__

#include <stdlib.h>
#include <stdint.h>

typedef struct dt_stack_t {
	uint8_t *start;
	uint8_t *ptr;
	size_t size;
} dt_stack_t;

void stack_allocate(dt_stack_t *stack, size_t size);
void stack_deallocate(dt_stack_t *stack);
int stack_push(dt_stack_t *stack, uint8_t value);
int stack_pop(dt_stack_t *stack, uint8_t *value);

#endif
