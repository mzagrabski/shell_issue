#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/shell/shell.h>

#define LOG_LEVEL LOG_LEVEL_INF
LOG_MODULE_REGISTER(cmd1);

int cmd1_func() {
	LOG_INF("CMD1");

	return 0;
}

SYS_INIT(cmd1_func, APPLICATION, 99);

static int cmd1_hello(const struct shell *shell, size_t argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_print(shell, "Command 1 hello");

	return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(sub_cmd1,
	SHELL_CMD_ARG(hello, NULL, "Hello", cmd1_hello, 1, 0),
	SHELL_SUBCMD_SET_END /* Array terminated. */
);

SHELL_CMD_REGISTER(cmd1, &sub_cmd1, "Command1", NULL);
