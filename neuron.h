#ifndef _NEURON_H_
#define _NEURON_H_

#include <stdio.h>
#include <stdint.h>

double analyze(double input[]);
void think_train(double input[][3], double output[]);
void train(double training_set_inputs[][3], double training_set_outputs[], uint32_t n);
void get_result();

#endif

