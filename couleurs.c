
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF); //on repousse a droite et garde les 8 derniers bits pour retrouver t
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF); //on repousse a droite et garde les 8 derniers bits pour retrouver r
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF); //same logic
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}


int add_shade(double distance, int color)
{
    if (distance <= 0)
        return color;
    if (distance >= 1)
        return (color << 32);
    
    // Calcul du décalage :
    // 1. log2(distance) donne l'exposant négatif
    // 2. -log2(distance) convertit en nombre positif pour le décalage
    // 3. (int) arrondit à l'entier
    int shift = (int)(-log2(distance));
    if (shift > 0 && shift < 32)
        return color >> shift; 
    return color;
}
int get_opposite(int color)
{
    // Masques pour extraire chaque composante
    int t = (color >> 24) & 0xFF;  // & 0xFF agit comme un tamis qui garde aue les 8 dernier bits.
    int r = (color >> 16) & 0xFF;  // rouge
    int g = (color >> 8) & 0xFF;   // vert
    int b = color & 0xFF;          // bleu
    
    // Inverse chaque composante (sauf transparence)
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
    
    // Recompose la couleur
    return create_trgb(t, r, g, b);
}

int main(int argc, char *argv[])
{
    if (argc ==5)
    {
        printf("%d\n", create_trgb(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])));
    }
    return 0;
}

// int add_shade(double distance, int color)
// {
//     if (distance == 0)
//         return (color);
//     if (distance == 1)
//         return (color << 32);
//     if (distance == 0.5)
//         return (color >> 1);
//     if (distance == 0.25)
//         return (color >> 2);
//     if (distance == 0.125)
//         return (color >> 3);
//     if (distance == 0.0625)
//         return (color >> 4);
//     return color;
// }