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
    int x;
    struct lst_elm_t *suc;
};

/* ***** ***** DÉCLARATION DES FONCTIONS ASSOCIÉES ***** ***** */

/** @brief Créer un élément de liste et y ranger la valeur entière value */
struct lst_elm_t *new_lst_elm(int value);

/** @brief Supprimer un élément de liste et mettre son pointeur à NULL */
void del_lst_elm(struct lst_elm_t **ptrE);

/** @brief Renvoyer la valeur entière de l'élément */
int getX(struct lst_elm_t *E);

/** @brief Modifier la valeur entière de l'élément */
void setX(struct lst_elm_t *E, int v);

/** @brief Renvoyer le pointeur sur le successeur de l'élément */
struct lst_elm_t *getSuc(struct lst_elm_t *E);

/** @brief Modifier le pointeur sur le successeur de l'élément */
void setSuc(struct lst_elm_t *E, struct lst_elm_t *S);

#endif // _LST_ELM_T_
