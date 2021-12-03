//
// Created by brice on 15/10/2021.
//

#include "./../include/lst_elm.h"


/* ***** ***** DIFINITION DES FONCTIONS ASSOCIÉES ***** ***** */

/** @brief Créer un élément de liste et y ranger la valeur entière value */
struct lst_elm_t *new_lst_elm(void *datum) {
    /** @note : calloc fonctionne de manière identique à malloc
        et de surcroît met à NULL(0) tous les octets alloués */
    struct lst_elm_t *E = (struct lst_elm_t *) calloc(1, sizeof(struct lst_elm_t));
    assert(E);
    E->datum = datum;
    return E;
}

/** @brief Supprimer un élément de liste et mettre son pointeur à NULL */
void del_lst_elm(struct lst_elm_t **ptrE) {
    assert(ptrE && *ptrE);
    free(*ptrE);
    *ptrE = NULL;
}

/** @brief Renvoyer la valeur entière de l'élément */
void *getDatum(struct lst_elm_t *E) {
    return E->datum;
}

/** @brief Modifier la valeur entière de l'élément */
void setDatum(struct lst_elm_t *E, void *datum) {
    E->x = datum;
}

/** @brief Renvoyer le pointeur sur le successeur de l'élément */
struct lst_elm_t *getSuc(struct lst_elm_t *E) {
    return E->suc;
}

/** @brief Modifier le pointeur sur le successeur de l'élément */
void setSuc(struct lst_elm_t *E, struct lst_elm_t *S) {
    E->suc = S->suc;
}
