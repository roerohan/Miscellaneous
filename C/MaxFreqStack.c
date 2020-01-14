#include <stdio.h>

// Function to create a stack with elements provided by the user
void createStack(int* arr, int len) {
    printf("Enter the elements in the stack:\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display the current status of the stack
void display(int* arr, int len) {
    printf("\nThe current stack is:\n");
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

// Function to find the element with maximum frequency in the stack
int findMaxFreqElement(int* arr, int len) {
    int count = 1, tempCount, tempElem;
    int elem = arr[0];
    for (int i = 0; i < len - 1; i++) {
        tempCount = 0;
        for (int j = i; j < len; j++) {
            if (arr[i] == arr[j]) {
                tempCount++;
            }
        }   
        if (tempCount > count) {
            count = tempCount;
            elem = arr[i];  
        } else if (tempCount == count) {
            if (arr[i] > elem && count != 1) {
                elem = arr[i];
            }
        }
    }

    return elem;
}

// Function to pop the element at the index 'index'
void pop (int* arr, int len, int index) {
    for (int i = index; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

// Function to pop the element having maximum frequency
int popMaxFreq(int* arr, int* len) {
    int elem = findMaxFreqElement(arr, *len);
    for (int i = 0; i < *len; i ++) {
        if (elem == arr[i]) {
            pop(arr, *len, i);
            i--;
            (*len)--; // Reduce the length of the array everytime an element is popped
        }
    }
    return elem;
}

int main() {
    int len;
    printf("Enter the length of the stack:\n");
    scanf("%d", &len);

    int arr[len];
    createStack(arr, len);
    
    while (len > 0) {
        printf("Popped Element: %d\n", popMaxFreq(arr, &len));
        display(arr, len);
    }    
    return 0;
}