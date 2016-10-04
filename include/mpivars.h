typedef struct mpi_variable {
     int rank;   /* process rank               */
     int nproc;  /* total number of processes  */

     int iproc;  /* number of processes along i-direction of the grid */
     int jproc;  /* number of processes along j-direction of the grid */
     int kproc;  /* number of processes along k-direction of the grid */
                /* Note: nproc = iproc * jproc * kproc  */

     int ip;     /* process rank along i-direction of the grid       */
     int jp;     /* process rank along j-direction of the grid       */
     int kp;     /* process rank along k-direction of the grid       */

     int is,ie;  /* start and end i-indices for this proc in global domain */
     int js,je;  /* start and end j-indices for this proc in global domain */
     int ks,ke;  /* start and end j-indices for this proc in global domain */

} MPIVariables;
