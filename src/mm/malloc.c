// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
  void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (ret == MAP_FAILED)
    return NULL;
  mem_list_add(ret, size);
  return ret;
}

void *calloc(size_t nmemb, size_t size) {
  size_t total_size = nmemb * size;
  void *ret = mmap(NULL, total_size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (ret == MAP_FAILED) {
    return NULL;
  }
  memset(ret, 0, total_size);
  mem_list_add(ret, total_size);
  return ret;
}

void free(void *ptr) { /* TODO: Implement free(). */ }

void *realloc(void *ptr, size_t size) {
  void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (ret == MAP_FAILED) {
    return NULL;
  }
  void *new = malloc(size);
  memcpy(new, ret, size);
  return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
  size_t total_size = nmemb * size;
  void *ret = mmap(NULL, total_size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (ret == MAP_FAILED) {
    return NULL;
  }
  void *new = malloc(total_size);
  memcpy(new, ret, total_size);
  return new;
}
