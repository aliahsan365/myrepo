#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int value;
    struct elemento *prev;
    struct elemento *next;
};

struct list
{

    struct elemento *first;
    int num_elementos;
};

void insert_ordered_element(struct list *list, struct elemento *e)
{

    int n = list->num_elementos;
    int x = e->value;

    if (n == 0)
    { //lista vacia
        list->first = (struct elemento *)malloc(sizeof(struct elemento *));
        list->first = e;
        e->prev = NULL;
        e->next = NULL;
        ++list->num_elementos;
        printf("primer elemento\n");
        return;
    }

    else
    { //lista ya contiene algun elemento (uno o mas)

        //reallocatamos memoria dinamica (en el heap) para (n+1) punteros al struct elemento
        list->first = (struct elemento *)realloc(list->first, (n + 1) * sizeof(struct elemento *));

        struct elemento *aux = list->first;

        int pos = 0;

        while (aux != NULL)
        {
            int v = aux->value;

            printf("%d\n", v);

            if (x > v)
            { //seguimos recorriendo
                aux = aux->next;

                ++pos;
                printf("pos es %d\n", pos);
            }

            else
            {
                printf("paro , pos encontrada %d\n", pos);
                break; // ya hemos encontrado la pos,por lo tanto, paramos el bucle.
            }
        }

        aux = list->first;

        if (pos == 0)
        { //hay algun elemento, pero nuestro nuevo elemento es el mas pequeño y, por lo tanto, va al princio

            list->first = e;
            e->prev = NULL;
            e->next = aux;
            aux->prev = e;
            ++list->num_elementos;
            printf("primer elmento, elemento mas pequeño\n");
        }

        else
        {
            aux = list->first;
            while (aux != NULL)
            {
                if (pos != 0)
                { // seguimos avanzando hasta encontrar la pos donde insertar
                    --pos;
                    aux = aux->next;
                }
                else
                { // alcanzamos la pos correcta para insertar
                    struct elemento *temp = aux->next;
                    if (temp == NULL)
                    { //nuestro el elemento e es el actual mayor absoluto (solitario) de la lista
                        //y va a ser insertado en la ultima posicion de la lista
                        e->next = NULL;
                        e->prev = aux;
                        aux->next = e;
                        printf("ultimo elemento de todos\n");
                        return;
                    }

                    else
                    { //vamos a insertar entre dos elementos, entre aux y temp

                        e->next = temp;
                        e->prev = aux;
                        aux->next = e;
                        temp->prev = e;
                        printf("elemento entre aux y temp\n");
                        return;
                    }
                }
            }
        }
    }
}

void insert_ordered_element2(struct list *list, struct elemento *e)
{

    int n = list->num_elementos;
    int x = e->value;

    if (n == 0)
    { //lista vacia
        list->first = (struct elemento *)malloc(sizeof(struct elemento *));
        list->first = e;
        ++list->num_elementos;
        printf("entro\n");
    }

    else
    { //lista ya contiene algun elemento

        //reallocatamos memoria dinamica (en el heap) para (n+1) punteros al struct elemento
        list->first = (struct elemento *)realloc(list->first, (n + 1) * sizeof(struct elemento *));

        struct elemento *aux = list->first;
        struct elemento *temp;
        while (aux != NULL)
        {
            temp = aux;
            aux = aux->next; //seguimos recorriendo
        }
        temp->next = e;
        e->prev = temp;
        e->next = NULL;
    }
}

void print_list(struct list *list)
{

    struct elemento *e;

    e = list->first;

    while (e != NULL)
    {

        printf("%d ", e->value);

        e = e->next;
    }

    printf("\n");
}

int main()
{
    struct list *l;
    l = (struct list *)malloc(1 * sizeof(struct list));
    l->first = NULL;
    l->num_elementos = 0;

    while (1)
    {
        printf("Enter a number (0 - exit): ");
        int n;
        if (scanf("%d", &n) != 1 || (n == 0))
            break;
        struct elemento *e;

        e = (struct elemento *)malloc(1 * sizeof(struct elemento));

        e->value = n;
        e->prev = NULL;
        e->next = NULL;

        insert_ordered_element(l, e);
        print_list(l);
    }
    return 0;

    free(l);
}