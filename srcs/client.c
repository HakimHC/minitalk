#include <unistd.h>
#include <signal.h>

#include "minitalk.h"

void send_bits(char byte, pid_t dest)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((byte >> i) & 1)
			kill(dest, B1);
		else
		 	kill(dest, B0);
		i--;
		usleep(20);
	}
	usleep(50);
}

void send_data(char *data, pid_t dest)
{
	while (*data)
		send_bits(*data++, dest);
	send_bits(0, dest);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*data;

	if (argc != 3)
		return ft_printf("error usage\n");
	pid = ft_atoi(argv[1]);
	data = argv[2];
	send_data(data, pid);
	return 0;
}
