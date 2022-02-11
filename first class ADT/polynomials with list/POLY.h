typedef struct poly *Poly;

typedef struct coord{
    int x;
    int y;
}Coord;

void show(Poly);
Poly term(int, int);
Poly add(Poly, Poly);
Poly mult(Poly, Poly);
float eval(Poly, float);
void freePOLY(Poly);
