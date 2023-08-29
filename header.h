/*
===================================================================================================
 * Auther : Omar Tarek Ibrahim 
 * Object : Clinic mangement system
 * date : 28/8/2023
 * header.h
===================================================================================================
 */
typedef struct node_type node;

struct node_type 
{
	u8 name[100];
	u8 age;
	u8 gender[10];
	u32 id;
	node * next;
};


void Add_patient(u8 name[],u32 age,u8 gender[], u32 id);
void Edit_List(u32 id);
void DeleteNode(u32 data);
void Time_Reservation() ;
void Cancel_Res(u32 ID);
void Print_List(u32 id);
void Print_Res();
void patient_res (u32 id);
