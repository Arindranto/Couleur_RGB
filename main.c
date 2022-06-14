/* MANIPULATION BIT A BIT SUR LES CODES COULEURS */

#include <stdio.h>
#include <stdlib.h>
// Les masques correspondants
#define MASQUE_VERT 0x00ff00
#define MASQUE_BLEU 0x0000ff

int rgb(){
    // Fonction qui retourne une couleur rgb contenue dans un seul int de 4 octets
    // Structure:
    //      Rouge: b23 b22 b21 b20 b19 b18 b17 b16
    //      Vert: b15 b14 b13 b12 b11 b10 b9 b8
    //      Bleu: b7 b6 b5 b4 b3 b2 b1 b0

    int red, green, blue;   // Pour stocker les intensités de chaque couleur
    do{
        puts("Les intensites doivent etre comprise entre 0  et 255");

        printf("\nEntrez l'intensite du rouge: ");
        scanf("%d", &red);
        printf("\nEntrez l'intensite du vert: ");
        scanf("%d", &green);
        printf("\nEntrez l'intensite du bleu: ");
        scanf("%d", &blue);
    } while (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255); // Vérifie si les intensités sont valides

    return red << 16 | green << 8 | blue;
}

void decompose(int rgb_color){
    // Affiche les intensités de chaque composante rgb d'une couleur encodée dans un int

    printf("Rouge: %d\n", rgb_color >> 16);
    printf("Vert: %d\n", (rgb_color & MASQUE_VERT) >> 8); // L'opérateur de shift est prioritaire par rapport au & bit à bit
    printf("Bleu: %d\n", rgb_color & MASQUE_BLEU);

    return;
}

int reduce(int rgb_color, int percentage){
    // Retourne une couleur assombrie à percentage%

    int red, green, blue; // Pour stocker les valeurs des composantes de rgb_color
    // Extraction des intensités de chaque composantes de rgb_color
    red= rgb_color >> 16;
    green= (rgb_color & MASQUE_VERT) >> 8;
    blue= rgb_color & MASQUE_BLEU;

    // Réduction
    red-= (int)(red * percentage / 100.0);
    green-= (int)(green * percentage / 100.0);
    blue-= (int)(blue * percentage / 100.0);

    return red << 16 | green << 8 | blue; // La couleur assombrie
}

int to_monochrome(int rgb_color){
    // Retourne une couleur monochrome encodée dans un int
    // en calculant la moyenne des intensités de chaque composantes de rgb_color

    int red, green, blue, avg; // Pour stocker les valeurs des composantes de rgb_color ainsi que leur moyenne
    // Extraction des intensités de chaque composantes de rgb_color
    red= rgb_color >> 16;
    green= (rgb_color & MASQUE_VERT) >> 8;
    blue= rgb_color & MASQUE_BLEU;

    avg= (red + green + blue)/3; // Moyenne

    return avg << 16 | avg << 8 | avg;
}

int main()
{
    int color= rgb();
    printf("\nDecomposition:\n");
    decompose(color);
    printf("Hexadecimal: #%x\n", color);

    printf("\n\nReduction de la couleur:\n");
    color= reduce(color, 20);
    decompose(color);
    printf("Hexadecimal: #%x\n", color);

    printf("\n\nCouleur monochrome:\n");
    color= to_monochrome(color);
    decompose(color);
    printf("Hexadecimal: #%x\n", color);

    return 0;
}
