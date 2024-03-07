"#include <stdio.h>
#include <string.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
 struct studentNode *back ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode(struct studentNode **walk , char n[] , int a , char s , float g);
void InsNode (struct studentNode *walk , char n[] , int a , char s , float g);
void GoBack( struct studentNode **walk );
void DelNode (struct studentNode **walk);


int main() {
 struct studentNode *start, *now ;
 start = NULL ;
 now = AddNode( &start, ""one"", 6, 'M', 3.11 ) ; ShowAll( start ) ;
 now = AddNode( &start, ""two"", 8, 'F', 3.22 ) ; ShowAll( start ) ;
 InsNode( now, ""three"", 10, 'M', 3.33 ) ; ShowAll( start ) ;
 InsNode( now, ""four"", 12, 'F', 3.44 ) ; ShowAll( start ) ;
 GoBack( &now ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 return 0 ;
}//end function


void ShowAll( struct studentNode *walk ) {
 while( walk != NULL ) {
  printf( ""%s "", walk->name ) ;
  walk = walk->next ;
 }//end while
 printf( ""\n__________________________________________\n"" ) ;
}//end function


struct studentNode *AddNode(struct studentNode **walk , char n[] , int a , char s , float g){
	struct studentNode *temp ;
	
	while(*walk != NULL){
		temp = *walk;
		walk = &(*walk)->next;
	}
	
	*walk = new struct studentNode;
	strcpy( (*walk)->name, n );
	(*walk)->age = a ;
	(*walk)->sex = s ;
	(*walk)->gpa = g ;	
	(*walk)->next = NULL ;
	(*walk)->back = temp;
	return *walk;
}//end function


void InsNode (struct studentNode *walk , char n[] , int a , char s , float g){
		walk->back->next = new struct studentNode ;
		strcpy(walk->back->next->name, n );
		walk->back->next->age = a ;
		walk->back->next->sex = s ;
		walk->back->next->gpa = g ;
		walk->back->next->next = walk;
		walk->back->next->back = walk->back;
		walk->back = walk->back->next;
	
	}
//end function


void GoBack( struct studentNode **walk ){
	if((*walk)->back != NULL){
		*walk = (*walk)->back;
	}
}//end function


void DelNode (struct studentNode **walk){
	struct studentNode *temp = NULL;
	if((*walk)->next != NULL){
		(*walk)->next->back = (*walk)->back;
		temp = (*walk)->next;
	}else{
		temp = (*walk)->back;
	}
	delete *walk;
	*walk = temp;
	(*walk)->next = NULL;
}//end function
"
