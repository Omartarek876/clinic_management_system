/*
===================================================================================================
 * Auther : Omar Tarek Ibrahim 
 * Object : Clinic mangement system
 * date : 26/8/2023
 * main.c
===================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "StdTypes.h"
#include "header.h"

node *head = NULL ;
node *current = NULL;
node *prev = NULL;

u32 ListLength = 0,Size=0,ID,time,i;
u8 name[100];
u8 gender[10];
u32 pat_age,pat_id,id;


void main (void)
{
    u8 flag = 0 , exit_f = 1;
    u32 pass , input , userinput , mode ,newValue,Node_Value,position;

    while(exit_f)
    {   
        printf("**************************************************\n");
        printf("      ********welcome to life clinic********\n");
		printf("**************************************************\n");
	    printf("-> to enter admin mode enter number 1 \n");
	    printf("-> to enter user mode enter number 2 \n");
		printf("-> to exit the program enter number 0 \n");
	    printf("your choice : ");
	    scanf("%d" , &mode);

	    if(mode == 1)
        { 
	      printf("**************************************************\n");
          printf("      **************admin mode**************\n");
		  printf("**************************************************\n");
		  printf("please, enter the password : ");
		  for(i = 0; i < 3; i++)
          {
		     scanf("%d" , &pass);
		     if (pass == 1234)
             {
                printf("**************************************************\n");
                printf("      ***************welcome****************\n");
		        printf("**************************************************\n");
				flag = 1;
				break;
             }
              if (i < 2)
             {
                 printf("wrong password !\n");
                 printf("enter the password again : ");
             }
		  }
		  if (flag == 1)
          {
				  printf("-> to add new patient enter 1 \n");
				 // printf("-> to display the patient file enter 2 \n");
				  printf("-> to edit the patient record enter 2 \n");
				  printf("-> to reserve a slot with the doctor enter 3\n");
				  printf("-> to cancel a reservation enter 4 \n");
				  printf("-> to exit the program enter number 0 \n");
				  printf("your choice : ");
				  scanf("%d" , &input);

				  switch(input)
				  {
                      case 1 :
                              printf("Please Enter the patient's name: ");
			                  scanf(" %[^\n]%*c",name);
					          printf("Please Enter the patient's age: ");
			                  scanf("%d",&pat_age);
					          printf("Please Enter the patient's gender (male or female): ");
			                  scanf(" %[^\n]%*c",gender);
                              printf("Please Enter the patient's id: ");
			                  scanf("%d",&pat_id);
					          Add_patient(name,pat_age,gender,pat_id);
                              break;

                      case 2 :
                              printf("Enter the patient ID: ");
					          scanf("%d",&id);
					          Edit_List(id);
                              break;

                      case 3 :
                              Time_Reservation();
					          break;

                      case 4 :
                             printf("Enter Your ID: ");
					         scanf("%d",&id);
                             Cancel_Res(id);
                             break;
					  case 0 :
					         exit_f = 0;
		                     printf("**************************************************\n");
                             printf("      *************** Good Bye ****************\n");
		                     printf("**************************************************\n");
							 break;
                      default :
                           printf("xxxxx Invalid Choice please try again xxxxx\n");
                           break;


				  }
          }
          else if (flag == 0)
          {
           printf("xxxxx Incorrect password for 3 consecutive times xxxxx\n");
           exit_f = 0;
          }
        }


        else if (mode == 2)
        {
             printf("**************************************************\n");
             printf("      **************user mode**************\n");
			 printf("      ***************welcome***************\n");
		     printf("**************************************************\n");
             printf("-> to dispaly paitent file enter 1 \n");
			 printf("-> to view today reservations enter 2 \n");
			 printf("-> to exit the program enter number 0 \n");
			 printf("your choice : ");
			 scanf("%d" , &mode);
			 switch(mode)
			 {
				 case 1 :
				          printf("please, Enter patient ID : " );
				          scanf("%d" , &id);
                          printf("      ********** Patient Record **********\n");
						  printf("                ****************\n");

					      Print_List(id);
				          break;

				 case 2 :
				          printf("      ********** Today Reservations **********\n");
						  printf("                ********************\n");
					      Print_Res();
				          break;
						  
                 case 0 :
					      exit_f = 0;
		                  printf("**************************************************\n");
                          printf("      *************** Good Bye ****************\n");
		                  printf("**************************************************\n");
						  break;
						  
				 default :
                         printf("Invalid Choice please try again\n");
                         break;
			 }

        }
        else if (mode == 0)
        {
           exit_f = 0;
		   printf("**************************************************\n");
           printf("      *************** Good Bye ****************\n");
		   printf("**************************************************\n");
        }
        else
        {
            printf("wrong entry\n");
        }
    }
}
