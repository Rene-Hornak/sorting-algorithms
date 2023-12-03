#include <stdio.h>
#include <ctype.h> // include toupper()

// GLOBAL VARIABLES
// ARRAY
int array[] = {19, 10, 8, 17, 9, 50, 1, 0, 100, 97, 12, 15, 80, 120, 150, 1000, 1200, 300, 500, 128};
// SIZE of ARRAY
int arrayLength = sizeof(array) / sizeof(array[0]);

void bubbleSort();
void insertionSort();
void selectionSort();

int main() {
    
    //print array
    printf("Unordered array: \n");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", array[i]);
    }

    char charSort;
    printf("\n\nEnter statement [Bubble, Insertion, Selection]: ");
    scanf("%c", &charSort);

    // change char to uppercase
    charSort = toupper(charSort);

    switch (charSort) {
    case 'B':
        bubbleSort();
        break;
    
    case 'I':
        insertionSort();
        break;
    
    case 'S':
        selectionSort();
        break;
    }

    //print array
    printf("\nOrdered array: \n");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}


// BUBBLE SORTING Big-O = O(n^2)
void bubbleSort() {
    printf("\n\nBubble sorting\n");
    for (int i = 0; i < arrayLength; i++) {
        for (int j = 0; j < arrayLength - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
            }
        }
    }
}

// INSERTION SORTING Big-O = O(n^2)
// USE: better if data is "mostly sorted"
void insertionSort() {
    printf("\n\nInsertion sorting\n");
    for (int i = 0; i < arrayLength; i++) {
        int current = array[i];

        int j = i - 1;

        while (j > -1 && current < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}

// SELECTION SORTING Big-O = O(n^2)
void selectionSort() {
    printf("\n\nSelection sorting\n");
    for (int i = 0; i < arrayLength; i++) {
        int minimum = i;
        for (int j = i + 1; j < arrayLength; j++) {
            if (array[j] < array[minimum]) {
                minimum = j;
            }
        }
        if (minimum != i) {
            int temporary = array[i];
            array[i] = array[minimum];
            array[minimum] = temporary;
        }
        
    }
    
}