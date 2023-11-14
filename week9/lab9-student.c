#include <stdio.h>
#include <stdlib.h>

typedef struct Student Student;

struct Student {
    char *name;
    char *prog;
    float grade;
};

Student addStudent(char *argv[], int *index);
void printStudents(Student * s, int *num);

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
    printStudents(students, &student_num);

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

void printStudents(Student * s, int * num)
{
    for (int i = 0; i < *num; i++) {
        printf("%s, %s, %.2f\n", s[i].name, s[i].prog, s[i].grade);
    }
}

