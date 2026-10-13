#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    struct Member
    {
        int id;
        char name[50];
        char surename[50];
        int age;
        char gender[20];
        char membership_type[20];
        int duration;
        float fees;
    
    };
    struct Member m[10];

    int count = 0;
    int choice, i, j, id, found;
    int searchChoice;
    float total, discount, finalFee;
    char searchName[50];
    char temp1[50],temp2[50];

    do{
        printf("\n======= FITNESS CENTER MANAGEMENT =======\n");
        printf("1. Add Member\n");
        printf("2. Display Members\n");
        printf("3. Calculate Membership Fee\n");
        printf("4. Search Member\n");
        printf("5. Update Member\n");
        printf("6. Highest and lowest fees\n");
        printf("7. Exit\n");
        
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid Input!\n");
            return 1;
        }
        switch(choice)
        {
            case 1:
                if(count >=10)
                {
                    printf("Only 10 member allowed!!!\n");
                    break;
                }
                printf("Enter Member Id: ");
                scanf("%d",&id);
                
                found = 0;
                for(i = 0; i < count; i++)
                {
                    if(m[i].id == id)
                    {
                        found = 1;
                        break;
                    }
                }
                if(found == 1)
                {
                    printf("Member already exists!!\n");
                    break;
                }
                m[count].id = id;

                printf("Enter name: ");
                scanf("%49s",m[count].name);
                printf("Enter Surename: ");
                scanf("%49s",m[count].surename);
                printf("Enter Age: ");
                scanf("%d", &m[count].age);
                printf("Enter Gender: ");
                scanf("%19s", m[count].gender);
                printf("Enter Membership_type (Basic/Standard/Premium)");
                scanf("%19s",m[count].membership_type);
                if(strcmp(m[count].membership_type, "Basic") != 0 && strcmp(m[count].membership_type, "Standard") != 0 && strcmp(m[count].membership_type, "Premium") != 0)
                    {
                        printf("Invalid membership type!");
                        break;
                    }
                printf("Enter Duration in months: ");
                scanf("%d",&m[count].duration);
                printf("Enter Monthly Fees: ");
                scanf("%f",&m[count].fees);
            
                count++;

                printf("Member added successfully!!!");
                break;

            case 2:
                if(count == 0)
                {
                    printf("No Members details avaliable!!!");
                }
                else
                {
                    for(i = 0;i < count;i++)
                    {
                        printf("\n---Member %d---",i);
                        printf("ID: %d\n",m[i].id);
                        strcpy(temp2,m[i].name);
                        strcat(temp2, " ");
                        strcat(temp2,m[i].surename);
                        printf("Name: %s\n",temp2);
                        printf("SureName: %s",m[i].name);
                        printf("Name lenght: %zu", strlen(m[i].name));
                        
                        strcpy(temp1,m[i].name);
                        for(j = 0,temp1[j] != '\0',j++)
                        {
                            temp1[j] = (char)toupper((unsigned)temp1[j]);
                        }
                        printf("Name in Uppercase: %s\n", temp1);
                        printf("Age: %d\n", m[i].age);
                        printf("Gender %s\n", m[i].gender);
                        printf("Membership type: %s\n", m[i].membership_type);
                        printf("Duration: %d\n", m[i].duration);
                        printf("Monthly Fee: %d\n", m[i].fees);
                    }
                }
                break;
            
            case 3:
                
                print("Enter Member Id: ");
                scanf("%d",&id);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(m[i].id == id)
                    {
                        total = m[i].fees * m[i].duration;
                        discount = 0;

                        if(m[i].duration >= 6)
                            {
                                discount = total * 10/100;
                            }
                        finalFee = total - discount;
                        
                        printf("Total Fee: Rs. %.2f\n",total);
                        printf("Discount: Rs. %2.f\n", discount);
                        printf("Final Fee: Rs. %2f\n", finalFee);

                        found = 1;
                        break;
                    }
                }
                if(found == 0)
                {
                    printf("Member not found!!");
                }
                break;

            case 4:
                printf("Search by:\n");
                printf("1. Member ID\n");
                printf("2. Member name\n");
                printf("Enter your Choice\n");
                scanf("%d",&searchChoice);

                if(searchChoice == 1)
                {
                    printf("Enter Member ID");
                    scanf("%d", &id);
                    
                    for(i = 0;i < count; i++)
                    {
                        if(m[i].id == id)
                        {
                            found = 1;
                            break;
                        }
                    }
                }
        }
    }
    

    
}