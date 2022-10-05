/*
* File: projeto.c
* Author: Jose Corte n-103210
* Description: Primeiro projeto da cadeira de IAED do IST.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STRLEN 100
#define MAXPAR 100

/* Parsing Declaration*/

char input[STRLEN]; /* String com o input do utilizador */
char par[STRLEN]; /* String com o parametro carregado */

/* Error Declaration */
typedef struct Error {
    int found;
    char output[STRLEN];
} Error;

/* Date Declaration */
typedef struct Date {
    int dia;
    int mes;
    int ano;
} Date;

Date date = {1, 2, 2022};

/* Hour Declaration */
typedef struct Hour {
    int hour;
    int min;
} Hour;

/* Aeirport Declaration */
typedef struct Airport {

    #define AIRPORTID 4
    #define AIRPORTPAIS 31
    #define AIRPORTCIDADE 51

    char id[AIRPORTID];
    char pais[AIRPORTPAIS];
    char cidade[AIRPORTCIDADE];
    int nvoos;

} Airport;

#define MAXAIRPORTS 40
Airport aeroportos[MAXAIRPORTS];

/* Voo Declaration */
typedef struct Voo {
    #define CODIGOVOO 7

    char codigo[CODIGOVOO];
    char id_partida[AIRPORTID];
    char id_chegada[AIRPORTID];
    Date data_partida;
    Hour hora_partida;
    Hour duracao;
    int capacidade;
} Voo;

#define MAXVOOS 30000
Voo voos[MAXVOOS];

/* Math Costum */

int pow_costum(int base, int exp)
{
    int res = 1;
    while(exp != 0)
    {
        res *= base;
        exp--;
    }
    return res;
}

/* Date Functions */
int date_comp(Date d1, Date d2) 
/* Retorna 0 se iguais, 1 se d1 < d2 e -1 se d2 < d1 */
{
    if(d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia) return 0;
    if(d1.dia < d2.dia && d1.mes <= d2.mes && d1.ano <= d2.ano) return 1;
    if(d1.mes < d2.mes && d1.ano <= d2.ano) return 1;
    if(d1.ano < d2.ano) return 1;
    return -1;
}

int date_day(Date d) /* Retorna o dia (1-365) do ano */
{
    #define MESES 12

    int dias = 0;
    int i;
    int mes[MESES] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    dias += d.dia;
    if(d.mes != 1)
    {
        for(i = 0; i < d.mes - 1; i++)
        {
            dias += mes[i];
        }
    }
    return dias;
}

/* Parsing Functions */

void get_input() /* Guarda o input do utilizador no string "input" */
{
    char c;
    int i = 0;

    strcpy(input, ""); /* Esvaziar o string */

    do{
        c = getchar();
        input[i] = c;
        i++;
    } while(c != '\n');
    input[i] = '\0';
}

int get_par(int index) /* Guarda o parametro do index no string "par" */

/* A funcao retorna 0 se encontrar o parametro e 1 se nao o encontrar */

{
    int i = 0, k = 0, count = 0;

    strcpy(par, ""); /* Esvaziar o string */

    if(index == 0)
    {
        par[0] = input[0];
        par[1] = '\0';
    }
    else
    {
        while(count < index && input[i] != '\n' && input[i] != '\0')
        {
            if(input[i] == ' ' || input[i] == '\t')
            {
                count++;
                while (input[i] == ' ' || input[i] == '\t')
                {
                    i++;
                }
            }
            else i++;
        }

        if(count == 0)
        {
            return 1; /* Nao encontrou o parametro */
        }

        while(input[i] != ' ' && input[i] != '\t' 
        && input[i] != '\0' && input[i] != '\n')
        {
            par[k] = input[i];
            k++;
            i++; 
        }
        par[k] = '\0';
    }
    return 0; /* Encontrou o parametro */
}

