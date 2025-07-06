#include <stdio.h>

void print_move(char *tower_A, char *tower_B) {
  printf("Move from %s to %s. \n", tower_A, tower_B);
}

void tower_of_hanoi(int no_of_disks, char *tower_A, char *tower_B,
                    char *tower_T) {
  if (no_of_disks == 1)
    print_move(tower_A, tower_B);
  else {
    // Move (n-1) disks from tower_A to tower_T
    tower_of_hanoi((no_of_disks - 1), tower_A, tower_T, tower_B);
    // Move remaining disk(n'th disk) from tower_A to tower_B
    tower_of_hanoi(1, tower_A, tower_B, tower_T);
    // // Move (n-1) disks from tower_T to tower_B
    tower_of_hanoi((no_of_disks - 1), tower_T, tower_B, tower_A);
  }
}

int main() {
  tower_of_hanoi(3, "tower_a", "tower_b", "tower_temp");
  return 0;
}

/* Output:

Move from tower_a to tower_b.
Move from tower_a to tower_temp.
Move from tower_b to tower_temp.
Move from tower_a to tower_b.
Move from tower_temp to tower_a.
Move from tower_temp to tower_b.
Move from tower_a to tower_b.

*/