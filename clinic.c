/*
===================================================================================================
 * Auther : Omar Tarek Ibrahim 
 * Object : Clinic mangement system
 * date : 28/8/2023
 * clinic.c
===================================================================================================
 */

#include "StdTypes.h"
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern node *head  ;
extern node *current  ;
extern node *prev  ;
extern u32 ListLength,Size,ID,time,i;
u32 arr[5]={-1,-1,-1,-1,-1};

node* new_node()
{
	node* temp=(node*)malloc(sizeof(node));
	return temp;
}

//add patient function
void Add_patient(u8 name[],u32 age,u8 gender[], u32 id)
{
    node *link = (node *)malloc(sizeof(node));
    u32 pos = 0;
    current = head;

    while(current != NULL)
    {
        if (current->id == id)
        {
            printf("This ID Is Already Exist\n");
            return;
        }
        current = current -> next;
        pos++;
    }

   strcpy(link->name,name);
   link->age = age;
   strcpy(link->gender,gender);
   link->id = id;
   link->next = NULL;
   printf("      ***the patient is added successfully*** \n\n");
      current = head;
    if(head==NULL)
   {
      head = link;
      return;
   }
   while(current->next != NULL)
   {
	   current = current->next;

   }
   current->next = link;
    Size++;

}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// edit list function
void Edit_List(u32 id)
{
    u8 x = 0;
    current=head;
    while(current != NULL && x==0)
   {  
      if(current->id == id)
      {
		printf("Enter your new name: ");
		scanf(" %[^\n]%*c",current->name);
		printf("Enter your new age: ");
		scanf("%d",&current->age);
		printf("Enter your new gender: ");
		scanf(" %[^\n]%*c",current->gender);
		printf("Enter your new ID: ");
		scanf("%d",&current->id);
		x=1;
      }
	  current=current->next;
   }
   
   if (x == 1)
   {
	   printf("   ***the patient record is edited successfully***\n");
	   return;
   }

   if (x == 0)
	{
		printf("this patient is not registered\n");
	}

	return;
}


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// time reservation
void Time_Reservation()
{    
    	u8 x = 0;
        printf("there are the available slots : \n");
     for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0]!=-1)
			           {
			             break;
			           }
                     else
                       {
                         printf("-> From 2pm to 2:30pm available, to reserve this slot please press 1\n");
                       }
                         break;
			case 1 : if(arr[1]!=-1)
			          {
                        break;
			          }
                      else
                      {
                       printf("-> From 2:30pm to 3pm available, to reserve this slot please press 2\n");
                      }
                       break;
			case 2 : if(arr[2]!=-1)
			          {
			            break;
			          }
                      else
                      {
                        printf("-> From 3:30pm to 4pm available, to reserve this slot please press 3\n");
                      }
                        break;
			case 3 : if(arr[3]!=-1)
			         {
			            break;
			         }
                    else
                    {
                        printf("-> From 4pm to 4:30pm available, to reserve this slot please press 4\n");
                    }
                       break;
			case 4 : if(arr[4]!=-1)
			         {
			             break;
			         }
                     else
                     {
                         printf("-> From 4:30pm to 5pm available, to reserve this slot please press 5\n");
                      }
                        break;
		}
	} 
	printf("***if you need to reserve a slot you must have an ID\n");
	
    printf("Please, Enter your ID: ");
	scanf("%d",&ID);
	
	printf("Enter your choice : ");
	scanf("%d" , &time);

	for(i=0;i<5;i++)
	{
			if(arr[i]==ID)
			{
				arr[i]=-1;
			}
    }

   current = head;
   while(current != NULL)
   {
      if(current->id == ID)
      {
        arr[time-1]=ID;
		x = 1;
      }
      current = current->next;
   } 
   
   if (x == 1)
   {
	   printf("  ***the slot is reserved successfully***\n");
	   printf("     ***hope you will be fine soon***\n");
	   return;
   }
    
   if (x == 0)
	  {
	     printf("xxxxx This ID is not exist, please sign up first xxxxx\n");
	  }
		return;

}


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// cancel reservation function
void Cancel_Res(u32 ID)
{
	u8 x=0;
	for(i=0;i<5;i++)
	{
			if(arr[i]==ID)
			{
				arr[i]=-1;
				x=1;
			}
    } 
	
	if (x==1)
	{
		printf("  ***the reservation is cancelled successfully***\n");
	}
 
	if(x==0)
	{
		printf("Wrong ID\n");
		return;
	}
	return;
}


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// print list
void Print_List(u32 id)
{
    u8 x=0;
    current = head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("-> Name: ");
            printf(current->name);
	        printf("\n");
            printf("-> Age: %d\n",current->age);
            printf("-> Gender: ");
            printf(current->gender);
	        printf("\n");
            printf("-> ID: %d\n",current->id);
			patient_res (current->id);
			
	     x=1;
        }
        current = current->next;
    }

    if (x == 0)
    {
		printf("xxxxx his patient is not registered xxxxx\n");
	}
	return;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// print reservations
void Print_Res()
{
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0]==-1)
			          {
			            break;
			          }
                      else
                      {
                          printf("From 2pm to 2:30pm is reserved by the ID Num: %d\n",arr[0]);
                      }
                        break;
			case 1 : if(arr[1]==-1)
		          	  {
			           break;
			          }
                      else
                      {
                          printf("From 2:30pm to 3pm is reserved by the ID Num: %d\n",arr[1]);
                      }
                       break;
			case 2 : if(arr[2]==-1)
			            {
			                break;
			            }
						else
                        {
                            printf("From 3:30pm to 4pm is reserved by the ID Num: %d\n",arr[2]);
                        }
                        break;
			case 3 : if(arr[3]==-1)
			             {
			                 break;
                          }
						else
                        {
                            printf("From 4pm to 4:30pm is reserved by the ID Num: %d\n",arr[3]);
                         }
                            break;
			case 4 : if(arr[4]==-1)
			            {
			                break;
			            }
						else
						{
						    printf("From 4:30pm to 5pm is reserved by the ID Num: %d\n",arr[4]);
                        }
						 break;
		}
	}
}

void patient_res (u32 id)
{   
    u8 x = 0;
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0] != id)
			          {
			            break;
			          }
                      else
                      {
                          printf("-> this patient reserved a slot From 2pm to 2:30pm\n");
						  x = 1;
                      }
                        break;
			case 1 : if(arr[1] != id)
		          	  {
			           break;
			          }
                      else
                      {
                          printf("-> this patient reserved a slot From 2:30pm to 3pm\n");
						  x = 1;
                      }
                       break;
			case 2 : if(arr[2] != id)
			            {
			                break;
			            }
						else
                        {
                          printf("-> this patient reserved a slot From 3:30pm to 4pm\n"); 
                          x = 1;
						  }
                        break;
			case 3 : if(arr[3] != id)
			             {
			                 break;
                          }
						else
                        {
                            printf("-> this patient reserved a slot From 4pm to 4:30pm\n");
							x = 1;
                         }
                            break;
			case 4 : if(arr[4] != id)
			            {
			                break;
			            }
						else
						{
						    printf("-> this patient reserved a slot From 4:30pm to 5pm\n");
							x = 1;
                        }
						 break;
		}
	} 
	
	if (x == 0)
	{
		printf("-> this patient did not reserve any slots\n");
	}
}




