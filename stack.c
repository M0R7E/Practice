#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int *stack() {
  int *stack = malloc(sizeof(int));
  stack[0] = 0;
  return stack;
}

int push(int *stack, int value) {
  stack = realloc(stack, sizeof(stack) + sizeof(int));
  stack[0] = stack[0] + 1;
  stack[stack[0]] = value;
  return 0;
}

int is_in(int *stack) { return stack[0] != 0; }

int pop(int *stack) {
  if (is_in(stack)) {
    int result = stack[stack[0]];
    stack = realloc(stack, sizeof(stack) - sizeof(int));
    stack[0] = stack[0] - 1;
    return result;
  }
  return 0;
}
