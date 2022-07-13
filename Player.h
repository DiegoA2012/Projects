#ifndef __Player_H
#define __Player_H

#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

#define MAX_CHAR_LEN 32
#define MAX_CITY_LEN 64
#define MIN_YEAR 2010
#define MAX_YEAR 2013
#define CURR_YEAR 2022
#define BUFFER_SIZE 1024
#define MAX_TEAM 10

enum _PARENT_TYPE {guard = 0, mother = 1, father = 2, grandmother = 3, grandfather = 4};
enum _PHONE_TYPE{nophone = 0, cell =1, home=2, work=3, };
enum _PARENT_TYPE gtype = guard;
enum _PHONE_TYPE ntype = nophone;

char buffer[BUFFER_SIZE];

struct __Player
{
char* FirstName;
size_t FirstNameLen;
char* lastName;
size_t lastNameLen;
char* GuardFirstName;
size_t GuardFirstNameLen;
char* GuardlastName;
size_t GuardlastNameLen;
int phType;
char* Phone;
size_t PhoneLen;
int gType;
unsigned short int birthYear;
char* addNum;
size_t addNumLen;
char* Street;
size_t StreetLen;
char* city;
size_t cityLen;
};

typedef struct __Player Player;
char const* numType[]={"Cell", "Home","Work"};
char const* guardType[]={"Mother", "Father","Grandma", "Grandpa"};

void getFirstName(Player* p);
void getLastName(Player* p);
void getBirthYear(Player* p);
void getCity(Player* p);
void getGaurdName(Player* p);
void getGaurdLastName(Player* p);
void getParentType(Player* p);
void getPhoneType(Player* p);
void getPhone(Player* p);
void displayRoster(Player* team, int teamSize, FILE* fOut);


void getFirstName(Player* p)
  {

      do{
        printf("What is the players name?");
        scanf(" %[^\n]s", buffer);
        getchar();
        }while(0 != check_string(buffer, MAX_CHAR_LEN));

        size_t AV = strlen(buffer)+1;
        p->FirstName =(char*)malloc(AV * sizeof(char));
        strcpy(p->FirstName, buffer);
        p->FirstNameLen = AV;
        memset(buffer, '\0', BUFFER_SIZE);
  }

void getLastName(Player* p)
  {

      do{
        printf("What is the players last name?");
        scanf(" %[^\n]s", buffer);
        getchar();
        }while(0 != check_string(buffer, MAX_CHAR_LEN));

        size_t AV = strlen(buffer)+1;
        p->lastName =(char*)malloc(AV * sizeof(char));
        strcpy(p->lastName, buffer);
        p->lastNameLen = AV;
        memset(buffer, '\0', BUFFER_SIZE);
  }
  void getGuardName(Player* p)
  {

      do{
        printf("What is the guardian's name?");
        scanf(" %[^\n]s", buffer);
        getchar();
        }while(0 != check_string(buffer, MAX_CHAR_LEN));

        size_t AV = strlen(buffer)+1;
        p->GuardFirstName =(char*)malloc(AV * sizeof(char));
        strcpy(p->GuardFirstName, buffer);
        p->GuardFirstNameLen = AV;
        memset(buffer, '\0', BUFFER_SIZE);
  }

void getGuardLastName(Player* p)
  {

      do{
        printf("What is the guardian's last name?");
        scanf(" %[^\n]s", buffer);
        getchar();
        }while(0 != check_string(buffer, MAX_CHAR_LEN));

        size_t AV = strlen(buffer)+1;
        p->GuardlastName =(char*)malloc(AV * sizeof(char));
        strcpy(p->GuardlastName, buffer);
        p->GuardlastNameLen = AV;
        memset(buffer, '\0', BUFFER_SIZE);
  }

