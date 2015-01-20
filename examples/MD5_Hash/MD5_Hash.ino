#include <MD5.h>
#include "printf"
MD5  hashMD5;
/*
This is en example of how to use my MD5 library. It provides two
easy-to-use methods, one for generating the MD5 hash, and the second
one to generate the hex encoding of the hash, which is frequently used.
*/
void setup()
{
  printf_begin();
  unsigned long ms;
  //initialize serial
  Serial.begin(9600);
  //give it a second
  delay(1000);
  //generate the MD5 hash for our string
  ms = micros();
  char *md5str = hashMD5.md5("abc");;
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  //print it on our serial monitor
  Serial.println("PLAIN   :abc");
  Serial.println("EXPECTED:900150983cd24fb0d6963f7d28e17f72");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  //generate the MD5 hash for our string
  ms = micros();
  md5str = hashMD5.md5("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq");
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq");
  Serial.println("EXPECTED:8215ef0796a20bcaaae116d3876c664a");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  
  //generate the MD5 hash for our string
  char aa[1000001];
  for (int i=0;i<1000000;i++)
    aa[i] = 'a';
  aa[1000000] = '\0';
  ms = micros();
  md5str = hashMD5.md5(aa);
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :1,000,000 x a");
  Serial.println("EXPECTED:7707d6ae4e027c70eea2a935c2296f21");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  unsigned char digest[16];
  unsigned char key[5] = "Jefe";
  int key_len = 4;
  unsigned char text[29] = "what do ya want for nothing?";
  int text_len = 28;
  ms = micros();
  hashMD5.hmac_md5(text, text_len, key, key_len, digest);
  for (int j=0;j<16;j++){
   printf("%02x",digest[i]); 
  }
  md5str = hashMD5.make_digest(digest,16);
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :what do ya want for nothing?");
  Serial.println("KEY     :Jefe");
  Serial.println("EXPECTED:750c783ee6ab0b503eaa86e310a5db738");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
}

void loop()
{
}
