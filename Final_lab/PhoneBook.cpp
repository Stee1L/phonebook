#include "PhoneBook.h"
#include <iostream>
#include <functional>
#include <string>
#include <fstream>

using namespace std;
int PhoneBook::Count = 1;

/*============================== CONSTRUCTORS ==============================*/
PhoneBook::PhoneBook(string number, string surname, string name, string patronymic)
{
	ID = Count++;
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
void PhoneBook::setID(int id)                       { ID = id; }

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
    ofstream file(filename, ios::out | ios::trunc);
    string line;

    if (!file.is_open()) { cout << "Ошибка при открытии файла!" << endl; }
    else {
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
}

void PhoneBook::searchByName(PhoneBook* book, string name, int size)
{
    bool exist = false;
    for (int i = 0; i < size; i++)
    {
        if (book[i].getName() == name) { book[i].printData(); exist = true; }
    }
    if (!exist) 
    { 
        cout << "Ничего не найдено! Введите '0' для выхода или укажите другое имя: "; 
        cin >> name;
        if (name != "0") { PhoneBook::searchByName(book, name, size); }
    }
}

void PhoneBook::searchBySurname(PhoneBook* book, string surname, int size)
{
    bool exist = false;
    for (int i = 0; i < size; i++)
    {
        if (book[i].getSurname() == surname) { book[i].printData(); exist = true; }
    }
    if (!exist)
    {
        cout << "Ничего не найдено! Введите '0' для выхода или укажите другую фамилию: ";
        cin >> surname;
        if (surname != "0") { PhoneBook::searchBySurname(book, surname, size); }
    }
}

void PhoneBook::searchByPatronymic(PhoneBook* book, string patronymic, int size)
{
    bool exist = false;
    for (int i = 0; i < size; i++)
    {
        if (book[i].getPatronymic() == patronymic) { book[i].printData(); exist = true; }
    }
    if (!exist)
    {
        cout << "Ничего не найдено! Введите '0' для выхода или укажите другое отчество: ";
        cin >> patronymic;
        if (patronymic != "0") { PhoneBook::searchBySurname(book, patronymic, size); }
    }
}

void PhoneBook::searchByNumber(PhoneBook* book, string number, int size)
{
    bool exist = false;
    for (int i = 0; i < size; i++)
    {
        if (book[i].getNumber() == number) { book[i].printData(); exist = true; }
    }
    if (!exist)
    {
        cout << "Ничего не найдено! Введите '0' для выхода или укажите другой номер: ";
        cin >> number;
        if (number != "0") { PhoneBook::searchBySurname(book, number, size); }
    }
}

PhoneBook PhoneBook::getByID(PhoneBook* book, int ID, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (book[i].getID() == ID) { return book[i]; }
    }
}

/*=========================== STATIC FUNCTIONS ===========================*/

PhoneBook* PhoneBook::changeData(PhoneBook* Book, string filename)
{
    int switchcase = 0;
    string searchData, changeData;
    int id = 0;
    bool isChanged = false;

    cout << "+-----------------------------------+" << endl;
    cout << "| 1. Поиск по имени                 |" << endl;
    cout << "| 2. Поиск по фамилии               |" << endl;
    cout << "| 3. Поиск по отчеству              |" << endl;
    cout << "| 4. Поиск по номеру телефона       |" << endl;
    cout << "| 5. Поиск по ID                    |" << endl;
    cout << "+-----------------------------------+" << endl << endl;
    cout << "Выберите действие:";
    cin >> switchcase;
    cout << endl;
    
    switch (switchcase)
    {
        case 1:
            cout << "Введите имя: ";
            cin >> searchData;
            PhoneBook::searchByName(Book, searchData, Count - 1);
            break;

        case 2:
            cout << "Введите фамилию: ";
            cin >> searchData;
            PhoneBook::searchBySurname(Book, searchData, Count - 1);
            break;

        case 3:
            cout << "Введите отчество: ";
            cin >> searchData;
            PhoneBook::searchByPatronymic(Book, searchData, Count - 1);
            break;

        case 4:
            cout << "Введите номер телефона: ";
            cin >> searchData;
            PhoneBook::searchByNumber(Book, searchData, Count - 1);
            break;

        case 5:
            cout << "Введите ID: ";
            cin >> id;
            PhoneBook::getByID(Book, id, Count - 1);
            break;

        default:
            break;
    }

    cout << "Введите ID записи: ";
    cin >> id;

    cout << "Запись с именем " << searchData << " найдена!" << endl << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "| 1. Изменить Имя                   |" << endl;
    cout << "| 2. Изменить фамилию               |" << endl;
    cout << "| 3. Изменить отчество              |" << endl;
    cout << "| 4. Изменить номер телефона        |" << endl;
    cout << "| 5. Удалить данные                 |" << endl;
    cout << "| 6. Назад                          |" << endl;
    cout << "+-----------------------------------+" << endl << endl << "Выберите действие: ";
    cin >> switchcase;

    switch (switchcase)
    {
        case 1:
            cout << "Введите имя:";
            cin >> changeData;
            Book[id - 1].setName(changeData);
            isChanged = true;
            break;

        case 2:
            cout << "Введите фамилию:";
            cin >> changeData;
            Book[id - 1].setSurname(changeData);
            isChanged = true;
            break;

        case 3:
            cout << "Введите отчество:";
            cin >> changeData;
            Book[id - 1].setPatronymic(changeData);
            isChanged = true;
            break;

        case 4:
            cout << "Введите номер телефона:";
            cin >> changeData;
            Book[id - 1].setNumber(changeData);
            isChanged = true;
            break;

        case 5:
            Book = PhoneBook::removeData(Book, Count - 1, id);
            cout << "Запись успешно удалена!" << endl << endl;
            isChanged = true;
            break;

        case 6:
            break;

        default:
            cout << "Введено неверное значение!" << endl;
            break;
    }
    if (isChanged) 
    { 
        cout << "Внести изменения в файл?" << endl << "1. Да" << endl << "2. Нет" << endl << endl << "Выберите действие: ";
        cin >> switchcase;
        switch (switchcase)
        {
            case 1:
                writeToFile(filename, Book, Count - 1);
                break;

            case 2: 
                break;

            default:
                cout << "Введено неверное значение!" << endl;
                break;
        }
    };
    return Book;
}

