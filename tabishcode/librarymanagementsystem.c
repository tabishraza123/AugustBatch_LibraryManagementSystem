#include<stdio.h>
#include<string.h>

void resetcolor();
void errorcolor();
void SuccessColor();
void yellow();
void blue();
void temp();

int number;
char booktitle[5][100];
char bookauthor[5][100];
int bookStatus[5];
char borrowbook[1][100];
char returnbook[1][100];
char searchbook_title[1][100];
char searchbook_author[1][100];
int bookcount, borrow = 0;

int main()
{
    temp();
    printf("\n**LIBRARY MANAGEMENT SYSTEM**** ");
    printf("\nPRESS 1 FOR ADD NEW BOOK            ");
    printf("\nPRESS 2 FOR DISPLAY AVAILABLE BOOKS ");
    printf("\nPRESS 3 FOR BORROW BOOK             ");
    printf("\nPRESS 4 FOR RETURN BOOK             ");
    printf("\nPRESS 5 FOR SEARCH BOOK BY TITLE    ");
    printf("\nPRESS 6 FOR SEARCH BOOK BY AUTHOR   ");
    printf("\nPRESS 0 FOR EXIT                    ");
    resetcolor();

    do
    {
        printf("\nPlease enter any number: ");
        while (scanf("%d", &number) != 1)
        {
            errorcolor();
            printf("\nInvalid input. Please enter a number: \n");
            resetcolor();
            while (getchar() != '\n');                
        }

        switch (number)
        {
        case 1:
            if (bookcount >= 5)
            {
                errorcolor();
                printf("\nCannot add more books.\n");
                resetcolor();
                break;
            }

            blue();
            printf("Enter Book Title: ");
            resetcolor();

            int validTitle = 0;
            while (!validTitle)
            {
                scanf("%s", &booktitle[bookcount]);

                int allDigits = 1;
                for (int i = 0; booktitle[bookcount][i] != '\0'; i++)
                {
                    if (booktitle[bookcount][i] < '0' || booktitle[bookcount][i] > '9')
                    {
                        allDigits = 0;
                        break;
                    }
                }

                if (allDigits)
                {
                    errorcolor();
                    printf("\nInvalid input.(Enter any character)");
                    resetcolor();
                    blue();
                    printf("\nPlease enter a valid book title: ");
                    resetcolor();
                }
                else
                {
                    validTitle = 1;
                }
            }

            blue();
            printf("Enter Book Author: ");
            resetcolor();

            int validAuthor = 0;
            while (!validAuthor)
            {
                scanf("%s", &bookauthor[bookcount]);

                int allDigits = 1;
                for (int i = 0; bookauthor[bookcount][i] != '\0'; i++)
                {
                    if (bookauthor[bookcount][i] < '0' || bookauthor[bookcount][i] > '9')
                    {
                        allDigits = 0;
                        break;
                    }
                }

                if (allDigits)
                {
                    errorcolor();
                    printf("\nInvalid input.(Enter any characters)");
                    resetcolor();
                    blue();
                    printf("\nPlease enter a valid author name: ");
                    resetcolor();
                }
                else
                {
                    validAuthor = 1;
                }
            }

            bookStatus[bookcount] = 1;
            bookcount++;

            SuccessColor();
            printf("\nCongratulations! New Book Added Successfully\n");
            resetcolor();
            break;
        case 2:
            if (bookcount == 0)
            {
                errorcolor();
                printf("\nNo books are available.\n");
                resetcolor();
            }
            else
            {
                blue();
                printf("\nAvailable Books     Author:\n");
                resetcolor();
                yellow();
                printf("========================================");
                resetcolor();
                for (int i = 0; i < bookcount; i++)
                {
                    if (bookStatus[i] == 1)
                    {
                        printf("\n%s                 %s", booktitle[i], bookauthor[i]);
                    }
                }
                yellow();
                printf("\n========================================\n");
                resetcolor();
            }
            break;

        case 3:
            if (bookcount == 0)
            {
                errorcolor();
                printf("\nNo books available to borrow.\n");
                resetcolor();
            }
            else
            {
                int found = 0;

                do
                {
                    blue();
                    printf("Enter the title of the book you want to borrow: ");
                    resetcolor();
                    scanf("%s",&borrowbook);

                    for (int i = 0; i < bookcount; i++)
                    {
                        if (strcmp(borrowbook[0],booktitle[i]) == 0 && bookStatus[i] == 1)
                        {
                            bookStatus[i] = 0;
                            found = 1;
                            borrow++;
                            SuccessColor();
                            printf("\nYour book is successfully borrowed.\n");
                            resetcolor();
                            break;
                        }
                    }

                    if (!found)
                    {
                        errorcolor();
                        printf("\nThis book is not available for borrowing.\n");
                        resetcolor();
                    }
                } while (!found);
            }
            break;

        case 4:
            if (bookcount == 0)
            {
                errorcolor();
                printf("\nNo books are borrowed.\n");
                resetcolor();
            }
            else
            {
                if (borrow == 0)
                {
                    errorcolor();
                    printf("\nYou haven't borrowed any books to return.\n");
                    resetcolor();
                }
                else
                {
                    int found = 0;

                    do
                    {
                        blue();
                        printf("Enter the title of the book you want to return: ");
                        resetcolor();
                        scanf("%s",&returnbook);

                        for (int i = 0; i < bookcount; i++)
                        {
                            if (strcmp(returnbook[0], booktitle[i]) == 0 && bookStatus[i] == 0)
                            {
                                bookStatus[i] = 1;
                                found = 1;
                                borrow--;
                                SuccessColor();
                                printf("\nYour book has been successfully returned.\n");
                                resetcolor();
                                break;
                            }
                        }

                        if (!found)
                        {
                            errorcolor();
                            printf("\nThis book is not borrowed.\n");
                            resetcolor();
                        }
                    } while (!found);
                }
            }
            break;

        case 5:
            if (bookcount == 0)
            {
                errorcolor();
                printf("\nNo books available to show.\n");
                resetcolor();
            }
            else
            {
                int found = 0;
                int user_choice = 1;

                do
                {
                    blue();
                    printf("Enter the first three characters of the book you want to search: ");
                    resetcolor();
                    scanf("%s",&searchbook_title);

                    for (int i = 0; i < bookcount; i++)
                    {
                        if (strncmp(searchbook_title[0], booktitle[i], 3) == 0)
                        {
                            found = 1;
                            SuccessColor();
                            printf("\nBook Found: '%s' by '%s'", booktitle[i], bookauthor[i]);
                            resetcolor();

                            if (bookStatus[i] == 1)
                            {
                                SuccessColor();
                                printf(" (Available)\n");
                                resetcolor();
                            }
                            else
                            {
                                errorcolor();
                                printf(" (Borrowed)\n");
                                resetcolor();
                            }
                            break;
                        }
                    }

                    if (!found)
                    {
                        errorcolor();
                        printf("\nNo book found matching these characters.\n");
                        resetcolor();

                        do
                        {
                            blue();
                            printf("\nWould you like to try again? (1: Yes, 0: Return to menu): ");
                            resetcolor();
                            scanf("%d", &user_choice);

                            if (user_choice != 1 && user_choice != 0)
                            {
                                errorcolor();
                                printf("\nInvalid choice.Enter 1 or 0 only.\n");
                                resetcolor();
                            }
                        } while (user_choice != 1 && user_choice != 0);
                    }
                } while (!found && user_choice == 1);
            }
            break;

        case 6:
            if (bookcount == 0)
            {
                errorcolor();
                printf("\nNo authors are listed.\n");
                resetcolor();
            }
            else
            {
                int found = 0;
                int user_choice = 1;

                do
                {
                    blue();
                    printf("Enter the first three characters of the author's name you want to search: ");
                    resetcolor();
                    scanf("%s",&searchbook_author);
                    found = 0;

                    for (int i = 0; i < bookcount; i++)
                    {
                        if (strncmp(searchbook_author[0], bookauthor[i], 3) == 0)
                        {
                            found = 1;
                            SuccessColor();
                            printf("\nBook by '%s': '%s'", bookauthor[i], booktitle[i]);
                            resetcolor();

                            if (bookStatus[i] == 1)
                            {
                                SuccessColor();
                                printf(" (Available)\n");
                                resetcolor();
                            }
                            else
                            {
                                errorcolor();
                                printf(" (Borrowed)\n");
                                resetcolor();
                            }
                        }
                    }

                    if (!found)
                    {
                        errorcolor();
                        printf("\nNo books found by an author matching these characters.\n");
                        resetcolor();

                        do
                        {
                            blue();
                            printf("\nWould you like to try again? (1: Yes, 0: Return to menu): ");
                            resetcolor();
                            scanf("%d", &user_choice);

                            if (user_choice != 1 && user_choice != 0)
                            {
                                errorcolor();
                                printf("\nInvalid choice.Enter 1 or 0 only.\n");
                                resetcolor();
                            }
                        } while (user_choice != 1 && user_choice != 0);
                    }
                } while (!found && user_choice == 1);
            }
            break;

        case 0:
            SuccessColor();
            printf("\nExiting the program.\n");
            resetcolor();
            break;

        default:
            errorcolor();
            printf("\nInvalid number! Please try again.\n");
            resetcolor();
            break;
        }

    } while (number != 0);

    return 0;
}

void resetcolor()
{
    printf("\033[0m");
}
void errorcolor()
{
    printf("\033[3;31m");
}
void SuccessColor()
{
    printf("\033[3;32m");
}
void yellow()
{
    printf("\033[3;33m");
}
void blue()
{
    printf("\033[3;36m");
}
void temp()
{
    printf("\033[3;45m");
}