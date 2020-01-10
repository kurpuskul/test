int read(int fd, char *buf, int size);
int write(int fd, char *buf, int size);
#define BUF 1024

int main(){
	char buf[BUF];
	char wel[] = "Welcome to my prog. Please enter some text below:\n";
	write(1, wel, sizeof wel);
	write(1, buf, read(0, buf, BUF));
	return 0;
}
