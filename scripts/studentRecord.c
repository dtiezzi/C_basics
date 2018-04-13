#include <stdio.h>

typedef struct {
	int number;
} Room;

typedef struct {
	char name[40];
	char id[5];
} course;

typedef struct {
	char name[40];
	int id;
	float marks;
	Room n;
	course cn;
} student;


void printStruct(student *st);

void main(void) {

	student s;
	printf("Type sudent informations:\n");
	printf("\nName:\n");
	scanf("%[^\n]s", &s.name);
	printf("\nID\n");
	scanf("%d", &s.id);
	printf("\nGrade:\n");
	scanf("%f", &s.marks);
	printf("\nRoom:\n");
	scanf("%d", &s.n.number);
	printf("\nCourse Name:\n");
	scanf("%[^\n]s", &s.cn.name);
	printf("\nCourse ID:\n");
	scanf("%s", &s.cn.id);
	printStruct(&s);
}

void printStruct(student *st) {
	printf("Displaying Information:\n");

	    printf("Name: ");
	    puts(st->name);
	    printf("ID: %d\n", st->id);
	    printf("Marks: %.1f\n", st->marks);
	    printf("Room#: %d\n", st->n.number);
	    printf("Course: %s\n", st->cn.name);
	    printf("COurse ID: %s\n", st->cn.id);
}