#include <strings.h>
#include <ctype.h>

#include "Player.h"
#include "Util.h"

#define ROSTER_FILE "roster.txt"

int main(int argc, char** arv) {
int count = 0;
Player roster[MAX_TEAM];

    do{
        getFirstName(&roster[count]);
        getLastName(&roster[count]);
        getBirthYear(&roster[count]);
        getCity(&roster[count]);
        getGuardName(&roster[count]);
        getGuardLastName(&roster[count]);
        getParentType(&roster[count]);
        getPhoneType(&roster[count]);
        getPhone(&roster[count]);

        count++;

        do{
            printf("Would you like to continue adding players to your roster? (Y or N): ");
            scanf("%[^\n]s", buffer);
            getchar();
                if(toupper(buffer[0]) == 'Y' || toupper(buffer[0]) == 'N'){
                    break;
                } else {
                printf("Only Accepting Y or N\n");
                }
            }while(1);
        }while(toupper(buffer[0])=='Y');

    displayRoster(roster, count, stdout);

    do {
        printf("Would you like to save the roster?(y or n): ");
        scanf("%s", buffer);
        if(toupper(buffer[0]) == 'Y' || toupper(buffer[0]) == 'N'){
                    break;
                } else {
                printf("Only Accepting Y or N\n");
                }
            }while(1);

        if(toupper(buffer[0])=='Y'){
            FILE* teamlist = fopen(ROSTER_FILE, "w");
            if(teamlist != NULL){
                displayRoster(roster, count, teamlist);
                fclose(teamlist);
            }else{
                printf("Error Failed to open file.");
            }
        }

        memset(buffer, '\0', BUFFER_SIZE);
        return 0;
    }

