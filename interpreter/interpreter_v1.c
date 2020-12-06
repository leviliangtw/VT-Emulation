// interpreter_v1.c
#include "interpreter_v1.h"

void interpreter_v1(char *buf, int size, reg *myreg){
    myreg->rIP = buf;
    char inst = *(myreg->rIP);
    int opcode = inst;

    while (inst){
        switch(opcode) {
            case 1:
                HandleCLRA(myreg);
                break;
            case 2:
                HandleINC3A(myreg);
                break;
            case 3:
                HandleDECA(myreg);
                break;
            case 4:
                HandleSETL(myreg);
                break;
            case 5:
                HandleBACK7(myreg);
                break;
            default:
                break;
        }
        inst = *(myreg->rIP);
        opcode = inst;
    }
}

void HandleHALT(reg *myreg){
    // printf("opcode 0: stop execution\n");
    // exit(0);
}

void HandleCLRA(reg *myreg){
    // printf("opcode 1: set content of register A to 0\n");
    struct routines rts = {{&HandleHALT, &HandleCLRA, &HandleINC3A, &HandleDECA, &HandleSETL, &HandleBACK7}};
    myreg->rIP += 1;
    // operation
    myreg->rA = 0;
    // operation
    // printf("    myreg address: %p\n", myreg);
    // printf("    myreg.rIP address: %p\n", myreg->rIP);
    // printf("    myreg.rIP's target value: %d\n", *myreg->rIP);
    // printf("    myreg.rA: %d\n", myreg->rA);
    // printf("    myreg.rL: %d\n", myreg->rL);
    // printf("    TPC: %d\n", TPC);
    // printf("    SPC: %d\n", SPC);
    // rts.handles[*myreg->rIP](myreg);
}

void HandleINC3A(reg *myreg){
    // printf("opcode 2: increment register A by 3\n");
    struct routines rts = {{&HandleHALT, &HandleCLRA, &HandleINC3A, &HandleDECA, &HandleSETL, &HandleBACK7}};
    myreg->rIP += 1;
    // operation
    myreg->rA += 3;
    // operation
    // printf("    myreg address: %p\n", myreg);
    // printf("    myreg.rIP address: %p\n", myreg->rIP);
    // printf("    myreg.rIP's target value: %d\n", *myreg->rIP);
    // printf("    myreg.rA: %d\n", myreg->rA);
    // printf("    myreg.rL: %d\n", myreg->rL);
    // printf("    TPC: %d\n", TPC);
    // printf("    SPC: %d\n", SPC);
    // rts.handles[*myreg->rIP](myreg);
}

void HandleDECA(reg *myreg){
    // printf("opcode 3: decrement register A by 1\n");
    struct routines rts = {{&HandleHALT, &HandleCLRA, &HandleINC3A, &HandleDECA, &HandleSETL, &HandleBACK7}};
    myreg->rIP += 1;
    // operation
    myreg->rA -=1;
    // operation
    // printf("    myreg address: %p\n", myreg);
    // printf("    myreg.rIP address: %p\n", myreg->rIP);
    // printf("    myreg.rIP's target value: %d\n", *myreg->rIP);
    // printf("    myreg.rA: %d\n", myreg->rA);
    // printf("    myreg.rL: %d\n", myreg->rL);
    // printf("    TPC: %d\n", TPC);
    // printf("    SPC: %d\n", SPC);
    // rts.handles[*myreg->rIP](myreg);
}

void HandleSETL(reg *myreg){
    // printf("opcode 4: copy value of register A to L\n");
    struct routines rts = {{&HandleHALT, &HandleCLRA, &HandleINC3A, &HandleDECA, &HandleSETL, &HandleBACK7}};
    myreg->rIP += 1;
    // operation
    myreg->rL = myreg->rA;
    // operation
    // printf("    myreg address: %p\n", myreg);
    // printf("    myreg.rIP address: %p\n", myreg->rIP);
    // printf("    myreg.rIP's target value: %d\n", *myreg->rIP);
    // printf("    myreg.rA: %d\n", myreg->rA);
    // printf("    myreg.rL: %d\n", myreg->rL);
    // printf("    TPC: %d\n", TPC);
    // printf("    SPC: %d\n", SPC);
    // rts.handles[*myreg->rIP](myreg);
}

void HandleBACK7(reg *myreg){
    // printf("opcode 5: decrement L; if value of L is positive, jump back by 7instructions (i.e. loop body is6one-byte instructions and the BACK7itself). Otherwise fall through to next instruction\n");
    // printf("    After interpreter, myreg: %d\n", myreg);
    // printf("    After interpreter, myreg.rIP: %d\n", *myreg->rIP);
    // printf("    After interpreter, myreg.rA: %d\n", myreg->rA);
    // printf("    After interpreter, myreg.rL: %d\n", myreg->rL);
    struct routines rts = {{&HandleHALT, &HandleCLRA, &HandleINC3A, &HandleDECA, &HandleSETL, &HandleBACK7}};
    if(myreg->rL <= 0) {
        myreg->rIP += 7;
        // operation
        myreg->rL += 1;
        // operation
    }
    myreg->rIP -= 6;
    // operation
    myreg->rL -= 1;
    // operation
    // printf("    myreg address: %p\n", myreg);
    // printf("    myreg.rIP address: %p\n", myreg->rIP);
    // printf("    myreg.rIP's target value: %d\n", *myreg->rIP);
    // printf("    myreg.rA: %d\n", myreg->rA);
    // printf("    myreg.rL: %d\n", myreg->rL);
    // printf("    TPC: %d\n", TPC);
    // printf("    SPC: %d\n", SPC);
    // rts.handles[*myreg->rIP](myreg);
}