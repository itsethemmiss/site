#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5000

typedef struct {
    char *name;
    double *values;
} DataRecord;

DataRecord* create_data_record(const char *name) {
    DataRecord *record = malloc(sizeof(DataRecord));
    record->name = strdup(name);
    record->values = malloc(SIZE * sizeof(double));
    for (int i = 0; i < SIZE; i++) {
        record->values[i] = (i % 100) * 0.1;
    }
    return record;
}

void analyze_record(DataRecord *record) {
    for (int i = 0; i < SIZE; i++) {
        if (record->values[i] > 10.0) {
            record->values[i] = sqrt(record->values[i]);
        } else {
            record->values[i] = log(fabs(record->values[i]) + 1);
        }
    }
}

void print_record(const DataRecord *record) {
    printf("Analysis of %s:\n", record->name);
    for (int i = 0; i < 10; i++) { // Print only the first 10 values
        printf("Value[%d]: %.4f\n", i, record->values[i]);
    }
}

void free_record(DataRecord *record) {
    free(record->name);
    free(record->values);
    free(record);
}

int main() {
    DataRecord *record = create_data_record("Sample Data");
    analyze_record(record);
    print_record(record);
    free_record(record);
    return 0;
}
