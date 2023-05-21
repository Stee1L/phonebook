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

void PhoneBook::searchByName(PhoneBook* book, string name)
{
    bool exist;
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getName() == name) { book[i].printData(); exist = true; }
    }
    if (!exist) cout << "Ничего не найдено";
}

void PhoneBook::searchBySurname(PhoneBook* book, string surname)
{
    bool exist;
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getSurname() == surname) { book[i].printData(); exist = true; }
    }
    if (!exist) cout << "Ничего не найдено";
}

void PhoneBook::searchByPatronymic(PhoneBook* book, string patronymic)
{
    bool exist;
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getPatronymic() == patronymic) { book[i].printData(); exist = true; }
    }
    cout << "Ничего не найдено";
}

void PhoneBook::searchByNumber(PhoneBook* book, string number)
{
    bool exist;
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getNumber() == number) { book[i].printData(); exist = true; }
    }
    cout << "Ничего не найдено";
}

PhoneBook PhoneBook::getByID(PhoneBook* book, int ID)
{
    for (int i = 0; i < sizeof(book); i++)
    {
        if (book[i].getID() == ID) { return book[i]; }
    }
}

/*=========================== STATIC FUNCTIONS ===========================*/

void PhoneBook::changeData(PhoneBook* Book)
{
    int switchcase = 0;
    string searchData, changeData;
    int id = 0;
    int switchChange = 0;
    PhoneBook data;

    cout << "1. Поиск по имени" << endl;
    cout << "2. Поиск по фамилии" << endl;
    cout << "3. Поиск по отчеству" << endl;
    cout << "4. Поиск по номеру телефона" << endl;
    
    switch (switchcase)
    {
        case 1:
            cout << "Введите имя: ";
            cin >> searchData;
            PhoneBook::searchByName(Book, searchData);
            break;

        case 2:
            cout << "Введите фамилию: ";
            cin >> searchData;
            PhoneBook::searchBySurname(Book, searchData);
            break;

        case 3:
            cout << "Введите отчество: ";
            cin >> searchData;
            PhoneBook::searchByPatronymic(Book, searchData);
            break;

        case 4:
            cout << "Введите номер телефона: ";
            cin >> searchData;
            PhoneBook::searchByNumber(Book, searchData);
            break;

        default:
            break;
    }

    cout << "Введите ID записи: ";
    cin >> id;
    data = PhoneBook::getByID(Book, id);

    cout << "Запись с именем " << searchData << " найдена!";
    cout << "1. Изменить Имя";
    cout << "2. Изменить фамилию";
    cout << "3. Изменить отчество";
    cout << "4. Изменить номер телефона";

    switch (switchChange)
    {
        case 1:
            cout << "Введите имя:";
            cin >> changeData;
            data.setName(changeData);
            break;

        case 2:
            cout << "Введите фамилию:";
            cin >> changeData;
            data.setSurname(changeData);
            break;

        case 3:
            cout << "Введите отчество:";
            cin >> changeData;
            data.setPatronymic(changeData);
            break;

        case 4:
            cout << "Введите номер телефона:";
            cin >> changeData;
            data.setNumber(changeData);
            break;

        default:
            cout << "Введено неверное значение!";
            break;
        }
}

void PhoneBook::Interface()
{  
    int switchcase;
    bool inWork = true;
    string filename;
    cout << "┍——————————————————————————————————————————————┑" << endl;
    cout << "| This is PhoneBook program v.1.0.0 ヽ(・∀・)ﾉ |" << endl;
    cout << "┕——————————————————————————————————————————————┙" << endl;
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
    cout << "Файл успешно открыт! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" << endl << endl;
    while (inWork)
    {
        cout << "1. Показать данные" << endl;
        cout << "2. Изменить данные" << endl;
        cout << "3. Добавить данные" << endl;
        cout << "4. Внести изменения в файл" << endl;
        cout << "5. Выйти из программы" << endl;
        cin >> switchcase;
        switch (switchcase)
        {
            case 1:
                for (int i = 0; i < sizeof(Book); i++) { Book[i].printData(); }
                break;
            case 2:
                PhoneBook:changeData(Book);
                break;
            case 3:
                break;
            case 4:
                PhoneBook::writeToFile(filename, Book, size);
                break;
            case 5: 
                inWork = false;
                break;
            default:
                break;
        }
    }
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