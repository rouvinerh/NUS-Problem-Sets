void *compute_AM_GM (float a, float b, float c, float *mean, float *geom)
{
    *mean = (a+b+c)/3;
    *geom = cbrt(a*b*c);

}

int main(void)
{
    float a,b,c;
    float mean;
    float geom;

    printf ("Enter 3 positive integers:");
    scanf ("%f %f %f", &a, &b, &c);
    compute_AM_GM(a,b,c,&mean,&geom);
    printf("Arithmetic Mean: %.2f\n", mean);
    printf("Geometric Mean: %.2f", geom);

}

