
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    struct Member {
        int id;
        char name[50];
        int age;
        char gender[10];
        char type[20];
        int duration;
        float fee;
    };

    struct Member m[10];

    int count = 0;
    int choice, i, j, id, found;
    int searchChoice;
    float total, discount, finalFee;

    char searchName[50];
    char temp1[50], temp2[50];

    do
    {
        printf("\n===== FITNESS CENTER MANAGEMENT =====\n");
        printf("1. Add Member\n");
        printf("2. Display Members\n");
        printf("3. Calculate Membership Fee\n");
        printf("4. Search Member\n");
        printf("5. Update Member\n");
        printf("6. Highest and Lowest Fee\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                if (count >= 10)
                {
                    printf("Maximum 10 members allowed!\n");
                    break;
                }

                printf("Enter Member ID: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (m[i].id == id)
                    {
                        found = 1;
                        break;
                    }
                }

                if (found == 1)
                {
                    printf("ID already exists!\n");
                    break;
                }

                m[count].id = id;

                printf("Enter Name: ");
                scanf(" %49[^\n]", m[count].name);

                printf("Enter Age: ");
                scanf("%d", &m[count].age);

                printf("Enter Gender: ");
                scanf("%9s", m[count].gender);

                printf("Enter Membership Type (Basic/Standard/Premium): ");
                scanf("%19s", m[count].type);

                if (strcmp(m[count].type, "Basic") != 0 && strcmp(m[count].type, "Standard") != 0 && strcmp(m[count].type, "Premium") != 0)
                {
                    printf("Invalid membership type!\n");
                    break;
                }

                printf("Enter Duration in Months: ");
                scanf("%d", &m[count].duration);

                printf("Enter Monthly Fee: ");
                scanf("%f", &m[count].fee);

                count++;

                printf("Member added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No members available!\n");
                    break;
                }

                for (i = 0; i < count; i++)
                {
                    printf("\n--- Member %d ---\n", i + 1);
                    printf("ID: %d\n", m[i].id);
                    printf("Name: %s\n", m[i].name);
                    printf("Name Length: %zu\n", strlen(m[i].name));

                    strcpy(temp1, m[i].name);
                    for (j = 0; temp1[j] != '\0'; j++)
                    {
                        temp1[j] =
                            (char)toupper((unsigned char)temp1[j]);
                    }
                    printf("Name in Uppercase: %s\n", temp1);

                    strcpy(temp2, "Member: ");
                    strcat(temp2, m[i].name);
                    printf("%s\n", temp2);

                    printf("Age: %d\n", m[i].age);
                    printf("Gender: %s\n", m[i].gender);
                    printf("Membership: %s\n", m[i].type);
                    printf("Duration: %d months\n", m[i].duration);
                    printf("Monthly Fee: Rs. %.2f\n", m[i].fee);
                }
                break;

            case 3:
                printf("Enter Member ID: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (m[i].id == id)
                    {
                        total = m[i].fee * m[i].duration;
                        discount = 0;

                        if (m[i].duration >= 6)
                        {
                            discount = total * 10 / 100;
                        }

                        finalFee = total - discount;

                        printf("Total Fee: Rs. %.2f\n", total);
                        printf("Discount: Rs. %.2f\n", discount);
                        printf("Final Fee: Rs. %.2f\n", finalFee);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Member not found!\n");
                }
                break;

            case 4:
                printf("Search by:\n");
                printf("1. Member ID\n");
                printf("2. Member Name\n");
                printf("Enter choice: ");
                scanf("%d", &searchChoice);

                found = 0;

                if (searchChoice == 1)
                {
                    printf("Enter Member ID: ");
                    scanf("%d", &id);

                    for (i = 0; i < count; i++)
                    {
                        if (m[i].id == id)
                        {
                            found = 1;
                            break;
                        }
                    }
                }
                else if (searchChoice == 2)
                {
                    printf("Enter Member Name: ");
                    scanf(" %49[^\n]", searchName);

                    for (i = 0; i < count; i++)
                    {
                        strcpy(temp1, m[i].name);
                        strcpy(temp2, searchName);

                        for (j = 0; temp1[j] != '\0'; j++)
                        {
                            temp1[j] =
                                (char)tolower((unsigned char)temp1[j]);
                        }

                        for (j = 0; temp2[j] != '\0'; j++)
                        {
                            temp2[j] =
                                (char)tolower((unsigned char)temp2[j]);
                        }

                        if (strcmp(temp1, temp2) == 0)
                        {
                            found = 1;
                            break;
                        }
                    }
                }
                else
                {
                    printf("Invalid search option!\n");
                    break;
                }

                if (found == 1)
                {
                    printf("\nMember Found!\n");
                    printf("ID: %d\n", m[i].id);
                    printf("Name: %s\n", m[i].name);
                    printf("Age: %d\n", m[i].age);
                    printf("Gender: %s\n", m[i].gender);
                    printf("Membership: %s\n", m[i].type);
                    printf("Duration: %d months\n", m[i].duration);
                    printf("Monthly Fee: Rs. %.2f\n", m[i].fee);
                }
                else
                {
                    printf("Member not found!\n");
                }
                break;

            case 5:
                printf("Enter Member ID to update: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (m[i].id == id)
                    {
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Member not found!\n");
                    break;
                }

                printf("Enter New Name: ");
                scanf(" %49[^\n]", searchName);
                strcpy(m[i].name, searchName);

                printf("Enter New Age: ");
                scanf("%d", &m[i].age);

                printf("Enter New Gender: ");
                scanf("%9s", m[i].gender);

                printf("Enter New Membership Type: ");
                scanf("%19s", m[i].type);

                if (strcmp(m[i].type, "Basic") != 0 &&
                    strcmp(m[i].type, "Standard") != 0 &&
                    strcmp(m[i].type, "Premium") != 0)
                {
                    printf("Invalid membership type!\n");
                    break;
                }

                printf("Enter New Duration: ");
                scanf("%d", &m[i].duration);

                printf("Enter New Monthly Fee: ");
                scanf("%f", &m[i].fee);

                printf("Member updated successfully!\n");
                break;

            case 6:
                if (count == 0)
                {
                    printf("No members available!\n");
                    break;
                }

                {
                    int high = 0, low = 0;

                    for (i = 1; i < count; i++)
                    {
                        if (m[i].fee > m[high].fee)
                        {
                            high = i;
                        }

                        if (m[i].fee < m[low].fee)
                        {
                            low = i;
                        }
                    }

                    printf("Highest Fee: %s - Rs. %.2f\n",
                           m[high].name, m[high].fee);

                    printf("Lowest Fee: %s - Rs. %.2f\n",
                           m[low].name, m[low].fee);
                }
                break;

            case 7:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
