#include "phonebook.h"

int main()
{
    PhoneBookListDescriptor* ListDescriptor = InitPhoneBookDescriptor();
    ShowMenu(ListDescriptor);
    return 0;
}
