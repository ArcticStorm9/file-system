#include <inttypes.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

#define BLOCK_SIZE 4096
#define INODES 128
#define countof( arr) (sizeof(arr)/sizeof(0[arr]))

struct inode {
    uint64_t size;
    uint64_t mtime;
    uint64_t type;
    uint64_t blocks[509];
};

struct dirent {
  char* name; // use strlen; when storing, add 1 to that bc youre adding a null terminator
  uint64_t finode;
};


void handleerr(bool b, int handle);

int opendisk(char *filename, uint64_t size);
int readblock(int handle, uint64_t blocknum, void *buffer);
int writeblock(int handle, uint64_t blocknum, void *buffer);
int syncdisk(int handle);
int closedisk(int handle);
bool testbit(uint64_t n);
void setbit(uint64_t n);
void clearbit(uint64_t n);
int formatdisk(int handle);
void dumpdisk(int handle);
int createfile(int handle, uint64_t sz, uint64_t t);
void deletefile(int handle, uint64_t blocknum);
void dumpfile(int handle, uint64_t blocknum);
int enlargefile(int handle, uint64_t blocknum, uint64_t sz);
int shrinkfile(int handle, uint64_t blocknum, uint64_t sz);
int writefile(int handle, uint64_t blocknum, void *buffer, uint64_t sz);
int readfile(int handle, uint64_t blocknum, void *buffer, uint64_t sz);
int createdirectory(int handle, uint64_t sz);
int deletedirectory(int handle, uint64_t inode);
int adddirentry(int handle, uint64_t dir_inode, uint64_t file_inode, char* filename);
void dumpdirectory(int handle, uint64_t inode);
void ls(int handle, uint64_t dir_inode);
int findinodebyfilename(int handle, uint64_t dir_inode, char* name);
void removedirentry(int handle, uint64_t dir_inode);
int hierdirsearch(int handle, char* name);
struct dirent* unpackdata(int handle, uint64_t dir_inode);
int packdata(int handle, uint64_t dir_inode, struct dirent* direntarr);
