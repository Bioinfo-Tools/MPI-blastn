/*
 * mpifunc.c
 *
 *  Created on: Mar 22, 2012
 *      Author: miguel.xavier
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "mpi.h"

#include "config.h"
#include "parallel.h"

#include "mpifunc.h"

typedef struct {

	/* MPI return status */
	MPI_Status status;

	/* Execution time */
	double exectime;

	/* Start time */
	double starttime;

	/* End time */
	double endtime;

} mpiconfig_s;

mpiconfig_s mpiconfig;

void mpiInit(int argc, char ***argv) {

	MPI_Init(&argc, argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &globals.my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &globals.total_proc);

}

void mpiStartTime() {
	mpiconfig.starttime = MPI_Wtime();
}

void mpiEndTime() {
	mpiconfig.endtime = MPI_Wtime();
}

double mpiGetExectime() {
	return mpiconfig.exectime = mpiconfig.endtime - mpiconfig.starttime;
}

void mpiFinalize() {
	MPI_Finalize();
}

void  mpiSend() {

}

void mpiReceive() {

}