void get_all_par(int index) 
/* Guarda uma string com todos os parametros apartir do index, inclusive */
{
    int count = 0;
    int i = 0;
    int k = 0;

    strcpy(par, ""); /* Esvaziar o string */

    while(count != index)
    {
        if(input[i] == ' ' || input[i] == '\t')
        {
            count++;
            while (input[i] == ' ' || input[i] == '\t')
            {
                    i++;
            }
        } else i++;
    }

    while(input[i] != '\0' && input[i] != '\n')
    {
        par[k] = input[i];
        i++;
        k++;
    }
    par[k] = '\0';
}

/* Comand Functions */

void airport() /* Aeroporto */
{
    Error error;
    Airport a;
    int k, i = 0;
    int found;

    error.found = 0;

    get_par(1); /* ID do aeroporto */
    strcpy(a.id, par);

    get_par(2); /* Pais do aeroporto */
    strcpy(a.pais, par);

    get_all_par(3); /* Cidade do aeroporto */
    strcpy(a.cidade, par);

    a.nvoos = 0;

    /* Load Array */

    found = 0;

    while(i < MAXAIRPORTS && found == 0)
    {
        if(strcmp(aeroportos[i].id, "") == 0)
        {
            found = 1;
        } else i++;
    }

    /* Output */
    for(k = 0; k < AIRPORTID-1; k++)
    {
        if(a.id[k] < 'A' || 'Z' < a.id[k])
        {
            printf("invalid airport ID\n");
            error.found = 1;
            break;
        }
    }

    if((found == 0) && (error.found == 0))
    {
        printf("too many airports\n");
        error.found = 1;
    }

    found = 0;

    if((error.found == 0))
    {
        for(k = 0; k < MAXAIRPORTS; k++)
        {
            if(strcmp(aeroportos[k].id, a.id) == 0)
            {
                found = 1;
            }
        }
        if(found == 1)
        {
            printf("duplicate airport\n"); 
            error.found = 1;
        }
    }
    
    if(error.found == 0)
    {
        aeroportos[i] = a;
        printf("airport %s\n", a.id);
    }    
}

void lista_voos()
{
    int i = 0, k = 0;

    while(i < MAXVOOS && strcmp(voos[i].codigo, "") != 0)
    {   
        i++;
    }

    for(k = 0; k < i; k++)
    {
        printf("%s %s %s %02d-%02d-%04d %02d:%02d\n", voos[k].codigo, 
        voos[k].id_partida, voos[k].id_chegada, voos[k].data_partida.dia, 
        voos[k].data_partida.mes, voos[k].data_partida.ano, 
        voos[k].hora_partida.hour, voos[k].hora_partida.min);
    }
    return;
}

