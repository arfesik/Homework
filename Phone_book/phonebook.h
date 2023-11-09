#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения данных
typedef struct PhoneBookData_ {
    char name[32];
    char surname[32];
    char phone[16];
} PhoneBookData;

typedef struct PhoneBookNode_ {
    PhoneBookData* data_;
    struct PhoneBookNode_* next_;
    struct PhoneBookNode_* prev_;
} PhoneBookNode;

typedef struct PhoneBookListDescriptor_ {
    size_t size_;
    PhoneBookNode* head_;
    PhoneBookNode* tail_;

} PhoneBookListDescriptor;

PhoneBookListDescriptor* InitPhoneBookDescriptor();
PhoneBookData* PhoneCard(char* name, char* surname, char* phone);
PhoneBookListDescriptor* GeneralSearch(PhoneBookListDescriptor* list, char * searchbuff, int choice);

char* GetListRecord(PhoneBookNode *node);

void ShowMenu(PhoneBookListDescriptor* descriptor_);
void CallSubMenu1(PhoneBookListDescriptor* descriptor_);
void CallSubMenu2(PhoneBookListDescriptor* descriptor_);
void Clear();
void DeleteList(PhoneBookListDescriptor* list);
void AddPhoneBookNode(PhoneBookListDescriptor* descriptor_, PhoneBookData* data_);
void PrintTop(int type_);
void PrintPhoneBook(PhoneBookListDescriptor* list, int choice);
void WriteAllToFile(PhoneBookListDescriptor* list);
void CreateListFromFile(PhoneBookListDescriptor *list);



#endif // PHONEBOOK_H

