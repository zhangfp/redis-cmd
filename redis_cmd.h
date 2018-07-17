#ifndef	__REDIS_CMD__
#define __REDIS_CMD__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hiredis.h"

/*宏定义*/
#define CMD_MAX_LENGHT  	1024
#define REDIS_SERVER_IP		"127.0.0.1"
#define REDIS_SERVER_PORT	6379

#ifdef __cplusplus
extern "C"
#endif
typedef enum result
{
    SUCCESS=0,
    FAILURE=1
} RESULT;

/*lpush key string*/
RESULT lpush(char *key, char *string);

/*lrange key start end*/
RESULT lrange(char *key, int start, int end);

#ifdef __cplusplus
extern "C"
#endif

#endif
