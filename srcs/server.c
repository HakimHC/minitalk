#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#include "libft.h"
#include "minitalk.h"

// 128 64 32 16 8 4 2 1
// 0000 0000
//
//
//65 in binary : 0100 0001
// original : 0000 0000
//

t_info g_info = {128, 0};

void wbyte(void)
{
	if (!g_info.flag)
	{
		write(1, &g_info.c, 1);
		if (!g_info.c)
			write(1, "\n", 1);
		g_info = (t_info){128, 0};
	}
}

void b_one(int signal)
{
	(void) signal;
	g_info.c = g_info.c | g_info.flag;
	g_info.flag /= 2;
	wbyte();
}

void b_zero(int signal)
{
	(void) signal;
	g_info.flag /= 2;
	if (!g_info.flag)
	wbyte();
}

int	main(void)
{
	pid_t pid = getpid();
	ft_printf("%u\n", pid);
	while (1) {
		signal(B1, &b_one);
		signal(B0, &b_zero);
	}
}
