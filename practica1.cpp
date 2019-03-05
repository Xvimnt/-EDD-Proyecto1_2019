
#include "practica1.h"

BinaryTree maestros;
CircularList cursos;

std::string practica1::newProfessor(const Data& data){
        maestros.add(data);
        return "ok";
}

std::string practica1::newCourse(const Data& data){
        cursos.add(data);
        return "ok";
}
