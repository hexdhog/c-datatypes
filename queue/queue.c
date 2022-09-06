#include "queue.h"

void queue_allocate(dt_queue_t *queue, size_t size) {
	if (queue == NULL) return;
	queue->ptr = malloc(size);
	queue->start = queue->ptr;
	queue->end = queue->ptr;
	queue->size = size;
	queue->length = 0;
}

void queue_deallocate(dt_queue_t *queue) {
	if (queue == NULL) return;

	if (queue->ptr != NULL) {
		free(queue->ptr);
		queue->ptr = NULL;
	}

	queue->start = NULL;
	queue->end = NULL;
	queue->size = 0;
}

int queue_add(dt_queue_t *queue, uint8_t value) {
	if (queue == NULL || queue->ptr == NULL) return -1;

	uint8_t *start = queue->start;
	size_t length = queue->length;

	if (start == queue->end && queue->length > 0) return -2;

	if (start == queue->ptr + queue->size - 1)
		start = queue->ptr;
	else
		start++;

	length++;

	*queue->start = value;
	queue->start = start;
	queue->length = length;

	return 0;
}

int queue_remove(dt_queue_t *queue, uint8_t *value) {
	if (queue == NULL || queue->ptr == NULL) return -1;

	uint8_t *end = queue->end;
	size_t length = queue->length;

	if (end == queue->start && length == 0) return -2;

	if (end == queue->ptr + queue->size - 1)
		end = queue->ptr;
	else
		end++;

	length--;

	*value = *queue->end;
	*queue->end = 0;
	queue->end = end;
	queue->length = length;

	return 0;
}
