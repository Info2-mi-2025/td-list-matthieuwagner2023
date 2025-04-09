#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ne pas modifier
void init_file()
{
    // data.txt
    FILE* f = fopen("data.txt", "w");
    if (f)
    {
        fprintf(f, "5\n12\n8\n1\n19\n");
        fclose(f);
    }

    // data2.txt
    f = fopen("data2.txt", "w");
    if (f)
    {
        fprintf(f, "10\n20\n30\n");
        fclose(f);
    }

    // data3.txt
    f = fopen("data3.txt", "w");
    if (f)
    {
        fprintf(f, "1\n2\n3\n4\n5\n");
        fclose(f);
    }

    // data_vide.txt
    f = fopen("data_vide.txt", "w");
    if (f)
    {
        fclose(f);  // fichier vide
    }
}



typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} List;

// Fonctions de base
void append(List* list, int value)
{
    if(list == NULL || list->head ==  NULL)
        exit(1);

    //Création nouveau noeud
    Node* new_node = malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->value = value;

    //Liste est vide
    if(list->head == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    
}

void free_list(List* list)
{
}

void print_list(const List* list)
{
}

void reverse_list(List* list)
{
}

int sum_list(const List* list)
{
    return 0;
}

int min_list(const List* list)
{
    return 0;
}

int max_list(const List* list)
{
    return 0;
}

void filter_list(List* list, int threshold)
{
}

void help()
{
    printf("Utilisation : ./app <fichier> [options]\n\n");
    printf("Options disponibles :\n");
    printf("  --reverse         Inverse l'ordre des éléments\n");
    printf("  --sum             Affiche la somme des éléments\n");
    printf("  --filter <val>    Filtre les éléments >= val\n");
    printf("  --add <val>       Ajoute une valeur à la fin du fichier\n");
    printf("  --help            Affiche ce message d'aide\n");
    printf("  --version, -v     Affiche la version du programme\n");
    printf("  --min             Affiche la valeur minimale de la liste\n");
    printf("  --max             Affiche la valeur maximale de la liste\n");
}

void version()
{
    printf("version 1.0\n");
}

// Lecture fichier
bool read_file(const char* filename, List* list)
{
    FILE* f = fopen(filename, "r");
    if (!f) return false;
    int value;
    
    while (fscanf(f, "%d", &value) == 1) append(list, value);
    
    fclose(f);
    return true;
}

bool add_to_file(const char* filename, int value)
{
    FILE* f = fopen(filename, "a");
    if (!f) return false;
    fprintf(f, "%d\n", value);
    fclose(f);
    return true;
}

int main(int argc, char* argv[])
{
    // Ne pas modifier
    init_file();
    // ---------------
    int value_filter = 0;
    int value_add = 0;
    List l;

    if(argc < 2)
        return 1;

    for (size_t i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "--help") == 0)
        {
            help();
        }
            
        else if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0)
        {
            version();
        }
            else if (sscanf(argv[i], "--filter%d", &value_filter))
        {
            filter_list(&l, value_filter);
        }
        else if(strcmp(argv[i], "--reverse") == 0)
        {
            reverse_list(&l);
        }
            else if (strcmp(argv[i], "--min") == 0)
        {
            //Code
        }
        else if (strcmp(argv[i], "--max") == 0)
        {
            //Code
        }
        else if (sscanf(argv[i], "--add%d", &value_add))
        {
            //Code
        }
        else if (strcmp(argv[i], "--sum") == 0)
        {
            //Code
        }
        else
        {
            FILE* f = fopen(argv[i], "r");
            if (f == NULL)
                return 2;
            if(f == NULL && argv[i][0] == '-')
                return 1;
            fclose(f);
        }

        
    }
    
    
    


    return 0;
}