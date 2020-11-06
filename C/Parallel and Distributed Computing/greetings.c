#include <stdio.h>
#include <string.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int rc, my_rank, p, source, dest, tag = 0, namelen;
    char message[MPI_MAX_PROCESSOR_NAME + 60];

    MPI_Status status;

    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS)
    {
        printf("Error starting MPI program. Terminating.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    MPI_Comm_size(MPI_COMM_WORLD, &p);

    if (my_rank != 0)
    {
        sprintf(message, "Greetings (from process %d)", my_rank);
        dest = 0;

        tag = my_rank;
        
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, dest, 5, MPI_COMM_WORLD);
    }
    else
    {
        for (source = 1; source < p; source++)
        {
            tag = source;
            MPI_Recv(message, sizeof(message), MPI_CHAR, source, MPI_ANY_SOURCE, MPI_COMM_WORLD, &status);
            printf("%s\n", message);
        }
    }

    MPI_Finalize();
}
