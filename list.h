struct list {
  int val;
  int num;
  struct list *last;
  struct list *next;
};
int length(struct list *list);
int addL(struct list *list, int value); // Добавляет в конец списка
int addS(struct list *list, int value); // Добавляет в начало списка
int addI(struct list *list, int index,
         int value); // Добавляет после выбранного индекса
int findByIndex(struct list *list, int index); // Ищет значение по индексу
int removeI(struct list *list, int index); // Удаляет элемент по индексу