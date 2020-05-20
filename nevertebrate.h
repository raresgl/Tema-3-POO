class Nevertebrate:public Animal{
protected:
    const bool v = false; //nu sunt vertebrate
public:
    Nevertebrate(int d = 0, int nr = 0, string n = ""):Animal(d, nr, n){}
    Nevertebrate(const Nevertebrate& a):Animal(a){}
    ~Nevertebrate(){}

    bool verifica (){
    return this -> v;}

    Nevertebrate& operator =(const Nevertebrate&);
    friend istream& operator >>(istream&, Nevertebrate&);
    friend ostream& operator <<(ostream&, const Nevertebrate&);
    void citire(istream&);
    void afisare(ostream&)const;
};
Nevertebrate& Nevertebrate::operator =(const Nevertebrate& a){
    Animal::operator=(a);
    return *this;
}

void Nevertebrate::citire(istream& is = cin){
    Animal::citire(is);
}

istream& operator>>(istream& is, Nevertebrate& a){
    a.citire();
    return is;
}

void Nevertebrate::afisare(ostream& os = cout)const{
    Animal::afisare(os);
}

ostream& operator<<(ostream& os, Nevertebrate& a){
    a.afisare();
    return os;
}
