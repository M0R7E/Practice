#include "stack.h"
#include <assert.h>
#include <stdio.h>

void test_1() {
  int *stack = Stack();
  Push(stack, 777);
  Push(stack, 123);
  assert(isIn(stack) == 1);
}

void test_2() {
  int *stack = Stack();
  Push(stack, 777);
  Push(stack, 123);
  assert(Pop(stack) == 123 && Pop(stack) == 777 && isIn(stack) == 0);
}

int main() {
  test_1();
  test_2();
  return 0;
}