PhoneBook* PhoneBook::removeData(PhoneBook* Book, int size, int id)
{
    for (int i = 0; i < size - 1; i++) 
    { 
        if (Book[i].getID() == id) 
        { 
            swap(Book[i], Book[i + 1]); 
            Book[i].setID(Book[i].getID() - 1);
        }
    }
    PhoneBook* book = new PhoneBook[--size];
    copy(Book, Book + size, book);
    delete[] Book;
    Count--;
    return book;
}

PhoneBook* PhoneBook::addData(PhoneBook* Book, int size)
{
    PhoneBook* book = new PhoneBook[++size];
    for (int i = 0; i < size - 1; i++)
        book[i] = Book[i];
    
    string name, surname, patronymic, number;

    cout << "Введите имя: ";
    cin >> name;
    cout << "Введите фамилию: ";
    cin >> surname;
    cout << "Введите отчество: ";
    cin >> patronymic;
    cout << "Введите номер телефона: ";
    cin >> number;
    book[size - 1] = PhoneBook(number, name, surname, patronymic);
    delete[] Book;
    return book;
}



void PhoneBook::Interface()
{  
    int switchcase, id;
    bool inWork = true;
    string filename;
    cout << "+-----------------------------------+" << endl;
    cout << "| This is PhoneBook program v.1.1.1 |" << endl; 
    cout << "+-----------------------------------+" << endl;
    cout << "Введите имя файла: "; 
    cin >> filename;

    int size = PhoneBook::rowsCount(filename);
    string** data = PhoneBook::readDataToArray(filename);
    PhoneBook* Book = new PhoneBook[size];
    for (int i = 0; i < size; i++)
    {
        Book[i] = PhoneBook(data[i][0], data[i][1], data[i][2], data[i][3]);
        //Book[i].printData();
    }
    cout << "Файл успешно открыт!" << endl << endl;
    while (inWork)
    {
        cout << "+-----------------------------------+" << endl;
        cout << "| 1. Показать данные                |" << endl;
        cout << "| 2. Изменить данные                |" << endl;
        cout << "| 3. Добавить данные                |" << endl;
        cout << "| 4. Внести изменения в файл        |" << endl;
        cout << "| 5. Выйти из программы             |" << endl;
        cout << "+-----------------------------------+" << endl << endl << "Выберите действие: ";
        
        cin >> switchcase;
        cout << endl;
        switch (switchcase)
        {
            case 1:
                for (int i = 0; i < Count - 1; i++) { Book[i].printData(); }
                break;
            case 2:
                Book = PhoneBook::changeData(Book, filename);
                break;
            case 3:
                Book = PhoneBook::addData(Book, Count - 1);
                break;
            case 4:
                PhoneBook::writeToFile(filename, Book, Count - 1);
                break;
            case 5: 
                inWork = false;
                break;
            default:
                while (!cin >> switchcase) { cin.clear(); cin.get(); }
                cout << "Введено неверное значение!" << endl << endl;
                break;
        }
    }
}

// счёт строк в файле
int PhoneBook::rowsCount(string filename)
{
    // открытие файла с именем filename
    ifstream file(filename);
    if (!file.is_open()) { cout << "Ошибка при открытии файла!" << endl; return 0; }

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
    if (!file.is_open()) { cout << "Ошибка при открытии файла!" << endl; return 0; }

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