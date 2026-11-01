 #include <stdlib.h>

 int main(int argc, char *argv[]){
     int ipos = 0, ival;
       int *iarray = (int *) malloc(10*sizeof(int));
     if (iarray == NULL) {
         return 1;
     }
       if (argc == 2) ival = atoi(argv[1]);
       if (argc != 2)
           return 1;
       for (int i = 0; i<10; i++){ iarray[i] = ipos; }
       for (int i = 0; i<10; i++){
             if (ival == iarray[i]) ipos = i;
          }
     free(iarray);
     }