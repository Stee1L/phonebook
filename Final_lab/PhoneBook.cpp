#include "PhoneBook.h"
#include <iostream>
#include <functional>
#include <string>
#include <fstream>

using namespace std;
int PhoneBook::Counter = 1;

/*============================== CONSTRUCTORS ==============================*/
PhoneBook::PhoneBook(string number, string surname, string name, string patronymic)
{
	ID = Counter++;
	Name = name;
    Surname = surname;
    Patronymic = patronymic;
	Number = number;
}

PhoneBook::PhoneBook() { Name = ""; Surname = ""; Patronymic = ""; Number = ""; }
PhoneBook::~PhoneBook() {}

/*================================ SETTERS ================================*/
void PhoneBook::setName(string name)                { Name = name; }
void PhoneBook::setSurname(string surnname)         { Surname = surnname; }
void PhoneBook::setPatronymic(string patronymic)    { Patronymic = patronymic; }
void PhoneBook::setNumber(string number)            { Number = number; }

/*================================ GETTERS ================================*/
string PhoneBook::getName()		    { return Name; }
string PhoneBook::getSurname()      { return Surname; }
string PhoneBook::getPatronymic()   { return Patronymic; }
string PhoneBook::getNumber()       { return Number; }
int PhoneBook::getID()              { return ID; }

/*=============================== FUNCTIONS ===============================*/

void PhoneBook::printData()
{
    cout << "ID: " << this->getID() << endl;
    cout << "Фамилия: " << this->getSurname() << endl;
    cout << "Имя: " << this->getName() << endl;
    cout << "Отчество: " << this->getPatronymic() << endl;
    cout << "Номер телефона: " << this->getNumber() << endl << endl;
}

void PhoneBook::writeToFile(string filename, PhoneBook* Book, int size)
{
    // процедура принимает на вход массив объектов, а затем записывает свойства каждого объекта в файл
    ofstream file(filename, ios::in | ios::out);
    string line;

    if (file.is_open()) cout << "Файл открыт успешно!" << endl;

    // запись новых данных в файл
    for (int i = 0; i < size; i++)
    {
        file << Book[i].getNumber();
        file << " ";
        file << Book[i].getSurname();
        file << " ";
        file << Book[i].getName();
        file << " ";
        file << Book[i].getPatronymic();
        file << endl;
    }
}

bool PhoneBook::searchByName(PhoneBook* book, string name)
{
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getName() == name) { book[i].printData(); return true; }
    }
    cout << "Ничего не найдено";
    return false;
}

bool PhoneBook::searchBySurname(PhoneBook* book, string surname)
{
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getSurname() == surname) { book[i].printData(); return true; }
    }
    cout << "Ничего не найдено";
    return false;
}

bool PhoneBook::searchByPatronymic(PhoneBook* book, string patronymic)
{
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getPatronymic() == patronymic) { book[i].printData(); return true; }
    }
    cout << "Ничего не найдено";
    return false;
}

PhoneBook PhoneBook::getByID(PhoneBook* book, int ID)
{
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getID() == ID) { return book[i]; }
    }
}

/*=========================== STATIC FUNCTIONS ===========================*/

void PhoneBook::Interface()
{  
    string filename;
    cout << "┍——————————————————————————————————————————————┑" << endl;
    cout << "| This is PhoneBook program v.1.0.0 ヽ(・∀・)ﾉ |" << endl;
    cout << "┕——————————————————————————————————————————————┙" << endl;
    cout << "Set filename for new Phone Book: "; 
    cin >> filename;

    int size = PhoneBook::rowsCount(filename);
    string** data = PhoneBook::readDataToArray(filename);
    PhoneBook* Book = new PhoneBook[size];
    for (int i = 0; i < size; i++)
    {
        Book[i] = PhoneBook(data[i][0], data[i][1], data[i][2], data[i][3]);
        Book[i].printData();
    }
    cout << "File opened successfully! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" << endl << endl;
    cout << "1. Show entries" << endl << "2. ";
}

// счёт строк в файле
int PhoneBook::rowsCount(string filename)
{
    // открытие файла с именем filename
    ifstream file(filename);
    if (file.is_open()) cout << "Файл открыт успешно!" << endl;

    // счёт строк в файле
    int rows = 0;
    string line;
    while (getline(file, line)) { rows++; }             // каждый вызов функции getline() считывает одну строку 
                                                        // до тех пор, пока не достигнет конца файла
    file.close();
    return rows;
}


// чтение данных из файла в массив data
string** PhoneBook::readDataToArray(string filename)
{
    // открытие файла с именем filename
    ifstream file(filename);
    if (file.is_open()) cout << "Файл открыт успешно!" << endl;

    int rows = rowsCount(filename);
    string line;

    string** data = new string * [rows];                // выделение памяти для динамического двумерного массива
    for (int i = 0; i < rows; i++)
        data[i] = new string[4];

    file.clear();                                       // метод clear() используется для сброса состояния потока
    file.seekg(0, ios::beg);                            // установка позиции чтения в начале файла 
                                                        // (0 - позиция, ios::beg - отсчёт с начала файла)
    // заполняем массив данными из файла
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 4; j++)
            file >> data[i][j];                         // здесь используется перегруженный оператор >> класса ifstream,
                                                        // начиная с указанной ранее позиции он читает каждое значение файла
                                                        // и записывает в соответствующую ячейку массива data
    file.close();
    return data;
}

// сортировка методом вставки
PhoneBook* PhoneBook::insertSortByAlphabet(PhoneBook* Book, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0 && Book[j - 1].getSurname() > Book[j].getSurname(); j--)
        {
            swap(Book[j - 1], Book[j]);
        }
    }
    return Book;
}

// сортировка методом пузырька
PhoneBook* PhoneBook::bubbleSortByAlphabet(PhoneBook* Book, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (Book[j].getSurname() > Book[j + 1].getSurname())
            {
                string temp = Book[j].getSurname();
                Book[j].setSurname(Book[j + 1].getSurname());
                Book[j + 1].setSurname(temp);
            }
        }
    }
    return Book;
}