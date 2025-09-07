#ifndef DYNLIST_H
#define DYNLIST_H

#include <stdlib.h>     // malloc
#include <string.h>     // memcpy
#include "types.h"
#include "debug.h"

/* Structure of a dynlist:
 * size_t capacity
 * size_t length
 * size_t stride
 * void *memory
 */

enum {
    CAPACITY,
    LENGTH,
    STRIDE,
    dynlist_FIELDS
};

typedef struct {
    int size, capacity, t_size;
    Allocator *allocator;
} DynlistHeader;

void *_dynlist_create(Allocator *a, size, size);
void _dynlist_destroy(Allocator *a, void *);

size _dynlist_field_get(void *, size);
void _dynlist_field_set(void *, size, size);

void *_dynlist_resize(Allocator *a, void *);

void *_dynlist_push(Allocator *a, void *, void *);
void _dynlist_pop(void *, void *);
void _dynlist_remove(void *, void *);
void _dynlist_removeat(void *, int);

#define dynlist_DEFAULT_CAP 1
#define dynlist_RESIZE_FACTOR 2

#define dynlist_init(a, type) _dynlist_create(a, dynlist_DEFAULT_CAP, sizeof(type))
#define dynlist_create_prealloc(a, type, capacity) _dynlist_create(a, capacity, sizeof(type))
#define dynlist_destroy(a, arr) _dynlist_destroy(a, arr)
#define dynlist_removeat(arr, index) _dynlist_removeat(arr, index)
#define dynlist_remove(arr, ptr) _dynlist_remove(arr, ptr)

#define dynlist_push(a, arr, x) arr = _dynlist_push(a, arr, &x)
#define dynlist_push_rval(a, arr, x) \
    do { \
        __auto_type temp = x; \
        arr = _dynlist_push(a, arr, &temp); \
    } while (0)

#define dynlist_pop(arr, xptr) _dynlist_pop(arr, xptr)

#define dynlist_capacity(arr) _dynlist_field_get(arr, CAPACITY)
#define dynlist_length(arr) _dynlist_field_get(arr, LENGTH)
#define dynlist_stride(arr) _dynlist_field_get(arr, STRIDE)
#endif