void voo() /* Voo */
{
    Error error;
    Voo v;
    Date data_1;
    int len, i = 0;
    int found = 0;
    int index_store = 0;
    
    error.found = 0;

    if(get_par(1) != 0) /* Listar os voos */
    {
        lista_voos();
        return;
    }

    /* Load Values */
    get_par(1);
    strcpy(v.codigo, par);
    get_par(2);
    strcpy(v.id_partida, par);
    get_par(3);
    strcpy(v.id_chegada, par);
    get_par(4);
    v.data_partida.dia = 10 * (par[0] - '0') + (par[1] - '0');
    v.data_partida.mes = 10 * (par[3] - '0') + (par[4] - '0');
    v.data_partida.ano = 1000 * (par[6] - '0') + 100 * (par[7] - '0') 
    + 10 * (par[8] - '0') + (par[9] - '0');
    get_par(5);
    v.hora_partida.hour = 10 * (par[0] - '0') + (par[1] - '0');
    v.hora_partida.min = 10 * (par[3] - '0') + (par[4] - '0'); 
    get_par(6);
    if(par[1] != ':')
    {
        v.duracao.hour = 10 * (par[0] - '0') + (par[1] - '0');
        v.duracao.min = 10 * (par[3] - '0') + (par[4] - '0');
    }
    else
    {
        v.duracao.hour = (par[0] - '0');
        v.duracao.min = 10 * (par[2] - '0') + (par[3] - '0');
    }
    get_par(7);
    len = strlen(par);
    v.capacidade = 0;
    while(len != 0)
    {
        v.capacidade += (pow_costum(10, len-1) * (par[i] - '0'));
        len--;
        i++;
    }

    /* Validation */
    /* invalid flight code */
    i = 0;
    len = strlen(v.codigo);
    if(len < 3 || 6 < len)
    {
        error.found = 1;
    }
    while(i <= len && error.found == 0)
    {
        if(i < 2 && (v.codigo[i] < 'A' || 'Z' < v.codigo[i]))
        {
            error.found = 1;
        }
        if((i > 1) && (i < len) && ((v.codigo[i] < '0') 
        || (v.codigo[i] > '9')))
        {
            error.found = 1;
        }
        if(i == 2 && v.codigo[i] == '0')
        {
            error.found = 1;
        }
        i++;
    }
    if(error.found == 1)
    {
        printf("invalid flight code\n");
        return;
    }

    /* flight already exists */
    len = MAXVOOS;
    for(i = 0; i < len; i++)
    {
        if(strcmp(voos[i].codigo, v.codigo) == 0 
        && voos[i].data_partida.dia == v.data_partida.dia
        && voos[i].data_partida.mes == v.data_partida.mes 
        && voos[i].data_partida.ano == v.data_partida.ano)
        {
            error.found = 1;
            printf("flight already exists\n");
            return;
        }
    }

    /* <IDAeroporto>: no such airport ID */
    len = MAXAIRPORTS;

    found = 0;
    for(i = 0; i < len; i++)
    {
        if(strcmp(aeroportos[i].id, v.id_partida) == 0)
        {
            found = 1;
        }
    }
    if(found == 0)
    {
        error.found = 1;
        printf("%s: no such airport ID\n", v.id_partida);
        return;
    }

    found = 0;
    for(i = 0; i < len; i++)
    {
        if(strcmp(aeroportos[i].id, v.id_chegada) == 0)
        {
            found = 1;
        }
    }
    if(found == 0)
    {
        error.found = 1;
        printf("%s: no such airport ID\n", v.id_chegada);
        return;
    }

    /* invalid date */
    data_1.dia = date.dia;
    data_1.mes = date.mes;
    data_1.ano = date.ano + 1;
    if(date_comp(date, v.data_partida) == -1 
    || date_comp(data_1, v.data_partida) == 1)
    {
        error.found = 1;
        printf("invalid date\n");
        return;
    }

    /* invalid duration */
    if(v.duracao.hour > 12 || (v.duracao.hour == 12 && v.duracao.min != 0))
    {
        error.found = 1;
        printf("invalid duration\n");
        return;
    }

    /* invalid capacity */
    if(v.capacidade < 10 || v.capacidade > 100)
    {
        error.found = 1;
        printf("invalid capacity\n");
        return;
    }

    /* Store Voo */
    if(error.found == 0)
    {
        found = 0;
        while(index_store < MAXVOOS && found == 0)
        {
            if(strcmp(voos[index_store].codigo, "") == 0)
            {
                found = 1;
            } else index_store++;
        }
        if(found == 1)
        {
            voos[index_store] = v;

            i = 0;
            while(strcmp(aeroportos[i].id, "") != 0 && i < MAXAIRPORTS)
            {
                if(strcmp(aeroportos[i].id, v.id_partida) == 0)
                {
                    aeroportos[i].nvoos++;
                }
                i++;
            }
            

        }
        else
        {
            printf("too many flights\n"); /* too many flights */
        }
    }
    return;
}

