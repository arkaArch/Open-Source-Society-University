#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
  int length;
  int breadth;
} rect = {5, 6};

int main() {
  struct Rectangle *ptr = &rect;
  printf("Area of rectangle is: %d\n", rect.length * rect.breadth);
  printf("Area of rectangle using pointer: %d\n",
         (*ptr).length * (*ptr).breadth);
  // But we use arrow syntax(->) for ease of use, & it's also conventional
  printf("Area of rectangle using pointer: %d\n", ptr->length * ptr->breadth);

  // Now we can create a rectangle in heap like
  struct Rectangle *heap_rect =
      (struct Rectangle *)malloc(sizeof(struct Rectangle));
  // Assign the values into in
  heap_rect->length = 15;
  heap_rect->breadth = 12;
  printf("Area of rectangle created inside heap is: %d\n",
         heap_rect->breadth * heap_rect->length);
  free(heap_rect);
  return 0;
}