//
// Created by brice on 15/10/2021.
//

#ifndef _LST_ELM_T_
#define _LST_ELM_T_

#include <stdlib.h> // librairie standard
#include <assert.h> // librairie d'assertions

/** @brief Le type abstrait d'un _élément_ de liste:
	+ x - un entier,
	+ suc - un pointeur sur son successeur (ou NULL s'il n'y en a pas)
*/
struct lst_elm_t {
    void *datum;
    struct lst_elm_t *suc;
};

/* ***** ***** DÉCLARATION DES FONCTIONS ASSOCIÉES ***** ***** */

/** @brief create a new list element and store datum into it */
struct lst_elm_t *new_lst_elm(void *datum);

/** @brief destroy the list element pointed by E and set E to NULL */
void del_lst_elm(struct lst_elm_t **ptrE);

/** @brief retreive the datum of the list element E */
void *getDatum(struct lst_elm_t *E);

/** @brief modify the date of the list element */
void setDatum(struct lst_elm_t *E, void *datum);

/** @brief retreive the succesor of the list element E */
struct lst_elm_t *getSuc(struct lst_elm_t *E);

/** @brief modify the succesor of the list element */
void setSuc(struct lst_elm_t *E, struct lst_elm_t *S);

#endif // _LST_ELM_T_
