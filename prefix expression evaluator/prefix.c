#include<stdio.h>


static int i;
float eval(char *s){
    float x = 0;
    if(s[i]==' ') i++; 
    if(s[i]=='+'){ i++; return eval(s) + eval(s); }
    if(s[i]=='*'){ i++; return eval(s) * eval(s); }
    if(s[i]=='-'){ i++; return eval(s) - eval(s); }
    if(s[i]=='/'){ i++; return eval(s) / eval(s); }
    while ((s[i]>='0') && (s[i]<='9')) x=10*x+(s[i++]-'0');//horner
    return x;
}

int main(int argc,char *argv[]){
    printf("%f",eval(argv[1]));
}
