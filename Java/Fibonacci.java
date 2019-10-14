import java.util.*;

class Fibonacci {

	static int fib(int n) {
		
		double phi = (1 + Math.sqrt(5)) / 2;
		return (int) Math.round(Math.pow(phi, n) / Math.sqrt(5));
		
	}

	public static void main(String[] args) {
		
		Scanner sn = new Scanner(System.in);
		
		System.out.println("Enter limit:");
		int n = sn.nextInt();
		for(int i = 1; i <= n; i++)
		{
			System.out.println(fib(i));
		}
		
	}
}
