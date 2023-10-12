/******************************************************************************

Austin Kinnear
Chapter 9 REVIEW Programming Assignment
10/04/2023 & 10/05/2023

*******************************************************************************/
#include <iostream>
using namespace std;

const int MATRIX_SIZE = 4; //Size of Matrix constant declared 

void displayMatrix(int *point); // each of the four required function prototypes
void findInt(int *point, int value); //finds the integer given
void swapColumns(int *point); //swaps the columns
void displayMenu(); 
void functionExitCode();

int main()
{
    int matrix[16] = { //changed from 2D to 1D with 16 elements as instructed on assignment page
        1, 3, 5, 7,
        9, 11, 13, 15,
        17, 19, 21, 23,
        25, 27, 29, 31
    };
 //removed {} changing the matrix from 2D to 1D
    
    int *point; //declaring the pointer as seen in assignemnt page
    point = matrix; //pointing to matrix array, done for similarity to notes rather than combining as int *point = matrix
    int choice = 0;
    
    do{
        displayMenu();
        cin >> choice;
        
        switch(choice){
        case 1: //displays matrix 
            cout << "Here is your array:\n";
            displayMatrix(point);
            break;
            
        case 2: //locates integer
            cout << "Enter an integer to locate: ";
            int value;
            cin >> value;
            findInt(point, value);
            break;
            
        case 3: //swaps columns 1 & 3, used sample output for text
            swapColumns(point);
            cout << "\nGot it! Column 1 and Column 3 have been swapped.";
            break;
        
        case 4: //Exit created
            functionExitCode();
            break;
        }
    } while (choice != 4);
    return 0; 
}

void displayMatrix(int *point){ //displays matrix for each input
    for (int row = 0; row < MATRIX_SIZE; row++){ //using row instead of the standard i so I can read it easier
        for(int col = 0; col < MATRIX_SIZE; col++){ //using col instead of j so I can read it easier
            cout << *(point + row * MATRIX_SIZE + col) << "\t";
        }
        cout << endl;
    }
}

void findInt(int *point,int value){ //finds specific int in matrix
    bool intFound = false; //Assume the integer has not been found yet
    for(int row = 0; row < MATRIX_SIZE; row++){ 
        for(int col = 0; col < MATRIX_SIZE; col++){ 
            if(*(point + row *MATRIX_SIZE + col) == value){ //changed to use pointer to print found int
                cout << value << " is located on row " << row+1 << ", column "<< col+1 << ".";
                intFound = true;
                return;
            }
        }
    }
    if (!intFound){ //if the integer is not found within the matrix
        cout << value << " is not in the array.\n";
    }
}

void swapColumns(int *point){ //swaps two columns in matrix
    for (int row = 0; row < MATRIX_SIZE; row++){
        int tempVariable = *(point + row * MATRIX_SIZE); // used to point to first spot of current row
        *(point + row *MATRIX_SIZE) = *(point + row * MATRIX_SIZE + 2); //assigns 3rd column to 1st
        *(point + row * MATRIX_SIZE + 2) = tempVariable; //uses temp variable to assign 1st column to the 3rd
        
    }
}

void displayMenu(){ //displays physical menu
    cout << "\n***Menu***\n";
    cout << "\n1. Display Array \n";
    cout << "2. Find My Integer\n";
    cout << "3. Swap Column 1 with Column 3\n";
    cout << "4. Exit\n";
    cout << "\nPlease enter your choice: ";
}

void functionExitCode(){ //Displays message upon exit
    cout << "\nThanks for playing!\n";
}

