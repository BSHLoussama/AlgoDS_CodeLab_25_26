# include <stdio.h>

struct Student 
{
    int id;
    char name[50];
    int age;
    float grade;
};

int main()
{

    struct Student students[50];

    int N;
    float sum = 0;

    do{
        printf("How many student do you have\n");
        scanf("%d", &N);

    }while (N < 1 && N >50);
    

    int i;
    for(i=0; i<N; i++)
    {
        printf("\nEnter information for student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%s", &students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Grade: ");
        scanf("%f", &students[i].grade);

        sum = sum + students[i].grade;

    }

    // Display students
    printf("\n--- Students List ---\n");
    for(i=0; i < N; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Grade: %.2f\n", students[i].grade);
    }

    float average = sum / N;
    printf("\nAverage Grade: %.2f\n", average);

    return 0;
}
