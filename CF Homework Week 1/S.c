#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

inline static void inputPoint(Point *point) {
    scanf("%d %d", &point->x, &point->y);
}

inline static float distance(const Point *p1, const Point *p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

typedef struct {
    Point *points;
    int size;
} Vector;

inline static void initVector(Vector *vector) {
    vector->points = NULL;
    vector->size = 0;
}

inline static void pushBack(Vector *vector, const Point *point) {
    vector->points = (Point *)realloc(vector->points, ++vector->size * sizeof(Point));
    vector->points[vector->size - 1] = *point;
}

inline static void displayVector(const Vector *vector) {
    for (int i = 0; i < vector->size; ++i) {
        printf("%d %d\n", vector->points[i].x, vector->points[i].y);
    }
}

inline static void freeVector(Vector *vector) {
    free(vector->points);
}

int main() {
    Point O;
    inputPoint(&O);

    int R0, R1;
    scanf("%d %d", &R0, &R1);

    Vector points0, points1, points2;
    initVector(&points0);
    initVector(&points1);
    initVector(&points2);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        Point point;
        inputPoint(&point);

        float d = distance(&O, &point);
        if (d < R0) {
            pushBack(&points0, &point);
        } else if (d < R1) {
            pushBack(&points1, &point);
        } else {
            pushBack(&points2, &point);
        }
    }

    printf("F0 %d\n", points0.size);
    displayVector(&points0);

    printf("F1 %d\n", points1.size);
    displayVector(&points1);

    printf("F2 %d\n", points2.size);
    displayVector(&points2);
}