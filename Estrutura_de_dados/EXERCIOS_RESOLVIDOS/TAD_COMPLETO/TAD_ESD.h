/*
 * File:   TAD_ESD.h
 * Author: Irlei
 *
 * Created on 16 de Junho de 2013, 22:55
 */


#include <stdio.h>
#include <stdlib.h>
#ifndef TAD_ESD_H
#define	TAD_ESD_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif



typedef int TipoChave;

typedef struct TipoItem *TipoItem;
typedef struct TipoCelula *Apontador;

typedef struct TipoCelula{
    TipoItem item;
    Apontador Prox;
} TipoCelula;



#endif	/* TAD_ESD_H */
#define	TAD_ESD_H
