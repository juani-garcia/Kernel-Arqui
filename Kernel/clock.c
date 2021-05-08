#include <clock.h>

#define WRITE_TO 0x70
#define READ_FROM 0x71
#define SECONDS 0x00
#define MINUTES 0x02
#define HOURS 0x04
#define YEAR 0x09

unsigned int accessClock(unsigned char mode);
unsigned int seconds()
{
    return accessClock(SECONDS);
}

unsigned int minutes()
{
    return accessClock(MINUTES);
}

unsigned int hours()
{
    return accessClock(HOURS);
}

unsigned int year()
{
    return accessClock(YEAR);
}