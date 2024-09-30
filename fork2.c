/**
 * @file    fork2.c
 * 
 * @brief   Exemple de code C pour des processus (thread) avec la fonction fork, 
 * 
 * @author  Harold Malbrouck
 * @date    2024-09-30
 *
 */
//#define _XOPEN_SOURCE 800
#define _GNU_SOURCE 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> 

const char* processusPereOuFils;

/// @brief Code exécuté par le processus Père
/// @param  aucun
void codeDuProcessusParent(void)
{
    processusPereOuFils = "Processus Père";
    sleep(1);
    printf("Je suis %s\n", processusPereOuFils);
}

/// @brief Code exécuté par le processus Fils
/// @param aucun
void codeDuProcessusEnfant(void)
{
    processusPereOuFils = "Processus Fils";
    sleep(2);
    printf("Je suis %s\n", processusPereOuFils);
}

/// @brief Exemple de processus Père/Fils avec la fonction 'fork'
/// @return 0
int main() 
{
    pid_t pid;
    pid = fork();

    if(pid < 0)
    { 
       perror("fork failed");
    }
    else if(pid == 0)
    {
    // Appel fonction Enfant
	codeDuProcessusEnfant();	
       wait(NULL);
    }
    else
    {
    // Appel fonction Parent
	codeDuProcessusParent();
    }
    return 0;
}
