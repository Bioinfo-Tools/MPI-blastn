/*
 * debug.h
 *
 *  Created on: Mar 22, 2012
 *      Author: miguel.xavier
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#if __GNUC__ == 2 && __GNUC_MINOR__ < 96
#define __builtin_expect(x, expected_value) (x)
#endif

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

#define DEBUG_LEVEL_QUIET		(0)
#define DEBUG_LEVEL_ERR			(1 << 0)
#define DEBUG_LEVEL_WARN		(1 << 1)
#define DEBUG_LEVEL_INFO		(1 << 2)
#define DEBUG_LEVEL_DEBUG		(1 << 3)
#define DEBUG_LEVEL_MORE_DEBUG	(1 << 4)

#define DEBUG_LEVEL_IS_DEBUG 		unlikely(globals.debugLevel >= DEBUG_LEVEL_DEBUG)
#define DEBUG_LEVEL_IS_MORE_DEBUG 	unlikely(globals.debugLevel >= DEBUG_LEVEL_MORE_DEBUG)

#define DEBUG_ENTER_FUNCTION \
	do { \
		if (DEBUG_LEVEL_IS_DEBUG) \
			printf("proc %d: %s - %s(%d): Entering\n", globals.my_rank, __FILE__, __FUNCTION__, __LINE__); \
	} while(0)

#define DEBUG_EXIT_FUNCTION \
	do { \
		if (DEBUG_LEVEL_IS_DEBUG) \
			printf("proc %d: %s - %s(%d): Exiting\n", globals.my_rank, __FILE__, __FUNCTION__, __LINE__); \
	} while(0)

#define DEBUG_RETURN_INT(x) \
	do { \
		if (DEBUG_LEVEL_IS_DEBUG){ \
			printf("%s - %s(%d): Exiting with %08x\n", __FILE__, __FUNCTION__, __LINE__, (u_int)x); \
	} \
	return x;\
	} while(0);

#define DEBUG_RETURN_CHAR(x) \
	do { \
		if (DEBUG_LEVEL_IS_DEBUG) \
			printf("%s - %s(%d): Exiting with %08x\n", __FILE__, __FUNCTION__, __LINE__,(u_char)x); \
	return x;	\
	} while(0);

#define DEBUG_RETURN_VOID \
	do { \
		if (DEBUG_LEVEL_IS_DEBUG) \
			printf("%s - %s(%d): Exiting\n", __FILE__, __FUNCTION__, __LINE__); \
	return;	\
	} while(0);

#define DEBUG_MSG(fmt, args... ) \
	do { \
		if (DEBUG_LEVEL_IS_DEBUG){ \
			printf("proc %d: %s - %s(%d): " fmt,globals.my_rank, __FILE__, __FUNCTION__, __LINE__ , ##args); \
			fflush(stdout);\
		}\
	} while(0);

#endif /* DEBUG_H_ */
