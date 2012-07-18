/*
 * mpifunc.h
 *
 *  Created on: Mar 22, 2012
 *      Author: miguel.xavier
 */

#ifndef MPIFUNC_H_
#define MPIFUNC_H_

/* MPI return status */
MPI_Status status;

void mpiInit(int argc, char ***argv);

void mpiStartTime();
void mpiEndTime();
double mpiGetExectime();
void mpiFinalize();

void mpiSend();
void mpiReceive();


#endif /* MPIFUNC_H_ */
