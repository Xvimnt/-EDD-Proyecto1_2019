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
std::list<Salon> Build::getSalones()
{
    return salones;
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

Matrix* Day::getMatrixNode(){
    return matriz;
}
    void Day::setMatrixNode(Matrix* node){
        matriz = node;
    }
//Here starts the methods for the salon

Salon::Salon(deuxData data)
{
    data = data;
    down = nullptr;
}
deuxData Salon::getData()
{
    return data;
}

void Salon::setNext(Salon *node)
{
    down = node;
}
Salon *Salon::getNext()
{
    return down;
}
cell *Salon::getRight()
{
    return right;
}
void Salon::setRight(cell *node)
{
    right = node;
}

//metodos para los horarios
schedule::schedule(deuxData data)
{
    this->data = data;
}
schedule *schedule::getNext()
{
    return next;
}
void schedule::setNext(schedule *node)
{
    next = node;
}
schedule *schedule::getPrevious()
{
    return previous;
}
void schedule::setPrevious(schedule *node)
{
    previous = node;
}
deuxData schedule::getData()
{
    return data;
}
cell *schedule::getLower()
{
    return down;
}
void schedule::setLower(cell *node)
{
    down = node;
}

//Metodos para la celda
cell::cell(Course *curso, Professor *catedratico)
{
    curso = curso;
    catedratico = catedratico;
}
void cell::setLeft(cell *node)
{
    left = node;
}
void cell::setRight(cell *node)
{
    right = node;
}
void cell::setUpper(cell *node)
{
    up = node;
}
void cell::setLower(cell *node)
{
    down = node;
}

cell *cell::getLeft()
{
    return left;
}
cell *cell::getRight()
{
    return right;
}
cell *cell::getUp()
{
    return up;
}
cell *cell::getDown()
{
    return down;
}

//definiendo el nodo matriz
Salon* Matrix::getFirstRow()
{
    return firstRow;
}
    schedule* Matrix::getFirstCol(){
        return firstCol;
    }
    void Matrix::setFirstRow(Salon* node){
        firstRow = node;
    }
    void Matrix::setFirstCol(schedule* node){
        firstCol = node;
    }