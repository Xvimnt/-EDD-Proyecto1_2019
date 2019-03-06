#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

struct Data{
    std::string id;
    std::string name;
};

struct deuxData{
    std::string name;
};

//Defining salons
class Salon
{
    private:
     deuxData data;
     Salon* next;
     Salon* previous;

     public:
      Salon(deuxData data);
      deuxData getData();
      void setNext(Salon* node);
      Salon* getNext();
      Salon* getPrevious();
      void setPrevious(Salon* node);
};

class Build{
    private:
        deuxData data;
        Salon* salon;
        Build* up;
        Build* down;

    public:
        Build(deuxData data);
        deuxData getData();
        Build* getUp();
        Build* getDown();
        void setUp(Build* build);
        void setDown(Build* build);
};

//Defining Professor
 class Professor
{
 private:
        Data data;
        Professor* left;
        Professor* right;

    public:
        Professor(Data data);
        Data getData();
        Professor* getLeft() ;
        Professor* getRight();
        void setRight(Professor* node);
        void setLeft(Professor* node);
};

//Defining course
class Course{
    private:
     Data data;
     Professor* professor;
     Course* next;

     public:
        Course(Data data);
        void setNext(Course* node);
        Course* getNext();
        Data getData();
};

//Defining Days
class Day
{
    private:
        deuxData data;
        Day* next;

    public:
        Day(deuxData data);
        Day* getNext();
        void setNext(Day* node);
        deuxData getData();
};

#endif // NODE_H
