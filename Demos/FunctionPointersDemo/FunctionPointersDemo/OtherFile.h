#pragma once

typedef void(*paramFunc)(int, int);

void runThing(paramFunc func, int num1, int num2);