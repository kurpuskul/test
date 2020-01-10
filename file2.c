int read(int fd, char *buf, int n);
int write(int fd, char *buf, int n);
#define BUFSIZE 1024

int main(){
 char buf[BUFSIZE];
 int n, k;
 n = read(0, buf, BUFSIZE);
 write(1, buf, n);
 return 0;
}
