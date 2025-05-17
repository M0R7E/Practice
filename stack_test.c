#include "stack.h"
#include <assert.h>
#include <stdio.h>

void push_test() {
  int *st = stack();
  push(st, 777);
  push(st, 123);
  assert(is_in(st) == 1);
}

void pop_test() {
  int *st = stack();
  push(st, 777);
  push(st, 123);
  assert(pop(st) == 123 && pop(st) == 777 && is_in(st) == 0);
}

void empty_pop_test() {
  int *st = stack();
  assert(is_in(st) == 0 && pop(st) == 0);
}

void is_in_test() {
  int *st = stack();
  assert(is_in(st) == 0);
  push(st, 3);
  assert(is_in(st) == 1);
}

int main() {
  push_test();
  pop_test();
  empty_pop_test();
  is_in_test();
  return 0;
}
