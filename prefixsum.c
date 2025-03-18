#include <mpi.h>
#include <stdio.h>

#define N 8

int main(int argc, char* argv[]) {
    int rank, size, arr[N], prefix_sum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    arr[rank] = rank + 1;
    MPI_Scan(&arr[rank], &prefix_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Rank %d: Prefix sum = %d\n", rank, prefix_sum);

    MPI_Finalize();
    return 0;
}
