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

std::list<Data> BinaryTree::getList()
{
    std::list<Data> result;
    std::list<Professor *> queue;

    if (root != nullptr)
        queue.push_back(root);

    //Se realiza el recorrido en inorden para mostrar la lista ordenada
    while (!queue.empty())
    {
        Professor *node = queue.front();
        queue.pop_front();

        if (node != nullptr)
        {
            result.push_back(node->getData());

            Professor *izq = node->getLeft();
            Professor *der = node->getRight();

            if (izq != nullptr)
            {
                queue.push_back(izq);
            }
            if (der != nullptr)
            {
                queue.push_back(der);
            }
        }
    }

    return result;
}

std::string BinaryTree::getGraphic()
{
    std::string result;
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = record, style = filled, fillcolor = seashell2];\n ");
    result.append(getGraphic2(getRoot()));

    result.append(" \n }");

    return result;
}

std::string BinaryTree::getGraphic2(Professor *node)
{
    std::string result;

    if (node != nullptr)
    {
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

Professor *BinaryTree::get(std::string id)
{
    if(root == nullptr) return nullptr;
    Professor* pointer = root;

    while(pointer->getData().id != id || pointer != nullptr){
        if(id < pointer->getData().id) pointer = pointer->getLeft();
        else pointer = pointer->getRight();
    }
    return nullptr;
}

void BinaryTree::modify(Professor *node, std::string newId, std::string newName)
{
    unlink(node);
    node->getData().id = newId;
    node->getData().name = newName;
    Insert(node,root);
}

void BinaryTree::unlink(Professor* node){
    Professor *padre = getParent(node);
    if (node->getLeft() != nullptr && node->getRight() != nullptr)
    {
        Professor *sucesor = getSucesor(node);
        if (padre->getLeft() == node)
        {
            padre->setLeft(sucesor);
        }
        else
        {
            padre->setRight(sucesor);
        }
        sucesor->setRight(node->getRight());
        sucesor->setLeft(node->getLeft());
    }
    else if (node->getLeft() == nullptr)
    {
        Professor *sucesor = getSucesor(node);
        if (padre->getLeft() == node)
        {
            padre->setLeft(sucesor);
        }
        else
        {
            padre->setRight(sucesor);
        }
        sucesor->setRight(node->getRight());
    }
    else if (node->getRight() == nullptr)
    {
        Professor *predecesor = getPredecesor(node);
        if (padre->getLeft() == node)
        {
            padre->setLeft(predecesor);
        }
        else
        {
            padre->setRight(predecesor);
        }
        predecesor->setLeft(node->getLeft());
    }
}

void BinaryTree::Delete(Professor *node)
{
    unlink(node);
    //Vaciar el puntero
    free(node);
}

Professor *BinaryTree::getSucesor(Professor *node)
{
    Professor *pointer = node->getRight();

    while (pointer->getLeft() != nullptr)
    {
        pointer = pointer->getLeft();
    }
    //limpiar el apuntador del nodo padre
    cleanParentPointer(pointer);

    return pointer;
}

void BinaryTree::cleanParentPointer(Professor *node)
{
    Professor *padre = getParent(node);

    if (padre->getLeft() == node)
    {
        padre->setLeft(nullptr);
    }
    else
    {
        padre->setRight(nullptr);
    }
}

Professor *BinaryTree::getPredecesor(Professor *node)
{
    Professor *pointer = node->getLeft();

    while (pointer->getRight() != nullptr)
    {
        pointer = pointer->getRight();
    }
    //limpiar el apuntador del nodo padre
    cleanParentPointer(pointer);

    return pointer;
}

Professor *BinaryTree::getParent(Professor *node)
{
    std::list<Professor *> queue;

    if (root != nullptr)
        queue.push_back(root);

    //Se realiza el recorrido en inorden para mostrar la lista ordenada
    while (!queue.empty())
    {
        Professor *pointer = queue.front();
        queue.pop_front();

        if (pointer != nullptr)
        {
            Professor *izq = pointer->getLeft();
            Professor *der = pointer->getRight();

            if (izq == node || der == node)
                return pointer;

            if (izq != nullptr)
            {
                queue.push_back(izq);
            }
            if (der != nullptr)
            {
                queue.push_back(der);
            }
        }
    }

    return nullptr;
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
        //Inserta el nodo ordenadamente
        Insert(temp);
    }
    else
    {
        first = temp;
        last = temp;
        temp->setNext(temp);
    }
}

void CircularList::Insert(Course *node)
{
    Course *pointer = first;
    Course *previous;

    if (node->getData().name < pointer->getData().name)
    {
        first = node; //ya que el puntero se empieza con head si es menor entonces el nuevo sera la nueva cabeza
        node->setNext(pointer);
    }
    else
    {
        do
        {
            //obtiene el nodo puntero siguiente y guarda el nodo puntero actual
            previous = pointer;
            pointer = pointer->getNext();

            if (pointer == first)
            {
                //si el puntero siguiente ya es el ultimo entonces node será la nueva cola
                previous->setNext(node);
                node->setNext(first);
                last = node;
                return;
            }
        } while (node->getData().name > pointer->getData().name);
        previous->setNext(node);
        node->setNext(pointer);
    }
}

std::list<Data> CircularList::getList()
{
    std::list<Data> result;

    Course *pointer = first;
    if (pointer != nullptr)
    {
        do
        {
            result.push_back(pointer->getData());
            pointer = pointer->getNext();

        } while (pointer != last);
    }

    return result;
}

std::string CircularList::getGraphic()
{
    if (first == nullptr)
        return "null";

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

Course *CircularList::get(std::string id)
{
    Course *pointer = first;

    while (pointer != last)
    {
        if (pointer->getData().id == id)
            return pointer;
        pointer = pointer->getNext();
    }
    return nullptr;
}

void CircularList::modify(Course *node, std::string newId, std::string newName)
{
    //Get the previous one
    Course *pointer = first;
    while (pointer->getNext()->getData().id != node->getData().id)
    {
        pointer = pointer->getNext();
    }

    //Desenlazar el nodo a modificar
    pointer->setNext(node->getNext());

    //modificar el nodo
    node->getData().name = newName;
    node->getData().id = newId;

    //Insertar el nodo ordenadamente
    Insert(node);
}

void CircularList::Delete(Course *node)
{
    //Conseguir el primer nodo de la lista
    Course *pointer = first;

    //si es el primero el que se quiere borrar
    if (node == pointer)
    {
        first = node->getNext();
    }
    else
    {
        Course *previous;
        //Conseguir el nodo anterior
        do
        {
            previous = pointer;
            pointer = pointer->getNext();

        } while (pointer != node);

        //Se desenlaza el nodo de su posicion de la lista
        previous->setNext(node->getNext());
    }

    //Limpiar el puntero
    free(node);
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

void doubleLinkedList::add(Data node)
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

std::list<Data> doubleLinkedList::getList()
{
    std::list<Data> result;
    Build *pointer = first;

    while (pointer != nullptr)
    {
        result.push_back(pointer->getData());
        pointer = pointer->getDown();
    }

    return result;
}

std::string doubleLinkedList::getGraphic()
{
    std::string result;
    result.append("digraph grafica{ \n rankdir = TB; \n node[shape = record, style = filled, fillcolor = seashell2];");
    Build *pointer = first;

    while (pointer)
    {
        result.append(" \n ");
        result.append(pointer->getData().id);
        result.append("[ label = \" ");
        result.append(pointer->getData().id);
        result.append("\" ];");

        Build *temp = pointer->getDown();
        if (temp != nullptr)
        {
            result.append(" \n ");
            result.append(pointer->getData().id);
            result.append(" -> " + temp->getData().id);
        }

        Build *previTemp = pointer->getUp();
        if (previTemp != nullptr)
        {
            result.append(" \n ");
            result.append(pointer->getData().id);
            result.append(" -> " + previTemp->getData().id);
        }
        pointer = temp;
    }
    result.append(" \n }");
    return result;
}

Build *doubleLinkedList::get(std::string name)
{
    Build *pointer = first;

    while (pointer != nullptr)
    {
        if (pointer->getData().id == name)
            return pointer;
        pointer = pointer->getDown();
    }
    return nullptr;
}

void doubleLinkedList::modify(Build *node, std::string newName, std::string newOcc)
{
    Build *previous = node->getUp();
    Build *next = node->getDown();

    //desvincular el nodo de sus hermanos
    previous->setDown(next);
    next->setUp(previous);

    //setear el nuevo valor
    node->getData().id = newName;
    node->getData().name = newOcc;

    //Insertar el nodo ordenadamente
    Insert(node);
}

void doubleLinkedList::Delete(Build *node)
{
    Build *previous = node->getUp();
    Build *next = node->getDown();

    //desvincular el nodo de sus hermanos
    previous->setDown(next);
    next->setUp(previous);

    //vaciar memoria
    free(node);
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
    if (dayName == "domingo")
    {
        return 0;
    }
    else if (dayName == "lunes")
    {
        return 1;
    }
    else if (dayName == "martes")
    {
        return 2;
    }
    else if (dayName == "miercoles")
    {
        return 3;
    }
    else if (dayName == "jueves")
    {
        return 4;
    }
    else if (dayName == "viernes")
    {
        return 5;
    }
    else if (dayName == "sabado")
    {
        return 6;
    }
    else
        return -1;
}

void arrayList::add(deuxData data)
{
    Day *node = new Day(data);
    Day *pointer = head;
    Day *previous;

    if (pointer != nullptr)
    {
        int currentOrder = getOrder(data.name);
        int nextOrder = getOrder(pointer->getData().name);

        if (currentOrder < nextOrder)
        {
            head = node; //ya que el puntero se empieza con head si es menor entonces el nuevo sera la nueva cabeza
            node->setNext(pointer);
        }
        else
        {
            do
            {
                previous = pointer;
                pointer = pointer->getNext();
                if (pointer != nullptr)
                {
                    nextOrder = getOrder(pointer->getData().name);
                }
                else
                {
                    previous->setNext(node);
                    return;
                }
            } while (currentOrder > nextOrder);
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
        if (temp != nullptr)
        {
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
    Salon *node = new Salon(data);
    Salon *pointer = head;
    Salon *previous;

    if (pointer != nullptr)
    {

        if (data.name < pointer->getData().name)
        {
            head = node; //ya que el puntero se empieza con head si es menor entonces el nuevo sera la nueva cabeza
            node->setNext(pointer);
        }
        else
        {
            do
            {
                previous = pointer;
                pointer = pointer->getNext();
                if (pointer == nullptr)
                {
                    previous->setNext(node);
                    return;
                }
            } while (data.name > pointer->getData().name);
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
        if (temp != nullptr)
        {
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
        if (temp != nullptr)
        {
            result.append(" \n ");
            result.append(pointer->getData().name);
            result.append(" -> " + temp->getData().name);
        }

        schedule *previTemp = pointer->getPrevious();
        if (previTemp != nullptr)
        {
            result.append(" \n ");
            result.append(pointer->getData().name);
            result.append(" -> " + previTemp->getData().name);
        }
        pointer = temp;
    }
    result.append(" \n }");
    return result;
}
