#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 8
#define COLS 8
#define NUM_BARRIERS 3
#define Paste_barriers 3

int color [3] = {1,2,3};

typedef struct {
    int row;
    int col;
} Position;

Position path[ROWS * COLS]; // ???????????????????????????????
Position barriers[NUM_BARRIERS]; // ??????????????????
Position paste[Paste_barriers];
Position target_position; 
int num_path_points = 0;

void addPathPoint(int row, int col) {
    path[num_path_points].row = row;
    path[num_path_points].col = col;
    num_path_points++;
}

int isBarrier(int row, int col) {
    for (int i = 0; i < NUM_BARRIERS; i++) {
        if (barriers[i].row == row && barriers[i].col == col) {
            return 1; // ????????????
        }
    }
    return 0; // ???????????????
}

void printPath() {
    printf("Path: ");
    for (int i = 0; i < num_path_points; i++) {
        printf("(%d,%d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

void Run_Paste () {
	if () {
		
	}
}


int main(int argc, char *argv[]) {
	// ???????????????????????
    barriers[0].row = 2;
    barriers[0].col = 3;
    barriers[1].row = 4;
    barriers[1].col = 4;
    barriers[2].row = 5;
    barriers[2].col = 2;
    
    // Green
    paste[0].row = 0;
    paste[0].col = 3;
	// Red
	paste[1].row = 3;
	paste[1].col = 0;
	//Blue
	paste[2].row = 7;
	paste[2].col = 3;

    // ??????????????????????
    int path_rows[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int path_cols[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int num_path_points = sizeof(path_rows) / sizeof(path_rows[0]);

    // ??????????????????????????????????
    for (int i = 0; i < num_path_points; i++) {
        for (int j = 0 ; j < num_path_points ; j++) {
            int row = path_rows[i];
            int col = path_cols[j];
            if (!isBarrier(row, col)) {
                addPathPoint(row, col);
            } else {
                printf("Encountered a barrier at (%d,%d)\n", row, col);
                Position current_position; 
			    current_position.row = row;  
			    current_position.col = col;
			    //int num = (rand() % 3) + 1; // use rand() function to get the random number 
			    int num = 2;
			    printf ("color of barrier %d \n", num);
				if (color[0] == num) {	
					target_position.row = paste[0].row;  
			    	target_position.col = paste[0].col; 
				}
				if (color[1] == num) {
					target_position.row = paste[1].row;  
			    	target_position.col = paste[1].col; 
				}
				if (color[2] == num) {
					target_position.row = paste[2].row;  
			    	target_position.col = paste[2].col; 
				}
				printf("target at (%d,%d)\n", target_position.row, target_position.col);
				
			  
			    double distance = sqrt(pow(target_position.row - current_position.row, 2) + pow(target_position.col - current_position.col, 2));
			    printf("cal_short_path: %.2f \n\n", distance);
            
                
                break;
            }
        }
    }

    printPath();
    
    return 0;
}
