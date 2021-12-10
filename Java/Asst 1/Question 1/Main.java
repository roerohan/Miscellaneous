import java.lang.*;
import java.io.*;
import java.util.*;

class Main {
    public static void selectionSort(int[] nums, int n) {
        for (int i = 0; i < n; i++) {
            int min = -1;
            int min_index = -1;
            for (int j = i; j < n; j++) {
                if (min == -1 || nums[j] < min) {
                    min = nums[j];
                    min_index = j;
                }
            }

            int temp = nums[i];
            nums[i] = min;
            nums[min_index] = temp;
        }
    }

    public static void displayArr(int[] nums, int n) {
        System.out.println("Elements in the array:");
        for (int i = 0; i < n; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }

    public static void inputArr(int[] nums, int n) {
        System.out.println("Enter " + n + " elements of array:");
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        sc.close();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the no of element in the array: ");

        int n = sc.nextInt();

        int[] nums = new int[n];

        inputArr(nums, n);
        selectionSort(nums, n);
        displayArr(nums, n);

        sc.close();
    }
}
