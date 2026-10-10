#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    struct Member
    {
        int id;
        char name[50];
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
            if(count >=10);
            {
                printf("Only 10 member allowed!!!\n");
                break;
            }
            printf("Enter Member Id: ");
            scanf("%d",&id);
            
            found = 0;
            for(i = 0; i < count; i++);
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
            scanf("%d",&m[count].fees);
        
            count++;
            printf("Member added successfully!!!");
            break;
        
        

        }
    }
    

    
    }