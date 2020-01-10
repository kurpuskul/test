int read(int fd, char *buf, int n);
int write(int fd, char *buf, int n);

int main(){
 char *buf = "trying\n";
 write(1, buf, sizeof(buf));
 return 0;
}
