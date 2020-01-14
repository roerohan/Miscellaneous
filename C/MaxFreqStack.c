#include <stdio.h>

void createStack(int* arr, int len) {
    printf("Enter the elements in the stack\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
}

void display(int* arr, int len) {
    printf("\nThe current stack is: \n");
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

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

void pop (int* arr, int len, int index) {
    for (int i = index; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int popMaxFreq(int* arr, int* len) {
    int elem = findMaxFreqElement(arr, *len);
    for (int i = 0; i < *len; i ++) {
        if (elem == arr[i]) {
            pop(arr, *len, i);
            i--;
            (*len)--;
        }
    }
    // display(arr, *len);
    return elem;
}

int main() {
    int len;
    printf("Enter the length of the stack\n");
    scanf("%d", &len);

    int arr[len];
    createStack(arr, len);
    
    while (len > 0) {
        printf("Popped Element: %d\n", popMaxFreq(arr, &len));
        display(arr, len);
    }    
    return 0;
}