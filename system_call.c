/**
 * @file system_call.c
 * 
 * @brief   Exemple de code C pour des appels systèmes 
 *          (équivalent à une commande dans un émulateur de terminal, ou un script Bash)
 * 
 * @author  Harold Malbrouck
 * @date    2024-09-30
 *
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * Ce programme affiche instannement processus 1  à l'ecran 
 * Après 10s affiche processus 3
 * Après 5s affiche processus 5
 * puis affiche terminé et s'arrete
 * @return     0 
 */
int main() {
  system("echo \"processus 1 \""); 
  system("sleep 10"); // processus 2
  system("echo \"processus 3 \""); 
  system("sleep 5"); // processus 4
  system("echo \"processus 5 \""); 

  printf("\n terminé \n");
  return 0;
}
