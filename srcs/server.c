#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#include "minitalk.h"

// 128 64 32 16 8 4 2 1
// 0000 0000
//
//
//65 in binary : 0100 0001
// original : 0000 0000
//

typedef struct s_info
{
	int flag;
	char c;
}	t_info;

t_info	info = {128, 0};

void wbyte(void)
{
	if (!info.flag)
		write(1, &info.c, 1);
}

void b_one(int signal)
{
	(void) signal;
	info.c = info.c | info.flag;
	info.flag /= 2;
	wbyte();
}

void b_zero(int signal)
{
	(void) signal;
	info.flag /= 2;
	if (!info.flag)
	wbyte();
}

int	main(void)
{
	/* signal(SIGUSR1, &b_one); */
	/* signal(SIGUSR1, &b_zero); */
	/* pid_t pid = getpid(); */
	/* ft_printf("%u\n", pid); */
	pid_t pid = fork();
	if (!pid) {
		kill(getppid(), SIGUSR2);
		usleep(2);
		kill(getppid(), SIGUSR1);
		usleep(2);
		kill(getppid(), SIGUSR2);
		usleep(2);
		kill(getppid(), SIGUSR2);
		usleep(2);
		kill(getppid(), SIGUSR2);
		usleep(2);
		kill(getppid(), SIGUSR2);
		usleep(2);
		kill(getppid(), SIGUSR2);
		usleep(2);
		kill(getppid(), SIGUSR1);
	}
	else {
		while (1) {
			signal(SIGUSR1, &b_one);
			signal(SIGUSR2, &b_zero);
		}
	}
}
