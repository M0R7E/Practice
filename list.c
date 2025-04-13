#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int length(struct list *list) { return list->last->num + 1; }

int addL(struct list *list, int value) {
  struct list *orig = list;
  list = list->last;
  list->next = malloc(sizeof(struct list));
  list->next->num = list->num + 1;
  list->next->val = value;
  orig->last = list->next;

  return 0;
}

int addS(struct list *list, int value) {
  int count = list->last->num + 1;
  int prevV;
  addL(list, 0);
  for (int i = 0; i <= count; i++) {
    list->num = i;
    prevV = list->val;
    list->val = value;
    value = prevV;
    if (i < count) {
      list = list->next;
    }
  }
  return 0;
}

int addI(struct list *list, int index, int value) {
  if (!(index < length(list) && index >= 0))
    exit(EXIT_FAILURE);
  int len = list->last->num;
  if (index == list->last->num) {
    addL(list, value);
  } else {
    for (int i = 0; i < index; i++)
      list = list->next;
    struct list *next = list->next;
    list->next = malloc(sizeof(struct list));
    list->next->val = value;
    list->next->num = list->num + 1;
    list = list->next;
    list->next = next;

    for (int i = list->num + 1; i <= len + 1; i++) {
      list = list->next;
      list->num = i;
    }
  }
  return 0;
}

int findByIndex(struct list *list, int index) {
  for (int i = 0; i < index; i++)
    list = list->next;
  return list->val;
}

int removeI(struct list *list, int index) {
  int last = list->last->num;
  struct list *orig = list;
  if (index != last) {
    for (int i = 0; i < index; i++)
      list = list->next;
    for (int i = index; i < last; i++) {
      list->val = list->next->val;
      if (i == last - 1) {
        orig->last = list;
        free(list->next);
        list->next = NULL;
      } else {
        list = list->next;
      }
    }
  } else {
    if (last > 0) {
      for (int i = 0; i < last - 1; i++)
        list = list->next;
      free(list->next);
      list->next = NULL;
      orig->last = list;
    } else {
      free(list);
    }
  }
  return 0;
}