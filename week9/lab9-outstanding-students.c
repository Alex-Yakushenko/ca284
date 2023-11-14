#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

struct Student {
    char *name;
    char *prog;
    float grade;
};

Student addStudent(char *argv[], int *index);
float avg(Student * s, int * num);
void outstanding(Student *s, int * num, float * avg);

int main(int argc, char*argv[])
{   
    Student *students = (Student*)calloc(2, sizeof(Student));
    int index = 1;
    for (int i = 0; i < 2; i++) {
        students[i] = addStudent(argv, &index);
    }
    int student_num = (argc - 1) / 3;
    if (student_num > 2) {
        Student *tmp = realloc(students, student_num*sizeof(Student));
        students = tmp;
        for (int i = 2; i < student_num; i++) {
            students[i] = addStudent(argv, &index);
        }
    }
    float average_grade = avg(students, &student_num);
    outstanding(students, &student_num, &average_grade);
    printf("Average grade: %.2f\n", average_grade);

    free(students);
    students = NULL;
    return 0;
}

Student addStudent(char *argv[], int *index)
{
    Student c;
    c.name = argv[*index];
    c.prog = argv[*index + 1];
    c.grade = atof(argv[*index + 2]);
    *index += 3;
    return c;
}

float avg(Student * s, int * num)
{
    float sum = 0;
    for (int i = 0; i < *num; i++) {
        sum += s[i].grade;
    }
    return sum / *num;
}

void outstanding(Student *s, int * num, float * avg)
{
    for (int i = 0; i < *num; i++) {
        if (strcmp(s[i].prog, "CSCE") == 0 && s[i].grade > *avg) {
            printf("%s, %.2f\n", s[i].name, s[i].grade);
        }
    }
}