void sort_aeroportos()
{
    Airport atemp;
    int i, j, done;

        for(i = 0; i < MAXAIRPORTS - 1; i++)
        {
            done = 1;
            for(j = 0; j < MAXAIRPORTS - 1 - i; j++)
            {
                if (aeroportos[j].id[0] < aeroportos[j-1].id[0] 
                && strcmp(aeroportos[j].id, "") != 0 
                && strcmp(aeroportos[j-1].id, "") != 0)
                {
                    atemp = aeroportos[j];
                    aeroportos[j] = aeroportos[j-1];
                    aeroportos[j-1] = atemp;
                    done = 0;
                }
                if (aeroportos[j].id[1] < aeroportos[j-1].id[1] 
                && aeroportos[j].id[0] == aeroportos[j-1].id[0]
                && strcmp(aeroportos[j].id, "") != 0 
                && strcmp(aeroportos[j-1].id, "") != 0)
                {
                    atemp = aeroportos[j];
                    aeroportos[j] = aeroportos[j-1];
                    aeroportos[j-1] = atemp;
                    done = 0;
                }
                if (aeroportos[j].id[2] < aeroportos[j-1].id[2] 
                && aeroportos[j].id[0] == aeroportos[j-1].id[0]
                && aeroportos[j].id[1] == aeroportos[j-1].id[1] 
                && strcmp(aeroportos[j].id, "") != 0 
                && strcmp(aeroportos[j-1].id, "") != 0)
                {
                    atemp = aeroportos[j];
                    aeroportos[j] = aeroportos[j-1];
                    aeroportos[j-1] = atemp;
                    done = 0;
                }
                
            }
        if(done) break;      
        }                   
    return;
}

void lista() /* Lista Aeroportos */ 
{
    int i, k, j, n;
    char id[3];
    int found = 0;
    Airport a;

    sort_aeroportos();

    if(get_par(1) != 0) /* Listar os aeroportos por ordem alfabetica */
    {
        i = 0;
        while(strcmp(aeroportos[i].id, "") != 0)
        {
            a = aeroportos[i];
            printf("%s %s %s %d\n", a.id, a.cidade, a.pais, a.nvoos);
            i++;
        }
        return;
    }

    get_all_par(1);
    
    i = 0;
    while(par[i] != '\0')
    {
        if(i > 0 && par[i-1] == '\0') break;

        found = 0;

        j = 0;
        for(k = i; k <= i + 2; k++)
        {
            id[j] = par[k];  
            j++;       
        }
        i = k + 1;
        id[j] = '\0';

        n = 0;
        while(strcmp(aeroportos[n].id, "") != 0)
        {
            if(strcmp(aeroportos[n].id, id) == 0 && 'A' < id[0] && id[0] < 'Z')
            {
                found = 1;
                a = aeroportos[n];
                printf("%s %s %s %d\n", a.id, a.cidade, a.pais, a.nvoos);
                break;
            }
            n++;
        }

        if(found == 0)
        {
            printf("%s: no such airport ID\n", id);
        }
    }
    return;
}

void update() /* Avanca a data do sitema */
{
    Date d, data_1;

    /* Load Date into d */
    get_par(1);
    d.dia = 10 * (par[0] - '0') + (par[1] - '0');
    d.mes = 10 * (par[3] - '0') + (par[4] - '0');
    d.ano = 1000 * (par[6] - '0') + 100 * (par[7] - '0') 
    + 10 * (par[8] - '0') + (par[9] - '0');
    
    /* Invalid Date */
    data_1.dia = date.dia;
    data_1.mes = date.mes;
    data_1.ano = date.ano + 1;
    if(date_comp(date, d) == -1 || date_comp(data_1, d) == 1)
    {
        printf("invalid date\n");
        return;
    }

    date.dia = d.dia;
    date.mes = d.mes;
    date.ano = d.ano;

    printf("%02d-%02d-%04d\n", date.dia, date.mes, date.ano);
    return;
}

