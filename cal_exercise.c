//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file, "%s %d", exercise_list[exercise_list_size].exercise_name, 
                  &exercise_list[exercise_list_size].calories_burned_per_minute) == 2 ) // if user enter 2 >> read exercise list 
		{exercise_list_size++;
		if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    char exercise_name[MAX_EXERCISE_NAME_LEN];
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    	for (i = 0; i < exercise_list_size; i++) {
       		printf("%s - %d kcal/min\n",  exercise_list[i].exercise_name, 
                                         exercise_list[i].calories_burned_per_minute); // list of exercises print.
    }
    printf("Type 'exit' to cancel.\n");												   // if user type 'exit' exit.


    // ToCode: to enter the exercise to be chosen with exit option

 	do{
 		printf("Type the exercise name: ");
 		scanf("%s", exercise_name);
 		
 		choice=0;
 		for (i = 0; i < exercise_list_size; i++) {
            if (strcmp(exercise_list[i].exercise_name, exercise_name) == 0) { // strcmp function >> typed string <> list string compare
                choice = 1; 												  // if typed string == list string, choice =1 
                break;
            }
        }
 		if (strcmp(exercise_name, "exit") == 0) {                             // if user type exit, return.
            printf("Exiting exercise selection.\n");
            return;
		}
		if (!choice) {
            printf("Invalid exercise name. Please try again.\n");            // if differnt name typed print
			}  
	} while (!choice);                                                        // while typed string =! list string 
    
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);


    // ToCode: to enter the selected exercise and total calcories burned in the health data
    int calories_burned = exercise_list[i].calories_burned_per_minute * duration;  		// calories Calculate
    printf("You burned %d kcal by doing %s for %d minutes.\n", calories_burned, exercise_list[i].exercise_name, duration);


    health_data->exercises[health_data->exercise_count] = exercise_list[i];      		// data stored
    health_data->total_calories_burned += calories_burned;
    health_data->exercise_count++;

}
