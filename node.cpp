#include "node.h"

// Here starts the  methods for Professor

Professor *Professor::getLeft()
{
    return left;
}

Professor *Professor::getRight()
{
    return right;
}

void Professor::setRight(Professor *node)
{
    right = node;
}

void Professor::setLeft(Professor *node)
{
    left = node;
}

Professor::Professor(Data data)
{
    data = data;
    left = nullptr;
    right = nullptr;
}

Data Professor::getData()
{
    return data;
}

//Here starts the course implementation
Data Course::getData()
{
    return data;
}

Course::Course(Data data)
{
    this->data = data;
}

Course *Course::getNext()
{
    return this->next;
}

void Course::setNext(Course *node)
{
    this->next = node;
}

//Here starts the buildings implementation
deuxData Build::getData()
{
    return data;
}

Build::Build(deuxData data)
{
    this->data = data;
    up = nullptr;
    down = nullptr;
}

Build *Build::getUp()
{
    return up;
}

Build *Build::getDown()
{
    return down;
}

void Build::setUp(Build *build)
{
    up = build;
}
void Build::setDown(Build *build)
{
    down = build;
}

//Here starts the methods for the days

Day::Day(deuxData data)
{
    this->data = data;
}

Day *Day::getNext()
{
    return next;
}

void Day::setNext(Day *node)
{
    next = node;
}

deuxData Day::getData()
{
    return data;
}

//Here starts the methods for the salon

Salon::Salon(deuxData data){
    data = data;
    next = nullptr;
}
      deuxData Salon::getData(){
          return data;
      }

      void Salon::setNext(Salon* node){
          next = node;
      }
      Salon* Salon::getNext(){
          return next;
      }

      Salon* Salon::getPrevious(){
          return previous;
      }
      void Salon::setPrevious(Salon* node){
          previous = node;
      }