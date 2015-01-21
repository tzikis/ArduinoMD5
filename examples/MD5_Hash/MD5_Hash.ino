#include <MD5.h>

MD5  hashMD5;
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
  
  unsigned char digest[17];
  digest[17] = 0x00;
  char key[] = {0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b, 0x00};
  int key_len;
  key_len = strlen(key);
  char *text = "Hi There";
  int text_len;
  text_len = strlen(text);
  ms = micros();
  hashMD5.hmac_md5(text, text_len, key, key_len, digest);
  md5str = hashMD5.make_digest(digest,16);
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :Hi There");
  Serial.println("KEY     :0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b");
  Serial.println("EXPECTED:9294727a3638bb1c13f48ef8158bfc9d");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  char *key2 = "Jefe";
  key_len = strlen(key2);
  char *text2 = "what do ya want for nothing?";
  text_len = strlen(text2);
  ms = micros();
  hashMD5.hmac_md5(text2, text_len, key2, key_len, digest);
  md5str = hashMD5.make_digest(digest,16);
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :what do ya want for nothing?");
  Serial.println("KEY     :Jefe");
  Serial.println("EXPECTED:750c783e6ab0b503eaa86e310a5db738");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  char key3[] = {0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa, 0x00};
  key_len = strlen(key3);
  char text3[] = {0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,
                  0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,
                  0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,
                  0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,
                  0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd, 0x00
                 };
  text_len = strlen(text3);
  Serial.println(text_len);
  ms = micros();
  hashMD5.hmac_md5(text3, text_len, key3, key_len, digest);
  md5str = hashMD5.make_digest(digest,16);
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :0xaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  Serial.println("KEY     :0xdd repeated 50 times");
  Serial.println("EXPECTED:56be34521d144c88dbb8c733f0e8b3f6");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  char key4[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,
                 0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,
                 0x15,0x16,0x17,0x18,0x19, 0x00};
  key_len = strlen(key4);
  char text4[] = {0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,
                  0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,
                  0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,
                  0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,
                  0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd,0xcd, 0x00
                 };
  text_len = strlen(text4);
  ms = micros();
  hashMD5.hmac_md5(text4, text_len, key4, key_len, digest);
  md5str = hashMD5.make_digest(digest,16);
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :0x0102030405060708090a0b0c0d0e0f10111213141516171819");
  Serial.println("KEY     :0xcd repeated 50 times");
  Serial.println("EXPECTED:697eaf0aca3a3aea3a75164746ffaa79");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  char key5[] = {0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x00};
  key_len = strlen(key5);
  char *text5 = "Test With Truncation";
  text_len = strlen(text5);
  ms = micros();
  hashMD5.hmac_md5(text5, text_len, key5, key_len, digest);
  md5str = hashMD5.make_digest(digest,16);
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :Test With Truncation");
  Serial.println("KEY     :0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c");
  Serial.println("EXPECTED:56461ef2342edc00f9bab995690efd4c");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  char key6[] = {0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x00
                };
  key_len = strlen(key6);
  char *text6 = "Test Using Larger Than Block-Size Key - Hash Key First";
  text_len = strlen(text6);
  ms = micros();
  hashMD5.hmac_md5(text6, text_len, key6, key_len, digest);
  md5str = hashMD5.make_digest(digest,16);
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :Test Using Larger Than Block-Size Key - Hash Key First");
  Serial.println("KEY     :0xaa repeated 80 times");
  Serial.println("EXPECTED:6b1ab7fe4bd7bf8f0b62e6ce61b9d0cd");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
  
  char key7[] = {0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                 0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x00
                };
  key_len = strlen(key7);
  char *text7 = "Test Using Larger Than Block-Size Key and Larger Than One Block-Size Data";
  text_len = strlen(text7);
  ms = micros();
  hashMD5.hmac_md5(text7, text_len, key7, key_len, digest);
  md5str = hashMD5.make_digest(digest,16);
  //generate the digest (hex encoding) of our hash
  Serial.print("done. (");
  ms = micros() - ms;
  Serial.print(ms);
  Serial.println(" micros)");
  Serial.println("PLAIN   :Test Using Larger Than Block-Size Key and Larger Than One Block-Size Data");
  Serial.println("KEY     :0xaa repeated 80 times");
  Serial.println("EXPECTED:6f630fad67cda0ee1fb1f562db3aa53e");
  Serial.print("RESULT  :");
  Serial.println(md5str);
  Serial.println();
}

void loop()
{
}
