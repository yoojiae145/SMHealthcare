//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", diet_list[diet_list_size].food_name, 
                  &diet_list[diet_list_size].calories_intake) == 2 ) {
    	diet_list_size++;
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    char food_name[MAX_FOOD_NAME_LEN];
    
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    	for (i = 0; i < diet_list_size; i++) {
        	printf("%s - %d kcal\n", diet_list[i].food_name, diet_list[i].calories_intake);		// Print diet's name and calories
    	}	
    		printf("Type 'exit' to cancel.\n");													// exit if typing 'exit'

    
	// ToCode: to enter the diet to be chosen with exit option
    do {
        printf("Type the food name: ");
        scanf("%s", food_name);																	// user entered food name

        choice = 0;
        for (i = 0; i < diet_list_size; i++) {
            if (strcmp(diet_list[i].food_name, food_name) == 0) {
                choice = 1; 																	// if choice Match
                break;
            }
        }

        if (strcmp(food_name, "exit") == 0) {
            printf("Exit.\n");
            return;																				// exit 
        }
        if (!choice) {
            printf("try again.\n");																// if not exist name entered
        }
    } while (!choice);

    // ToCode: to enter the selected diet in the health data
    printf("You selected: %s (%d kcal)\n", diet_list[i].food_name, diet_list[i].calories_intake);

    	health_data->diet[health_data->diet_count] = diet_list[i]; 								// selected diet save
    	health_data->diet_count++; 																// diet count 

    // ToCode: to enter the total calories intake in the health data
 		health_data->total_calories_intake += diet_list[i].calories_intake; 					// total calories update
    
	printf("Total calories intake updated to: %d kcal\n", health_data->total_calories_intake);


}

