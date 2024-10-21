// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
  char *p;
  for (p = destination; *source != '\0'; source++, p++)
    *p = *source;
  *p = *source;
  return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
  char *p;
  size_t k;
  for (p = destination, k = 0; *source != '\0' && k < len; source++, p++, k++)
    *p = *source;
  for (; k < len; p++, k++)
    *p = '\0';
  return destination;
}

char *strcat(char *destination, const char *source) {
  char *p;
  for (p = destination + strlen(destination); *source != '\0'; source++, p++)
    *p = *source;
  *p = *source;
  return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
  char *p;
  size_t k;
  for (p = destination + strlen(destination), k = 0; *source != '\0' && k < len;
       source++, p++, k++)
    *p = *source;
  *p = '\0';
  return destination;
}

int strcmp(const char *str1, const char *str2) {
  char *p1, *p2;
  for (p1 = str1, p2 = str2; *p1 != '\0' && *p2 != '\0'; p1++, p2++) {
    if (*p1 < *p2)
      return -1;
    if (*p1 > *p2)
      return 1;
  }
  if (*p1 == '\0' && *p2 != '\0')
    return -1;
  if (*p1 != '\0' && *p2 == '\0')
    return 1;
  return 0;
}

int strncmp(const char *str1, const char *str2, size_t len) {
  char *p1, *p2;
  size_t k;
  for (p1 = str1, p2 = str2, k = 0; *p1 != '\0' && *p2 != '\0' && k < len;
       p1++, p2++, k++) {
    if (*p1 < *p2)
      return -1;
    if (*p1 > *p2)
      return 1;
  }
  if (k == len)
    return 0;
  if (*p1 == '\0' && *p2 != '\0')
    return -1;
  if (*p1 != '\0' && *p2 == '\0')
    return 1;
  return 0;
}

size_t strlen(const char *str) {
  size_t i = 0;

  for (; *str != '\0'; str++, i++)
    ;

  return i;
}

char *strchr(const char *str, int c) {
  char *p;
  for (p = str; *p != '\0'; p++)
    if (*p == c)
      return p;
  return NULL;
}

char *strrchr(const char *str, int c) {
  char *p;
  for (p = str + strlen(str) - 1; p >= str; p--)
    if (*p == c)
      return p;
  return NULL;
}

char *strstr(const char *haystack, const char *needle) {
  char *p;
  for (p = haystack; *p != '\0'; p++)
    if (*p == *needle) {
      char *k1, *k2;
      for (k1 = p, k2 = needle; *k1 != '\0' && *k2 != '\0' && *k1 == *k2;
           k1++, k2++)
        ;
      if (*k2 == '\0')
        return p;
    }
  return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
  char *p;
  for (p = haystack + strlen(haystack) - 1; p >= haystack; p--)
    if (*p == *(needle + strlen(needle) - 1)) {
      char *k1, *k2;
      for (k1 = p, k2 = needle + strlen(needle) - 1;
           k1 >= haystack && k2 >= needle && *k1 == *k2; k1--, k2--)
        ;
      if (k2 < needle)
        return k1 + 1;
    }
  return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
  char *p;
  unsigned char *dest = destination;
  unsigned char *src = source;
  size_t k = 0;
  for (p = dest, k = 0; k < num; src++, p++, k++)
    *p = *src;
  return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
  char *p;
  unsigned char *dest = destination;
  unsigned char *src = source;
  size_t k;
  if (dest == src)
    return destination;
  if (dest < src) {
    for (k = 0; k < num; k++) {
      dest[k] = src[k];
    }
  } else {
    for (k = num; k > 0; k--) {
      dest[k - 1] = src[k - 1];
    }
  }
  return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  unsigned char *p1 = ptr1;
  unsigned char *p2 = ptr2;
  size_t k = 0;
  for (k = 0; k < num; p1++, p2++, k++) {
    if (*p1 < *p2)
      return -1;
    if (*p1 > *p2)
      return 1;
  }
  return 0;
}

void *memset(void *source, int value, size_t num) {
  unsigned char *p;
  size_t k;
  for (p = source, k = 0; k < num; p++, k++)
    *p = value;
  return source;
}
