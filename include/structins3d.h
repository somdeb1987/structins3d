typedef struct solver_parameters{

    /*  grid parameters */
    
    double *x,*y,*z;
    double *x_g,*y_g,*z_g;

    double *xi,*eta,*zeta;
    double *xi_g,*eta_g,*zeta_g;

    double *jac;
    
    double *x_xi,*x_eta,*x_zeta;
    double *y_xi,*y_eta,*y_zeta;
    double *z_xi,*z_eta,*z_zeta;

    double *xi_x,*xi_y,*xi_z;
    double *eta_x,*eta_y,*eta_z;
    double *zeta_x,*zeta_y,*zeta_z;
    
    /*  */



} StructIns3DNS

int ReadInputs      (void*,void*);
int Initialize      (void*,void*);
int OutputSolution  (void*,void*);
int CleanUp         (void*,void*);

#ifdef __cplusplus
extern "C"
#endif
