#ifndef __CMD_H
#define __CMD_H

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

struct cmd{
	char cmd_code[64];
	int (*cmd_func)(void);
};

int register_cmds(struct cmd cmds[], int count);


#endif
