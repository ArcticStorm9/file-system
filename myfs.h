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

struct inode {
    uint64_t size;
    uint64_t mtime;
    uint64_t type;
    uint64_t blocks[509];
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
/*void deletedirectory(int handle, uint64_t blocknum);
int createdirectoryentry(int handle, uint64_t blocknum);
void dumpdirectory(int handle, uint64_t blocknum);
void listdirectoryfiles(int handle, uint64_t blocknum);
int findfileindirectory(int handle, uint64_t blocknum, char* filename);
void removedirectoryentry(int handle, uint64_t dirblocknum, uint64_t fileblocknum);
int hierarchicalsearch(int handle);
*/
