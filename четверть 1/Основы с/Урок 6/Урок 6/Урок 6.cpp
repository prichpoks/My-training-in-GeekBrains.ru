

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//TASK 1
void printmas(int* mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << ' ';
    }
}
void powmas(void)
{
    int n, * ptr;
    cout << "Entrer n\n";
    cin >> n;
    ptr = new (nothrow) int[n];

    if (ptr)
    {
        for (int i = 0; i < n; i++)
        {
            ptr[i] = pow(2, i);
        }

    }
    printmas(ptr, n);
    delete[] ptr;
}

//TASK 2
void enterrand(int**p)
{
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        for (int count = 0; count < 4; count++)
            p[i][count] = rand();
    }
}

void printrmas(int**p)
{
    for (int i = 0; i < 4; i++)
    {
        for (int count = 0; count < 4; count++)
            cout << p[i][count] << '|';
        cout << '\n';
    }
}

void delmas(int** p)
{
        for (int count = 0; count < 4; count++)
            delete[] p[count];
    delete[] p;
}
void randmas()
{
    
    int** p = new (nothrow) int*[4];
    if (p)
    {
        for (int i = 0; i < 4; i++)
            p[i] = new int[4];
    }
    enterrand(p);
    printrmas(p);
    delmas(p);

}

// TASK 3
void cfile1()
{
    string name;
    cout << "enter name file: ";
    cin >> name;
    ofstream fout(name);
    for (int i = 0; i < 50; i++)
        fout << '1';
    fout.close();
}

void cfile2()
{
    string name;
    cout << "enter name file: ";
    cin >> name;
    ofstream fout(name);
    for (int i = 0; i < 50; i++)
        fout << '2';
    fout.close();
}
void createTfiles()
{
    cfile1();
    cfile2();
}

// TASK 4
void addfile()
{
    string file1, file2, file3, buf;
    cout << "enter name file1: ";
    cin >> file1;
    cout << "enter name file2: ";
    cin >> file2;
    cout << "enter name file3: ";
    cin >> file3;
    ifstream fin(file1);
    ofstream fout(file3);
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            getline(fin, buf);
            fout << buf;
        }
    }
    fin.close();
    ifstream pin(file2);
    if (pin.is_open())
    {
        while (!pin.eof())
        {
            getline(pin, buf);
            fout << buf;
        }
    }
    pin.close();
}

// TASK 5
void scanword()
{
    bool fl = false;
    string nword, file, buf;
    cout << "enter name word: ";
    cin >> nword;
    cout << "enter name file: ";
    cin >> file;
    ifstream fin(file);
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            getline(fin, buf);
            if (buf.find(nword) != string::npos)
            {
                cout << "Yes we found word!";
                fl = true;
            }

        }
        if (!fl)
            cout << "We can not find Word";
    }
    fin.close();
}

int main()
{
   
    powmas();
    cout << '\n';
    randmas();
    cout << '\n';
    createTfiles();
    addfile();
    scanword();
    cout << "\nHello World!\n";
    return 0;
}