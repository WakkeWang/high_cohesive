#include <stdio.h>
#include "cmd.h"

static int cmd_do_on(void)
{
	printf("this is %s func\n",__func__);
	return 0;
}

static int cmd_do_off(void)
{
	printf("this is %s func\n",__func__);
	return 0;
}

static struct cmd do_cmds[] = {
	{"do_on", cmd_do_on},
	{"do_off", cmd_do_off},
};

int do_init( int argc, const char **argv)
{
	register_cmds(do_cmds, ARRAY_SIZE(do_cmds));

	return 0;
}
