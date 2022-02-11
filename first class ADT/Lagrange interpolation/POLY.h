typedef struct poly *Poly;

typedef struct coord{
    int x;
    int y;
}Coord;

void show(Poly);
Poly term(float, float);
Poly add(Poly, Poly);
Poly mult(Poly, Poly);
float eval(Poly, float);
void freePOLY(Poly);
Poly interpola(Coord*,unsigned int);