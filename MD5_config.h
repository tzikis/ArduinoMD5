#ifndef MD5_config_h
#define MD5_config_h

#define HMAC_IPAD 0x36
#define HMAC_OPAD 0x5c
#define BLOCK_SIZE 16

#if  (defined(__linux) || defined(linux)) && !defined(__ARDUINO_X86__)

  #define MD5_LINUX
  
  #include <stdint.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sys/time.h>
  #include <unistd.h>
#else
  #include <Arduino.h>
#endif

#include <string.h>
#endif
