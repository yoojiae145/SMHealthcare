//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadExercises(EXERCISEFILEPATH);
    loadDiets(DIETFILEPATH);
	
    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do { 
    	int calories_remain= health_data.total_calories_intake - health_data.total_calories_burned - BASAL_METABOLIC_RATE;		 //remain calories cal.
    	
    	if (calories_remain==0 ){
            printf("You have consumed all your calories for today! \n");
            break; 																												// Exit the loop
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:															// choice 1-> exercise 
            	inputExercise(&health_data);								// get exercise data
                saveData(HEALTHFILEPATH, &health_data);						// Save data in the file
                break;
                
            case 2:															// choice 2-> diet 
            	inputDiet(&health_data);									// get diet data
                saveData(HEALTHFILEPATH, &health_data);						// Save data in the file
                break;
                
            case 3:															// choice 3-> information
            	printHealthData(&health_data);								
                break;
                
            case 4:															// choice 4-> exit
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
            	break;
        }
    } while (choice != 4); 												// if  user's choice 4 program exit 

    return 0;
}

