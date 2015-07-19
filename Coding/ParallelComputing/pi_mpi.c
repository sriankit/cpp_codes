#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define WORKTAG 1
#define DIETAG 2
#define ITER 5000000

void master(void);
void slave(void);
int do_work(int work);


int main(int argc, char **argv){
  int myrank;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  if (myrank == 0)
    master();
  else
    slave();

  MPI_Finalize();
  return 0;
}

void master(void){
  int ntasks, rank;
  int work;
  int result;
  MPI_Status status;

  MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

  for (rank = 1; rank < ntasks; ++rank){
    work = rank;
    MPI_Send(&work,1,MPI_INT,rank,WORKTAG,MPI_COMM_WORLD);
  }

  double count = 0;
  for (rank = 1; rank < ntasks; ++rank){
    MPI_Recv(&result, 1, MPI_INT, MPI_ANY_SOURCE,MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    count += result;
  }

  printf("%0.15lf",4.0*count/((double)(ntasks-1)*ITER));

  for (rank = 1; rank < ntasks; ++rank)
    MPI_Send(0, 0, MPI_INT, rank, DIETAG, MPI_COMM_WORLD);
}


void slave(void){
  int work;
  int result;
  MPI_Status status;

  while (1) {
    MPI_Recv(&work, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

    if (status.MPI_TAG == DIETAG)
      return;

    result = do_work(work);
    MPI_Send(&result, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
}

int do_work(int work){
    srand(work);

    int count1 = 0;
    int i;
    for(i=0;i<ITER;i++){
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if(x*x + y*y <= 1) count1++;
    }
    return count1;
}
