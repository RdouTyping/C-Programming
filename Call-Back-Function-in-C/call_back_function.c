#include <stdio.h>
#include <stdlib.h>

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

typedef struct _OP {
    float (*p_add)(float, float); 
    float (*p_sub)(float, float); 
    float (*p_mul)(float, float); 
    float (*p_div)(float, float); 
} OP; 

void init_op(OP *op)
{
    op->p_add = ADD;
    op->p_sub = SUB;
    op->p_mul = &MUL;
    op->p_div = &DIV;
}

float (*op_array[4])(float, float);


float op_call_back(float a, float b, float (*op_func)(float, float))
{
    return (*op_func)(a, b);
}

int main(int argc, char *argv[]) 
{
    OP *op = (OP *)malloc(sizeof(OP)); 
    init_op(op);
    
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", (op->p_add)(1.3, 2.2), (*op->p_sub)(1.3, 2.2), 
            (op->p_mul)(1.3, 2.2), (*op->p_div)(1.3, 2.2));
      
    op_array[0] = ADD;
    op_array[1] = SUB;
    op_array[2] = MUL;
    op_array[3] = DIV;
    
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", (*op_array[0])(1.3, 2.2), (*op_array[1])(1.3, 2.2), 
            (*op_array[2])(1.3, 2.2), (*op_array[3])(1.3, 2.2));
   
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", 
            op_call_back(1.3, 2.2, ADD), 
            op_call_back(1.3, 2.2, SUB), 
            op_call_back(1.3, 2.2, MUL), 
            op_call_back(1.3, 2.2, DIV));

    return 0; 
}
