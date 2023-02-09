#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/shell/shell.h>

#define LOG_LEVEL LOG_LEVEL_INF
LOG_MODULE_REGISTER(cmd2);

int cmd2_func() {
	LOG_INF("CMD2");

	return 0;
}

SYS_INIT(cmd2_func, APPLICATION, 99);

static int cmd2_hello(const struct shell *shell, size_t argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_print(shell, "Command 2 hello");

	return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(sub_cmd2,
	SHELL_CMD_ARG(hello, NULL, "Hello", cmd2_hello, 1, 0),
	SHELL_SUBCMD_SET_END /* Array terminated. */
);

SHELL_CMD_REGISTER(cmd2, &sub_cmd2, "Command2", NULL);
