import java.util.Scanner;

interface ArrayInterface {
    public void read();
    public void sort();
    public void display();
}

class ArrayClass implements ArrayInterface {
    int[] nums;
    int n;
    
    ArrayClass(int n) {
        this.n = n;
        this.nums = new int[n];
    }

    public void read() {
        System.out.println("Enter " + n + " elements of array:");

        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            this.nums[i] = sc.nextInt();
        }

        sc.close();
    }

    public void sort() {
        // Sort using insertion sort
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j-1]) {
                    int temp = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = temp;
                } else {
                    break;
                }
            }
        }
    }

    public void display() {
        System.out.println("The elements in the array are:");
        for (int i = 0; i < n; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }
}