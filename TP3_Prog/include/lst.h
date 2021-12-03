//
// Created by brice on 15/10/2021.
//

#ifndef _S3_LST_
#define _S3_LST_

#include "lst_elm.h"

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

/** @brief Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t *L);

/** @brief Construire une liste vide */
struct lst_t *new_lst();

/** @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t *L, int v);

/** @brief Visualiser les éléments de la liste L */
void print_lst(struct lst_t *L);

/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t **ptrL);


/** @brief La fonction prend trois arguments : La liste L est modifiée par l’insertion de la valeur entière value après l’emplacement désigné par place. */
void insert_after(struct lst_t *L, const int value, struct lst_elm_t *place);

/** @brief La fonction insère dans l’ordre croissant la valeur entière value dans la liste L. */
void insert_ordered(struct lst_t *L, const int value);

#endif // _S3_LST_
