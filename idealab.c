// Author : Dipankar Achinta, April, 2012
// Mock Python command line interpreter
// This program emulates the python command line interpreter tool.
// It accepts strings and stores it in a runtime defined variable, just like in the actual interpreter instance
// Also it finds the length of the string stored in the variable

#include <stdio.h>
#include <conio.h>
#include <string.h>

// Function signature
void retain_string(char*, int);
int  len(char*);

// The main function
// All the emualation happens here
void main()
{
    int i, len_user_ip, len_stripped_ip, j = 0, index_of_unstripped, index_of_stripped, len_var, same_str = 0, len_user_ip2;
    char user_ip[40], filtered_array[40], _var[40], user_ip2[40];
    char user_ip3[40], find_length[6] = {'l', 'e', 'n', '(', '\0'};
    int len_user_ip3, len_find_length, get_length = 0, length_of_str = 0, str_longiness, k;
    clrscr();
    printf("\n\n");
    printf("************************** CURRENT INTERPRETER INSTANCE *********");
    printf("***************\n\n\n");
    printf(">>> ");
    gets(user_ip);
    len_user_ip = strlen(user_ip);
    for(i = 0; i < 40 && user_ip[i] != '\0' && i < len_user_ip; i++)
    {
        if(user_ip[i] == ' ' || user_ip[i] == '=')
        {
            break;
        }
        else
        {
            _var[i] = user_ip[i];
        }
    }
    _var[i] = '\0';
    len_var = strlen(_var);
    for(i = 0; i < len_user_ip && i < 40 && user_ip[i] != '\0'; i++)
    {
        if(user_ip[i] == '"')
        {
            index_of_unstripped = i;
            break;
        }
    }
    retain_string(user_ip, index_of_unstripped);
    len_stripped_ip = strlen(user_ip);
    for(i = 0; i < len_stripped_ip && i < 40 && user_ip[i] != '\0'; i++)
    {
        if(user_ip[i] == '"')
        {
            index_of_stripped = i;
            break;
        }
    }
    filtered_array[j] = '\'';
    j += 1;
    for(i = index_of_stripped + 1; i < 40 && user_ip[i] != '\0'; i++) // Becoz, index_of_stripped = '"', which is already assigned & replaced by '\'' at filtered_array[0];
    {
        filtered_array[j] = user_ip[i];
        j++;
    }
    filtered_array[j - 1] = '\'';
    filtered_array[j] = '\0';
    input:
    printf(">>> ");
    gets(user_ip2);
    len_user_ip2 = strlen(user_ip2);
    if(len_user_ip2 == len_var)
    {
        for(i = 0; i < len_user_ip2; i++)
        {
            if(user_ip2[i] == _var[i])
            {
                same_str = 1;
            }
        }
    }
    else
    {
        goto input;
    }
    if(same_str == 1)
    {
        printf("%s\n", filtered_array);
    }
    input1:
    printf(">>> ");
    gets(user_ip3);
    len_user_ip3 = strlen(user_ip3);
    len_find_length = strlen(find_length);
    for(i = 0; i < len_find_length && find_length[i] != '\0'; i++)
    {
        if(user_ip3[i] == find_length[i])
        {
            get_length = 1;
        }
        else
        {
            get_length = 0;
            goto input1;
        }
    }
    for(j = i - 1; j < len_user_ip3 && user_ip3[j] != '\0'; j++)
    {
        if(user_ip3[j] == ')')
        {
            if((j + 1) == len_user_ip3)
            {
                get_length = 1;
                break;
            }
            else
            {
                for(i = j + 1; i < len_user_ip3 && user_ip3[i] != '\0'; i++)
                {
                    if(user_ip3[i] == ' ')
                    {
                        get_length = 1;
                    }
                    else
                    {
                        get_length = 0;
                        goto input1;
                    }
                }
           }
        }
        else
        {
            get_length = 0;
        }
    }
    if(get_length == 1)
    {
        j = 0; 
        for(i = len_find_length, k = j; i < len_user_ip3 && user_ip3[i] != ')' && _var[k] != '\0'; i++)
        {
            if(user_ip3[i] == _var[j])
            {
                length_of_str = 1;
                j++;
            }
            else
            {
                if(user_ip3[i] == ' ')
                {
                    continue;
                }
                else
                {
                    get_length = 0;
                    length_of_str = 0;
                    goto input1;
                }
            }
        }
    }
    else
    {
        goto input1;
    }
    if(length_of_str == 1)
    {
        str_longiness = len(filtered_array);
        printf("%d\n", str_longiness);
    }
    printf(">>> ");
    getch();
}

// Pointer magic to the rescue
void retain_string(char* i_mediate, int index_of_Q)
{
    int i;
    for(i = index_of_Q; i > 0 ; i--)
    {
        if(*(i_mediate + i) == ' ')
        {
            *(i_mediate + i - 1) = *(i_mediate + i);
        }
    }
}

// Function that actually does the string length calculation
// This may not be how it is done in the real deal, but thats what I thought back then
int len(char* dummy_array)
{
    int i, dummy_len;
    dummy_len = strlen(dummy_array);
    for(i = 1; i < dummy_len && dummy_array[i] != '\'' && dummy_array[i] != '\0'; i++)
    {
        ;
    }
    return (i - 1);
}