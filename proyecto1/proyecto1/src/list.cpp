#include "list.h"

//------------ Metodos del arbol binario -----------------

BinaryTree::BinaryTree()
{
    this->setRoot(nullptr);
}

void BinaryTree::add(Data data)
{
    Professor *temp = new Professor(data);
    if (this->getRoot() != nullptr)
    {
        Insert(temp, root);
    }
    else
    {
        this->setRoot(temp);
    }
}

void BinaryTree::Insert(Professor *professor, Professor *pointer)
{
    if (professor->getData().id < pointer->getData().id)
    {
        Professor *left = pointer->getLeft();
        if (left != nullptr)
        {
            Insert(professor, left);
        }
        else
        {
            pointer->setLeft(professor);
        }
    }
    else if (professor->getData().id > pointer->getData().id)
    {
        Professor *right = pointer->getRight();
        if (right != nullptr)
        {
            Insert(professor, right);
        }
        else
        {
            pointer->setRight(professor);
        }
    }
}

Professor *BinaryTree::getRoot()
{
    return root;
}

void BinaryTree::setRoot(Professor *professor)
{
    root = professor;
}

std::string BinaryTree::getGraphic()
{
    std::string result;
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = record, style = filled, fillcolor = seashell2];\n ");
    result.append( getGraphic2(getRoot()));
    
    result.append(" \n }");

    return result;
}

std::string BinaryTree::getGraphic2(Professor *node)
{
    std::string result;

    if(node != nullptr){
        result.append(" \n ");
        result.append(node->getData().id);
        result.append("[ label = \" <C0>|");
        result.append((std::string)node->getData().name);
        result.append("|<C1> \" ];");

        Professor *izq = node->getLeft();
        Professor *der = node->getRight();

        if (izq != nullptr)
        {
            result.append(" \n ");
            result.append(node->getData().id);
            result.append(":C0->");
            result.append(izq->getData().id);
            result.append(getGraphic2(izq));
        }
        if (der != nullptr)
        {
            result.append(" \n ");
            result.append(node->getData().id);
            result.append(":C1->");
            result.append(der->getData().id);
            result.append(getGraphic2(der));
        }
    }
    return result;
}

//---------------Metodos de la lista circular--------------
CircularList::CircularList()
{
    this->setFirst(nullptr);
}

void CircularList::setFirst(Course *node)
{
    first = node;
}

void CircularList::setLast(Course *node)
{
    last = node;
}

void CircularList::add(Data data)
{
    Course *temp = new Course(data);

    if (first != nullptr)
    {
        last->setNext(temp);
        temp->setNext(first);
        last = temp;
    }
    else
    {
        first = temp;
        last = temp;
        temp->setNext(temp);
    }
}

std::string CircularList::getGraphic()
{
    if(first == nullptr) return "null";

    std::string result;
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = record, style = filled, fillcolor = seashell2];");

    Course *pointer = first;
    Course *flag;
    
    do 
    {   
        result.append(" \n ");
        result.append(pointer->getData().id);
        result.append(" ");
        result.append("[ label = \" ");
        result.append(pointer->getData().name);
        result.append(" \" ]; \n ");

        Course *temp = pointer->getNext();
        result.append(pointer->getData().id + "->" + temp->getData().id);
        flag = pointer;
        pointer = temp;
        
    } while (flag != last);

    result.append(" \n }");
    return result;
}

// ----------------Metodos de lista doblemente enlazada----------

void doubleLinkedList::setFirst(Build *node)
{
    first = node;
}

void doubleLinkedList::setLast(Build *node)
{
    last = node;
}

void doubleLinkedList::Insert(Build *node)
{
    Build *pointer = first;

    while (pointer != last)
    {
        std::cout << "pasando una vez por el ciclo" << std::endl;
        if (node->getData().name < pointer->getData().name)
        {
            if (pointer == first)
            {
                first = node;
                node->setUp(nullptr);
            }
            else
            {
                //Desenlaza el nodo arriba del puntero
                Build *up = pointer->getUp();
                up->setDown(node);
                node->setUp(up);
            }

            //Setea los apuntadores para el nuevo nodo
            node->setDown(pointer);
            pointer->setUp(node);

            return;
        }
        else
        {
            pointer = pointer->getDown();
          
        }
    }
    last = node;
    node->setDown(nullptr);
    node->setUp(pointer);
    pointer->setDown(node);
}

void doubleLinkedList::add(deuxData node)
{
    Build *temp = new Build(node);

    if (first != nullptr)
    {
        Insert(temp);
    }
    else
    {
        first = temp;
        last = temp;
        temp->setUp(nullptr);
        temp->setDown(nullptr);
    }
}

std::string doubleLinkedList::getGraphic()
{
    std::string result;
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = record, style = filled, fillcolor = seashell2];");
    Build *pointer = first;

    while (pointer)
    {
        result.append(" \n ");
        result.append(pointer->getData().name);
        result.append("[ label = \" ");
        result.append(pointer->getData().name);
        result.append("\" ];");

        Build *temp = pointer->getDown();
        if(temp != nullptr){
            result.append(" \n ");
            result.append(pointer->getData().name);
            result.append(" -> " + temp->getData().name);
        }

        Build *previTemp = pointer->getUp();
        if(previTemp != nullptr){
            result.append(" \n ");
            result.append(pointer->getData().name);
            result.append(" -> " + previTemp->getData().name);
        }
        pointer = temp;
    }
    result.append(" \n }");
    return result;
}

//------------------------------Metodos de lista simple ordenada------------------

Day *arrayList::getHead()
{
    return head;
}

arrayList::arrayList()
{
    head = nullptr;
}

void arrayList::setHead(Day *node)
{
    head = node;
}

