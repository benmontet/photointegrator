#ifndef _N_BODY_
#define _N_BODY_

/*
  n_body.h

  Benjamin Montet, Josh Carter, 2013-5

  N-body BS integrator of Newton's equations 

*/

// r, v, a are NX3 matricies of coordinates, velocities and accelerations at starting state (at time0) and are
// overwritten by evolved values (at time).  Accelerations are obviously irrelevant in describing the starting state.
// Prot is an NX1 matrix of rotation periods for the stars. k2 is an NX1 matrix of the apsidal motion
// constant (one-half the tidal Love number often used in planetary studies). A point source has k2=0,
// while a uniform sphere has k2=0.75
// HMAX is maximum step, status is integral status value (1 is failure), ORBIT_ERROR is orbit error and HLIMIT
// is minimum step size (smaller triggers status = 1).
void evolve(double ** r, double ** v, double ** a, double * mass, double * eta, int N, double * radius, double* Prot, double*k2,
	    double time0, double time, double HMAX, int & status, double ORBIT_ERROR, double HLIMIT);

#endif
