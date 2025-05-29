#include <vector>
#include <iostream>
#include <istream>
#include <conio.h>

using namespace std;

class Term{
    public:
    double coeff;
    int pow;
    Term(){
        coeff = 0;
        pow = 0;
    }
    Term(double coeff, int pow){
        this->coeff = coeff;
        this->pow = pow;
    }
    friend istream& operator>>(istream& in, Term& obj){
        cout<<"Enter coeff and exponent separated with a space: ";
        in>>obj.coeff;
        in>>obj.pow;
        return in;
    }

    friend ostream& operator<<(ostream& out, Term& obj){
        if( obj.coeff == 0) return out;
        out<<obj.coeff;
        if(obj.pow == 0 ) return out;
        if( obj.pow == 1 ) out<<"x";
        else out<<"x^"<<obj.pow;
        
        return out;
    }
    Term& operator+(Term& obj){
        if(this->pow != obj.pow) throw exception();
        Term* res = new Term(this->coeff+obj.coeff, this->pow);
        return *res;
    }

};

class Polynomial{
    vector<Term> terms;

    public:
    Polynomial(){}

    void addTerm(Term* t){
        this->terms.push_back(*t);
    }

    friend istream& operator>>(istream& in, Polynomial& obj){
        cout<<"Enter terms in the decreasing order of there exponent"<<endl;
        char choice = ' ';
        while(choice != 'q' && choice != 'Q'){
            Term* t = new Term();
            in>>*t;
            obj.addTerm(t);
            cout<<"Enter (q) to quit, or press any key"<<endl;
            choice = getch();
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Polynomial& obj){
        int n = obj.terms.size();
        for(int i = 0; i < n; i++){
            out<<obj.terms[i];
            if(i != n-1) out<<" + ";
        }
        return out;
    }

    Polynomial& operator+(Polynomial& obj){
        Polynomial* p = new Polynomial();
        int p1Size = this->terms.size();
        int p2Size = obj.terms.size();

        int first = 0, second = 0;
        while(first < p1Size && second < p2Size){
            Term* t = new Term();
            if(this->terms[first].pow == obj.terms[second].pow){
                *t = this->terms[first] + obj.terms[second];
                first++;
                second++;
            }else if(this->terms[first].pow > obj.terms[second].pow){
                t->coeff = this->terms[first].coeff;
                t->pow = this->terms[first].pow;
                first++;
            }else{
                t->coeff = obj.terms[second].coeff;
                t->pow = obj.terms[second].pow;
                second++;
            }
            p->addTerm(t);
        }
        while(first < p1Size){
            Term* t = new Term();
            t->coeff = this->terms[first].coeff;
            t->pow = this->terms[first].pow;
            first++;
            p->addTerm(t);
        }
        while(second < p2Size){
            Term* t = new Term();
            t->coeff = obj.terms[second].coeff;
            t->pow = obj.terms[second].pow;
            second++;
            p->addTerm(t);
        }

        return *p;
    }
};


int main(){
    Polynomial p1,p2,p3;
    cout<<"Enter polynomial 1"<<endl;
    cin>>p1;
    cout<<"\n\nEnter polynomial 2"<<endl;
    cin>>p2;

    cout<<"Poly 1: "<<p1<<endl;
    cout<<"Poly 2: "<<p2<<endl;
    p3 = p1 + p2;
    cout<<"\n\nPoly 1 + Poly 3: "<<p3<<endl;
    return 0;
}