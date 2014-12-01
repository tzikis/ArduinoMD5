#include <MD5.h>

int main(int argc, char** argv) 
{
  //generate the MD5 hash for our string
  unsigned char* hash=MD5::make_hash("hello world");
  //generate the digest (hex encoding) of our hash
  char *md5str = MD5::make_digest(hash, 16);
  free(hash);
  printf("%s\n",md5str);
  free(md5str);
  return 0;
}

