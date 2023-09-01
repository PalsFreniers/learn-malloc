#include <malloc.h>
#include <stdio.h>

int *create_tab(int size) {
	// code sans malloc
	// int ret[size]; //ne passe pas a la norme 42
	// int i = 0;
	// while(i < size) {
	// 		ret[i] = i;
	// 		i++;
	// }
	// return ret;  // erreur on sort de la "stackframe"
	//				//donc ret n'existe plus
	// code avec malloc
	int *ret = malloc(size * sizeof(int));
	int i = 0;
	while(i < size) {
		ret[i] = i;
		i++;
	}
	return ret; // on ne libère pas la mémoire pour l'instant
				// puisque qu'on va l'utiliser en dehors de la fonction
}

int main() {
//	code sans malloc
// 	int *tab = create_tab(12);  // erreur : retourne un addresse
// 								// dans la stack qui n'est plus valide
// 	printf("affichage du tableau :\n\t=> [ ");
// 	for (int i = 0; i < 12; i++)
// 	{
// 		printf("%d ", tab[i]);
// 	}
// 	printf("]; taille : 12\n");
// 	return 0; // pas besoin de libéré la mémoire car
// 			 // rien n'a été alloué en dehors de la stack
// 	//code sans malloc
	int *tab = create_tab(12);
	printf("affichage du tableau :\n\t=> [ ");
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("]; taille : 12\n");
	free(tab);  // attention à bien libéré la mémoire
			 	// après utilisation pour eviter les leaks
	return 0;
}
