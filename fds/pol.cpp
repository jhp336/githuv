#include <iostream>
#include "poly.h"
using namespace std;

istream& operator>> (istream& is, Polynomial& p) {
    // #terms and (coefficoent, exponent)의 pair들을 읽어들인다.
    // 높은 차수의 항부터 입력되어 저장된다고 가정한다.
    int noofterms; float coef; int exp;
    is >> noofterms;
    for (int i = 0; i < noofterms; i++) {
        is >> coef >> exp; // 계수와 지수 pair를 읽어들인다.
        p.NewTerm(coef, exp);
    }
    return is;
}

ostream& operator<< (ostream& os, Polynomial& p) {
    // 포맷에 맞게 출력하는 코드 입력
    for (int i = 0; i < p.terms; i++) {
        float coef = p.termArray[i].coef;
        int exp = p.termArray[i].exp;
        if (i != 0) {
            if (coef > 0) 
                os << "+";
        }
        if (exp > 0) {
            if (coef == -1)
                os << "-";
            else if (coef != 1)
                os << coef;
            
            if (exp != 1)
                os << "x^" << exp << " ";
            else os << "x ";
        }
        else os << coef;

        
    }
        os << endl;
    
        return os;
}

Polynomial::Polynomial() :capacity(1), terms(0)
{
    termArray = new Term[capacity];
}
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    // 다항식 뒤에 새로운 항을 추가하는 함수로 교재에 있음
    if (terms == capacity) {
        capacity *= 2;
        Term* temp = new Term[capacity];
        copy(termArray, termArray + terms, temp);
        delete[] termArray;
        termArray = temp;
    }
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}

Polynomial Polynomial::operator+(Polynomial& b)
{
    //교재의 Add와 동일한 함수로 이름만 바꾸면 됨
    Polynomial c;
    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms)) {
        if (termArray[aPos].exp == b.termArray[bPos].exp) {
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp);
            aPos++; bPos++;
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp) {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    }
    for (; aPos < terms; aPos++)
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    for (; bPos < b.terms; bPos++)
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

    return c;
}