#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct movie
{
    char *title;
    int year;
    char *languages[5][12];
    double rating;
    struct movie *next;
};

int printMovie(struct movie *tm){

    printf("title: %s, Year: %i, languages: %s, rating %lf \n",tm->title,tm->year,tm->languages,tm->rating);
}

int createArray(char *text, char arrayString[5][12]){

    printf("testing1: \n");
    for (int i = 0; i < 5; i++){
        memcpy()
        printf("%s \n",arrayString[i]);
    }

    // arrayString = malloc(60*sizeof(char));
    // char arrayString[5][12];
    int j = 0;
    int k = 0;
    for(int i = 0; i < strlen(text) ;i++){
        if(text[i] != '['){
            if(text[i] != ';' && text[i] != ']'){
                arrayString[k][j] = text[i];
                j++;
            }else{
                k++;
                j = 0;
            }
        }
    }

    printf("testing2: \n");
    for (int i = 0; i < 5; i++){
        printf("%s \n",arrayString[i]);
    }

    return 0;
    // printf("%p", &arrayString);
    // return &arrayString;
}

// int printArray(char array[]){
//     for (int i = 0; i < sizeof(array); i++){
//         printf("%s \n",array[i]);
//     }
//     return 0;
// }

struct movie *createMovie(char *myString){
    // struct movie *tempNode;
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

    char array[5][12];
    // char array = (char**) malloc(60*sizeof(char));
    createArray(token, array);
    // createArray(token, tempNode->languages);

    // memcpy(tempNode->languages,array,sizeof(array));
    // tempNode->languages = calloc(strlen(token)+1,sizeof(char));
    // strcpy(tempNode->languages,token);

    // rating
    char *blankPtr;
    token = strtok_r(NULL, ",", &saveptr);
    tempNode->rating = strtod(token, &blankPtr);

    // printMovie(tempNode);
    return tempNode;
}

int showYear(int year, struct movie *head, struct movie *tail){
    struct movie *tempNode = head;
    while(tempNode != tail){
        // printMovie(tempNode);
        if(tempNode->year == year){
            printMovie(tempNode);
        }
        tempNode = tempNode->next;
    }
    // printMovie(tempNode);
    if(tempNode->year == year){
            printMovie(tempNode);
    }
    return 0;
}

int highestRatedPerYear(){

}

int moviesInLanguage(){

}

int main(){
    FILE *fptr;
    // Open a file in read mode
    fptr = fopen("movies_sample_1.csv", "r");
    // Store the content of the file
    char myString[100];
    // The head of the linked list
    struct movie *head = NULL;
    // The tail of the linked list
    struct movie *tail = NULL;

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

    // testing
    fclose(fptr);
    printf(" \n");
    struct movie *tempNode = head;
    while(tempNode != tail){
        printMovie(tempNode);
        tempNode = tempNode->next;
    }
    printMovie(tempNode);

    printMovie(tail);

    char array[5][10] = {"english","spanish","german"};

    for(int i = 0; i < 5; i ++){
        printf("%s \n", array[i]);
    }


    // main loop
    int myNum;
    printf("1. Show movies released in the specified year\n");
    printf("2. Show highest rated movie for each year\n");
    printf("3. Show the title and year of release of all movies in a specific language\n");
    printf("4. Exit from the program\n");
    scanf("%d", &myNum);

    while (myNum != 4){
        if(myNum == 1){
            int year;
            printf("%d \n", myNum);
            printf("Enter the year for which you want to see movies: ");
            scanf("%d", &year);
            showYear(year,head,tail);

        }else if(myNum == 2){
            printf("%d \n", myNum);

        }else{
            printf("%d \n", myNum);
            char language[30];
            printf("Enter the language for which you want to see movies:");
            scanf("%s",&language);
            moviesInLanguage(language,head,tail);
        }

        printf("1. Show movies released in the specified year\n");
        printf("2. Show highest rated movie for each year\n");
        printf("3. Show the title and year of release of all movies in a specific language\n");
        printf("4. Exit from the program\n");
        scanf("%d", &myNum);

    }

    return 0;
}

