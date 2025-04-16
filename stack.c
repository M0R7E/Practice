#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int *Stack() {
  int *stack = malloc(sizeof(int));
  stack[0] = 0;
  return stack;
}

int Push(int *stack, int value) {
  stack = realloc(stack, sizeof(stack) + sizeof(int));
  stack[0] = stack[0] + 1;
  stack[stack[0]] = value;
  return 0;
}

int isIn(int *stack) {
  if (stack[0] == 0) {
    return 0;
  } else
    return 1;
}

int Pop(int *stack) {
  if (isIn(stack)) {
    int result = stack[stack[0]];
    stack = realloc(stack, sizeof(stack) - 1);
    stack[0] = stack[0] - 1;
    return result;
  } else
    exit(EXIT_FAILURE);
}