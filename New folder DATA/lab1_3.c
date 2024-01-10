
#include <stdio.h>
int *GetSet( int * ) ;

int main() {
    int *data, num ;
    data = GetSet( &num ) ;
    return 0 ;
}//end function

int *GetSet(int *num) {
    int *data;
    printf("Get number of members: ");
    scanf("%d", num);
    data = (int *)malloc(*num * sizeof(int));

    for (int i = 0; i < *num; ++i) {
        printf("Membership fee %d: ", i + 1);
        scanf("%d", &data[i]);
    }

    printf("Number of members :%d", *num);
    for (int i = 0; i < *num; ++i) {
        printf("\n");
        printf("member %d: %d", i + 1, data[i]);
    }
    return *data;
}