int less_voo(Voo v1, Voo v2) /* Se v1 < v2 returns 0 else return -1*/
{
    if(v1.data_partida.ano < v2.data_partida.ano) return 0;

    if(v1.data_partida.ano == v2.data_partida.ano
    && v1.data_partida.mes < v2.data_partida.mes) return 0;

    if(v1.data_partida.ano == v2.data_partida.ano
    && v1.data_partida.mes == v2.data_partida.mes
    && v1.data_partida.dia < v2.data_partida.dia) return 0;

    if(v1.data_partida.ano == v2.data_partida.ano
    && v1.data_partida.mes == v2.data_partida.mes
    && v1.data_partida.dia == v2.data_partida.dia
    && v1.hora_partida.hour < v2.hora_partida.hour) return 0;

    if(v1.data_partida.ano == v2.data_partida.ano
    && v1.data_partida.mes == v2.data_partida.mes
    && v1.data_partida.dia == v2.data_partida.dia
    && v1.hora_partida.hour == v2.hora_partida.hour
    && v1.hora_partida.min < v2.hora_partida.min) return 0;

    return -1;
}

void partida(int type) /* Lista os Voos com partida do Aeroporto */
{
    char id[3];
    Voo voos_sorted[MAXVOOS];
    Voo temp;
    int i, j, done, found, count = 0;

    /* Load voos_sorted */
    i = 0;
    while(i < MAXVOOS && strcmp(voos[i].codigo, "") != 0)
    {
        voos_sorted[i] = voos[i];
        i++;
        count++;
    }
    strcpy(voos_sorted[i].codigo, "");
    count++;

    /* Sort voos_sorted */

    i = 0;
        
    for (i = 0; i < count; i++)
    {
        done = 1;
        for (j = count; j > i; j--)
        {
            if(less_voo(voos_sorted[j], voos_sorted[j-1]) == 0 && 
            strcmp(voos_sorted[j].codigo, "") != 0 
            && strcmp(voos_sorted[j-1].codigo, "") != 0)
            {
                temp = voos_sorted[j];
                voos_sorted[j] = voos_sorted[j-1];
                voos_sorted[j-1] = temp;

                done = 0;
            }
        }            
        if (done == 0) break;
    }

    /* Load Values */
    get_par(1);
    strcpy(id, par);

    /*Find Voo */
    if(type == 0)
    {
        i = 0;
        found = 0;
        while(strcmp(voos_sorted[i].codigo, "") != 0 && i < count)
        {   
            if (strcmp(voos_sorted[i].id_partida, id) == 0)
            {
                    printf("%s %s %02d-%02d-%04d %02d:%02d\n", 
                    voos_sorted[i].codigo, voos_sorted[i].id_chegada, 
                    voos_sorted[i].data_partida.dia, voos_sorted[i].data_partida.mes, 
                    voos_sorted[i].data_partida.ano,
                    voos_sorted[i].hora_partida.hour, 
                    voos_sorted[i].hora_partida.min);

                found = 1;
            }

            i++;
        }
    }
    if(type == 1)
    {
        i = 0;
        found = 0;
        while(strcmp(voos_sorted[i].codigo, "") != 0 && i < count)
        {   
            if (strcmp(voos_sorted[i].id_chegada, id) == 0)
            {
                    printf("%s %s %02d-%02d-%04d %02d:%02d\n", 
                    voos_sorted[i].codigo, 
                    voos_sorted[i].id_chegada, 
                    voos_sorted[i].data_partida.dia, 
                    voos_sorted[i].data_partida.mes, 
                    voos_sorted[i].data_partida.ano,
                    voos_sorted[i].hora_partida.hour, 
                    voos_sorted[i].hora_partida.min);

                found = 1;
            }

            i++;
        }        
    }

    if(found == 0)
    {
        printf("%s: no such airport ID\n", id);
    }

}

int main()
{
    int exit = 0;
    char c;

    while(exit == 0)
    {
        get_input();
        get_par(0);

        c = par[0];
        switch(c)
        {
            case 'q':
                exit = 1;
                break;

            case 'a':
                airport();
                break;

            case 'v':
                voo();
                break;

            case 'l':
                lista();
                break;

            case 't':
                update();
                break;

            case 'p':
                partida(0);
                break;

            case 'c':
                partida(1);
                break;

            default:
                return 1; /* No comand found */
        }
    }
    return 0;
}