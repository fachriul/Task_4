#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L)
{
    First = NULL;
    last = NULL;
}

address alokasi(infotype x)
{
    address P = new elemenList;
    Info(P) = x;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

void insertFirst(List &L, address P)
{
    Next(P) = First(L);
    Next(Prev(P)) = P;
    First(L) = P;
}

void insertLast(List &L, address P)
{
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        Prev(P) = L.Last;
        Prev(Next(P)) = P;
        L.Last = P;
    }
}
void insertAfter(List &L, address P, address Prec)
{
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        Next(P) = Next(Prec);
        Prev(P) = Prec;
        Prev(Next(Prec)) = P;
        Next(Prec) = P;
    }
}

void deleteFirst(List &L, address &P)
{
    P = First(L);
    if (first(L) != last(L))
    {
        first(L) = next(P);
		next(P) = NULL;
		prev(first(L)) = NULL;
    }

	else
    {
        first(L) = NULL;
		last(L) = NULL;
    }
}

void deleteLast(List &L, address &P)
{
    if(Next(First(L)) == NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        P = Last(L);
        Last(L) = prev(last(L));
        prev(P) = NULL;
        next(last(L)) = NULL;
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    P = Next(Prec);
	Next(Prec) = next(P);
	Prev(next(P)) = Prec;
	Prev(P) = NULL;
	Next(P) = NULL;

}

address findElm(List L, infotype x)
{
    address Q = First(L);
    while(Q != NULL){
        if(Info(Q).ID == x.ID){
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}

int countElm(List L)
{
     int num = 0;
     if (L.first == NULL) return 0;
     address Q = First(L);
     do{
         num++;
         Q = Next(Q);
     }while(Q != L.first);
     return num;
}
