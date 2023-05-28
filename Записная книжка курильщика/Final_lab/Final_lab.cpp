#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class PhoneBook
{
private:
	int ID;																		// уникальный ID объекта
    static int& Counter() { static int Count = 1; return Count; }               // счётчик объектов
	string Number;																// номер и ФИО
	string Name;
	string Surname;
	string Patronymic;

public:
    /*============================== CONSTRUCTORS ==============================*/
    PhoneBook(string number, string surname, string name, string patronymic)
    {
        ID = Counter()++;
        Name = name;
        Surname = surname;
        Patronymic = patronymic;
        Number = number;
    }

    PhoneBook() { Name = ""; Surname = ""; Patronymic = ""; Number = ""; }
    ~PhoneBook() {}

    /*================================ SETTERS ================================*/
    void setName(string name) { Name = name; }
    void setSurname(string surnname) { Surname = surnname; }
    void setPatronymic(string patronymic) { Patronymic = patronymic; }
    void setNumber(string number) { Number = number; }
    void setID(int id) { ID = id; }

    /*================================ GETTERS ================================*/
    string getName() { return Name; }
    string getSurname() { return Surname; }
    string getPatronymic() { return Patronymic; }
    string getNumber() { return Number; }
    int getID() { return ID; }
    static int getCount() { int count = Counter(); return count; }

    /*=============================== FUNCTIONS ===============================*/

    void printData()
    {
        cout << "ID: " << this->getID() << endl;
        cout << "Фамилия: " << this->getSurname() << endl;
        cout << "Имя: " << this->getName() << endl;
        cout << "Отчество: " << this->getPatronymic() << endl;
        cout << "Номер телефона: " << this->getNumber() << endl << endl;
    }

    static void writeToFile(string filename, PhoneBook* Book, int size)
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
                file << "_";
                file << Book[i].getName();
                file << "_";
                file << Book[i].getPatronymic();
                file << endl;
            }
            cout << "Файл успешно изменен!" << endl << endl;
        }
    }

    static void searchByName(PhoneBook* book, string name, int size)
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
            if (name != "0") { searchByName(book, name, size); }
        }
    }

    static void searchBySurname(PhoneBook* book, string surname, int size)
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
            if (surname != "0") { searchBySurname(book, surname, size); }
        }
    }

    static void searchByPatronymic(PhoneBook* book, string patronymic, int size)
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
            if (patronymic != "0") { searchByPatronymic(book, patronymic, size); }
        }
    }

    static void searchByNumber(PhoneBook* book, string number, int size)
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
            if (number != "0") { searchByNumber(book, number, size); }
        }
    }

    static PhoneBook getByID(PhoneBook* book, int ID, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (book[i].getID() == ID) { return book[i]; }
        }
    }

    /*=========================== STATIC FUNCTIONS ===========================*/

    static PhoneBook* changeData(PhoneBook* Book, string filename)
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
        cout << "Выберите действие: ";
        cin >> switchcase;
        cout << endl;

        switch (switchcase)
        {
        case 1:
            cout << "Введите имя: ";
            cin >> searchData;
            searchByName(Book, searchData, getCount() - 1);
            break;

        case 2:
            cout << "Введите фамилию: ";
            cin >> searchData;
            searchBySurname(Book, searchData, getCount() - 1);
            break;

        case 3:
            cout << "Введите отчество: ";
            cin >> searchData;
            searchByPatronymic(Book, searchData, getCount() - 1);
            break;

        case 4:
            cout << "Введите номер телефона: ";
            cin >> searchData;
            searchByNumber(Book, searchData, getCount() - 1);
            break;

        case 5:
            cout << "Введите ID: ";
            cin >> id;
            getByID(Book, id, getCount() - 1);
            break;

        default:
            while (!cin >> switchcase) { cin.clear(); cin.get(); }
            cout << "Введено неверное значение!" << endl << endl;
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
            cout << "Введите имя: ";
            cin >> changeData;
            Book[id - 1].setName(changeData);
            isChanged = true;
            break;

        case 2:
            cout << "Введите фамилию: ";
            cin >> changeData;
            Book[id - 1].setSurname(changeData);
            isChanged = true;
            break;

        case 3:
            cout << "Введите отчество: ";
            cin >> changeData;
            Book[id - 1].setPatronymic(changeData);
            isChanged = true;
            break;

        case 4:
            cout << "Введите номер телефона: ";
            cin >> changeData;
            Book[id - 1].setNumber(changeData);
            isChanged = true;
            break;

        case 5:
            Book = removeData(Book, getCount() - 1, id);
            cout << "Запись успешно удалена!" << endl << endl;
            isChanged = true;
            break;

        case 6:
            break;

        default:
            while (!cin >> switchcase) { cin.clear(); cin.get(); }
            cout << "Введено неверное значение!" << endl << endl;
            break;
        }
        if (isChanged)
        {
            cout << "Внести изменения в файл?" << endl << "1. Да" << endl << "2. Нет" << endl << endl << "Выберите действие: ";
            cin >> switchcase;
            switch (switchcase)
            {
            case 1:
                writeToFile(filename, Book, getCount() - 1);
                break;

            case 2:
                break;

            default:
                while (!cin >> switchcase) { cin.clear(); cin.get(); }
                cout << "Введено неверное значение!" << endl << endl;
                break;
            }
        };
        return Book;
    }

    static PhoneBook* removeData(PhoneBook* Book, int size, int id)
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
        Counter()--;
        return book;
    }

    static PhoneBook* addData(PhoneBook* Book, int size)
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
        while (number.length() < 11) { cout << "Введен некорректный номер! Попробуйте ещё раз: "; cin >> number; }
        book[size - 1] = PhoneBook(number, name, surname, patronymic);
        cout << endl << "Запись успешно добавлена!" << endl << endl;
        delete[] Book;
        return book;
    }



    static void Interface()
    {
        int switchcase;
        bool inWork = true;
        string filename;
        cout << "+-----------------------------------+" << endl;
        cout << "| This is PhoneBook program v.1.1.1 |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "Введите имя файла: ";
        cin >> filename;

        int size = rowsCount(filename);
        if (size > 0)
        {
            string** data = readDataToArray(filename);
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
                cout << "| 5. Сортировать данные             |" << endl;
                cout << "| 6. Выйти из программы             |" << endl;
                cout << "+-----------------------------------+" << endl << endl << "Выберите действие: ";

                cin >> switchcase;
                cout << endl;
                switch (switchcase)
                {
                case 1:
                    for (int i = 0; i < getCount() - 1; i++) { Book[i].printData(); }
                    break;
                case 2:
                    Book = changeData(Book, filename);
                    break;
                case 3:
                    Book = addData(Book, getCount() - 1);
                    break;
                case 4:
                    writeToFile(filename, Book, getCount() - 1);
                    break;
                case 5:
                    cout << "+-----------------------------------+" << endl;
                    cout << "| 1. Сортировка методом пузырька    |" << endl;
                    cout << "| 2. Сортировка методом вставок     |" << endl;
                    cout << "+-----------------------------------+" << endl << endl << "Выберите действие: ";
                    cin >> switchcase;
                    cout << endl;

                    switch (switchcase)
                    {
                    case 1:
                        Book = bubbleSortByAlphabet(Book, size);
                        break;
                    case 2:
                        Book = insertSortByAlphabet(Book, size);
                        break;
                    default:
                        break;
                    }
                    break;
                case 6:
                    inWork = false;
                    break;
                default:
                    while (!cin >> switchcase) { cin.clear(); cin.get(); }
                    cout << "Введено неверное значение!" << endl << endl;
                    break;
                }
            }
        }
        else { cout << "Указано неверное название файла!"; }
    }

    // счёт строк в файле
    static int rowsCount(string filename)
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
    static string** readDataToArray(string filename)
    {
        // открытие файла с именем filename
        ifstream file(filename);
        if (!file.is_open()) { cout << "Ошибка при открытии файла!" << endl; return 0; }

        int rows = rowsCount(filename);
        string line;

        string** data = new string * [rows];            // выделение памяти для динамического двумерного массива
        for (int i = 0; i < rows; i++)
            data[i] = new string[4];

        file.clear();                                   // метод clear() используется для сброса состояния потока
        file.seekg(0, ios::beg);                        // установка позиции чтения в начале файла 
                                                        // (0 - позиция, ios::beg - отсчёт с начала файла)
                                                        // заполняем массив данными из файла
        for (int i = 0; i < rows; i++)
        {
            file >> data[i][0];                         // здесь используется перегруженный оператор >> класса ifstream,
                                                        // начиная с указанной ранее позиции он читает каждое значение файла
                                                        // и записывает в соответствующую ячейку массива data
            string tempstr;
            file >> tempstr;
            int tmp = 1;
            for (int j = 0; j < tempstr.length(); j++)
            {
                string word;
                if (tempstr[j] == '_') { tmp++; }
                else { data[i][tmp] += tempstr[j]; }
            }
        }

        file.close();
        return data;
    }

    // сортировка методом вставки
    static PhoneBook* insertSortByAlphabet(PhoneBook* Book, int size)
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
    static PhoneBook* bubbleSortByAlphabet(PhoneBook* Book, int size)
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
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PhoneBook::Interface();
}
