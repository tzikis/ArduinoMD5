#ifndef MD5_config_h
#define MD5_config_h

#if  (defined(__linux) || defined(linux)) && !defined(__ARDUINO_X86__)

  #define MD5_LINUX
  
  #include <stdint.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
#else
  #include <Arduino.h>
#endif

#include <string.h>
#endif
