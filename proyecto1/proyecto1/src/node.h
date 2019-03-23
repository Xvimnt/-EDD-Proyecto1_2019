#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <list>

class cell;
class Matrix;

struct Data
{
    std::string id;
    std::string name;
};

struct deuxData
{
    std::string name;
};

//Defining salons
class Salon
{
  private:
    deuxData data;
    Salon *down;
    cell* right;

  public:
    Salon(deuxData data);
    deuxData getData();
    void setNext(Salon *node);
    Salon *getNext();
    cell* getRight();
    void setRight(cell* node);
};

class Build
{
  private:
    Data data;
    Salon *salon;
    Build *up;
    Build *down;
    std::list<Salon> salones;

  public:
    Build(Data data);
    Data getData();
    Build *getUp();
    Build *getDown();
    void setUp(Build *build);
    void setDown(Build *build);
    std::list<Salon> getSalones();
};

//Defining Professor
class Professor
{
  private:
    Data data;
    Professor *left;
    Professor *right;

  public:
    Professor(Data data);
    Data getData();
    Professor *getLeft();
    Professor *getRight();
    void setRight(Professor *node);
    void setLeft(Professor *node);
};

//Defining course
class Course
{
  private:
    Data data;
    Professor *professor;
    Course *next;

  public:
    Course(Data data);
    void setProfessor(Professor* node);
    void setNext(Course *node);
    Course *getNext();
    Data getData();
};

//Defining Days
class Day
{
  private:
    deuxData data;
    Day *next;
    Matrix* matriz;

  public:
    Day(deuxData data);
    Day *getNext();
    void setNext(Day *node);
    deuxData getData();
    Matrix* getMatrixNode();
    void setMatrixNode(Matrix* node);
};

//Definiendo horarios
class schedule
{
  private:
    deuxData data;
    schedule *next;
    schedule *previous;
    cell* down;

  public:
    schedule(deuxData data);
    schedule *getNext();
    void setNext(schedule *node);
    schedule *getPrevious();
    void setPrevious(schedule *node);
    deuxData getData();
    cell* getLower();
    void setLower(cell* node);
};

//Definiendo Celda
class cell
{
  private:
    Course *curso;
    Professor *catedratico;
    cell *left;
    cell *right;
    cell *up;
    cell *down;

  public:
    cell(Course *curso, Professor *catedratico);
    void setLeft(cell *node);
    void setRight(cell *node);
    void setUpper(cell *node);
    void setLower(cell *node);
    cell *getLeft();
    cell *getRight();
    cell *getUp();
    cell *getDown();
};

//definiendo el nodo matriz
class Matrix
{
  private:
    Salon* firstRow;
    schedule* firstCol;

  public:
    Salon* getFirstRow();
    schedule* getFirstCol();
    void setFirstRow(Salon* node);
    void setFirstCol(schedule* node);
};

#endif // NODE_H
