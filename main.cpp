#include <iostream>
using namespace std;

//________________________________РЕАЛИЗАЦИЯ ОДНОСВЯЗНОГО СПИСКА____________________________________________________________

template<typename T>
class List
{
public:
    List();//Комментарии в реализации
    ~List();//Комментарии в реализации
    void pop_front();//Комментарии в реализации
    void clear();//Комментарии в реализации
    void push_back(T data);//Комментарии в реализации
    int GetSize(){return Size;} // Возращает количество элементов списка
    T& operator[](const int index);//Комментарии в реализации
    void push_front(T data);//Комментарии в реализации
    void insert(T Value, int index);//Комментарии в реализации
    void removeAt(int index);//Комментарии в реализации
    void pop_back();//Комментарии в реализации

private:
    template<typename G>
    class Node // Класс отдельного Узла(данные и адрес)
    {

    public:
        Node* pNext;//указатель на следующий элемент
        T data;//данные
        Node(T data = T(), Node *pNext = nullptr)// значения по умолчанию, если нет передаваемых значений
        {
            this->data = data;// присваивание данных
            this->pNext = pNext;// присваивание адреса
        }
    };
    int Size;
    Node<T> *head;
};

//-----------------------------------------Конструктор и деструктор--------------------------------------------------
//Конструктор Лист
template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

//деструктор Лист
template<typename T>
List<T>::~List()
{
    clear();
}

//______________________________________________Методы класса_________________________________________________________

//метод удаляющий первый элемент списка
template<typename T>
void List<T>::pop_front()
{
    //присваиваем временной переменной temp адрес head
    Node<T> *temp = head;
    // а head присваиваем адрес следующего элемента
    head = head->pNext;
    //удаляем временную переменную temp
    delete temp;
    //так как мы удалаяем элемент списка не забываем про счётчик size
    Size--;
}

//метод удаляющий весь список
template<typename T>
void List<T>::clear()
{
    while(Size)
    {
        pop_front();
    }
}

//метод - добавить элемент в конец списка
template<typename T>
void List<T>::push_back(T data)
{
    if(head == nullptr)// первому элементу при
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

//метод возращающий данные по переданному индексу
template<typename T>
T &List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if(counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

//метод добавляющий элемент в начало списка
template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;

}

//метод добавляющий данные в определенный индекс и сдвигает остальные элементы вперед
template<typename T>
void List<T>::insert(T Value, int index)
{
    if(index == 0)
    {
        push_front(Value);
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }
        Node<T> *newNode = new Node<T>(Value, previous->pNext);
        previous->pNext = newNode;

        Size++;
    }
}


//метод удаляющий элемент по указанному индексу
template<typename T>
void List<T>::removeAt(int index)
{
    if(index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }
        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

//метод удаляющий последний элемент
template<typename T>
void List<T>::pop_back()
{
    removeAt(Size-1); // Просто отнимаем у счётчика size единицу и мы нашли последний элемент
}

//-------------------------------------------Функция main-------------------------------------------------------------
int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);

    cout << lst.GetSize() << endl;

    return 0;
}




