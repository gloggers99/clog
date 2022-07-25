#ifndef CLOG_H_
#define CLOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *prog_name;
    FILE *fd;
    char *log_file;
    int log_opts;
} CLogConfig;

/*
 * clog_init(char *prog_name, FILE *fd):
 *      initialize a CLogConfig configuration
 */
CLogConfig clog_init(char *prog_name, char *log_file, int log_opts) {
    CLogConfig log_conf = {
        .prog_name = prog_name,
        .fd = NULL,
        .log_file  = log_file == NULL ? (char *) "/dev/stderr" : log_file
    };

    return log_conf;
}

void log(CLogConfig conf, char *msg, ...) {
    va_list args;
    va_start(args, msg);

    /* file hasn't been opened or failed to open */
    conf.fd = fopen(conf.log_file, "w");

    time_t seconds;
    seconds = time(NULL);

    //fprintf(conf.fd, "[%s :: %ld] ", conf.prog_name, seconds);
    fprintf(conf.fd, "[%s] ", conf.prog_name);
    vfprintf(conf.fd, msg, args);
    fprintf(conf.fd, "\n");
    va_end(args);

    fclose(conf.fd);
}

#ifdef __cplusplus
}
#endif

#endif
