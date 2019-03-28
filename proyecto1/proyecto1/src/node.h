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

struct curso{
  std::string codigo;
  std::string curso;
  std::string catedratico;
};

struct salData{
  std::string edificio;
  std::string salon;
  std::string capacidad;
};

//Defining salons
class Salon
{
  private:
    Data data;
    Salon *down;
    cell* right;

  public:
    Salon(Data data);
    Data getData();
    void setNext(Salon *node);
    Salon *getNext();
    cell* getRight();
    void setRight(cell* node);
};

class Salones;

class Build
{
  private:
    deuxData data;
    Salon *salon;
    Build *up;
    Build *down;
    Salones *salones;

  public:
    Build(deuxData data);
    deuxData getData();
    Build *getUp();
    Build *getDown();
    void setUp(Build *build);
    void setDown(Build *build);
    Salones *getSalones();
};

class Course;

//Defining Professor
class Professor
{
  private:
    Data data;
    Professor *left;
    Professor *right;
    Course* curso;

  public:
    Professor(Data data);
    Data getData();
    Professor *getLeft();
    Professor *getRight();
    Course* getCurso();
    void setRight(Professor *node);
    void setLeft(Professor *node);
    void setCurso(Course *node);
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
