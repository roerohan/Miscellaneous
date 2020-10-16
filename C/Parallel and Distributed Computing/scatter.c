// MPI Scatter sample
#include <stdio.h>
#include <mpi.h>

void main(int argc, char *argv[])
{
    int rank, size, i, j;
    double param[4], mine;
    int sndcnt, revcnt;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    revcnt = 1;
    if (rank == 3)
    {
        for (i = 0; i < 4; i++)
            param[i] = 23.0 + i;
        sndcnt = 1;
    }
    MPI_Scatter(param, sndcnt, MPI_DOUBLE, &mine, revcnt, MPI_DOUBLE, 3, MPI_COMM_WORLD);
    printf("P:%d mine is %f\n", rank, mine);
    MPI_Finalize();
}
