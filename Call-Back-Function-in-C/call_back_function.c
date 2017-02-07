#include <stdio.h>
#include <stdlib.h>

/****************************************
 * structure for function pointers 
 ***************************************/
typedef struct _OP {
    float (*p_add)(float, float); 
    float (*p_sub)(float, float); 
    float (*p_mul)(float, float); 
    float (*p_div)(float, float); 
} OP; 

/****************************************
 * functions for '+', '-', '*', '\' 
 ***************************************/
float ADD(float a, float b) 
{
    return a + b;
}

float SUB(float a, float b) 
{
    return a - b;
}

float MUL(float a, float b) 
{
    return a * b;
}

float DIV(float a, float b) 
{
    return a / b;
}

/****************************************
 * initialize function pointers 
 ***************************************/
void init_op(OP *op)
{
    op->p_add = ADD;
    op->p_sub = SUB;
    op->p_mul = &MUL;
    op->p_div = &DIV;
}

/****************************************
 * library function *
 ***************************************/
float add_sub_mul_div(float a, float b, float (*op_func)(float, float))
{
    return (*op_func)(a, b);
}

int main(int argc, char *argv[]) 
{
    OP *op = (OP *)malloc(sizeof(OP)); 
    init_op(op);
    
    /* use function pointer to call functions */ 
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", (op->p_add)(1.3, 2.2), (*op->p_sub)(1.3, 2.2), 
            (op->p_mul)(1.3, 2.2), (*op->p_div)(1.3, 2.2));
     
    /* callback functions */ 
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", 
            add_sub_mul_div(1.3, 2.2, ADD), 
            add_sub_mul_div(1.3, 2.2, SUB), 
            add_sub_mul_div(1.3, 2.2, MUL), 
            add_sub_mul_div(1.3, 2.2, DIV));

    return 0; 
}
