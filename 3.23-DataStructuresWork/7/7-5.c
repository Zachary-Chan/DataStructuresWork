#include <stdio.h>

typedef struct {
    int ID;
    char name[20];
    float grade[3];
}Stu;

void print(Stu student){
    printf("%d %s ", student.ID, student.name);

    for(int i = 0; i < 2; i++){
        printf("%.1f ", student.grade[i]);
    }
    printf("%.1f\n", student.grade[2]);
}

int main(){
    int num;
    scanf("%d", &num);
    Stu student[5];

    for(int i = 0; i < 5; i++){
        scanf("%d%s", &student[i].ID, student[i].name);

        for(int j = 0; j < 3; j++){
            scanf("%f", &student[i].grade[j]);
        }
    }

    for(int i = 0; i < 5; i++){
        print(student[i]);
    }
}
