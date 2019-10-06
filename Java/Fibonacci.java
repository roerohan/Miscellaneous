public class Fibonacci{

	public static void fibonacciSecuence(int n)
	{
		
		int a = 0, b = 1, c = 0;

		do{
			System.out.print(a+" ");
			c = a + b;
			a = b;
			b = c;
		}while(--n>0);
		System.out.println("");
	}

	public static void main(String[] args) {
		/*
			Calculate a number in and specific position on Fibonacci Secuence
		*/
		fibonacciSecuence(9);
		fibonacciSecuence(12);

	}
}