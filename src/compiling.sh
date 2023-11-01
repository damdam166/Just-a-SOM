#!/bin/bash


cc -std=c99 -Wall -o som.out main.c functions/functions.c functions/functions.h kohonen_algorithm/kohonen_som.c kohonen_algorithm/kohonen_som.h -lm
