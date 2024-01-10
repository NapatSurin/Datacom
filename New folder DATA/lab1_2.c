
#include <stdio.h>
#include <string.h>

void GetSet( int [], int * ) ;

int main() {
    int *data, num ;
    GetSet( &data, &num ) ;
    return 0 ;
}//end function
void GetSet(int data[], int *num) {
    printf("Get number of members: ");
    scanf("%d", num);

    for (int i = 0; i < *num; ++i) {
        printf("Membership fee %d: ", i + 1);
        scanf("%d", &data[i]);
    }
    
    printf("Number of members :%d", *num);
    for (int i = 0; i < *num; ++i) {
        printf("\n");
        printf("member %d: ",data[i]);
    }
}
