#include <stdio.h>
#include <sys/time.h>
#include <mpi.h>
#include <mpivars.h>
#include <structins3d.h>

int structins3d(int argc, char* argv[]){

    MPIVariables    mpi;
    int             ierr;
    struct timeval  main_start, solve_start;
    struct timeval  main_end  , solve_end  ;
    StructIns3DNS   solver;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&mpi.rank);
    MPI_Comm_size(MPI_COMM_WORLD,&mpi.nproc);
    if (!mpi.rank)  printf("Running in parallel with %d processes",mpi.nproc);
    
    gettimeofday(&main_start,NULL);
        ierr=Readinputs(&solver,&mpi);
        if(ierr) return(ierr);
      
        
        ierr = Initialize(&solver,&mpi);
        if(ierr) return(ierr);

    gettimeofday(&solver_start,NULL);


    gettimeofday(&solver_end,NULL);
        ierr = OutputSolution(&solver,&mpi);
        if(ierr) return(ierr);

        
        ierr = CleanUp(&solver);
        if(ierr) return(ierr);


    if (!mpi.rank) printf("Finished.\n");
    gettimeofday(&main_end,NULL);

    
    MPI_Finalize();
    return(0);
}
