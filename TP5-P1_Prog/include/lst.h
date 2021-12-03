//
// Created by brice on 15/10/2021.
//

#ifndef _S3_LST_
#define _S3_LST_

#include "./lst_elm.h"

#include <stdio.h> // librairie input/output
#include <stdlib.h> // librairie standard
#include <assert.h> // librairie d'assertions
#include <stdbool.h> // librairie du type booléen

/** @brief Le type abstrait d'une _liste_:
	* + head - le premier élément de la liste
	* + tail - le dernier élément de la liste
	* + numelm - le nombre d'élément dans la liste
*/
struct lst_t {
    struct lst_elm_t *head;
    struct lst_elm_t *tail;
    int numelm;
};

/* ***** ***** DÉCLARATION DES FONCTIONS ASSOCIÉES ***** ***** */

/** @brief Construire une liste vide */
struct lst_t *new_lst();

/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t **ptrL, void (*ptrFct )());

/** @brief Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t *L);

/** @brief Ajouter en tête de la liste L la donnée */
void cons(struct lst_t *L, void *datum);

/** @brief Ajouter en queue de la liste L la donnée */
void queue(struct lst_t *L, void *datum);

/** @brief La fonction prend trois arguments :
 * La liste "L" est modifiée par l’insertion de la valeur entière "value" après l’emplacement désigné par "place". */
void insert_after(struct lst_t *L, const void *datum, struct lst_elm_t *place);

/** @brief Insérer dans la liste L la donnée suivant l'ordre donné par la fonction pointée par ptrFct */
void insert_ordered(struct lst_t *L, void *datum, bool (*ptrFct )());

/** @brief Consulter la tête de la liste */
struct lst_elm_t *getHead(struct lst_t *L);

/** @brief Consulter la queue de la liste */
struct lst_elm_t *getTail(struct lst_t *L);

/** @brief Consulter le nombre d'éléments rangés dans la liste */
int getNumelm(struct lst_t *L);

/** @brief Modifier le nombre d'éléments rangés dans la liste */
int setNumelm(struct lst_t *L, int numElm);

/** @brief Visualiser les éléments de la liste L grâce à la fonction pointée par ptrFct */
void view_lst(struct lst_t *L, void (*ptrFct )());

/** @brief Visualiser la liste entière */
void print_lst(struct list *L, void (*ptrf )())

#endif // _S3_LST_
