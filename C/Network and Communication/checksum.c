#include<stdio.h>
#include<string.h>
 
char* checksum(char a[50], char b[50]) {
    char sum[strlen(a)], complement[50];
    int i, length;
    
    if(strlen(a)==strlen(b)){
		length = strlen(a);
		char carry='0';
        
		for(i=length-1;i>=0;i--)
        {
			if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                sum[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                sum[i]='1';
                carry='1';
 
            }
            else
                break;
        }
        
        printf(strncat(carry, sum, 1));
        return strncat(&carry, sum, 1);
		
	}
	else {
		printf("\nWrong input strings");
        return "Error";
	}
}

int main()
{   
    char input[50], sum[50], complement[50];
    int i = 0, k, m;

    printf("Enter the number of packets: ");
    scanf("%d", &k);

    printf("Enter the size of a packet: ");
    scanf("%d", &m);

    printf("Enter the entire message: ");
    scanf("%s", input);

    if (k*m != strlen(input)) {
        printf("Message size not valid.");
        return 1;
    }

    char temp1[m], temp2[m];

    while (i < m) {
        temp1[i%m] = input[i];
        temp2[i%m] = input[i+m];
        i++;
    }

    checksum(temp1, temp2);

    // while (i < m*k) {
    //     temp1[i%m] = input[i]; 
    //     if (i%m == 0) {
    //         strcpy(temp2, checksum(temp1, temp2));
    //     }
    // }

    // printf("%s\n", temp2);
}