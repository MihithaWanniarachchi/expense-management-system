#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

char correctpw[20]="1234";
typedef struct{
    char date[12];
    int amount;
}income;


typedef  struct{
    char date[12];
    int amount;
    char category[20];
}expense;

income incomes[MAX];
int numIncomes=0;

expense expenses[MAX];
int numExpense=0;

//add incomes
void addIncome()
{
    char c,ch;
    printf(" ----------------------\n");
    printf("|      ADD INCOME      |\n");
    printf(" ----------------------\n\n");
    printf("Enter date(YYYY/MM/DD): ");
    scanf("%s",incomes[numIncomes].date);//scan the date

    printf("Enter the amount: ");
    scanf("%d",&incomes[numIncomes].amount);//scan the amount

    while (getchar() != '\n');

    numIncomes++;
    printf("Income added successfully!\n");

    printf("Do you want to save this income?(y/n): ");
    scanf("%c",&c);

    if(c=='y'||c=='Y'){
        saveIncomeToFile();//call the function to save incomes to the file
    }
    else
        printf("Income not saved.\n");

    while (getchar() != '\n');


    printf("Do you want to add another income?(y/n): ");
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y'){
        addIncome();//again add new income
    }
    else
        returnMenu();

}
// save incomes to files
void saveIncomeToFile()
{
    FILE *file = fopen("incometracker.txt", "a");//save into a file named incometracker
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    //get the index of last income in incomes[]
    int index = numIncomes - 1;

    //write data into the file
    fprintf(file, "%s %d\n", incomes[index].date, incomes[index].amount);

    fclose(file);
    printf("Income saved.\n");
}
//load infomation from incometracker file
void loadIncomeFromFile()
{
    FILE *file = fopen("incometracker.txt","r");


    numIncomes = 0;

    while(fscanf(file,"%s %d",incomes[numIncomes].date,&incomes[numIncomes].amount)==2){
        numIncomes++;
    }
    fclose(file);
}

