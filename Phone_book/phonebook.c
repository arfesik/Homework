#include "phonebook.h"

void ShowMenu(PhoneBookListDescriptor* descriptor_)
{
    int choose;
    printf("\n1. ADD person in phonebook\n2. DISPLAY phonebook\n3. Write to FILE\n4. Read from FILE\n5. SEARCH person\n6. Exit\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        CallSubMenu1(descriptor_);
        break;
    case 2:
        Clear();
        PrintPhoneBook(descriptor_, 0);
        ShowMenu(descriptor_);
        break;
    case 3:
        if (descriptor_->size_ != 0)
        {
        WriteAllToFile(descriptor_);
        }
        else
        {
        printf("\nPhone book is empty, nothing to write to FILE\n");
        }
        ShowMenu(descriptor_);
        break;
    case 4:
        CreateListFromFile(descriptor_);
        ShowMenu(descriptor_);
        break;
    case 5:
        CallSubMenu2(descriptor_);
        ShowMenu(descriptor_);
        break;
    case 6:
        DeleteList(descriptor_);
        free(descriptor_);
        descriptor_ = NULL;
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

void CallSubMenu1(PhoneBookListDescriptor* descriptor_)
{
    Clear();
    char name[32];
    char surname[32];
    char phone[16];

    printf("Type name: ");
    scanf("%s", name);


    printf("Type surname: ");
    scanf("%s", surname);

    printf("Type phone (without + or -): ");
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

void PrintTop(int type_)
{
    printf("**************************************************\n");
    switch(type_)
    {
    case 0:
        printf("*                   Phone Book                   *\n");
        break;
    case 1:
        printf("*                   Search result                *\n");
        break;
    }

    printf("**************************************************\n");
    printf("*  №  *         Name           *      Phone      *\n");
    printf("**************************************************\n");
}

void PrintPhoneBook(PhoneBookListDescriptor *list, int choice)
{
    PhoneBookNode* tmp = list->head_;
    PrintTop(choice);
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
        printf("\nAdded to FILE succsessfully\n");
    }
}

char *GetListRecord(PhoneBookNode *node)
{
    int lname = strlen((char*)&(node->data_->name));
    int lsurname = strlen((char*)&(node->data_->surname));
    int lphone = strlen((char*)&(node->data_->phone));

    static char buff[85];

    if(strlen(buff) != 0)
        strncpy(buff,"\0",sizeof(buff));

    memcpy(buff, (char *)&(node->data_->name), lname);
    memcpy(buff + lname, " ", 1);
    memcpy(buff + lname + 1, (char*)&(node->data_->surname), lsurname);
    memcpy(buff + lname + lsurname + 1, " ", 1);
    memcpy(buff + lname + lsurname + 2, (char*)&(node->data_->phone), lphone);
    memcpy(buff + lname + lsurname + lphone + 2, " ", 1);

    return buff;
}


void CreateListFromFile(PhoneBookListDescriptor *list)
{
    if (list->head_ != 0)
    {
        DeleteList(list);
        list->head_ = NULL;
        list->tail_ = NULL;
        list->size_ = 0;
    }

    char* filename = "phonebook.txt";
    char buffer[85];
    char* istr;
    char name[32];
    char surname[32];
    char phone[16];
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        while(fgets(buffer, sizeof(buffer), fp) != NULL)
        {
            istr = strtok(buffer, " ");
            strncpy(name, istr, sizeof(name));
            istr = strtok(NULL, " ");
            strncpy(surname, istr, sizeof(surname));
            istr = strtok(NULL, " ");
            strncpy(phone, istr, sizeof(phone));
            PhoneBookData* tmp = PhoneCard(name, surname, phone);
            AddPhoneBookNode(list, tmp);

        }
        fclose(fp);
        printf("\nData loaded\n");
    }
}

void CallSubMenu2(PhoneBookListDescriptor *descriptor_)
{
    int choose;
    char searchbuff[32];
    Clear();
    printf("Press 1 - search by name\nPress 2 - search by surname\nPress 3 - search by phone\n");
    scanf("%d", &choose);
    switch(choose)
    {
    case 1:
        printf("\nType name to search: ");
        scanf("%s", searchbuff);
        if(descriptor_->size_ != 0)
        {
            PhoneBookListDescriptor* searchresult_ = GeneralSearch(descriptor_, searchbuff, 1);
            if(searchresult_->size_ != 0)
            {
            PrintPhoneBook(searchresult_, 1);
            }
            else
            {
            PrintTop(1);
            printf("*                   No data found                *\n");
            }
            DeleteList(searchresult_);
            free(searchresult_);
            searchresult_ = NULL;
        }
        else
        {
            printf("\nPhone book is empty, nothing to search");
        }
        break;
    case 2:
        printf("\nType surname to search: ");
        scanf("%s", searchbuff);
        if(descriptor_->size_ != 0)
        {
            PhoneBookListDescriptor* searchresult_ = GeneralSearch(descriptor_, searchbuff, 2);
            if(searchresult_->size_ != 0)
            {
            PrintPhoneBook(searchresult_, 1);
            }
            else
            {
            PrintTop(1);
            printf("*                   No data found                *\n");
            }
            DeleteList(searchresult_);
            free(searchresult_);
            searchresult_ = NULL;
        }
        else
        {
            printf("\nPhone book is empty, nothing to search");
        }
        break;
    case 3:
        printf("\nType phone to search: ");
        scanf("%s", searchbuff);
        if(descriptor_->size_ != 0)
        {
            PhoneBookListDescriptor* searchresult_ = GeneralSearch(descriptor_, searchbuff, 3);
            if(searchresult_->size_ != 0)
            {
            PrintPhoneBook(searchresult_, 1);
            }
            else
            {
            PrintTop(1);
            printf("*                   No data found                *\n");
            }
            DeleteList(searchresult_);
            free(searchresult_);
            searchresult_ = NULL;
        }
        else
        {
            printf("\nPhone book is empty, nothing to search");
        }
        break;
    }

}

PhoneBookListDescriptor *GeneralSearch(PhoneBookListDescriptor *list, char* searchbuff, int choice)
{

    PhoneBookListDescriptor* searchresult = InitPhoneBookDescriptor();
    PhoneBookNode* tmp = list->head_;
    for (size_t i = 1; i <= list->size_; ++i)
    {
        switch(choice)
        {
        case 1:
           // if (strcmp((char*)&(tmp->data_->name), searchbuff) == 0)
            if (strstr((char*)&(tmp->data_->name), searchbuff) != NULL)
            {
            PhoneBookData* data_ = PhoneCard((char*)&(tmp->data_->name),(char*)&(tmp->data_->surname),(char*)&(tmp->data_->phone));
            AddPhoneBookNode(searchresult, data_);
            }
            tmp = tmp->next_;
            break;
        case 2:
            if (strstr((char*)&(tmp->data_->surname), searchbuff) != NULL)
            {
            PhoneBookData* data_ = PhoneCard((char*)&(tmp->data_->name),(char*)&(tmp->data_->surname),(char*)&(tmp->data_->phone));
            AddPhoneBookNode(searchresult, data_);
            }
            tmp = tmp->next_;
            break;
        case 3:
            if (strstr((char*)&(tmp->data_->phone), searchbuff) != NULL)
            {
            PhoneBookData* data_ = PhoneCard((char*)&(tmp->data_->name),(char*)&(tmp->data_->surname),(char*)&(tmp->data_->phone));
            AddPhoneBookNode(searchresult, data_);
            }
            tmp = tmp->next_;
            break;
        }
    }
    return searchresult;
}
