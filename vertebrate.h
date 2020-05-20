
class Vertebrate: public Animal{
protected:
    const bool v = true; //sunt vertebrate
public:
    Vertebrate(int d = 0, int nr = 0, string n = ""):Animal(d, nr, n){}
    Vertebrate(const Vertebrate &a):Animal(a){}
    ~Vertebrate(){}

    bool verifica (){
    return this -> v;}

    Vertebrate& operator =(const Vertebrate&);
    friend istream& operator >>(istream&, Vertebrate&);
    friend ostream& operator <<(ostream&, const Vertebrate&);
    void citire(istream&);
    void afisare(ostream&)const;
};
Vertebrate& Vertebrate::operator =(const Vertebrate &a){
    Animal::operator=(a);
    return *this;
}

void Vertebrate::citire(istream& is = cin){
    Animal::citire(is);
}

istream& operator>>(istream& is, Vertebrate& a){
    a.citire();
    return is;
}

void Vertebrate::afisare(ostream& os = cout)const{
    Animal::afisare(os);
}

ostream& operator<<(ostream& os, Vertebrate& a){
    a.afisare();
    return os;
}
