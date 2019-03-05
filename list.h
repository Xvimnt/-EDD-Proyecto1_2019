#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <string>

class BinaryTree
{

private:
  Professor *root;

public:
  void add(Data data);
  BinaryTree();
  Professor *getRoot();
  void setRoot(Professor *professor);
  void Insert(Professor *professor, Professor *pointer);
};

class CircularList
{
private:
  Course *first;
  Course *last;

public:
  void add(Data data);
  CircularList();
  Course *getFirst();
  Course *getLast();
  void setFirst(Course *node);
  void setLast(Course *node);
};

class doubleLinkedList
{
private:
  Build *first;
  Build *last;

public:
  Build *getFirst();
  Build *getLast();
  void setFirst(Build *node);
  void setLast(Build *node);
  void add(deuxData node);
  void Insert(Build *node);
};

class arrayList
{
private:
  Day *head;
  deuxData data;

public:
  Day *getHead();
  arrayList(deuxData data);
  void setHead(Day *node);
  void add(Day *node);
};

#endif // LIST_H
