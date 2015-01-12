#include <MD5.h>

int main(int argc, char** argv) 
{
  double ms;
  //generate the MD5 hash for our string
  ms = MD5::millis();
  unsigned char* hash=MD5::make_hash("abc");
  //generate the digest (hex encoding) of our hash
  char *md5str = MD5::make_digest(hash, 16);
  printf("Done in (%f) ms",(MD5::millis() - ms));
  free(hash);
  //print it on our serial monitor
  printf("PLAIN   :abc\n");
  printf("EXPECTED:900150983cd24fb0d6963f7d28e17f72\n");
  printf("RESULT  :");
  printf("%s\n",md5str);
  printf("\n");
  
  //generate the MD5 hash for our string
  ms = MD5::millis();
  hash=MD5::make_hash("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq");
  //generate the digest (hex encoding) of our hash
  md5str = MD5::make_digest(hash, 16);
  printf("Done in (%f) ms",(MD5::millis() - ms));
  printf("PLAIN   :abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq\n");
  printf("EXPECTED:8215ef0796a20bcaaae116d3876c664a\n");
  printf("RESULT  :");
  printf("%s\n",md5str);
  printf("\n");
  
  //generate the MD5 hash for our string
  char aa[100001];
  for (int i=0;i<1000000;i++)
    aa[i] = 'a';
  aa[1000000] = '\0';
  ms = MD5::millis();
  hash=MD5::make_hash(aa);
  //generate the digest (hex encoding) of our hash
  md5str = MD5::make_digest(hash, 16);
  printf("Done in (%f) ms",(MD5::millis() - ms));
  printf("PLAIN   :1,000,000 x a\n");
  printf("EXPECTED:7707d6ae4e027c70eea2a935c2296f21\n");
  printf("RESULT  :");
  printf("%s\n",md5str);
  printf("\n");
  //Give the Memory back to the System if you run the md5 Hash generation in a loop
  free(md5str);
  return 0;
}

