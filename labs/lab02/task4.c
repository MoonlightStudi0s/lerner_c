#include <stdio.h>

struct Rectangle {
    float width;
    float height;
};

float area_by_val(struct Rectangle r) {
    return r.width * r.height;
}

float perim_by_ptr(struct Rectangle *r) {
    return 2 * (r->width + r->height);
}

void main() {
    struct Rectangle rect;
    rect.width = 10.5;
    rect.height = 4.2;

    printf("Area: %.2f\n", area_by_val(rect));
    printf("Perimeter: %.2f\n", perim_by_ptr(&rect));
}