#include <stdio.h>

void month (int m, int y) {
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("There are 31 days in this month");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("There are 30 days in this month");
            break;
        case 2:
            if ( (y % 4 == 0 && y % 100 != 0 ) || y % 400 == 0 ) printf("There are 29 days in this month");
            else printf("There are 28 days in this month");
        default:
            printf("invalid month");
            break;
    }
    printf("\n");
    if ( (y % 4 == 0 && y % 100 != 0 ) || y % 400 == 0 ) printf("%d is a leap year", y);
    else printf("%d is not a leap year", y);
}

int cnt ( int d, int m, int y) {
    int sum = 0;
    for ( int i = 1; i < m; i++ ) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                sum += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                sum += 30;
                break;
            case 2:
                if ( (y % 4 == 0 && y % 100 != 0 ) || y % 400 == 0 ) sum += 29;
                else sum += 28;
                break;

        }
    }
    return (d + sum);

}

void thepreday (int *d, int *m, int *y) {
    int lastday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ( *d > 01 ) {
        (*d)--;
    } else if ( *d == 01 && *m > 01 ) {
        if ( ((*y % 4 == 0 && *y % 100 != 0 ) || *y % 400 == 0) && *m == 03 ) {
            *d = 29;
            (*m)--;
        } else {
            (*m)--;
            (*d) = lastday[*m];
        }
    } else if ( *d == 01 && *m == 01) {
        *d = 31;
        *m = 12;
        (*y)--;
    }
}

void thenextday (int *d, int *m, int *y) {
    int lastday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ( *d < lastday[*m] || ( *m == 02 && *d < 29)) {
        (*d)++;
    } else if ( *d == lastday[*m] ) {
        if ( *m < 12 ) {
            *d = 01;
            (*m)++;
        } else {
            *d = 01;
            *m = 01;
            (*y)++;
        }
    } else if ( *d == 29 && *m == 02 ) {
        *d = 01;
        *m = 03;
    }
}

int main () {
    int q, w, e;
    printf("Enter a day ( dd ): ");
    scanf("%d", &q);
    printf("Enter a month in number ( mm ): ");
    scanf("%d", &w);
    printf("Enter a year ( yyyy ): ");
    scanf("%d", &e);
    month (w,e);
    printf("\n---------------------------------------\n");
    printf("%d days have passed since the beginning of %04d", cnt(q, w, e), e);
    printf("\n---------------------------------------\n");
    int a = q, b = w, c = e;
    thepreday(&a, &b, &c);
    printf("The previous day is: %02d/%02d/%04d", a, b, c);
    printf("\n---------------------------------------\n");
    int j = q, k = w, l = e;
    thenextday(&j, &k, &l);
    printf("The day after is: %02d/%02d/%04d", j, k, l);
}



