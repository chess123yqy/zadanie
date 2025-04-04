#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// санена часть 
struct Contact {
    string name;
    string phone;
    string email;
};

const int MAX_CONTACTS = 100;
Contact contacts[MAX_CONTACTS];
int contactCount = 0;

bool addContact(const string& name, const string& phone, const string& email) {
    if (contactCount < MAX_CONTACTS) {
        contacts[contactCount].name = name;
        contacts[contactCount].phone = phone;
        contacts[contactCount].email = email;
        contactCount++;
        return true;
    }
    return false;
}

string findContact(const string& name) {
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].name == name) {
            return "Имя: " + contacts[i].name + ", Телефон: " + contacts[i].phone + ", Email: " + contacts[i].email;
        }
    }
}

bool editContact(const string& name, const string& newName, const string& newPhone, const string& newEmail) {
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].name == name) {
            contacts[i].name = newName;
            contacts[i].phone = newPhone;
            contacts[i].email = newEmail;
            return true;
        }
    }
    return false;
}

bool deleteContact(const string& name) {
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].name == name) {
            contacts[i] = contacts[contactCount - 1];
            contactCount--;
            return true;
        }
    }
    return false;
}

bool saveToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < contactCount; i++) {
            file << contacts[i].name << " " << contacts[i].phone << " " << contacts[i].email << endl;
        }
        file.close();
        return true;
    }
    return false;
}
// конец саненной части




// льва часть 
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    string str1, str2, str3,str4;
    while (true) {
        cout <<
            "1. Добавить контакт\n"
            "2. Найти контакт\n"
            "3. Изменить контакт\n"
            "4. Удалить контакт\n"
            "5. Сохранить контакты в файл\n";
        cin >> a;
        switch (a)
        {
        case 1: 
            cout << "Введите имя: " << endl;
            cin >> str1;
            cout << "Введите телефон: " << endl;
            cin >> str2;
            cout << "Введите email: " << endl;
            cin >> str3;
            addContact(str1, str2, str3);
            break;

        case 2:
            cout << "Введите имя для поиска: " << endl;
            cin >> str1;
            cout << findContact(str1) << endl;
            break;

        case 3: 
            cout << "Введите имя контакта для изменения: ";
            cin >> str1;
            cout << "Введите новое имя: ";
            cin >> str2;
            cout << "Введите новый телефон: ";
            cin >> str3;
            cout << "Введите новый email: ";
            cin >> str4;
            if (editContact(str1, str2, str3, str4)) {
                cout << "Контакт изменен." << endl;
            }
            else {
                cout << "Ошибка при изменении контакта." << endl;
            }
            break;

        case 4: 
            cout << "Введите имя контакта для удаления: ";
            cin >> str1;
            if (deleteContact(str1)) {
                cout << "Контакт удален." << endl;
            }
            else {
                cout << "Ошибка при удалении контакта." << endl;
            }
            break;

        case 5: 
            if (saveToFile("contacts.txt")) {
                cout << "Контакты сохранены в файл." << endl;
            }
            else {
                cout << "Ошибка при сохранении в файл." << endl;
            }
            break;

        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    }
}

// конец львиной часть 
