#include "stack.h"

void stack_allocate(dt_stack_t *stack, size_t size) {
	if (stack == NULL) return;
	stack->start = (uint8_t *) malloc(size);
	stack->size = size;
	stack->ptr = stack->start + stack->size;
}

void stack_deallocate(dt_stack_t *stack) {
	if (stack == NULL || stack->start == NULL) return;
	free(stack->start);
	stack->start = NULL;
	stack->ptr = NULL;
	stack->size = 0;
}

int stack_push(dt_stack_t *stack, uint8_t value) {
	if (stack == NULL || stack->start == NULL) return -1;
	if (stack->ptr <= stack->start) return -2;

	stack->ptr--;
	*stack->ptr = value;

	return 0;
}

int stack_pop(dt_stack_t *stack, uint8_t *value) {
	if (stack == NULL || stack->start == NULL) return -1;
	if (stack->ptr > stack->start + stack->size) return -2;
	if (stack->ptr == stack->start + stack->size) return -3;

	*value = *stack->ptr;
	*stack->ptr = 0;
	stack->ptr++;

	return 0;
}
