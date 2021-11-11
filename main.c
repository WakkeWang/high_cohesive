#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "cmd.h"

struct cmd_list{
	struct list_head list;
	struct cmd cmd;
};


struct cmd_list cmd_list;

int register_cmds(struct cmd r_cmds[], int count)
{
	int i;
	struct cmd_list *p = NULL;

	for(i = 0; i < count; i++)
	{
		p = (struct cmd_list*)malloc(sizeof(struct cmd_list));
		p->cmd = r_cmds[i];
		list_add(&p->list, &cmd_list.list);	
	}
	
	return 0;
}

int main( int argc, const char **argv)
{
	struct list_head *pos = NULL;
	
	INIT_LIST_HEAD(&cmd_list.list);

	led_init();
	do_init();

	list_for_each(pos, &cmd_list.list) {
		printf("cmd->name=%s\n", ((struct cmd_list*)pos)->cmd.cmd_code);
		((struct cmd_list*)pos)->cmd.cmd_func();
	}

	return 0;
}