void getCity(Player* p)
{

         do{
        printf("What is the street number?");
        scanf(" %[^\n]s", buffer);
        getchar();
        }while(0 != check_string(buffer, 6));
        size_t A = strlen(buffer)+1;
        p->addNum =(char*)malloc(A * sizeof(char));
        strcpy(p->addNum, buffer);
        p->addNumLen = A;
        memset(buffer, '\0', BUFFER_SIZE);

        do{
        printf("What is the Street Name?");
        scanf(" %[^\n]s", buffer);
        getchar();
        }while(0 != check_string(buffer, MAX_CHAR_LEN));
        size_t SN = strlen(buffer)+1;
        p->Street =(char*)malloc(SN * sizeof(char));
        strcpy(p->Street, buffer);
        p->StreetLen = SN;
        memset(buffer, '\0', BUFFER_SIZE);

        do{
        printf("What is the city of residence?");
        scanf(" %[^\n]s", buffer);
        getchar();
        }while(0 != check_string(buffer, MAX_CHAR_LEN));

        size_t C = strlen(buffer)+1;
        p->city =(char*)malloc(C * sizeof(char));
        strcpy(p->city, buffer);
        p->cityLen = C;
        memset(buffer, '\0', BUFFER_SIZE);

}

void getBirthYear(Player* p)
{
        unsigned short tempVal = 0;
       do{
        printf("What is the Birth Year?: ");
        scanf("%hu", &tempVal);
        getchar();
            if((tempVal < MIN_YEAR)|| (tempVal > MAX_YEAR)){
              printf("Year of Birth Range must be between 2009 & 2013\n");
            }else{
            break;
            }
        }while(1);
        p->birthYear = tempVal;
}

void getPhone(Player* p)
{
    do {
    printf("Enter a phone number (xxx) xxx-xxxx: ");
    scanf(" %[^\n]s", buffer);
    getchar();
    }while(0 != check_string(buffer, 16));

        size_t AV = strlen(buffer)+1;
        p->Phone =(char*)malloc(AV * sizeof(char));
        strcpy(p->Phone, buffer);
        p->PhoneLen = AV;
        memset(buffer, '\0', BUFFER_SIZE);
}

void getPhoneType(Player* p)
{
 int tempVal;
       do{
    ntype = nophone;

    printf("What is the Phone Type? Enter 1-cell, 2-home, 3-work: ");
    scanf("%d", &tempVal);
    getchar();

    if(ntype == nophone && tempVal == 0){
      ntype = nophone;
      printf("Enter valid phone number.\n");
    }else if(tempVal == 1){
        ntype = cell;
      break;
    }else if(tempVal == 2){
        ntype = home;
        break;
    }else if(tempVal == 3){
        ntype = work;
        break;
    }
    }while(1);
        p->phType = ntype-1;
}

void getParentType(Player* p){
    int tempVal2;
do{
    gtype = guard;
    printf("Relationship of Guardian to Player? Enter 1- mother ,2-father, 3-grandmother , 4-grandfather:");
    scanf("%d", &tempVal2);
    getchar();
    if(gtype == guard && tempVal2 == 0){
      gtype = guard;
    printf("Enter valid guardianship.\n");
    }else if(tempVal2 == 1){
        gtype = mother;
      break;
    }else if(tempVal2 == 2){
        gtype = father;
        break;
    }else if(tempVal2 ==3){
        gtype = grandmother;
        break;
    }else if(tempVal2 == 4){
        gtype = grandfather;
        break;
    }
    }while(1);
     p->gType = tempVal2-1;
}
void displayRoster(Player* team, int teamSize, FILE* fOut){
    int index = 0;
    for(;index < teamSize; index++){
    fprintf(fOut, "Player's Name : %s %s\tYear of Birth: %hu\t Address: %s %s, %s\n", team[index].FirstName, team[index].lastName, team[index].birthYear, team[index].addNum,team[index].Street,team[index].city);
    fprintf(fOut, "Guardian's Name : %s %s\tRelation: %s\tPhoneType & Number: %s %s\n",team[index].GuardFirstName, team[index].GuardlastName,guardType[team[index].gType],numType[team[index].phType], team[index].Phone);
    }
}
#endif
