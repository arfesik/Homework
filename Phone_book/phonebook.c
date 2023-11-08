#include "phonebook.h"

void ShowMenu(PhoneBookListDescriptor* descriptor_)
{
    int choose;
    printf("\n1. ADD person in phonebook\n2. DISPLAY phonebook\n3. Write to FILE\n4. Read from FILE\n5. SEARCH person\n6. Exit\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        CallMenu1(descriptor_);
        break;
    case 2:
        Clear();
        PrintPhoneBook(descriptor_);
        ShowMenu(descriptor_);
        break;
    case 3:
        WriteAllToFile(descriptor_);
        ShowMenu(descriptor_);
        break;
    case 4:
        printf("1");
        break;
    case 5:
        printf("1");
        break;
    case 6:
        exit(0);
        break;
    }
}

PhoneBookListDescriptor* InitPhoneBookDescriptor()
{
    PhoneBookListDescriptor* tmp = (PhoneBookListDescriptor*) malloc(sizeof(PhoneBookListDescriptor));
    if(tmp == NULL)
    {
        exit(1);
    }

    tmp->size_= 0;
    tmp->head_ = NULL;
    tmp->tail_ = NULL;

    return tmp;
}

void DeleteList(PhoneBookListDescriptor* list)
{
    PhoneBookNode* tmp = list->head_;
    PhoneBookNode* next = NULL;
    while (tmp)
    {
        next = tmp->next_;
        free(tmp->data_);
        free(tmp);
        tmp = next;

    }
}


PhoneBookData* PhoneCard(char* name_, char* surname_, char* phone_)
{
    PhoneBookData* tmp = (PhoneBookData*) malloc(sizeof(PhoneBookData));
    if(tmp == NULL)
    {
        exit(2);
    }

    strncpy(tmp->name, name_, sizeof(tmp->name));
    strncpy(tmp->surname, surname_, sizeof(tmp->surname));
    strncpy(tmp->phone, phone_, sizeof(tmp->phone));

    return tmp;
}

void AddPhoneBookNode(PhoneBookListDescriptor *descriptor_, PhoneBookData *data_)
{
    PhoneBookNode* tmp = (PhoneBookNode*) malloc(sizeof(PhoneBookNode));
    if(tmp == NULL)
    {
        exit(3);
    }

    tmp->data_ = data_;
    tmp->next_ = NULL;
    tmp->prev_ = descriptor_->tail_;

    if(descriptor_->tail_)
    {
        descriptor_->tail_->next_ = tmp;
    }
    descriptor_->tail_ = tmp;

    if(descriptor_->head_ == NULL)
    {
        descriptor_->head_ = tmp;
    }
    descriptor_->size_++;
}

void CallMenu1(PhoneBookListDescriptor* descriptor_)
{
    Clear();
    char name[64];
    char surname[32];
    char phone[16];

    printf("Type name: ");
    scanf("%s", name);


    printf("Type surname: ");
    scanf("%s", surname);

    printf("Type phone: ");
    scanf("%s", phone);
    //printf("\n%s %s %s\n", name, surname, phone);

    PhoneBookData* DATA_ = PhoneCard(name, surname, phone);
    AddPhoneBookNode(descriptor_, DATA_);
    Clear();
    printf("Record succsessfully added....\n");
    ShowMenu(descriptor_);

}

void Clear()
{
    printf("\x1B[2J\x1B[H");
}

void PrintTop()
{
    printf("**************************************************\n");
    printf("*                   Phone Book                   *\n");
    printf("**************************************************\n");
    printf("*  №  *         Name           *      Phone      *\n");
    printf("**************************************************\n");
}

void PrintPhoneBook(PhoneBookListDescriptor *list)
{
    PhoneBookNode* tmp = list->head_;
    PrintTop();
    for (size_t i = 1; i <= list->size_; ++i)
    {
        unsigned short sp = 20 - strlen(tmp->data_->name)-strlen(tmp->data_->surname);
        printf("   %u   ", (unsigned int)i);
        printf("  %s", tmp->data_->name);
        printf(" %s", tmp->data_->surname);
        printf(" %s", " ");
        for(int k = 1; k <= sp; ++k)
        {
            printf("%s", " ");
        }
        printf("%s\n", tmp->data_->phone);
        tmp = tmp->next_;
    }
}

void WriteAllToFile(PhoneBookListDescriptor *list)
{
    char* filename = "phonebook.txt";
    FILE *fp = fopen(filename, "w");
    if(fp)
    {
        PhoneBookNode* tmp = list->head_;
        for (size_t i = 1; i <= list->size_; ++i)
        {
            fputs(GetListRecord(tmp), fp);
            fputs("\n", fp);
            tmp = tmp->next_;
        }
        fclose(fp);
        printf("\nAdded to FILE succsessfully ");
    }
}

char *GetListRecord(PhoneBookNode *node)
{
    int lname = strlen((char*)&(node->data_->name));
    int lsurname = strlen((char*)&(node->data_->surname));
    int lphone = strlen((char*)&(node->data_->phone));

    static char buff[84];

    memcpy(buff, (char *)&(node->data_->name), lname);
    memcpy(buff + lname, " ", 1);
    memcpy(buff + lname + 1, (char*)&(node->data_->surname), lsurname);
    memcpy(buff + lname + lsurname + 1, " ", 1);
    memcpy(buff + lname + lsurname + 2, (char*)&(node->data_->phone), lphone + 1);

    return buff;
}

