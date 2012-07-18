/*
 * main.c
 *
 *  Created on: Mar 21, 2012
 *      Author: miguel.xavier
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <mpi.h>
#include "debug.h"
#include "config.h"
#include "parallel.h"

int main(int argc, char *argv[]) {

	globals.debugLevel = DEBUG_LEVEL_DEBUG;

	globals.queries = argv[1];
	globals.base_name = argv[2];
	globals.out = argv[3];
	globals.num_threads = atoi(argv[4]);

	/* Initialize MPI */
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &globals.my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &globals.total_proc);

	/* Execute MPI function */
	mpiBlastnExecute();

	/* Finalize MPI */
	MPI_Finalize();

	return 0;
}
