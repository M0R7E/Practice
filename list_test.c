#include "list.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

void test_1() {
  struct list list;
  list.num = 0;
  list.val = 10; // это значение первого элемента
  list.last = &list;
  addS(&list, 1);
  addL(&list, 2);
  addI(&list, 2, 3);
  assert(findByIndex(&list, 0) == 1 && findByIndex(&list, 1) == 10 &&
         findByIndex(&list, 2) == 2 && findByIndex(&list, 3) == 3);
}

void test_2() {
  struct list list;
  list.num = 0;
  list.val = 10; // это значение первого элемента
  list.last = &list;
  addS(&list, 1);
  addL(&list, 2);
  addI(&list, 2, 3);
  removeI(&list, 1);
  assert(findByIndex(&list, 0) == 1 && findByIndex(&list, 1) == 2 &&
         findByIndex(&list, 2) == 3);
}

void test_3() {
  struct list list;
  list.num = 0;
  list.val = 10; // это значение первого элемента
  list.last = &list;
  addS(&list, 1);
  addL(&list, 2);
  addI(&list, 2, 3);
  assert(length(&list) == 4);
}

int main() {
  test_1();
  test_2();
  test_3();

  return 0;
}