int arrayList::getOrder(std::string dayName)
{
    if(dayName == "domingo"){
        return 0;
    }else if(dayName == "lunes"){
        return 1;
    }else if(dayName == "martes"){
        return 2;
    }else if(dayName == "miercoles"){
        return 3;
    }else if(dayName == "jueves"){
        return 4;
    }else if(dayName == "viernes"){
        return 5;
    }else if(dayName == "sabado"){
        return 6;
    }
    else return -1;
}

void arrayList::add(deuxData data)
{
    Day* node = new Day(data);
    Day *pointer = head;
    Day *previous;

    if (pointer != nullptr)
    {
        int currentOrder = getOrder(data.name);
        int nextOrder = getOrder(pointer->getData().name);

        if(currentOrder < nextOrder)
        {
            head = node; //ya que el puntero se empieza con head si es menor entonces el nuevo sera la nueva cabeza
            node->setNext(pointer);
        }
        else
        {
            do{
                previous = pointer;
                pointer = pointer->getNext();
                if(pointer != nullptr)
                {
                    nextOrder = getOrder(pointer->getData().name);
                }
                else
                {
                    previous->setNext(node);
                    return;
                }
            }while(currentOrder > nextOrder);
            previous->setNext(node);
            node->setNext(pointer);
        }
    }        
    else
    {
        head = node;
    }
}

std::string arrayList::getGraphic()
{
    std::string result;
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = record, style = filled, fillcolor = seashell2]; ");
    Day *pointer = head;

    while (pointer != nullptr)
    {
        result.append(" \n ");
        result.append(pointer->getData().name);
        result.append("[ label = \" ");
        result.append(pointer->getData().name);
        result.append("\" ];");

        Day *temp = pointer->getNext();
        if(temp != nullptr){
            std::cout << "apuntando a " << temp->getData().name << std::endl;
            result.append(" \n ");
            result.append(pointer->getData().name);
            result.append("->" + temp->getData().name);
        }
        pointer = temp;
    }

    result.append(" \n ");
    result.append("}");

    return result;
}

//-----------------Metodos de la lista ordenada de salones---------

Salon *Salones::getHead()
{
    return head;
}
void Salones::setHead(Salon *node)
{
    head = node;
}

void Salones::add(deuxData data)
{
    Salon* node = new Salon(data);
    Salon *pointer = head;
    Salon *previous;

    if (pointer != nullptr)
    {
        
        if( data.name < pointer->getData().name)
        {
            head = node; //ya que el puntero se empieza con head si es menor entonces el nuevo sera la nueva cabeza
            node->setNext(pointer);
        }
        else
        {
            do{
                previous = pointer;
                pointer = pointer->getNext();
                if(pointer == nullptr)
                {
                    previous->setNext(node);
                    return;
                }
            }while(data.name > pointer->getData().name);
            previous->setNext(node);
            node->setNext(pointer);
        }
    }        
    else
    {
        head = node;
    }
}

std::string Salones::getGraphic()
{
    std::string result;
    Salon *pointer = head;

    while (pointer != nullptr)
    {
        std::cout << "inicializando a " << pointer->getData().name << std::endl;
        result.append("\n");
        result.append(pointer->getData().name);
        result.append("[ label = \" ");
        result.append(pointer->getData().name);
        result.append("\" ];");

        Salon *temp = pointer->getNext();
        if(temp != nullptr){
            std::cout << "apuntando a " << temp->getData().name << std::endl;
            result.append("\n");
            result.append(pointer->getData().name);
            result.append("->" + temp->getData().name);
        }

        pointer = temp;
    }

    return result;
}

//Definiendo doubled linked list de horarios--------------------

void Horarios::setFirst(schedule *node)
{
    first = node;
}

void Horarios::setLast(schedule *node)
{
    last = node;
}

void Horarios::Insert(schedule *node)
{
    schedule *pointer = first;
    if (node->getData().name < pointer->getData().name)
        {
            first = node;
            node->setPrevious(nullptr);
            node->setNext(pointer);
            pointer->setPrevious(node);
            return;
        }
        
    while (pointer != last)
    {
        if (node->getData().name < pointer->getData().name)
        {
                //Desenlaza el nodo arriba del puntero
                schedule *up = pointer->getPrevious();
                up->setNext(node);
                node->setPrevious(up);

            //Setea los apuntadores para el nuevo nodo
            node->setNext(pointer);
            pointer->setPrevious(node);
            return;
        }
        else
        {
            pointer = pointer->getNext();
          
        }
    }
    last = node;
    node->setNext(nullptr);
    node->setPrevious(pointer);
    pointer->setNext(node);
}

void Horarios::add(deuxData node)
{
    schedule *temp = new schedule(node);

    if (first != nullptr)
    {
        Insert(temp);
    }
    else
    {
        first = temp;
        last = temp;
        temp->setPrevious(nullptr);
        temp->setNext(nullptr);
    }
}

std::string Horarios::getGraphic()
{
    std::string result;
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = record, style = filled, fillcolor = seashell2];");
    schedule *pointer = first;

    while (pointer)
    {
        result.append(" \n ");
        result.append(pointer->getData().name);
        result.append("[ label = \" ");
        result.append(pointer->getData().name);
        result.append("\" ];");

        schedule *temp = pointer->getNext();
        if(temp != nullptr){
            result.append(" \n ");
            result.append(pointer->getData().name);
            result.append(" -> " + temp->getData().name);
        }

        schedule *previTemp = pointer->getPrevious();
        if(previTemp != nullptr){
            result.append(" \n ");
            result.append(pointer->getData().name);
            result.append(" -> " + previTemp->getData().name);
        }
        pointer = temp;
    }
    result.append(" \n }");
    return result;
}
