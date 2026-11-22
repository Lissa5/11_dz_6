#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct date {
    int d;
    int m;
    int y;
};

struct plant {
    char name[50];
    char vid[50];
    struct date posad;
    float height;
    int poliv;
};

typedef struct plant Plant;

void show(Plant p) {
    printf("%s (%s), посадка %02d.%02d.%04d, высота %.1f см, полив каждые %d дн.\n",
        p.name, p.vid, p.posad.d, p.posad.m, p.posad.y, p.height, p.poliv);
}

int main(void) {
    setlocale(LC_ALL, "Russian");

    Plant a[3];

    for (int i = 0; i < 3; i++) {
        printf("\nРастение %d\n", i + 1);

        printf("Название: ");
        scanf_s("%49s", a[i].name, (unsigned)sizeof(a[i].name));

        printf("Вид: ");
        scanf_s("%49s", a[i].vid, (unsigned)sizeof(a[i].vid));

        printf("Дата посадки (день месяц год): ");
        scanf_s("%d %d %d", &a[i].posad.d, &a[i].posad.m, &a[i].posad.y);

        printf("Высота (см): ");
        scanf_s("%f", &a[i].height);

        printf("Частота полива (дней): ");
        scanf_s("%d", &a[i].poliv);
    }

    float porog;
    printf("\nВведите пороговую высоту (см): ");
    scanf_s("%f", &porog);

    printf("\nВсе растения:\n");
    for (int i = 0; i < 3; i++) {
        show(a[i]);
    }

    printf("\nРастения с поливом не реже 1 раза в 5 дней и высотой выше %.1f см:\n", porog);
    int f = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i].poliv <= 5 && a[i].height > porog) {
            show(a[i]);
            f = 1;
        }
    }
    if (!f) {
        printf("Нет таких растений.\n");
    }

    system("pause");
    return 0;
}