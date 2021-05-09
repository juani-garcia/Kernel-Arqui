#include <clock.h>

#define SECONDS 0x00
#define MINUTES 0x02
#define HOURS 0x04
#define DAYS 0x07
#define MONTH 0x08
#define YEAR 0x09
#define TIME_ZONE -3


unsigned char accessClock(unsigned char mode);
static unsigned int decode(unsigned char time);

unsigned int seconds()
{
    return decode(accessClock(SECONDS));
}

unsigned int minutes()
{
    return decode(accessClock(MINUTES));
}

unsigned int hours()
{
    return decode(accessClock(HOURS)) + TIME_ZONE;
}

unsigned int day(){
    return decode(accessClock(DAYS));
}

unsigned int month(){
    return decode(accessClock(MONTH));
}

unsigned int year()
{
    return decode(accessClock(YEAR));
}

static unsigned int decode(unsigned char time)
{
    return (time >> 4) * 10 + (time & 0x0F);
}