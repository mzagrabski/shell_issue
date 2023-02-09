#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>

#define LOG_LEVEL LOG_LEVEL_INF
LOG_MODULE_REGISTER(main);

int main_func() {
	LOG_INF("Main");

	return 0;
}

SYS_INIT(main_func, APPLICATION, 98);
