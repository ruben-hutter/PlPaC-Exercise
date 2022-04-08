#ifndef pyramid_h
#define pyramid_h

typedef struct {
	int base;
	int height;
} PYRAMID;

PYRAMID construct_pyramid(int base, int height);

double calculate(PYRAMID &p);

#endif //was missing
