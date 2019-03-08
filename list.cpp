#include "list.h"

//------------ Metodos del arbol binario -----------------

BinaryTree::BinaryTree()
{
    this->setRoot(nullptr);
}

void BinaryTree::add(Data data)
{
    Professor *root = getRoot();
    Professor *temp = new Professor(data);
    if (root != nullptr)
    {
        Insert(temp, root);
    }
    else
    {
        setRoot(temp);
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

std::string* BinaryTree::getGraphic(){
    std::string* result;
    return getGraphic(root, result);
}

std::string* BinaryTree::getGraphic(Professor* node , std::string* result){

        result->append(node->getData().id);
        result->append("[ label = \" ");
        result->append(node->getData().name);
        result->append("\" ];\n");

        Professor* izq = node->getLeft();
        Professor* der = node->getRight();

        if(izq != nullptr){
            result->append(node->getData().id);
            result->append(":C0->");
            result->append(izq->getData().id);
            getGraphic(izq, result);
        }
        if(der != nullptr){
            result->append(node->getData().id);
            result->append(":C1->");
            result->append(der->getData().id);
            getGraphic(der, result);
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

std::string CircularList::getGraphic(){
    std::string result;
    Course* pointer = first;

    while(pointer != last){
        result.append(pointer->getData().id);
        result.append(" ");
        result.append(pointer->getData().name);
        result.append("\n");
        pointer = pointer->getNext();
    }
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

    while (pointer)
    {
        if (node->getData().name < pointer->getData().name)
        {
            if (pointer == first)
            {
                first = node;
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
    node->setUp(pointer);
    pointer->setDown(node);
    last = node;
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

std::string doubleLinkedList::getGraphic(){
    std::string result;
    
    Build* pointer = first;

    while(pointer){
        result.append(pointer->getData().name);
        result.append("\n");
        pointer->getDown();
    }

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

void arrayList::add(Day *node)
{
    Day *pointer = head;
    Day *deuxPointer = head->getNext();

    if (pointer != nullptr)
    {
        if (node->getData().name < pointer->getData.name)
        {
            node->setNext(pointer);
            head = node;
        }
        else
        {
            while (deuxPointer)
            {
                if (node->getData().name < deuxPointer->getData.name)
                {
                    pointer->setNext(node);
                    node->setNext(deuxPointer);
                    return;
                }
                else
                {
                    pointer = pointer->getNext();
                    deuxPointer = deuxPointer->getNext();
                }
            }
            pointer->setNext(node);
        }
    }
    else
    {
        head = node;
    }
}

std::string arrayList::getGraphic(){
    std::string result;
    Day* pointer = head;

    while(pointer){
        result.append(pointer->getData().name);
        result.append("\n");
        pointer->getNext();
    }

    return result;
}

//-----------------Metodos de la lista ordenada de saloness---------

Salon *Salones::getHead()
{
    return head;
}
void Salones::setHead(Salon *node)
{
    head = node;
}

void Salones::add(Salon *node)
{
    Salon *pointer = head;
    Salon *deuxPointer = head->getNext();

    if (pointer != nullptr)
    {
        if (node->getData().name < pointer->getData.name)
        {
            node->setNext(pointer);
            head = node;
        }
        else
        {
            while (deuxPointer)
            {
                if (node->getData().name < deuxPointer->getData.name)
                {
                    pointer->setNext(node);
                    node->setNext(deuxPointer);
                    return;
                }
                else
                {
                    pointer = pointer->getNext();
                    deuxPointer = deuxPointer->getNext();
                }
            }
            pointer->setNext(node);
        }
    }
    else
    {
        head = node;
    }
}

std::string Salones::getGraphic(){
    std::string result;
    Salon* pointer = head;

    while(pointer){
        result.append(pointer->getData().name);
        result.append("\n");
        pointer->getNext();
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

    while (pointer)
    {
        if (node->getData().name < pointer->getData().name)
        {
            if (pointer == first)
            {
                first = node;
            }
            else
            {
                //Desenlaza el nodo arriba del puntero
                schedule *up = pointer->getPrevious();
                up->setNext(node);
                node->setPrevious(up);
            }

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
    node->setPrevious(pointer);
    pointer->setNext(node);
    last = node;
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

std::string Horarios::getGraphic(){
    std::string result;
    schedule* pointer = first;

    while(pointer){
        result.append(pointer->getData().name);
        result.append("\n");
        pointer->getNext();
    }

    return result;
}
