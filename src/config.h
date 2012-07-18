/*
 * config.h
 *
 *  Created on: Mar 21, 2012
 *      Author: miguel.xavier
 */

#ifndef CONFIG_H_
#define CONFIG_H_

enum {
	start, stop
};

typedef struct {

	/* Queries name */
	char *queries;

	/* Base name */
	char *base_name;

	/* Result file */
	char *out;

	int num_threads;
	int my_rank;
	int total_proc;
	int debugLevel;

} globals_s;

typedef struct {
	int sequence_number;
	int sequence_proc_total;
} blastconf_s;

globals_s globals;
blastconf_s blastconf;

#endif /* CONFIG_H_ */
