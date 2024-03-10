
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Pet
{
protected:
    bool is_vacsinated = true;
public:
   
};

class Cat : public Pet
{
    string name;
    string opus;
public:
    Cat() : name{ "" }, opus{ "" } {}
    Cat(string name_, string opus_) : name{ name_ }, opus{ opus_ } {}

    void show_data()
    {
        cout << "\n" << name << endl;
        cout << opus << endl;
        cout << is_vacsinated;
    }
};

class Dog : public Pet
{
    string name;
    string opus;
public:
    Dog() : name{ "" }, opus{ "" } {}
    Dog(string name_, string opus_) : name{ name_ }, opus{ opus_ } {}
    void show_data()
    {
        cout << "\n" << name << endl;
        cout << opus << endl;
        cout << is_vacsinated;
    }
};

class Parrot : public Pet
{
    string name;
    string opus;
public:
    Parrot() : name{ "" }, opus{ "" } {}
    Parrot(string name_, string opus_) : name{ name_ }, opus{ opus_ } {}
    void show_data()
    {
        cout << "\n" << name << endl;
        cout << opus << endl;
        cout << is_vacsinated;
    }
};

//-----------------------------------    TASK_2   -----------------------------------------------//

#include <iostream>
#include <cstring>

using namespace std;

class String {
protected:
    char* str;
    int length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (this == &other)
            return *this;

        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);

        return *this;
    }

    int getLength() const {
        return length;
    }

    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    String& operator+=(const String& other) {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        delete[] str;
        str = temp;
        length += other.length;
        return *this;
    }

    const char* c_str() const {
        return str;
    }
};

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) {
        bool valid = true;
        for (int i = 0; i < strlen(s); ++i) {
            if (s[i] != '0' && s[i] != '1') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            clear();
        }
        else {
            length = strlen(s);
            str = new char[length + 1];
            strcpy(str, s);
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    ~BitString() {}

    void changeSign() {
        for (int i = 0; i < getLength(); ++i) {
            if (c_str()[i] == '0')
                str[i] = '1';
            else if (c_str()[i] == '1')
                str[i] = '0';
        }
    }

    BitString operator+(const BitString& other) const {
        int num1 = 0, num2 = 0;
        for (int i = 0; i < getLength(); ++i) {
            num1 = num1 * 2 + (c_str()[i] - '0');
        }
        for (int i = 0; i < other.getLength(); ++i) {
            num2 = num2 * 2 + (other.c_str()[i] - '0');
        }

        int sum = num1 + num2;

        char temp[33];
        for (int i = 31; i >= 0; --i) {
            temp[31 - i] = '0' + ((sum >> i) & 1);
        }
        temp[32] = '\0';

        return BitString(temp);
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return !(*this == other);
    }
};

int main() {
    BitString bs1("1010");
    BitString bs2("1101");
    BitString bs3 = bs1 + bs2;
    cout << bs3.c_str() << endl;

    bs1.changeSign();
    cout << bs1.c_str() << endl;

    return 0;
}





