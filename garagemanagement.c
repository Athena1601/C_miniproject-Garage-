
#include <stdio.h>
#include <string.h>

struct manage
{
    char name[30];
    char problem[30];
    char model[30];
    char date[30];
    char pay[30];
    int vehicle, phone, cost;

} x[100];

int n, i, j = 0, a = 0, sum = 0, g, flag, num;

void login();
void logo();
void read();
void add();
void view();
void search();
void edit();
void del();
void write();

int main()
{
    login();
    read();
    int c, i, q;
    logo();
    int m, n;

    while (c != 6)
    {

        printf("\t\t\t\t**Enter your choice**\n\n\t\t\t\t1. Add Information\n\t\t\t\t2. View Information\n\t\t\t\t3. Search\n\t\t\t\t4. Edit Information\n\t\t\t\t5. Delete Information\n\t\t\t\t6. Exit to save\n\n\t\t\t\tOption=");
        scanf("%d", &c); // choice for option
        fflush(stdin);   // making it clear
        if (c == 1)      // add
        {
            logo();
            system("cls");
            add();
        }
        else if (c == 2) // view
        {

            system("cls");
            logo();
            view();
        }
        else if (c == 3) // search
        {
            system("cls");
            logo();
            search();
        }
        else if (c == 4) // edit
        {
            system("cls");
            logo();
            edit();
        }
        else if (c == 5) // delete
        {
            system("cls");
            logo();
            del();
        }
        else if (c == 6)
        {
            write();
            return 0;
        }
        else
        {
            system("cls");//clears the screen
            logo();
            printf("\n\n\t\t\t\tInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}

void login()
{
    logo();
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10];
    char pass[10];
    do
    {
    head:
        printf("\n  ++++++++++++++++++++++++++++++  LOGIN FIRST  ++++++++++++++++++++++++++++++  ");
        printf(" \n\n                  ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n\n                  ENTER PASSWORD:-");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        // char code=pword;
        i = 0;
        // scanf("%s",&pword);
        if (strcmp(uname, "admin") == 0 && strcmp(pword, "pass") == 0)
        {
            printf("  \n\n\n       WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;

            getch(); // holds the screen
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();
        goto head;
    }
    system("cls");
}

void logo()
{
    printf("\t\t\t$------------------------------------$\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t*    Garage Management  System       *\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t*------------------------------------*\n");
}

void add()
{
    logo();
    printf("\n\n");
    printf("\t\t\t\tAlready data inputed on the database =%d\n\n", num); // how many inputs
    printf("\t\t\t\tHow many entry do you want to add = ");
    scanf("%d", &n);
    sum = n + num;

    for (i = num; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("\t\t\t\tEnter Customer's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("\t\t\t\tEnter Problem = ");
        gets(x[i].problem);
        fflush(stdin);
        printf("\t\t\t\tEnter the model = ");
        gets(x[i].model);
        fflush(stdin);
        printf("\t\t\t\tEnter vehicle no = ");
        scanf("%d", &x[i].vehicle);
        fflush(stdin);
        printf("\t\t\t\tEnter phone number = ");
        scanf("%d", &x[i].phone);
        fflush(stdin);
        printf("\t\t\t\tEnter the cost of repair = ");
        scanf("%d", &x[i].cost);
        fflush(stdin);
        printf("\t\t\t\tEnter Payment Status = ");
        gets(x[i].pay);
        fflush(stdin);
        printf("\t\t\t\tEnter Date = ");
        gets(x[i].date);
        fflush(stdin);
        printf("\n");
        // j++;
        a++;
        num++;
    }
}

void view()
{
    for (i = 0; i < num; i++)
    {

        printf("\n\t\t\t\tSerial Number=%d\n", i);
        printf("\t\t\t\tName = ");
        puts(x[i].name);
        printf("\t\t\t\tproblem = ");
        puts(x[i].problem);
        printf("\t\t\t\tModel = ");
        puts(x[i].model);
        printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[i].vehicle, x[i].phone, x[i].cost);
        printf("\t\t\t\tPayment = ");
        puts(x[i].pay);
        printf("\t\t\t\tDate=");
        puts(x[i].date);
        printf("\n\n");
    }
}

void edit()
{
    int q, p;
    fflush(stdin);
    printf("\t\t\t\tWhat do you want to edit ?\n");
    printf("\t\t\t\tEnter your option\n");
    printf("\t\t\t\t1.Name\n\t\t\t\t2.problem\n\t\t\t\t3.model\n\t\t\t\t4.vehicle\n\t\t\t\t5.Phone no.\n\t\t\t\t6.Cost of reapair\n\t\t\t\t7.Date\n\t\t\t\t8.Payment status\n");
    printf("\t\t\t\tOption = ");
    scanf("%d", &q); // option
    if (q <= 8)
    {
        printf("\t\t\t\tEnter the serial no of that customer = (0 - %d)=", num - 1);
        scanf("%d", &p); // serial number
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("\t\t\t\tEnter the new name = ");
                gets(x[p].name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("\t\t\t\tEnter the new problem = ");
                gets(x[p].problem);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("\t\t\t\tEnter the new model = ");
                gets(x[p].model);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("\t\t\t\tEnter the new vehicle no = ");
                scanf("%d", &x[p].vehicle);
            }

            else if (q == 5)
            {
                fflush(stdin);
                printf("\t\t\t\tEnter the new Phone no = ");
                scanf("%d", &x[p].phone);
            }
            else if (q == 6)
            {
                fflush(stdin);
                printf("\t\t\t\tEnter the new COST = ");
                scanf("%d", &x[p].cost);
            }
            else if (q == 8)
            {
                fflush(stdin);
                printf("\t\t\t\tEnter the new Payment status= ");
                gets(x[p].pay);
            }
            else if (q == 7)
            {
                fflush(stdin);
                printf("\t\t\t\tEnter the new DATE = ");
                gets(x[p].date);
            }
        }
        else
        {
            printf("\n\n\t\t\t\tInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\n\t\t\t\tInvalid option\nTry Again!!\n\n");
    }
}

void search()
{
    int s, h, f;
    char u[100];
    printf("\t\t\t\tBy what do you want to search ?\n");
    printf("\t\t\t\t1.BY Serial no.\n\t\t\t\t2.BY Name\n\t\t\t\t3.BY problem\n\t\t\t\t4.BY vehicle no.\n\t\t\t\t5.BY Phone no.\n\t\t\t\t6.BY Model\n\t\t\t\t7.BY Cost\n\t\t\t\t8.BY Date\n\t\t\t\t9.BY Payment Status\n\t\t\t\tOption = ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("\t\t\t\tEnter Serial number of the customer = ");
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("\t\t\t\tSerial Number=%d\n", s);
            printf("\t\t\t\tName = ");
            puts(x[s].name);
            printf("\t\t\t\tproblem = ");
            puts(x[s].problem);
            printf("\t\t\t\tModel = ");
            puts(x[s].model);
            printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
            printf("\t\t\t\tPayment = ");
            puts(x[s].pay);
            printf("\t\t\t\tDate = ");
            puts(x[s].date);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2) // problem is here!!
    {
        int f = 1;
        fflush(stdin);
        printf("\t\t\t\tEnter your name=");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].name) == 0)
            {
                printf("\n");
                printf("\t\t\t\tSerial Number=%d\n", g);
                printf("\t\t\t\tName = ");
                puts(x[g].name);
                printf("\t\t\t\tproblem = ");
                puts(x[g].problem);
                printf("\t\t\t\tModel = ");
                puts(x[g].model);
                printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
                printf("\t\t\t\tPayment status = ");
                puts(x[s].pay);
                printf("\t\t\t\tDate = ");
                puts(x[g].date);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\t\t\t\t\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        fflush(stdin);
        printf("\t\t\t\tEnter problem = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].problem) == 0)
            {
                printf("\n");
                printf("\t\t\t\tSerial Number=%d\n", g);
                printf("\t\t\t\tName = ");
                puts(x[g].name);
                printf("\t\t\t\tproblem = ");
                puts(x[g].problem);
                printf("\t\t\t\tModel = ");
                puts(x[g].model);
                printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
                printf("\t\t\t\tPayment status = ");
                puts(x[s].pay);
                printf("\t\t\t\tDate = ");
                puts(x[g].date);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\t\t\t\t\nNot Found\n");
    }
    else if (h == 4)
    {
        int f = 1;
        printf("\t\t\t\tEnter vehicle number = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].vehicle)
            {
                printf("\n");
                printf("\t\t\t\tSerial Number=%d\n", g);
                printf("\t\t\t\tName = ");
                puts(x[g].name);
                printf("\t\t\t\tproblem = ");
                puts(x[g].problem);
                printf("\t\t\t\tModel = ");
                puts(x[g].model);
                printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
                printf("\t\t\t\tPayment status = ");
                puts(x[s].pay);
                printf("\t\t\t\tDate = ");
                puts(x[g].date);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\t\t\t\tNot Found\n\n");
    }
    else if (h == 5)
    {
        int f = 1;
        printf("\t\t\t\tEnter Phone number = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].phone)
            {
                printf("\n");
                printf("\t\t\t\tSerial Number=%d\n", g);
                printf("\t\t\t\tName = ");
                puts(x[g].name);
                printf("\t\t\t\tproblem = ");
                puts(x[g].problem);
                printf("\t\t\t\tModel = ");
                puts(x[g].model);
                printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
                printf("\t\t\t\tPayment status = ");
                puts(x[s].pay);
                printf("\t\t\t\tDate = ");
                puts(x[g].date);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\t\t\t\tNot Found");
    }
    else if (h == 6)
    {
        int f = 1;
        fflush(stdin);
        printf("\t\t\t\tEnter model = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].model) == 0)
            {
                printf("\n");
                printf("\t\t\t\tSerial Number=%d\n", g);
                printf("\t\t\t\tName = ");
                puts(x[g].name);
                printf("\t\t\t\tproblem = ");
                puts(x[g].problem);
                printf("\t\t\t\tModel = ");
                puts(x[g].model);
                printf("\t\t\t\tvehicle no = %d\nPhone number = 0%d\nCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
                printf("\t\t\t\tPayment status = ");
                puts(x[s].pay);
                printf("\t\t\t\tDate = ");
                puts(x[g].date);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\t\t\t\tNot Found\n\n");
    }
    else if (h == 7)
    {
        int f = 1;
        printf("\t\t\t\tEnter Service Cost = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].cost)
            {
                printf("\n");
                printf("\t\t\t\tSerial Number=%d\n", g);
                printf("\t\t\t\tName = ");
                puts(x[g].name);
                printf("\t\t\t\tproblem = ");
                puts(x[g].problem);
                printf("\t\t\t\tModel = ");
                puts(x[g].model);
                printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
                printf("\t\t\t\tPayment status = ");
                puts(x[s].pay);
                printf("\t\t\t\tDate = ");
                puts(x[g].date);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\n\t\t\t\tNot Found\n");
    }
    else if (h == 9)
    {
        int f = 1;
        fflush(stdin);
        printf("\t\t\t\tEnter The Payment status = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].pay) == 0)
            {
                printf("\n");
                printf("\t\t\t\tSerial Number=%d\n", g);
                printf("\t\t\t\tName = ");
                puts(x[g].name);
                printf("\t\t\t\tproblem = ");
                puts(x[g].problem);
                printf("\t\t\t\tModel = ");
                puts(x[g].model);
                printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
                printf("Payment status = ");
                puts(x[g].pay);
                printf("\t\t\t\tDate = ");
                puts(x[g].date);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\n\t\t\t\tNot Found\n");
    }
    else if (h == 8)
    {
        int f = 1;
        fflush(stdin);
        printf("\t\t\t\tEnter the DATE of service = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].date) == 0)
            {
                printf("\n");
                printf("\t\t\t\tSerial Number=%d\n", g);
                printf("\t\t\t\tName = ");
                puts(x[g].name);
                printf("\t\t\t\tproblem = ");
                puts(x[g].problem);
                printf("\t\t\t\tModel = ");
                puts(x[g].model);
                printf("\t\t\t\tvehicle no = %d\n\t\t\t\tPhone number = 0%d\n\t\t\t\tCost = Rs.%d\n", x[g].vehicle, x[g].phone, x[g].cost);
                printf("Payment status = ");
                puts(x[s].pay);
                printf("\t\t\t\tDate = ");
                puts(x[g].date);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\n\t\t\t\tNot Found\n");
    }

    else
        printf("\n\n\t\t\t\tInvalid input\n\n");
}

void del()
{
    int f, h;
    printf("\t\t\t\tEnter the serial number of the customer  that you want to delete=");
    scanf("%d", &f);
    if (f < num)// serial number starts with 0 and it will go inside the loop if serial number is < number of orders
    {
        printf("\t\t\t\tWhat do you want ?\n");
        printf("\t\t\t\t1.Remove the whole record\n\t\t\t\t2.Remove Name\n\t\t\t\t3.Remove problem\n\t\t\t\t4.Remove model\n\t\t\t\t5.Remove vehicle\n\t\t\t\t6.Remove phone number\n\t\t\t\t7.Remove Cost\n\t\t\t\t8.Remove Date\n\t\t\t\t9.Payment Status\n\t\t\t\tOption = ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num) // ask to deepak about this
            {
                strcpy(x[f].name, x[f + 1].name);
                strcpy(x[f].problem, x[f + 1].problem);
                strcpy(x[f].model, x[f + 1].model);
                strcpy(x[f].date, x[f + 1].date);
                strcpy(x[f].pay, x[f + 1].pay);
                x[f].vehicle = x[f + 1].vehicle;
                x[f].phone = x[f + 1].phone;
                x[f].cost = x[f + 1].cost;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(x[f].name, "Cleared");
        }
        else if (h == 3)
        {
            strcpy(x[f].problem, "Cleared");
        }
        else if (h == 4)
        {
            strcpy(x[f].model, "Cleared");
        }
        else if (h == 5)
        {
            x[f].vehicle = 0;
        }
        else if (h == 6)
        {
            x[f].phone = 0;
        }
        else if (h == 8)
        {
            strcpy(x[f].date, "Cleared");
        }
        else if (h == 7)
        {
            x[f].cost = 0;
        }
        else if (h == 9)
        {
            strcpy(x[f].pay, "NULL");
        }
    }
    else
        printf("\n\n\t\t\t\tInvalid Serial number\n");
}

void read()
{
    FILE *fp = fopen("Garage.txt", "r");
    if (fp == NULL)
    {
        // creation of empty file and opens it
        fp = fopen("Garage.txt", "w");
        fclose(fp);
        printf("\t\t\t\tFile does not exist, I JUST CREATED IT, exiting...\n\n\n");
    }

    num = fread(x, sizeof(struct manage), 100, fp);
    fclose(fp);
}

void write()
{
    FILE *fp = fopen("Garage.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
    }
    fwrite(x, sizeof(struct manage), num, fp);

    fclose(fp);
}
