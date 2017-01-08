//
// Created by 张一鸣 on 2017/1/8.
//

#include "polynomials_List.h"
#include "../fatal.h"
#include "list_P.h"
#define MaxDegree 100

static int Max(int A, int B) {
    return A > B ? A : B;
}

void initial_Position(Position p);
typedef PtrToNode Polynomial_L;
void PrintPoly_L(const Polynomial_L Q);

void AddPolynomial_L(const Polynomial_L Poly1, const Polynomial_L Poly2, Polynomial_L PolySum) {
    Position p1tem,p2tem,pstem,pstemHeader;
    p1tem = Poly1->Next;
    p2tem = Poly2->Next;

    pstem = malloc(sizeof(Position));
    pstemHeader = pstem;
    initial_Position(pstem);
    while (p1tem != NULL && p2tem != NULL) {
        Position p = malloc(sizeof(Position));
        p->Next = NULL;
        if (p1tem->Exponent > p2tem->Exponent) {
            p->Coefficient = p1tem->Coefficient;
            p->Exponent = p->Exponent;
            p1tem = p1tem->Next;
        } else if (p1tem->Exponent < p2tem->Exponent) {
            p->Coefficient = p2tem->Coefficient;
            p->Exponent = p2tem->Exponent;
            p2tem = p2tem->Next;
        } else {
            p->Exponent = p1tem->Exponent;
            p->Coefficient = p1tem->Coefficient + p2tem->Coefficient;
            p1tem = p1tem->Next;
            p2tem = p2tem->Next;
        }
        Insert_P(p,PolySum,pstem);
        pstem = pstem->Next;
    }

    if (p1tem != NULL || p2tem != NULL) {
        Position p = p1tem != NULL ? p1tem : p2tem;

        while (p != NULL ) {
            Position tmp = malloc(sizeof(Position));
            tmp->Next = NULL;
            tmp->Coefficient = p->Coefficient;
            tmp->Exponent = p->Exponent;
            Insert_P(p,PolySum,pstem);
            pstem = pstem->Next;
            p = p->Next;
        }
    }
    DeleteList_P(PolySum);
    PolySum->Next = pstemHeader->Next;
}

void MultPolynomial_L( const Polynomial_L Poly1, const Polynomial_L Poly2, Polynomial_L PolyProd )
{
    Position p1tmp = Poly1->Next;
    Position p2tmp = Poly2->Next;

    Position pTmp = malloc(sizeof(Position));
    initial_Position(pTmp);
    List pTmpHeader = pTmp;
    Position psumTmp = malloc(sizeof(Position));
    initial_Position(psumTmp);

    while (p1tmp != NULL) {
        while (p2tmp != NULL) {
            Position p = malloc(sizeof(Position));
            initial_Position(p);
            p->Coefficient = p1tmp->Coefficient * p2tmp->Coefficient;
            p->Exponent = p1tmp->Exponent + p2tmp->Exponent;
            Insert_P(p,NULL,pTmp);
            pTmp = pTmp->Next;
            p2tmp = p2tmp->Next;
        }
        p1tmp = p1tmp->Next;
        p2tmp = Poly2->Next;
        PrintPoly_L(pTmpHeader);
        AddPolynomial_L(pTmpHeader,psumTmp,psumTmp);
        pTmp = malloc(sizeof(Position));
        initial_Position(pTmp);
        pTmpHeader = pTmp;
    }
    DeleteList_P(PolyProd);
    Insert_P(psumTmp->Next,NULL,PolyProd);
}

void initial_Position(Position p) {
    p->Next = NULL;
    p->Exponent = 0;
    p->Coefficient = 0;
}

void PrintPoly_L(const Polynomial_L Q) {
    Position tmp = Q->Next;
    while (tmp != NULL) {
        printf("%dx^%d",tmp->Coefficient,tmp->Exponent);
        tmp = tmp->Next;
        if (tmp != NULL) {
            printf("+");
        } else {
            printf("\n");
        }
    }
}

void polynomials_test_list() {
    List PLIST,QLIST;

    Polynomial_L P, Q;

    PLIST = malloc(sizeof(List));
    QLIST = malloc(sizeof(List));
    initial_Position(PLIST);
    initial_Position(QLIST);

    Q = malloc(sizeof(Polynomial_L));
    initial_Position(Q);
    Q->Coefficient = 1;
    Q->Exponent = 0;

    P = malloc(sizeof(Polynomial_L));
    P->Coefficient = 1;
    P->Exponent = 1;
    Insert_P(Q,NULL,P);

    Insert_P(P,PLIST,PLIST);
    PrintPoly_L(PLIST);
    MultPolynomial_L(PLIST,PLIST,QLIST);
    PrintPoly_L(QLIST);
    MultPolynomial_L(QLIST,QLIST,PLIST);
    PrintPoly_L(PLIST);
}