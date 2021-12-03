//
// Created by brice on 12/11/2021.
//

#include "./../include/lst_elm.h"
#include "./../include/lst.h"
#include "./../include/outils.h"

int main() {
    int v;
    struct lst_t *L = new_lst();
    struct lst_t *L2 = new_lst();

    printf("Donnée une valeur < à 0 pour mettre fin.\n");
    scanf("%d", &v);
    while (v > 0) {
        cons(L, v);
        insert_ordered(L2, v);
        scanf("%d", &v);
    }
    view_lst(L);
    view_lst(L2);

    insert_after(L, 666, L->head->suc);
    view_lst(L);

    del_lst(&L);
    return EXIT_SUCCESS;
}