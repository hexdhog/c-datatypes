#ifndef __DT_QUEUE_H__
#define __DT_QUEUE_H__

#include <stdlib.h>
#include <stdint.h>

typedef struct dt_queue_t {
	uint8_t *ptr;
	uint8_t *start;
	uint8_t *end;
	size_t size;
	size_t length;
} dt_queue_t;

void queue_allocate(dt_queue_t *queue, size_t size);
void queue_deallocate(dt_queue_t *queue);
int queue_add(dt_queue_t *queue, uint8_t value);
int queue_remove(dt_queue_t *queue, uint8_t *value);

#endif
