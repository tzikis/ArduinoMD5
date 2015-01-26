#include <MD5.h>

MD5 hashMD5;
int main(int argc, char** argv) 
{
  printf("********************\n");
  printf("****MD5 examples****\n");
  printf("********************\n");
  printf("\n");
  double ms;
  ms = hashMD5.millis();
  char *md5str = hashMD5.md5("abc");
  printf("Done in (%f) ms\n",(hashMD5.millis() - ms));
  printf("PLAIN   :abc\n");
  printf("EXPECTED:900150983cd24fb0d6963f7d28e17f72\n");
  printf("RESULT  :");
  printf("%s\n",md5str);
  printf("\n");
  
  ms = hashMD5.millis();
  md5str = hashMD5.md5("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq");
  printf("Done in (%f) ms\n",(hashMD5.millis() - ms));
  printf("PLAIN   :abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq\n");
  printf("EXPECTED:8215ef0796a20bcaaae116d3876c664a\n");
  printf("RESULT  :");
  printf("%s\n",md5str);
  printf("\n");
  
  char aa[1000001];
  for (int i=0;i<1000000;i++)
    aa[i] = 'a';
  aa[1000000] = '\0';
  ms = hashMD5.millis();
  md5str = hashMD5.md5(aa);
  printf("Done in (%f) ms\n",(hashMD5.millis() - ms));
  printf("PLAIN   :1,000,000 x a\n");
  printf("EXPECTED:7707d6ae4e027c70eea2a935c2296f21\n");
  printf("RESULT  :");
  printf("%s\n",md5str);
  printf("\n");
  return 0;
}

