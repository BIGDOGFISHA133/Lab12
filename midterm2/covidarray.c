#include <stdio.h>
#include <string.h>
#include <time.h>

struct user  
{  
 char firstname[20];       // This struct contains firstname, lastname, birthdate, sex,
 char lastname[20];        // dosage number(dnumber), previous dose date (pdd, pmm, pyy),
 int dd,mm,yy;             // the vaccine type, and their zip
 char sex[6];
 int pdd,pmm,pyy;
 int dnumber;
 char vaccinetype[15];
 char zip[5];
};  

int getage(int pdate, int pmonth, int pyear, int bdate, int bmonth, int byear) // Pdate is for previous dose, Bdate is for today'sdate
{                                                                               // final_date, month, and year will be used to calculate age
 int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 if (bdate > pdate) 
  {
  pdate = pdate + month[bmonth - 1];
  pmonth = pmonth - 1;
  }
 if (bmonth > pmonth) 
 {
  pyear = pyear - 1;
  pmonth = pmonth + 12;
 }
 int final_date = pdate - bdate;
 int final_month = pmonth - bmonth;
 int final_year = pyear - byear;
 return final_year;
}

int main(void) 
{
  struct user user[10];
  int choice;                                       // I will be using this to determine gender/vaccine type
  char id[8];                                       // ID
  char age[2];                                      // age
  int i;                                            // counter variable
  for(i = 0;i<10;i++)
  {
   printf("Enter detail for person number %d:\n",i+1);      // I wouldn't have been able to finish coding if I made different methods,
   printf("Enter First Name: ");                      // so I brute forced all the printf statements for now
   scanf("%s", user[i].firstname);
   printf("Enter Last Name: ");                       // This part of the code is just the simple entries, like name and DOB
   scanf("%s", user[i].lastname);
   printf("Enter Birth Date(mm/dd/yyyy): ");
   scanf("%d/%d/%d",&user[i].dd,&user[i].mm,&user[i].yy);
   printf("Enter Zip: ");
   scanf("%s", user[i].zip);

   printf("Enter Dose Number (1 or 2): ");                                 // This is for the dosage number
   scanf("%d", &user[i].dnumber);
   if(!(user[i].dnumber == 1 || user[i].dnumber == 2))
   {
    printf("Please enter valid dose number.\n");
    return 1;
   }
   if(user[i].dnumber == 2)
   {
     printf("Enter Previous Dose Date(mm/dd/yyyy) : ");             // Is previous dose was administered
     scanf("%d/%d/%d",&user[i].pdd,&user[i].pmm,&user[i].pyy);  
   }
   printf("Choose sex by entering 1, 2, or 3: \n1. Male\n2. Female\n3. Other\n");      // This is to determine gender, using 1, 2, or 3 as shortcuts for 
   scanf("%d", &choice);                                                               // male, female, and other respectively
   if (choice == 1)
       strcpy(user[i].sex, "Male");
   else if (choice == 2)
       strcpy(user[i].sex, "Female");
   else
       strcpy(user[i].sex, "Other");

   printf("Choose the vaccine by entering 1, 2, or 3: \n1. Pfizer\n2. Moderna\n3. Johnson&Johnson\n");
    scanf("%d", &choice);
   if(choice == 1)
     strcpy(user[i].vaccinetype, "Pfizer");
   else if(choice == 2)
     strcpy(user[i].vaccinetype, "Moderna");
   else if(choice == 3)
     strcpy(user[i].vaccinetype, "Johnson&Johnson");
   else
   {
    printf("Please choose valid vaccine.\n");
    return 1;
    }

   
   time_t t = time(NULL);                                          // Create time for today's date
   struct tm today = *localtime(&t);
   int age = getage( today.tm_mday,today.tm_mon + 1,today.tm_year + 1900,user[i].dd,user[i].mm,user[i].yy);

   id[0] = user[i].firstname[0];                           // This is what creates the ID of the person
   id[1] = user[i].lastname[0];
   id[2] = (char)(age/10+ '0');
   id[3] = (char)(age%10+ '0');
   id[4] = user[i].vaccinetype[0];
   id[5] = user[i].zip[3];
   id[6] = user[i].zip[4];
   id[7] = user[i].zip[5];

   printf("\nFirst Name: %s\n",user[i].firstname);         // Printf statements to make sure everything printed correctly
   printf("Last Name: %s\n",user[i].lastname);
   printf("Birthdate: %d/%d/%d\n",user[i].mm,user[i].dd,user[i].yy);
   printf("Sex: %s\n",user[i].sex);
   printf("Dose: %d\n",user[i].dnumber);
   if(user[i].dnumber == 2)
   {
    printf("Previous Dose Date : %d/%d/%d\n",user[i].pmm,user[i].pdd,user[i].pyy);
    }
   printf("Vaccine: %s\n",user[i].vaccinetype);
   printf("Zip: %s\n",user[i].zip);
   printf("Code: %s\n\n",id);
  }
  return 0;
}