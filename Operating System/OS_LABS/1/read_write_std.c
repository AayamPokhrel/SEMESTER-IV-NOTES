#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main() {
	char buffer[10];

	write(1, "Enter 10 bytes of data: ", 24);
	read(0, buffer, 10);

	// Flush any leftover input so it doesn't leak into the shell
	tcflush(0, TCIFLUSH);

	write(1, "Stored buffer: ", 15);
	write(1, buffer, 10);
	write(1, "\n", 1);

	return 0;
}
