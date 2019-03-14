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
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = cicrcle, style = filled, fillcolor = seashell2];\n ");
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
        result.append("[ label = \" ");
        result.append((std::string)node->getData().name);
        result.append("\" ];");

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

void arrayList::add(deuxData data)
{
    Day* node = new Day(data);
    Day *pointer = head;
    Day *deuxPointer = head->getNext();

    if (pointer != nullptr)
    {
        if (node->getData().name < pointer->getData().name)
        {
            node->setNext(pointer);
            head = node;
        }
        else
        {
            while (deuxPointer)
            {
                if (node->getData().name < deuxPointer->getData().name)
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

std::string arrayList::getGraphic()
{
    std::string result;
    Day *pointer = head;
    int count = 0;

    while (pointer)
    {
        result.append(pointer->getData().name);
        result.append("" + count);
        result.append(" ");
        result.append("[ label = \" ");
        result.append(pointer->getData().name);
        result.append("\" ];\n");

        Day *temp = pointer->getNext();
        result.append(pointer->getData().name);
        result.append("" + count);
        result.append("->" + temp->getData().name);
        result.append( "" + (count + 1));
        result.append("\n");
        count++;

        pointer = temp;
    }

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

void Salones::add(Salon *node)
{
    Salon *pointer = head;
    Salon *deuxPointer = head->getNext();

    if (pointer != nullptr)
    {
        if (node->getData().name < pointer->getData().name)
        {
            node->setNext(pointer);
            head = node;
        }
        else
        {
            while (deuxPointer)
            {
                if (node->getData().name < deuxPointer->getData().name)
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

std::string Salones::getGraphic()
{
    std::string result;
    Salon *pointer = head;

    int count = 0;

    while (pointer)
    {
        result.append(pointer->getData().name);
        result.append("" + count);
        result.append(" ");
        result.append("[ label = \" ");
        result.append(pointer->getData().name);
        result.append("\" ];\n");

        Salon *temp = pointer->getNext();
        result.append(pointer->getData().name);
        result.append("" + count);
        result.append("->" + temp->getData().name);
        result.append( "" + (count + 1));
        result.append("\n");
        count++;

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

    while (pointer != last)
    {
        std::cout << "pasando una vez por el ciclo" << std::endl;
        if (node->getData().name < pointer->getData().name)
        {
            if (pointer == first)
            {
                first = node;
                node->setPrevious(nullptr);
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
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = record, style = filled, fillcolor = seashell2];\n");
    schedule *pointer = first;
    int count = 0;

    while (pointer)
    {
        result.append(pointer->getData().name);
        result.append("" + count);
        result.append(" ");
        result.append("[ label = \" ");
        result.append(pointer->getData().name);
        result.append("\" ];\n");

        schedule *temp = pointer->getNext();
        if(temp != nullptr){
            result.append(pointer->getData().name);
            result.append("" + count);
            result.append("->" + temp->getData().name);
            result.append( "" + (count + 1));
            result.append("\n");
        }

        schedule *previTemp = pointer->getPrevious();
        if(previTemp != nullptr){
            result.append(pointer->getData().name);
            result.append("" + count);
            result.append("->" + previTemp->getData().name);
            result.append( "" + (count - 1));
            result.append("\n");
        }

        count++;
        pointer = temp;
    }
    result.append("\n}");
    return result;
}
