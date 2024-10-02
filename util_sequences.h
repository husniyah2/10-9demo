#ifndef UTIL_SEQUENCES_H
#define UTIL_SEQUENCES_H

int uniform_Samples (float x[], float min, float max, float step);
float linespace(float x[], int n, float min, float max);

int interpolate(int n, float x[], float y[]);
void cos_samples(int n, float x[], float y[], float amp, float freq, float phase);
void sin_samples(int n, float x[], float y[], float amp, float freq, float phase);
void damped_cos_samples(int n, float x[], float y[], float alpha, float w);

#endif // UTIL_SEQUENCES_H
