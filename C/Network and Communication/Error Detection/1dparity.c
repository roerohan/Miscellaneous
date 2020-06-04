# include <stdio.h> 
# define bool int 

bool getParity(unsigned int n) 
{ 
	bool parity = 0; 
	while (n) 
	{ 
		parity = !parity; 
		n	 = n & (n - 1); 
	}		 
	return parity; 
} 

int main() 
{ 
    int n;
	printf("Enter the message (integer, even parity check): ");
    scanf("%d", &n);
	printf("The number after adding parity bit is: %d\n", (n<<1 + getParity(n))); 
	
	getchar(); 
	return 0; 
} 
