#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* structure to store employee salary details */
struct employee
{
        int empId;
        char name[32];
        int basic, hra, da, ma;
        int pf, insurance;
        float gross, net;
};
//   red color
void red()
{
        printf("\033[1;31m");
}
// green color text
void green()
{
        printf("\033[1;32m");
}

//yellow colour text
void yellow()
{
        printf("\033[1;33m");
}


// blue colour of text
void blue()
{
        printf("\033[1;34m");
}

// for purple colour
void purple()
{
        printf("\033[1;35m");
}
// for white
void white()
{
        printf("\033[1;37m");
}


// for reset color .
void reset()
{
        printf("\033[0m");
}
// for loading
int load()
{
        int i;
        while (1)
        {
                blue();
                printf("LOADING\t");
                reset();
                for (i = 0; i < 3; i++)
                {
                        red();
                        Beep(0, 500);

                        printf(".");

                        Beep(0, 500);
                        reset();
                }
                system("cls"); //for clearing the terminal screen
                break;
        }
}
// when network is slow we use this loading.
int load1()
{
        int i;
        while (1)
        {
                blue();
                printf("Network slow please wait");
                reset();
                for (i = 0; i < 4; i++)
                {
                        red();
                        Beep(1500, 500);

                        printf(".");

                        Beep(1000, 500);
                        reset();
                }
                system("cls");
                break;
        }
}
int load2()
{
        int i;
        while (1)
        {
                red();
                printf("EXIT !! PLEASE WAIT");
                reset();
                for (i = 0; i < 6; i++)
                {
                        Beep(1000, 500);
                        blue();  
                        printf(">>");

                        Beep(1000, 500);
                        reset();
                }
                system("cls");
                break;
        }
}

/* prints payslip for the requested employee */
void printSalary(struct employee e1)
{
        green();
        printf("==================== GENERATING SALLERYSLIP ===================\n");
      
        white();
          printf("1)\tSALARY SLIP:\t\t  %s\n", e1.name);              
          printf("2)\tEMPLOYEE ID:\t\t  %d\n", e1.empId);            
          printf("3)\tBASIC SALARY:\t\t  %d\t\n", e1.basic);             
          printf("4)\tHOUSERENT ALLOWANCE:\t  %d\t\t\n", e1.hra);              
          printf("5)\tDEARNESS ALLOWANCE:\t  %d\t\t\t\n", e1.da);                
          printf("6)\tMEDICAL ALLOWANCE:\t  %d\t\t\t\n", e1.ma);                
          printf("7)\tGROSS SALARY:\t\t  %.2f Rupees\n", e1.gross);
                green();      
          printf("\t*********************Deductions**********************\n"); 
          white();                   
          printf("1)\tPROVIDENT FUND:\t %d\t\t\t\n", e1.pf);           
          printf("2)\tINSURANCE:\t %d\t\t\t\n", e1.insurance);        
          printf("3)\tNET SALARY:\t %.2f Rupees\t\t \n", e1.net);    
          green();
          printf("==================================================================\n");   
        return;
        reset();
}

/* display all the employee records entered */
void display(struct employee e1)
{
        int i;
        printf(" %d\t %s\t %d\t%d\t%d\t%d\t%d\t%d\n",e1.empId, e1.name, e1.basic, e1.hra, e1.da, e1.ma, e1.pf, e1.insurance);
        return;
}

