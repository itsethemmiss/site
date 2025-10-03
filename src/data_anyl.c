#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10000
#define THRESHOLD 0.5

typedef struct {
    double *data;
    size_t size;
} DataSet;

DataSet create_data_set(size_t size) {
    DataSet ds;
    ds.data = malloc(size * sizeof(double));
    ds.size = size;
    for (size_t i = 0; i < size; i++) {
        ds.data[i] = sin(i) * cos(i);
    }
    return ds;
}

void analyze_data(DataSet *ds) {
    for (size_t i = 0; i < ds->size; i++) {
        if (ds->data[i] > THRESHOLD) {
            ds->data[i] = sqrt(ds->data[i]);
        } else {
            ds->data[i] = log(fabs(ds->data[i]) + 1);
        }
    }
}

void print_analysis(DataSet *ds) {
    for (size_t i = 0; i < ds->size; i++) {
        printf("Data[%zu]: %.4f\n", i, ds->data[i]);
    }
}

int main() {
    DataSet ds = create_data_set(SIZE);
    analyze_data(&ds);
    print_analysis(&ds);
    free(ds.data);
    return 0;
}
