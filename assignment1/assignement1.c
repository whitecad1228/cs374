#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct movie
{
    char *title;
    int year;
    char *languages;
    double rating;
    struct movie *next;
};

int printMovie(struct movie *tm){

    printf("title: %s, Year: %i, languages: %s, rating %lf \n",tm->title,tm->year,tm->languages,tm->rating);
}

struct movie *createMovie(char *myString){
    struct movie *tempNode = malloc(sizeof(struct movie));
    char *saveptr;
    printf("%s", myString);
    // title
    char *token = strtok_r(myString, ",", &saveptr);
    tempNode->title = calloc(strlen(token)+1,sizeof(char));
    strcpy(tempNode->title,token);
    // year
    token = strtok_r(NULL, ",", &saveptr);
    tempNode->year = atoi(token);
    // languages
    token = strtok_r(NULL, ",", &saveptr);
    // memcpy(tempNode->languages,token,sizeof(array));
    tempNode->languages = calloc(strlen(token)+1,sizeof(char));
    strcpy(tempNode->languages,token);

    // rating
    char *blankPtr;
    token = strtok_r(NULL, ",", &saveptr);
    tempNode->rating = strtod(token, &blankPtr);

    return tempNode;
}

int showYear(int year, struct movie *head, struct movie *tail){
    struct movie *tempNode = head;
    while(tempNode != tail){
        if(tempNode->year == year){
            printMovie(tempNode);
        }
        tempNode = tempNode->next;
    }
    if(tempNode->year == year){
            printMovie(tempNode);
    }
    return 0;
}

int highestRatedPerYear(){

}

int moviesInLanguage(char language, struct movie *head, struct movie *tail){
    struct movie *tempNode = head;
    while(tempNode != tail){
        if(strstr(language,tempNode->languages)){
            printMovie(tempNode);
        }
        tempNode = tempNode->next;
    }
    

}

int main(){
    // opening file and adding basic vars
    FILE *fptr;
    fptr = fopen("movies_sample_1.csv", "r");
    char myString[100];
    struct movie *head = NULL;
    struct movie *tail = NULL;

    // creating movie list
    fgets(myString, 100, fptr);
    while(fgets(myString, 100, fptr)) {

        struct movie *tempNode = createMovie(myString);
        if (head == NULL){
            head = tempNode;
            tail = tempNode;
        }else{
            tail->next = tempNode;
            tail = tempNode;
        }

    }
    fclose(fptr);

    // testing
    // printf(" \n");
    // struct movie *tempNode = head;
    // while(tempNode != tail){
    //     printMovie(tempNode);
    //     tempNode = tempNode->next;
    // }
    // printMovie(tempNode);

    // printMovie(tail);

    // char array[5][10] = {"english","spanish","german"};

    // for(int i = 0; i < 5; i ++){
    //     printf("%s \n", array[i]);
    // }


    // main loop
    int myNum;
    printf("1. Show movies released in the specified year\n");
    printf("2. Show highest rated movie for each year\n");
    printf("3. Show the title and year of release of all movies in a specific language\n");
    printf("4. Exit from the program\n");
    scanf("%d", &myNum);

    while (myNum != 4){
        // checks for response
        if(myNum == 1){
            // gets the year entered for that movie
            int year;
            printf("%d \n", myNum);
            printf("Enter the year for which you want to see movies: ");
            scanf("%d", &year);
            showYear(year,head,tail);

        }else if(myNum == 2){
            // returns the highest rated movie for each year
            printf("%d \n", myNum);

            struct movie *tempNode = head;

            struct movie movieRatings[15] = {{0}};
            printMovie(head);

            printf("%d \n", movieRatings[0].title == NULL);
            printf("%d \n", movieRatings[0].title == " ");
            printf("%d \n", movieRatings[0].rating < head->rating);
            printf("%s \n", movieRatings[0].title);

            while(tempNode != tail){
                for(int i =0; i < 15; i++){
                    if(movieRatings[i].title == NULL){
                        movieRatings[i] = *tempNode;
                        break;
                        // printMovie(tempNode);
                    }else if(movieRatings[i].year == tempNode->year){
                        if(movieRatings[i].rating < tempNode->rating){
                            // printMovie(tempNode);
                            movieRatings[i] = *tempNode;
                        }else{
                            break;
                        }
                    }
                }
                tempNode = tempNode->next;
            }
            for(int i = 0; i <15; i++){
                printMovie(&movieRatings[i]);
            }

        }else{
            // returns all the movies with that language
            printf("%d \n", myNum);
            char language[30];
            printf("Enter the language for which you want to see movies:");
            scanf("%s",&language);
            printf("%s \n",language );
            struct movie *tempNode = head;
            while(tempNode != tail){
                if(strstr(tempNode->languages,language)){
                    printMovie(tempNode);
                }
                tempNode = tempNode->next;
            }
        }

        // will then re-ask prompts.
        printf("1. Show movies released in the specified year\n");
        printf("2. Show highest rated movie for each year\n");
        printf("3. Show the title and year of release of all movies in a specific language\n");
        printf("4. Exit from the program\n");
        scanf("%d", &myNum);

    }

    return 0;
}

