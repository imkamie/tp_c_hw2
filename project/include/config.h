#ifndef PROJECT_INCLUDE_CONFIG_H_
#define PROJECT_INCLUDE_CONFIG_H_

typedef struct config_struct {
    int mode;  // 1 is parallel, 0 is consistent
    int cpu_number;
    int array_size;
} config_t;

config_t* parse_config_file(char *filename);

#endif  // PROJECT_INCLUDE_CONFIG_H_
