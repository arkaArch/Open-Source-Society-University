/* Here we can sort students by their name, date of birth and marks */
#include <stdio.h>
#include <string.h>
#define STUDENT_NUMBER 3

struct date {
  int day;
  int month;
  int year;
};

struct student {
  char name[30];
  struct date dob;
  int marks;
};

void display_std(struct student std[]) {
  printf("Name \t\t\t DOB \t\t Marks \n");
  printf("--------------------------------------------------\n");
  for (int i = 0; i < STUDENT_NUMBER; i++) {
    printf("%s \t\t", std[i].name);
    printf("%d/%d/%d \t", std[i].dob.day, std[i].dob.month, std[i].dob.year);
    printf("%d", std[i].marks);
    printf("\n");
  }
  printf("\n\n");
}

void sort_by_name(struct student std[]) {
  struct student temp;
  for (int i = 0; i < STUDENT_NUMBER - 1; i++) {
    for (int j = i + 1; j < STUDENT_NUMBER; j++) {
      if (strcmp(std[i].name, std[j].name) > 0) {
        temp = std[i];
        std[i] = std[j];
        std[j] = temp;
      }
    }
  }
};

int compare_date(struct date date1, struct date date2) {
  if (date1.year > date2.year)
    return -1;
  if (date1.year < date2.year)
    return 1;
  if (date1.month > date2.month)
    return 1;
  if (date1.month < date2.month)
    return -1;
  if (date1.day > date2.day)
    return 1;
  if (date1.day < date2.day)
    return -1;
  return 0;
};

void sort_by_dob(struct student std[]) {
  struct student temp;
  for (int i = 0; i < STUDENT_NUMBER - 1; i++) {
    for (int j = i + 1; j < STUDENT_NUMBER; j++) {
      if (compare_date(std[i].dob, std[j].dob) == 1) {
        temp = std[i];
        std[i] = std[j];
        std[j] = temp;
      }
    }
  }
};

void sort_by_marks(struct student std[]) {
  struct student temp;
  for (int i = 0; i < STUDENT_NUMBER - 1; i++) {
    for (int j = i + 1; j < STUDENT_NUMBER; j++) {
      if (std[i].marks > std[j].marks) {
        temp = std[i];
        std[i] = std[j];
        std[j] = temp;
      }
    }
  }
};

/* Give usr the available sort types */
void sort(struct student std[], int choice) {
  switch (choice) {
  case 1:
    printf("Sort by name in alphabatical order:\n");
    sort_by_name(std);
    break;
  case 2:
    printf("Sort by dob in assending order:\n");
    sort_by_dob(std);
    break;
  case 3:
    printf("Sort by number in assending order:\n");
    sort_by_marks(std);
    break;
  default:
    printf("Wrong input. \n");
  }
  display_std(std);
}

int main() {
  /* Creating 3 student array
  We can take those as inputs */
  struct student stds[STUDENT_NUMBER] = {
      {.name = "Arka Kar",
       .dob = {.day = 3, .month = 7, .year = 1990},
       .marks = 234},
      {.name = "Chaitali Saha",
       .dob = {.day = 18, .month = 3, .year = 1994},
       .marks = 324},
      {.name = "Narendra Ghosh",
       .dob = {.day = 12, .month = 12, .year = 1996},
       .marks = 312}};

  sort(stds, 1);
  sort(stds, 2);
  sort(stds, 3);

  return 0;
}
