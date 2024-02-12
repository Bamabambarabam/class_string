#include "str.h"

MyString::MyString() {
    str = nullptr;
}

// конструктор с одним параметром (есть значение по-умолчанию nullptr)
MyString::MyString(const char *str) {
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
    this->str[strlen(str)] = '\0';
}

// конструктор копирования
MyString::MyString(const MyString &other) {
    if (other.str) {
        this->str = new char[strlen(other.str) + 1];
        strcpy(this->str, other.str);
    } else this->str = nullptr;
}

// конструктор переноса
MyString::MyString(MyString &&other) : str(std::move(other.str)) {
    other.str = nullptr;
}

// конструктор с одним параметром
MyString::MyString(const std::string &other) {
    this->str = new char[other.length() + 1];
    strcpy(this->str, other.c_str());
}

// возвращение указателя на данные (тип char*)
char *MyString::get() const {
    return this->str;
}

// количество символов (длина строки)
size_t MyString::length() {
    if (this->str) return strlen(this->str);
    else return 0;
}

// копирующее присваивание
MyString &MyString::operator=(const MyString &other) {
    if (nullptr != this->str) {
        delete[] str;
    }
    this->str = new char[strlen(other.str) + 1];
    strcpy(this->str, other.str);
    return *this;
}

// перемещающее присваивание
MyString &MyString::operator=(MyString &&other) {
    if (nullptr != this->str) {
        delete[] str;
    }
    str = other.str;
    other.str = nullptr;
    return *this;
}


// сравнение на равенство
bool MyString::operator==(const MyString &other) const {
    return strcmp(this->str, other.str) == 0;
}

// сравнение на неравенство
bool MyString::operator!=(const MyString &other) const {
    return strcmp(this->str, other.str) != 0;
}

// сложение (конкатенация двух строк)
MyString MyString::operator+(const MyString &other) const {
    MyString new_string;
    new_string.str = new char[strlen(this->str) + strlen(other.str) + 1];
    int count = 0;
    for (int i = 0; i < strlen(this->str); i++) {
        count = i;
        new_string.str[count] = this->str[i];
    }
    for (int i = 0; i < strlen(other.str); i++) {
        count += 1;
        new_string.str[count] = other.str[i];
    }
    new_string.str[count + 1] = '\0';
    return new_string;
}

// вычитание (из первой строки удаляются все символы, присутствующие во второй строке)
MyString MyString::operator-(const MyString &other) const {
    MyString new_string;
    new_string.str = new char[strlen(this->str) + 1];
    bool data[128] = {false};
    for (int i = 0; i < strlen(other.str); i++) {
        data[other.str[i] - 'A'] = true;
    }
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (!data[str[i] - 'A']) {
            new_string[count] = str[i];
            count += 1;
        }
    }
    new_string.str[count] = '\0';
    return new_string;
}

// умножение на целое число (строка повторяется заданное число раз)
MyString MyString::operator*(const int factor) const {
    MyString new_string;
    new_string.str = new char[strlen(this->str) * factor + 1];
    int count = 0;
    for (int i = 0; i < factor; i++) {
        for (int j = count, k = 0; k < strlen(str); j++, k++) {
            new_string[j] = str[k];
            count += 1;
        }
    }
    new_string.str[strlen(this->str) * factor] = '\0';
    return new_string;
}

// лексикографическое сравнение
bool MyString::operator>(const MyString &other) const {
    return (strcmp(str, other.str) > 0);
}

// лексикографическое сравнение
bool MyString::operator>=(const MyString &other) const {
    return (strcmp(str, other.str) >= 0);
}

// лексикографическое сравнение
bool MyString::operator<(const MyString &other) const {
    return (strcmp(str, other.str) < 0);
}

// лексикографическое сравнение
bool MyString::operator<=(const MyString &other) const {
    return (strcmp(str, other.str) <= 0);
}

// у латинских букв меняется регистр
MyString MyString::operator!() const {
    MyString new_string;
    new_string.str = new char[strlen(this->str) + 1];
    for (int i = 0; i < strlen(this->str); i++) {
        if ((str[i] - 'A' >= 0) and ((str[i] - 'A' <= 25))) {
            new_string[i] = tolower(str[i]);
        } else new_string[i] = toupper(str[i]);
    }
    new_string.str[strlen(this->str)] = '\0';
    return new_string;
}

//поиск подстроки
int MyString::operator()(const char *sub) const {
    if (strlen(sub) > strlen(this->str)) {
        return 0;
    } else {
        int count = 0;
        for (int i = 0; i < strlen(this->str); i++) {
            if (str[i] == sub[count]) {
                count += 1;
                if (count == strlen(sub)) return 1;
            } else {
                count = 0;
                continue;
            }
        }
    }
    return 0;
}

//доступ к символу по индексу
char &MyString::operator[](int index) {
    return this->str[index];
}

// запись в поток
std::ostream &operator<<(std::ostream &os, MyString &str) {
    return os << str.str;
}

// чтение из потока
std::istream &operator>>(std::istream &is, MyString &str) {
    char buffer[2048];
    is >> buffer;
    delete[] str.str;
    str.str = new char[strlen(buffer) + 1];
    strcpy(str.str, buffer);
    return is;
}

// деструктор
MyString::~MyString() {
    delete[] this->str;
}