
typedef void (*Pexception)(void);

#define ZERO_EXCEPTION_ID 0

static void zero_division();

void exceptionDispatcher(int exception) {
    Pexception exceptions[0x20]={0};
    exceptions[0] = &zero_division;
    Pexception exc = exceptions[exception];
    if (exc != 0)
        exc();
    return;
}

static void zero_division() {
    // Handler para manejar excepcíon
}