float *centroid (float v1, float v2, float v3)
{
    float *ans = malloc (2 * sizeof(float));
    *ans = ((v1)+(v2)+(v3))/(3);

    return ans;
}


int main()
{
    struct triangle {
    float v1x, v2x, v3x , v1y, v2y, v3y;

    }triangle;

    struct answer
    {
        float *x, *y;
    }answer;

    printf ("Enter 1st coordinates:");
    scanf ("%f %f", &triangle.v1x, &triangle.v1y);

    printf ("Enter 2nd coordinates:");
    scanf ("%f %f", &triangle.v2x, &triangle.v2y);

    printf ("Enter 3rd coordinates:");
    scanf ("%f %f", &triangle.v3x, &triangle.v3y);

    answer.x = centroid(triangle.v1x, triangle.v2x, triangle.v3x);
    answer.y = centroid(triangle.v1y, triangle.v2y, triangle.v3y);

    printf ("Coordinates are %.2f, %.2f", *answer.x , *answer.y);

}
