import java.lang.System;
import java.lang.Math;

class Main {
  public static void main(String[] args) {
    int[] numArray = new int[] {0, 3, 4, 5, 5, 6, 8, 13, 17, 404, 1000, 1001};
    int target = 404;
    int searchIndex = binarySearch(numArray, target);

    if(searchIndex == -1) {
      System.out.println("Couldn't find the target value in the array.");
    } else {
      System.out.println("Found target value " + target + " at index " + searchIndex + " in the array.");
    }
  }

  /**
   * Searches the array for a target value. 
   * If it cannot be found, -1 is returned.
   * 
   * @param array The integer array
   * @param target The target value
  */
  public static int binarySearch(int[] array, int target) {
    int left = 0;
    int right = array.length - 1;

    int middle;

    while(left <= right) {
      middle = (int) Math.floor((left + right) / 2);
      int val = array[middle];
      
      if(val < target) {
        left = middle + 1;
      }

      if(val > target) {
        right = middle - 1;
      }

      if(val == target) {
        return middle;
      }
    }

    return -1;
  }
}
