// Корнилов Сергей
// Группа 1861
// С++ Сложные моменты
// Урок 3



#include <iostream>
#include <list>
#include <vector>
// Задание 1
template <class T>
void PushBack(T*l)
{
    size_t size = 0;
    double res = 0;
    for (auto x : *l)
    {
        size++;
        res += x;
    }
    res = res / static_cast<double>(size);
    l->push_back(res);
}

//Задание 2
void PrintMatrix(double** ptr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << "[" << ptr[i][j] << "] ";
        }
        std::cout << std::endl;
    }
}
double determinant(double** ptr, size_t size)
{
    if (size == 1)
    {
        return ptr[0][0];
    }
    else if (size == 2)
    {
        return ptr[0][0] * ptr[1][1] - ptr[1][0] * ptr[0][1];
    }
    else
    {
        double res = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (ptr[0][i] == 0)
            {
                std::cout << ptr[0][i];
                continue;
            }
            double** p = new double* [size - 1];
            for (size_t j = 0; j < size - 1; j++)
            {
                p[j] = new double[size - 1];
            }
            for (size_t j = 1; j < size; j++)
            {
                for (size_t k = 0; k < size; k++)
                {
                    if (k == i)
                        continue;
                    else if (k < i)
                        p[j-1][k] = ptr[j][k];
                    else
                        p[j-1][k - 1] = ptr[j][k];
                }

            }
            if (i % 2 == 0)
            {
                res += 1 * (ptr[0][i] * determinant(p, size - 1));
                
            }
            else
            {
                res += -1 * (ptr[0][i] * determinant(p, size - 1));
                
            }
            for (size_t i = 0; i < size - 1; i++)
            {
                delete[]p[i];
            }
            delete[]p;
        }
        return res;
    }
}
class Matrix
{
protected:
    double** ptr;
    size_t size;
public:
    Matrix(size_t s) : size(s)
    {
        ptr = new double* [size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = new double[size];
            for (int j = 0; j < size; j++)
            {
                /*std::cout << "Enter element = ";
                std::cin >> ptr[i][j];
                std::cout << std::endl;*/

                ptr[i][j] = static_cast<double>(rand() % 10);
            }
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < size; i++)
        {
            delete[]ptr[i];
        }
        delete[]ptr;
    }
    double Mdeterminant()
    {
        return determinant(ptr, size);
    }
};

//Задание 3
class Noda
{
protected:
    int data;
    Noda* next;
    Noda* back;
public:
    Noda(int d, Noda *n, Noda *b):data(d), next(n), back(b){}
    friend class Iter;
    friend class List;
    
    
};

class Iter
{
protected:
    Noda* iter;
public:
    Iter()
    {
        iter = 0;
    }
    Iter(Noda* i) :iter(i) {}
    friend class List;
    Iter operator = (Iter iter)
    {
        return Iter(this->iter = iter.iter);
    }
    Iter operator = (Noda* iter)
    {
        return Iter(this->iter = iter);
    }
    bool operator != ( Iter ite1)
    {
        return (this->iter != ite1.iter);
    }
    Iter operator++(int)
    {
        return Iter(this->iter = this->iter->next);
    }
    Iter operator++()
    {
        return Iter(this->iter = this->iter->next);
    }
    int operator *()
    {
        return this->iter->data;
    }
    void PrintIter()
    {
        std::cout << iter->data << std::endl;
    }
};
class List
{
private:
    size_t size;
    Iter first;
    Iter last;
    //Iter end;
public:
    List()
    {
        size = 0;
        first = 0;
        last = 0;
    }
    void PushBackl(int data)
    {
        if (size == 0)
        {
            last = new Noda(data, 0, 0);
            first = last;
            size++;
        }
        else
        {
            Noda * ptr = new Noda(data, first.iter, last.iter );
            last.iter->next = ptr;
            last = ptr;
            size++;
        }
    }
    void PushStartl(int data)
    {
        if (size == 0)
        {
            first = new Noda(data, 0, 0);
            last = first;
            size++;
        }
        else
        {
            Noda* ptr = new Noda(data, first.iter, last.iter);
            first.iter->back = ptr;
            first = ptr;
            size++;
        }
    }
    void PopBackl()
    {
        if (size == 1)
        {
            delete first.iter;
            first = 0;
            last = 0;
            size--;
        }
        if (size > 1)
        {
            Noda* ptr = last.iter;
            last.iter->back->next = first.iter;
            first.iter->back = ptr->back;
            delete ptr;
            size--;
        }
        

    }
    void PopStartl()
    {
        if (size == 1)
        {
            delete first.iter;
            first = 0;
            last = 0;
            size--;
        }
        if (size > 1)
        {
            Noda* ptr = first.iter;
            last.iter->next = ptr;
            first.iter->next->back = last.iter;
            delete ptr;
            size--;
        }
    }
    void PrintListfor()
    {
        if (size == 1)
        {
            std::cout << "[" << first.iter->data << "]->";
        }
        else if (size > 1)
        {
            for (Iter i = first; i != last; i++)
            {
                std::cout << "[" << i.iter->data << "]->";
            }
            std::cout << "[" << last.iter->data << "]->";
        }
    }
    Iter begin()
    {
        return first;
    }
    Iter end()
    {
        return last;
    }
};
int main()
{
    /*std::list<double> l{ 1.3, 2, 2, -3, -4.03 };
    PushBack(&l);
    std::cout << l.back() << std::endl;
    */


    //Matrix m(4);
    //std::cout << "deter = " << m.Mdeterminant() << std::endl;

    List ls;
    /*Noda* ptr1, *ptr2, *ptr3;
    ptr1 = new Noda(22,0,0);
    ptr2 = new Noda(11, ptr1, ptr1);
    ptr3 = ptr1;
    Iter it1 = ptr1, it2 = ptr2;
    it1.PrintIter();
    it2.PrintIter();
    std::cout << (it1 != it2) << std::endl;
    it2++;
    it2.PrintIter();
    std::cout << (it1 != it2) << std::endl;*/

    ls.PushBackl(4);
    ls.PushStartl(18);
    ls.PushBackl(3);
    ls.PushBackl(42);
    ls.PushBackl(11);
    ls.PushBackl(33);
    ls.PushBackl(10);
    ls.PrintListfor();
    for (auto x : ls)
    {
        std::cout << x << ' ';
    }


}