#include <stdio.h>

int validate(char *name)
{
    int i;

    for (i = 0; name[i] != '\0'; i++)
    {
        if (!(name[i] > 65 && name[i] <= 90) && !(name[i] >= 97 && name[i] <= 122) && (!name[i] >= 48 && name[i] <= 57))
        {
            return 1;
        }
    }

    return 0;
}

int main()
{

    char *name = "An?321";

    if (validate(name))
    {
        printf("It's a VALID string");
    }
    else
    {
        printf("INVALID string");
    }
}