#include "redis_cmd.h"

/*execute redis command*/
redisReply *execRedisCmd(char *cmd)
{
    /*检查入参*/
    if(NULL == cmd)
    {
        printf("NULL pointer");
        return NULL;
    }

    /*连接redis*/
    redisContext *context = redisConnect(REDIS_SERVER_IP,REDIS_SERVER_PORT);
    if(NULL == context || context->err)
    {
        redisFree(context);
        printf("%d connect redis server failure:%s\n",__LINE__, context->errstr);
        return NULL;
    }
    //printf("connect redis server success\n");

    /*执行redis命令*/
    redisReply *reply = (redisReply *)redisCommand(context, cmd);
	
	/*释放连接*/
	redisFree(context);
	
    if(NULL == reply)
    {
        printf("%d execute command:%s failure\n", __LINE__, cmd);
        return NULL;
    }
	
	return reply;
}
