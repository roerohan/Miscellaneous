//server.c
#include "/home/user/msgbuf.h"
#define SHMSZ    127
int main()
{
key_t key;
message_buf *m;
char ans='y';
key = 9876;
if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
        {
                perror("shmget");
                exit(1);
        }
        printf("\nShared Memory Id = %d\n",shmid);
        if ((m = shmat(shmid, NULL, 0)) == (message_buf *) -1)
        {       perror("shmat");
                exit(1);
        }

      printf("\n m= %d\n",m);
      while(ans=='y')
      {
             sleep(1);
             printf("Enter your choice");
             scanf("%c",&ans);
             getchar();
      }
      return 0;
}



//client.c
#include "/home/user/msgbuf.h"
#define SHMSZ    127
int main()
{
key_t key;
message_buf *rbuf;
key = 9876;
if ((shmid = shmget(key, SHMSZ, 0666)) < 0)
        {
                perror("shmget");
                exit(1);
        }
        printf("\nShared Memory Id = %d\n",shmid);
        if ((rbuf = shmat(shmid, NULL, 0)) == (message_buf *) -1)
        {       perror("shmat");
                exit(1);
        }
      printf("\n rbuf= %d\n",rbuf);
      return 0;
}