void addExpense()
{
    char c,ch,choice;
    int number;


   printf(" ----------------------\n");
   printf("|     ADD EXPENSES     |\n");
   printf(" ----------------------\n\n");
   printf("Enter date(YYYY/MM/DD): ");
   scanf("%s",expenses[numExpense].date);//scan the date of expense


   printf("1.Food         2.Savings\n");
   printf("3.Utilities    4.Entertainment\n");
   printf("5.Transport    6.Investment\n");
   printf("7.Clothes      8.Other  \n");
   printf("Enter the category : ");

   scanf("%s",expenses[numExpense].category);//scan the category



   printf("Enter the amount: ");
   scanf("%d",&expenses[numExpense].amount);//sccan the amount

   //removing remaing characters in input buffer
   while (getchar() != '\n');

   numExpense++;//increment number of expenses
   printf("Expense added successfully!\n");

   printf("Do you want to save this expense?(y/n)");
   scanf("%c",&c);

   if(c=='y'||c=='Y'){
    saveExpenseToFile();//call function to save expense
   }
   else
    printf("Expense not saved.\n");

    while (getchar() != '\n');


    printf("Do you want to add another expense?(y/n)");
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y'){
        addExpense();
    }
    else
        returnMenu();
}
//function to save expenses into a file named expensetracker
void saveExpenseToFile()
{
    FILE *file = fopen("expensetracker.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int index = numExpense - 1;

    fprintf(file, "%s %s %d\n", expenses[index].date,expenses[index].category,expenses[index].amount);

    fclose(file);
    printf("Expense saved.\n");
}
//load expenses from the file
void loadExpenseFromFile()
{
    FILE *file = fopen("expensetracker.txt","r");


    numExpense = 0;

    while(fscanf(file,"%s %s %d",expenses[numExpense].date,expenses[numExpense].category,&expenses[numExpense].amount)==3){
        numExpense++;
    }
    fclose(file);
}


void viewDetails()
{
    char c;

    printf(" ------------------------\n");
    printf("|      view details      |\n");
    printf(" ------------------------\n\n");
//check if there are incomes
   if(numIncomes==0){
        printf("No income found. \n");
   }
   else{
        printf("---------------\n");
        printf("| INCOME LIST |\n");
        printf("---------------\n");

        printf("DATE           AMOUNT\n");
        for(int i=0;i<numIncomes;i++){
            //print amount and date of incomes
            printf("%10s %10d\n",incomes[i].date,incomes[i].amount);
   }
   }




//check if there are expenses
    if(numExpense==0){
        printf("No expense found. \n");
    }
    else{
        printf("---------------\n");
        printf("| EXPENSE LIST |\n");
        printf("---------------\n");
        printf("DATE          CATEGORY      AMOUNT\n");

        for(int j=0;j<numExpense;j++){
            //print date,category and amount
            printf("%10s %10s %10d\n",expenses[j].date,expenses[j].category,expenses[j].amount);
    }

    }

    returnMenu();

}
//Function to calculate balance
void checkBalance()
{
    int totalIn=0,totalEx=0;
    char c;

    printf(" -----------------------\n");
    printf("|        BALANCE        |\n");
    printf(" -----------------------\n\n");
    //calculate total incomes
    for(int i=0;i<numIncomes;i++){
        totalIn+=incomes[i].amount;
    }
    printf("Total income: %d\n",totalIn);
    //calculate total outcomes
    for(int j=0;j<numExpense;j++){
        totalEx+=expenses[j].amount;
    }
    printf("Total expense: %d\n",totalEx);
    //Display balance
    printf("Balance: %d\n",totalIn-totalEx);

   returnMenu();
}

//Function to search income and expenses
void searchRecords()
{
    char day[12],cat[20];
    int a,f1=0,f2=0,f3=0;
    char No[]="no";

    printf(" --------------------------\n");
    printf("|      SEARCH DETAILS      |\n");
    printf(" --------------------------\n\n");
    printf("Search by\n 1.Date    2.Category\n");
    //ask to choose date or category
    printf("Enter your choice :");
    scanf("%d",&a);
    //if the use choose date
    if(a==1){
        printf("Enter the date: ");
        scanf("%s",day);

        printf("\n     INCOME\n");
        printf("DATE           AMOUNT\n");
        //finding matching date
        for(int i=0;i<numIncomes;i++){
            if(strcmp(incomes[i].date,day)==0){
                printf("%10s %10d \n",incomes[i].date,incomes[i].amount);
                f1++;
            }
        }
        if(f1==0){
            printf("%s %15s",No,No);//if no result found
        }
        printf("\n");
        printf("\n            EXPENSES");

        printf("\nDATE          CATEGORY      AMOUNT\n");
    //  finding matching date
    for(int j=0;j<numExpense;j++){
            if(strcmp(expenses[j].date,day)==0){
                printf("%10s %10s %10d\n",expenses[j].date,expenses[j].category,expenses[j].amount);
                f2++;
            }
    }
    if(f2==0){
            printf("%s %15s %12s\n",No,No,No);//if no result found
        }


    }
//if user choose category
    if(a==2){
        printf("Enter the category you want: ");
        scanf("%s",cat);

        printf("%s:\n",cat);
        printf("DATE         AMOUNT\n");

        for(int k=0;k<numExpense;k++){
            if(strcasecmp(expenses[k].category,cat)==0){
                printf("%10s %10d\n",expenses[k].date,expenses[k].amount);
                f3++;
            }
    }
    if(f3==0){
            printf("%s %15s\n",No,No);
        }

    }
    returnMenu();
}
//function that include change pw and reset
void settings()
{
    char c;
    int a;
    char enteredpw[20];
    int iscorrect=0;
    printf(" ----------------------\n");
    printf("|       SETTINGS       |\n");
    printf(" ----------------------\n\n");
    //repeat until password is correct
    while(!iscorrect){
        printf("Enter the password: ");
        scanf("%s",enteredpw);
        //check if the password is correct
        if(strcmp(enteredpw,correctpw)==0){
            printf("1.Change password      2.Reset\n");
            printf("Enter your choice?: ");
            scanf("%d",&a);
            iscorrect++;//increment it if password is correct
    }
    else
        printf("Incorrect password.Try again.\n ");

    }

    //give options to choose change password or reset
    switch(a){
        case 1 :changePw();//call function to change password
                savePasswordToFile();//save password to a file
                break;
        case 2 :reset();//call function to reset
                break;
        default:menu();
                break;

    }
}
//function to reset
void changePw()
{
    char ch;
    printf("Enter new password: ");//Ask to enter new password
    scanf("%s", correctpw);

    printf("Password changed successfully.\n");

    while (getchar() != '\n');
    printf("Do you want to save this password?(y/n)");
    scanf("%c",&ch);


    if(ch=='y'||ch=='Y'){
        printf("Password saved.\n");
        savePasswordToFile();//save new password to file

   }
    else{
         printf("Password not changed.\n");
    }
    clearTerminal();//clear the terminal screeen
    menu();

}
//function tosave password to a file
void savePasswordToFile()
{
    FILE* file = fopen("password.txt", "w");

    if (file == NULL) {
        printf("Error opening password file.\n");
        return;
    }

    fprintf(file, "%s", correctpw);
    fclose(file);

}
//function to load password from file
void loadPasswordFromFile()
{
    FILE* file = fopen("password.txt", "r");
    if (file == NULL) {
        // set a default password
        strcpy(correctpw, "1234");
        return;
    }

    fscanf(file, "%s", correctpw);

    fclose(file);
}

//function to restart income
void reset()
{
    char c;
    // set income data into zero
     numIncomes = 0;

    //set  expense data into zero
    numExpense = 0;

    // Reset the income file
    FILE *incomeFile = fopen("incometracker.txt", "w");
    fclose(incomeFile);

    // Reset the expense file
    FILE *expenseFile = fopen("expensetracker.txt", "w");
    fclose(expenseFile);

    printf("System reset successful. All data cleared.\n");

    returnMenu();

}
//function to return to menu
void returnMenu()
{
    int c;
    while (getchar() != '\n');

    printf("Do you want to return main menu?(y/n)");
    scanf("%c",&c);

    if(c=='y'||c=='Y'){
        clearTerminal();
        menu();
    }
    else{
        printf("Thank you!");
        exit(0);
    }

}

void clearTerminal()
{

    #ifdef _WIN32
         system("cls");//for windows
    #else
        system("clear");//for mac,linux
    #endif
}
// Function to display the main menu and handle user choices
void menu()
{
    int ch=0;

    printf(" ------------------------------------------------\n");
    printf("|                      MENU                      |\n");
    printf(" ------------------------------------------------\n");
    printf("[1] Add your income         [2] Add your expenses \n");
    printf("[3] View details            [4] Check balance\n");
    printf("[5] Search records          [6] Settings \n");

    printf("Enter your choice: ");
    scanf("%d",&ch);
//select option
    switch(ch)
    {
        case 1:clearTerminal();
            addIncome();
               break;
        case 2:clearTerminal();
               addExpense();
               break;
        case 3:clearTerminal();
               viewDetails();
               break;
        case 4:clearTerminal();
               checkBalance();
               break;
        case 5:clearTerminal();
               searchRecords();
               break;
        case 6:clearTerminal();
               settings();
               break;
        default:printf("Wrong choice");
                break;
    }


}

int main()
{
    loadIncomeFromFile();
    loadExpenseFromFile();
    loadPasswordFromFile();


    char enteredpw[20];
    int iscorrect=0;

        printf(" ------------------------------------------------\n");
        printf("|    WELCOME TO OUR EXPENSE MANAGEMENT SYSTEM    |\n");
        printf(" ------------------------------------------------\n\n");
        printf("-----Let's manage your money-----\n\n");
    while(!iscorrect){

        printf("Enter the password: ");
        scanf("%s", enteredpw);
        //check the password is correct
        if (strcmp(enteredpw, correctpw) == 0) {
            clearTerminal();
            menu();
            break;

        } else {
            printf("Incorrect password! Try again.\n");
        }

    }


    return 0;
}
