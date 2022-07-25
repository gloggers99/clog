# CLog: fast and easy C logging
### basic stderr runtime log:

``` c
#include "clog.h"

CLogConfig g_logConf;

int main(int argc, char *argv[]) {
    /* setting 2nd argument (file path) to NULL outputs to stderr,
       multiple applications can log to the same file. */
    g_logConf = clog_init(argv[0], NULL);

    /* will output:
     *  "[*program name*] *log message*"
     */
    log(g_logConf, "Hello, world!");

    return 0;
}
```
## features:
- [X] basic logging
- [X] stderr/stdout support
- [X] C++ compatibility
- [ ] multiple fd's at once
- [ ] real configurability
## why use CLog:
you shold consider using CLog if:
- you are locked into using C
- you want a single file logging implementation
- you want to use a logger with a very permissive license
