#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения данных телефонной книги

typedef struct PhoneBookData_ {
    char name[32];
    char surname[32];
    char phone[16];
} PhoneBookData;

// Структура для реализации двусвязного спика

typedef struct PhoneBookNode_ {
    PhoneBookData* data_;
    struct PhoneBookNode_* next_;
    struct PhoneBookNode_* prev_;
} PhoneBookNode;

// Структура для реализации двусвязного списка

typedef struct PhoneBookListDescriptor_ {
    size_t size_;
    PhoneBookNode* head_;
    PhoneBookNode* tail_;

} PhoneBookListDescriptor;

PhoneBookListDescriptor* InitPhoneBookDescriptor(); // Создает объект дескриптор для списка
PhoneBookData* PhoneCard(char* name, char* surname, char* phone); // Создает карточку с информацией в телефонной книге
PhoneBookListDescriptor* GeneralSearch(PhoneBookListDescriptor* list, char * searchbuff, int choice); // Осуществление поиска

char* GetListRecord(PhoneBookNode *node); // Процесс записи полей структуры для хранения данных в строку

void ShowMenu(PhoneBookListDescriptor* descriptor_); // Отображение меню
void CallSubMenu1(PhoneBookListDescriptor* descriptor_); // Дополнительное меню ввода
void CallSubMenu2(PhoneBookListDescriptor* descriptor_); // Дополнительное меню выбора
void Clear(); // Очистка экрана
void DeleteList(PhoneBookListDescriptor* list); // Удалить весь список
void AddPhoneBookNode(PhoneBookListDescriptor* descriptor_, PhoneBookData* data_); // Добавить элемент списка
void PrintTop(int type_); // Печать шапки интерфейса
void PrintPhoneBook(PhoneBookListDescriptor* list, int choice); // Вывод телефонной книги на экран
void WriteAllToFile(PhoneBookListDescriptor* list); // Запись в файл
void CreateListFromFile(PhoneBookListDescriptor *list); // Выгрузить телефонную книгу из файла



#endif // PHONEBOOK_H

