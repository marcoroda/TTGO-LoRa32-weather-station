
#include "Arduino.h"
#include "lmic.h"

/*  This EUI must be in little-endian format, so least-significant-byte
    first. When copying an EUI from ttnctl output, this means to reverse
    the bytes.
*/

// Copy the value from Device EUI from the TTN console in LSB mode.
static const u1_t PROGMEM DEVEUI[8]= { }; // Device EUI, hex, lsb

// Copy the value from Application EUI from the TTN console in LSB mode
static const u1_t PROGMEM APPEUI[8]= { ; // Application EUI, hex, lsb

/*  This key should be in big endian format (or, since it is not really a
    number but a block of memory, endianness does not really apply). In
    practice, a key taken from ttnctl can be copied as-is. Anyway its in MSB mode.
*/
static const u1_t PROGMEM APPKEY[16] = { }; // App Key, hex, msb

