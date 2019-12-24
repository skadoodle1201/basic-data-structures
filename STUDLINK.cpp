#include <stdio.h>
#include <stdlib.h>
                       
struct studentNode {                                      
   char name;
   int age;
   int rollno;
   struct studentNode *nextPtr;
};                       
typedef struct studentNode StudentNode;
typedef StudentNode *StudentNodePtr;
/* prototypes */
void insert( StudentNodePtr *headOfList,  char name, int age, double balance );
char deletenode( StudentNodePtr  *headOfList, char sname  );
int isEmpty( StudentNodePtr sPtr );
void printList( StudentNodePtr currentPtr );
void instructions( void );
int main( void )
{ 
   StudentNodePtr startPtr = NULL;
   int choice;
   char nm;  
   int ag;
   double bln;
   instructions(); 
   printf( "? " );
   scanf( "%d", &choice );
 
   while ( choice != 3 ) { 
      switch ( choice ) { 
         case 1:
            printf( "Enter a name: " );
            scanf( "\n%s", &nm );
            printf( "Enter age: " );
            scanf( "\n%d", &ag );
            printf( "Enter GPA : " );
            scanf( "\n%lf", &bln );
            insert( &startPtr, nm, ag, bln ); 
            printList( startPtr );
            break;
         case 2: 
           
            if ( !isEmpty( startPtr ) ) { 
               printf( "Enter name to be deleted: " );
               scanf( "\n%s", &nm );
               if ( deletenode( &startPtr, nm ) ) { 
                  printf( "%s deleted.\n", nm );
                  printList( startPtr );
               } 
               else {
                  printf( "%s not found.\n\n", nm );
               }
            }
            else {
               printf( "List is empty.\n\n" );
            } 
            break;
         default:
            printf( "Invalid choice.\n\n" );
            instructions();
            break;
      
      } 
      printf( "? " );
      scanf( "%d", &choice );
   } 
   printf( "End of run.\n" );
   
   return 0; 
} 
void instructions( void )
{ 
   printf( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.\n" );
} 
void insert( StudentNodePtr *headOfList,  char name, int age, double balance )
{ 
   StudentNodePtr newPtr;      
   StudentNodePtr previousPtr; 
   StudentNodePtr currentPtr;  
   newPtr = ( StudentNode * ) malloc( sizeof( StudentNode ) ); 
   if ( newPtr != NULL ) { 
      newPtr->name = name;
      newPtr->age = age;
      newPtr->balance = balance;
      newPtr->nextPtr = NULL; 
      previousPtr = NULL;
      currentPtr = *headOfList;
            
      if ( currentPtr != NULL ) {
         previousPtr = currentPtr;          
         currentPtr = currentPtr->nextPtr; 
      } 
    
      if ( previousPtr == NULL ) { 
         newPtr->nextPtr = *headOfList;
         *headOfList = newPtr;
      } 
      else { 
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      }
   
   }
   else {
      printf( "%s not inserted. No memory available.\n", name);
   } 
  } 
char deletenode( StudentNodePtr  *headOfList, char sname  )
{ 
   StudentNodePtr previousPtr; 
   StudentNodePtr currentPtr;  
   StudentNodePtr tempPtr;     
 
   if ( sname == ( *headOfList )->name ) { 
      tempPtr = *headOfList; 
      *headOfList = ( *headOfList )->nextPtr; 
      free( tempPtr ); 
      tempPtr = *headOfList; 
      *headOfList = ( *headOfList )->nextPtr; 
      free( tempPtr );
      return sname;
   } 
   else { 
      previousPtr = *headOfList;
      currentPtr = ( *headOfList )->nextPtr;
      
      while ( currentPtr != NULL && currentPtr->name != sname ) { 
         previousPtr = currentPtr;         
         currentPtr = currentPtr->nextPtr; 
      } 
      
      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return sname;
      } 
     
   } 
   return '\0';
  } 
  int isEmpty( StudentNodePtr sPtr )
  { 
   return sPtr == NULL;
  } 
  
  void printList( StudentNodePtr currentPtr )
  { 
   
   if ( currentPtr == NULL ) {
      printf( "List is empty.\n\n" );
   } 
   else { 
      printf( "The list is:\n" );
      while ( currentPtr != NULL ) { 
         printf( "%s --> ", currentPtr->name);
         currentPtr = currentPtr->nextPtr;   
      } 
      printf( "NULL\n\n" );
   } 
  }