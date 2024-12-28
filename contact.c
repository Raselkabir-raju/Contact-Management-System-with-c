#include<stdio.h>

struct Contact{
   char name[50];
   char phone[50];
   char email[50];

};

void addContact()
{
 FILE *file;

   file = fopen("contact.txt","a");
   if(file==NULL)
   {
    printf("File does not exist");
   }
   else
   {
    
    struct Contact contact;


   printf("Enter Name: ");
   fgets(contact.name,sizeof contact.name,stdin);

   printf("Enter Phone: ");
   fgets(contact.phone,sizeof contact.phone,stdin);

   printf("Enter Email: ");
   fgets(contact.email,sizeof contact.email,stdin);

   //write to the file

   fprintf(file,"%s%s%s",contact.name,contact.phone,contact.email);

   printf("Added to Contact Management System\n");
   }
    fclose(file);
}

void displayContacts()
{

    struct Contact contact;

 FILE *file;

   file = fopen("contact.txt","r");
   if(file==NULL)
   {
    printf("File does not exist");
   }
   else
   {
    
    printf("Contacts.\n");

   while( fscanf(file, " %[^\n] %[^\n] %[^\n]",contact.name,contact.phone,contact.email)!=EOF)

     {
        printf("Name: %s\n Phone: %s\n Email: %s\n\n",contact.name,contact.phone,contact.email);
     }
 }
    fclose(file);
}

int main()
{
        //addContact();

       // displayContacts();

       int choice;
       do{
            printf("\nContact Management System\n");

            printf("1. Add Contact\n");
            printf("2. Display Contacts\n");
            printf("3. Exit\n");

            printf("Enter Your Choice:");
            scanf("%d",&choice);

            fflush(stdin);

            switch(choice){
                case 1:
                addContact();
                break;

                case 2:
                displayContacts();
                break;

                case 3:
                printf("Exiting.....\n");
                break;

                default:
                printf("Invalid Choice Please try again.\n");
                break;
            }
       }

       while(choice!=3);


}