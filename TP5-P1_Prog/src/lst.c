//
// Created by brice on 15/10/2021.
//

#include "./../include/lst.h"


/* ***** ***** DIFINITION DES FONCTIONS ASSOCIÉES ***** ***** */

/** @brief Construire une liste vide */
struct lst_t *new_lst() {
    /** @note : calloc fonctionne de manière identique à malloc
    	et de surcroît met à NULL(0) tous les octets alloués */
    struct lst_t *L = (struct lst_t *) calloc(1, sizeof(struct lst_t));
    assert(L);
    return L;
}

/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t **ptrL, void (*ptrFct )()) {
    assert(ptrL && *ptrL);
    free(*ptrL);
    *ptrL = NULL;
}

/** @brief Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t *L) {
    assert(L);
    return L->numelm == 0;
}


/** @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t *L, void *datum) {
    assert(L);

    struct lst_elm_t *E;
    E = new_lst_elm(datum);
    assert(E);

    E->suc = L->head;
    L->head = E;
    if (L->numelm == 0)
        L->tail = E;
    L->numelm++;
}

/** @brief Ajouter en queue de la liste L la donnée */
void queue(struct lst_t *L, void *datum) {
    assert(L);

    struct lst_elm_t *E;
    E = new_lst_elm(datum);
    assert(E);

    E->suc = L->tail;
    L->tail = E;
}


/** @brief La fonction prend trois arguments :
 * La liste "L" est modifiée par l’insertion de la valeur entière "value" après l’emplacement désigné par "place". */
void insert_after(struct lst_t *L, const void *datum, struct lst_elm_t *place) {
    if (place == NULL)
        cons(L, datum);
    else {
        struct lst_elm_t *newElm;
        newElm = new_lst_elm(datum);
        assert(newElm);

        newElm->suc = place->suc;
        place->suc = newElm;
        L->numelm++;

        if (place == L->tail)
            L->tail = newElm;
    }
}

/** @brief La fonction insère dans l’ordre croissant la valeur entière value dans la liste L. */
void insert_ordered(struct lst_t *L, const int value) {
    if (L->head == NULL || L->head->x >= value) {
        cons(L, value);
    } else if (L->tail->x <= value) {
        struct lst_elm_t *newElm;
        newElm = new_lst_elm(value);
        assert(newElm);

        L->tail->suc = newElm;
        L->tail = newElm;
        L->numelm++;
    } else {
        struct lst_elm_t *elmSuivie;
        elmSuivie = L->head;
        assert(elmSuivie);

        int conteur = 0;
        int boolContinue = 1;
        while (boolContinue == 1 && conteur < L->numelm) {
            if (elmSuivie->suc->x >= value) {
                insert_after(L, value, elmSuivie);
                boolContinue = 0;
            }
            elmSuivie = elmSuivie->suc;
            conteur++;
        }
    }
}


/** @brief Consulter la tête de la liste */
struct lst_elm_t *getHead(struct lst_t *L) {
    return L->head;
}

/** @brief Consulter la queue de la liste */
struct lst_elm_t *getTail(struct lst_t *L) {
    /return L->tail;
}


/** @brief Consulter le nombre d'éléments rangés dans la liste */
int getNumelm(struct lst_t *L) {
    return L->numelm;
}

/** @brief Modifier le nombre d'éléments rangés dans la liste */
int setNumelm(struct lst_t *L, int numElm) {
    L->numelm = numElm;
}


/** @brief Visualiser les éléments de la liste L grâce à la fonction pointée par ptrFct */
void view_lst(struct lst_t *L, void (*ptrFct )()) {
    printf("[ ");
    for (struct lst_elm_t *E = L->head; E; E = E->suc) {
        printf("%d ", E->x);
    }
    printf("]\n");
}

void print_lst(struct lst_t *L, void (*ptrf )()) {
    for (struct lst_elm_t *E = L - > head; E; E = E->suc) {
        (*ptrf)(E->datum);
    }
}