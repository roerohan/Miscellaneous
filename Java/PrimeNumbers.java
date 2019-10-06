public class PrimeNumbers{

	public static boolean isPrime(int n)
	{
		int div = 2, cont = 2;

		while(cont < n)
		{
			if(n % cont == 0)
			{
				div++;
				break;
			}
			cont++;
		}

		return (div==2);
	}

	public static void main(String[] args) {
		
		int n = 35, m = 2024;
		
		/*
			Calculate prime numbers between n and m
		*/

		for (int i=n;i<=m ;i++ ) {
			
			if(isPrime(i))
			{
				System.out.println(i);
			}
		}

	}
}