int main()
{
        // i=for loop 2)ch =ask for continueor exit 3) num = taking no. of emloyee 4)flag=checking two condition 5)empId =matching emp id
        int i, ch, num, flag, empID;      
       //1)choice use in first switch 2)update use for checking condition when we want to update 3)updatechoice use for switch ladder
          int choice, update, updateChoice;
       //Here we take pointer variable just because dynamically memory allocation.
        struct employee *e1;       
        /* get the number of employees from the user  */
        green();
        printf("Enter the number of employees:");
        scanf("%d", &num);

        /* dynamically allocate memory to store employee salary details */
        e1 = (struct employee *)malloc(sizeof(struct employee) * num );

        /* get the employee salary details from the customer */
        load();
                white();
        printf("Enter your input for every employee:\n");
        for (i = 0; i < num; i++)
        {
                printf("Employee ID:");
                scanf("%d", &(e1[i].empId));
                getchar();
                printf("Employee Name:");
                gets(e1[i].name);
                printf("Basic Salary:");
                scanf("%d", &(e1[i].basic));
                printf("House Rent Allowance:");
                scanf("%d", &(e1[i].hra));
                printf("Dearness Allowance:");
                scanf("%d", &(e1[i].da));
                printf("Medical Allowance:");
                scanf("%d", &(e1[i].ma));
                printf("Enter the deductions: \n");
                printf("Provident Fund:");
                scanf("%d", &(e1[i].pf));
                printf("Insurance:");
                scanf("%d", &(e1[i].insurance));
                printf("\n");
        }
        /* printing payslip for the given employee ID */
        load();
        while (1)
        {
                green();
                printf("\n\n ======================== EMPLOYEE PAYROLL SYSTEM ===================== \n\n");
                reset();
                white();
                printf("\n\n***************************CHOOSE YOUR OPTION****************************\n");
                printf("\n1) SHOW ALL RECORDS\n");
                printf("\n2) PRINT THE SALARY SLIP\n");
                printf("\n3) UPDATE EMPLOYEE RECORD\n");
                printf("\n4) EXIT\n");
                green();
                printf("\n ======================================================================\n");
                reset();
                white();
                printf("Enter your choice : ");
                scanf("%d", &choice);
                reset();

                // if (choice != 4)
                // {
                        switch (choice)
                        {
                        case 1: /*printing all the records entered before printing the slip */
                                load();
                                green();
                                printf("=========================== ALL EMPLOYEE DETAIL ==================================\n");
                                red();
                                printf("\n Sl.No Emp.ID\t Emp.Name\t Basic\tHRA\tDA\tMA\tPF\tInsurance \n");
                                green();
                                

                                for (i = 0; i < num; i++)
                                {
                                        printf("\n==================================================================================\n");

                                    red();   printf("%d\t",i+1); green(); display(e1[i]);
                                }
                                printf("\n==================================================================================\n");
                                reset();
                                break;

                        case 2: /* gross and net salary calculation */
                                load();
                                for (i = 0; i < num; i++)
                                {
                                        e1[i].gross = e1[i].basic + e1[i].hra + e1[i].da + e1[i].ma;

                                        e1[i].net = e1[i].gross - (e1[i].pf + e1[i].insurance);
                                }
                                green();
                                printf("Enter employee ID to get payslip:");
                                scanf("%d", &empID);
                                reset();
                                flag = 0;
                                for (i = 0; i < num; i++)
                                {
                                        if (empID == e1[i].empId)
                                        {       
                                                load();
                                                load1();
                                                printSalary(e1[i]);
                                                flag = 1;
                                        }
                                }

                                if (flag == 0)
                                {
                                        yellow();
                                        printf("No Record Found!!\n");
                                }
                                break;

                        case 3:
                                load();
                                green();
                                printf("Enter the employee ID to update data: ");
                                scanf("%d", &update);

                                flag = 0;
                                for (i = 0; i < num; i++)
                                {
                                        if (update == e1[i].empId)
                                        {
                                                load();
                                                load1();
                                                 green();
                                                printf("\n\n========================== WHAT YOU WANT TO UPDATE =============================== \n");
                                                red();
                                                printf("1) NAME\n");
                                                printf("2) BASIC SALARY\n");
                                                printf("3) HOUSE RENT ALLOWANCE\n");
                                                printf("4) DEARNESS ALLOWANCE\n");
                                                printf("5) MEDICAL ALLOWANCE\n");
                                                printf("6) PROVIDENT FUND \n");
                                                printf("7) INSURANCE \n");
                                                printf("8) UPDATE ALL RECORDS \n");
                                                green();
                                                printf("\n====================================================================================\n");
                                                printf("Enter your choice : ");
                                                reset();
                                                scanf("%d", &updateChoice);
                                                switch (updateChoice)
                                                {
                                                case 1:
                                                        getchar();
                                                        blue();
                                                        printf("Employee Name:");
                                                        gets(e1[i].name);

                                                        break;

                                                case 2:
                                                        blue();
                                                        printf("Basic Salary:");
                                                        scanf("%d", &(e1[i].basic));
                                                        break;

                                                case 3:
                                                        blue();
                                                        printf("House Rent Allowance:");
                                                        scanf("%d", &(e1[i].hra));
                                                        break;

                                                case 4:
                                                        blue();
                                                        printf("Dearness Allowance:");
                                                        scanf("%d", &(e1[i].da));
                                                        break;

                                                case 5:
                                                        blue();
                                                        printf("Medical Allowance:");
                                                        scanf("%d", &(e1[i].ma));
                                                        break;

                                                case 6:
                                                        blue();
                                                        printf("Provident Fund:");
                                                        scanf("%d", &(e1[i].pf));
                                                        break;

                                                case 7:
                                                        blue();
                                                        printf("Insurance:");
                                                        scanf("%d", &(e1[i].insurance));
                                                        break;

                                                case 8:
                                                        blue();
                                                        getchar();
                                                        printf("Employee Name:");
                                                        gets(e1[i].name);
                                                        printf("Basic Salary:");
                                                        scanf("%d", &(e1[i].basic));
                                                        printf("House Rent Allowance:");
                                                        scanf("%d", &(e1[i].hra));
                                                        printf("Dearness Allowance:");
                                                        scanf("%d", &(e1[i].da));
                                                        printf("Medical Allowance:");
                                                        scanf("%d", &(e1[i].ma));
                                                        printf("******** Enter the deductions **********\n");
                                                        printf("Provident Fund:");
                                                        scanf("%d", &(e1[i].pf));
                                                        printf("Insurance:");
                                                        scanf("%d", &(e1[i].insurance));
                                                        printf("\n");
                                                        break;

                                                default:
                                                        red(),
                                                            printf("Error Selection. Try Again !");
                                                }

                                                flag = 1;
                                        }
                                }

                                if (flag == 0)
                                {
                                        red();
                                        printf("No Record Found!!\n");
                                }
                                break;

                        case 4:
                                exit(1);
                                break;

                        default:
                                red();
                                printf("\tERROR\t404 NOT FOUND");
                        }
                        purple();
                        printf("\n Do You Want To Continue(1/0):");
                        scanf("%d", &ch);
                        reset();
                if (ch == 0)
                {         
                        yellow();
                        printf("~~THANK YOU FOR VISITING EMPLOYEE SALLERY DEPARTMENT~~\n\n");
                        load2();
                        break;
                }
                }
        return 0;
        }
