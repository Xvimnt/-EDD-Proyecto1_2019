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
  std::string getGraphic();
  std::string getGraphic2(Professor *node);
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
  std::string getGraphic();
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
  std::string getGraphic();
};

class arrayList
{
private:
  Day *head;

public:
  Day *getHead();
  arrayList();
  void setHead(Day *node);
  void add(deuxData data);
  int getOrder(std::string dayName);
  std::string getGraphic();
};

class Salones
{
private:
  Salon *head;
  Salon *queue;

public:
  Salon *getHead();
  void setHead(Salon *node);
  Salon *getQueue();
  void setQueue(Salon *node);
  void add(deuxData data);
  std::string getGraphic();
};

class Horarios
{
private:
  schedule *first;
  schedule *last;

public:
  schedule *getFirst();
  schedule *getLast();
  void setFirst(schedule *node);
  void setLast(schedule *node);
  void add(deuxData node);
  void Insert(schedule *node);
  std::string getGraphic();
};

#endif // LIST_H
