//
//  main.c
//  emulator8080
//
//  Created by Paweł Mazurkiewicz on 02/07/16.
//  Copyright © 2016 Paweł Mazurkiewicz. All rights reserved.
//

#include <stdio.h>
#include "cpu.h"
#include "main.h"

void read_bin_into_mem(cpu_state *state, char *filename, uint32_t offset){
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        printf("Error: Could not open this file: %s\n", filename);
        exit(-1);
    }
    fseek(file, 0L, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0L, SEEK_SET);
    
    uint8_t *buffer = &state->memory[offset];
    fread(buffer, fsize, 1, file);
    fclose(file);
}

int cmd_processor_loop(const char* bin){
    uint8_t terminated = 0;
    //cpu_state* state = init8080(0x10000); //for now 16K is default
    while (!terminated){
        terminated = 1; //PLACEHOLDER
        //terminated = emulate8080op(state);
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    printf(
    "%c[1m**************************************************%c[0m\n"
    "%sIntel 8080 Emulator (boboemu) by Paweł Mazurkiewicz\n"
    "Version: %s\n%s"
    "%c[1m**************************************************%c[0m\n",
    ESC, ESC, KGRN, VERSION, KNRM, ESC, ESC);
    if (argv[1] != NULL) return cmd_processor_loop(argv[1]);
    else return cmd_processor_loop(NULL);
}
