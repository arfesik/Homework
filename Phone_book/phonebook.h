#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* GetListRecord(PhoneBookNode *node);

void ShowMenu(PhoneBookListDescriptor* descriptor_);
void CallMenu1(PhoneBookListDescriptor* descriptor_);
void Clear();
void DeleteList(PhoneBookListDescriptor* list);
void AddPhoneBookNode(PhoneBookListDescriptor* descriptor_, PhoneBookData* data_);
void PrintTop();
void PrintPhoneBook(PhoneBookListDescriptor* list);
void WriteAllToFile(PhoneBookListDescriptor* list);


#endif // PHONEBOOK_H

