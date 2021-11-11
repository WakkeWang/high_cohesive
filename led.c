#include <stdio.h>
#include "cmd.h"

static int cmd_led_on(void)
{
	printf("this is %s func\n",__func__);
	return 0;
}

static int cmd_led_blink(void)
{
	printf("this is %s func\n",__func__);
	return 0;
}

static int cmd_led_off(void)
{
	printf("this is %s func\n",__func__);
	return 0;
}

static struct cmd led_cmds[] = {
	{"led_on", cmd_led_on},
	{"led_off", cmd_led_off},
	{"led_blink", cmd_led_blink},
};

int led_init( int argc, const char **argv)
{
	register_cmds(led_cmds, ARRAY_SIZE(led_cmds));

	return 0;
}
