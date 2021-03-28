#ifndef TP_C_HW2_CONFIG_H
#define TP_C_HW2_CONFIG_H

typedef struct config_struct {
    int mode; // 1 is parallel, 0 is consistent
    int cpu_number;
    int array_size;
} config_t;

config_t* parse_config_file(char *filename);

#endif //TP_C_HW2_CONFIG_H
