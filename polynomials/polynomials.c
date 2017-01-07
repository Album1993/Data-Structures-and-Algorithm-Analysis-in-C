//
// Created by 张一鸣 on 2017/1/7.
//

#include "polynomials.h"
#include "../fatal.h"
#include "list_P.h"
#define MaxDegree 100

static int Max(int A, int B) {
    return A > B ? A : B;
}


//
//typedef struct {
//    int CoeffArray[MaxDegree];
//    int HighPower;
//} * Polynomial;
//
//void ZeroPolynomial (Polynomial poly) {
//    int i;
//    for (i = 0; i <= MaxDegree; ++i)
//        poly->CoeffArray[i] = 0;
//    poly->HighPower = 0;
//}
//
//void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum) {
//    int i;
//    ZeroPolynomial(PolySum);
//    PolySum->HighPower = Max(Poly1->HighPower,Poly2->HighPower);
//    for (i = PolySum->HighPower; i >= 0 ; i--) {
//        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
//    }
//}
//
//void MultPolynomial( const Polynomial Poly1,
//                const Polynomial Poly2, Polynomial PolyProd )
//{
//    int i, j;
//
//    ZeroPolynomial( PolyProd );
//    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
//
//    if( PolyProd->HighPower > MaxDegree )
//        Error( "Exceeded array size" );
//    else
//        for( i = 0; i <= Poly1->HighPower; i++ )
//            for( j = 0; j <= Poly2->HighPower; j++ )
//                PolyProd->CoeffArray[ i + j ] +=
//                        Poly1->CoeffArray[ i ] *
//                        Poly2->CoeffArray[ j ];
//}
//
//void
//PrintPoly( const Polynomial Q )
//{
//    int i;
//
//    for( i = Q->HighPower; i > 0; i-- )
//        printf( "%dx^%d + ", Q->CoeffArray[ i ], i );
//    printf( "%d\n", Q->CoeffArray[ 0 ] );
//}


typedef PtrToNode Polynomial;

void ZeroPolynomial (Polynomial poly) {
    MakeEmpty_P(poly);
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum) {
    ZeroPolynomial(PolySum);
    Position p1tem,p2tem,pstem;
    p1tem = Poly1->Next;
    p2tem = Poly2->Next;
    pstem = PolySum;
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
}

void MultPolynomial( const Polynomial Poly1,
                     const Polynomial Poly2, Polynomial PolyProd )
{

}


void PrintPoly(const Polynomial Q) {
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

void polynomials_test() {

    List PLIST,QLIST;

    Polynomial P, Q;

    PLIST = malloc(sizeof(List));
    QLIST = malloc(sizeof(List));
    PLIST->Next = NULL;
    PLIST->Exponent = 0;
    PLIST->Coefficient = 0;
    QLIST->Next = NULL;
    QLIST->Exponent = 0;
    QLIST->Coefficient = 0;

    P = malloc(sizeof(Polynomial));
    P->Coefficient = 1;
    P->Exponent = 1;
    P->Next = NULL;

    Insert_P(P,PLIST,PLIST);
    PrintPoly(PLIST);
    AddPolynomial(PLIST,PLIST,QLIST);
    PrintPoly(QLIST);
//
//    P->HighPower = 1; P->CoeffArray[ 0 ] = 1; P->CoeffArray[ 1 ] = 1;
//    PrintPoly( P );
//    MultPolynomial( P, P, Q );
//    PrintPoly( Q );
//    MultPolynomial( Q, Q, P );
//    PrintPoly( P );
//    AddPolynomial( P, P, Q );
//    PrintPoly( Q );

}