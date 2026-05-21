#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char savedName[50];
int savedAge;
char savedPhone[15];
char savedPin[20];
double savedbalance;
char savedAccount[50];


int accountstat= 0;

void showBalance(){
    if(!accountstat) {
         printf("Sorry, but no account been found! Create one first by adding a account.");
                }

                printf("\nUSER ACCOUNT DASHBOARD\n");
                printf("Account Number: %s\n", savedAccount);
                printf("Name: %s\n", savedName);
                printf("Age: %d\n", savedAge);
                printf("Phone Number:  %s\n", savedPhone);
                printf("Balance: %lf\n", savedbalance);
}

void addAccount(){
               printf("\nTo add a new account please answer the questions below.\n");
               printf("Your Account Number(*Can be fount in the checkbook*): \n");
               scanf(" %[^\n]", savedAccount);
               printf("Your Name: \n");
               scanf(" %[^\n]", savedName);
               printf("Your Age: \n");
               scanf("%d", &savedAge);
               printf("Your Phone Number: \n");
               scanf(" %s", savedPhone);
               printf("Balance: ");
               scanf("%lf", &savedbalance);
               printf("Your desired PIN: \n");
               scanf(" %s", savedPin);

               accountstat=1;
               printf("Account has been created successfully");
               printf("Please Review:\nAccount Number: %s\nName: %s\nAge: %d\nPhone Number: %s\nYour Current Balance: %.2lf\nPIN: [hidden]\n\n",savedAccount, savedName, savedAge, savedPhone, savedbalance);
            }

            void checkout(){
                 if(!accountstat){
         printf("Sorry, but no account been found! Create one first by adding a account.");
                }

                char enteredPIN[20];
                double ammount;

                printf("\nEnter your PIN before going ahead: \n");
                scanf(" %s", enteredPIN);

                if (strcmp(savedPin,enteredPIN)==0){
                    printf("Enter the amount you want to checkout:\n");

                    scanf(" %lf", &ammount);
                    printf("PIN Correct!, You may go-ahead!\n");
                    if(ammount > savedbalance){
                        printf("Not enough balance!");
                    }
                    else{
                            savedbalance -= ammount;


                    printf("The checkout request was successful & %.2lf$ was checked-out!  Remaining Balance: %.2lf$", ammount,savedbalance);
}
                }
                else {
                    printf("Invalid PIN! Please try again.");
                }
            }

            void humansup(){
                char name[50];
                char phone[15];
                char account[50];

                printf("\nFor human support please answer the below data!\n");
                printf("Name: \n");
                scanf(" %s", name);

                printf("Phone-Number: \n");
                scanf(" %s", phone);

                printf("Account Number: \n");
                scanf(" %s", account);

                printf("Human Support is on it's way!");
            }



            int main(){

                      char choice;

                       while(1){
                       printf("\nTEST BANKING SYSTEM \n");
                       printf("1.See Bank-Balance / Account Info.\n");
                       printf("2.Add An Account.\n");
                       printf("3.Checkout.\n");
                       printf("4.Human-Support.\n");
                       printf("5.Quit Menu.\n");
                       scanf(" %c", &choice);

                      switch (choice)
                      {
                      case '1': showBalance(); break;

                         case '2': addAccount(); break;

                         case '3': checkout(); break;

                         case '4': humansup(); break;

                         case '5': printf("Thanks for using TEST SYSTEM BANKING! Made by 'Sarnab Bhattacharjee'");
                                   printf("System is now offline, if you want to run the system again then just repoen it!");
                                   exit(0);

                      default: printf("\nInvalid Input!!\n"); break;
                      }

                    }

                      return 0;


            }
