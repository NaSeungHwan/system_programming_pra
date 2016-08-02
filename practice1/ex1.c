#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
	int fd, fd1, fd2;
	ssize_t nread;
	off_t newpos;

	char buffer[1024];
	char content[] = "Hello!\n";

	fd = open("data.txt", O_RDWR);
	
	nread = read(fd, buffer, 1024);
	write(1, buffer, nread);

	newpos = lseek(fd, (off_t)5, SEEK_SET);
	nread = read(fd, buffer, 1024);
	write(1, buffer, nread);

	close(fd);

	fd1 = open("data1.txt", O_RDWR | O_CREAT, 0644);
	fd2 = creat("data2.txt", 0644);

	close(fd1);
	close(fd2);

	unlink("data2.txt");

	return 0;
}
