/* mystack.h -- Stack declaration and function prototypes:  */

struct stack
{
    float v[20];
    int top;
};
typedef struct stack Stack;

void push(Stack *S, float val);
float pop(Stack *S);
void init(Stack *S);
int full(Stack *S);
void MyStackPrint(Stack *S);

