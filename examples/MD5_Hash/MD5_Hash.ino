#include <MD5.h>
/*
This is en example of how to use my MD5 library. It provides two
easy-to-use methods, one for generating the MD5 hash, and the second
one to generate the hex encoding of the hash, which is frequently used.
*/
void setup()
{
  unsigned long ms;
  //initialize serial
  Serial.begin(9600);
  //give it a second
  delay(1000);
  //generate the MD5 hash for our string
  ms = micros();
  unsigned char* hash=MD5::make_hash("abc");
  //generate the digest (hex encoding) of our hash
  char *md5str = MD5::make_digest(hash, 16);
  free(hash);
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
  hash=MD5::make_hash("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq");
  //generate the digest (hex encoding) of our hash
  md5str = MD5::make_digest(hash, 16);
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
  hash=MD5::make_hash(aa);
  //generate the digest (hex encoding) of our hash
  md5str = MD5::make_digest(hash, 16);
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :1,000,000 x a");
  Serial.println("EXPECTED:7707d6ae4e027c70eea2a935c2296f21");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  //Give the Memory back to the System if you run the md5 Hash generation in a loop
  free(md5str);
}

void loop()
{
}
