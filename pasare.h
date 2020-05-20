class Pasare: public Vertebrate {
private:
    bool zboara;
public:

    Pasare(int d = 0, int nr = 0, string n = "", bool z = true):Vertebrate(d, nr, n){
    this -> zboara = z;
    }
    Pasare(const Pasare& a):Vertebrate(a){
    this -> zboara = a.zboara;
    }
    ~Pasare(){}

    void setter(int d = 0, int nr = 0, string n = "", bool z = true){
    Vertebrate::setter(d, nr, n);
    this -> zboara = z;
    }

    void set_zboara(bool z = true){
    this -> zboara = z;
    }
    bool get_zboara(){
    return this -> zboara;
    }

    Pasare& operator =(const Pasare&);
    friend istream& operator >>(istream&, Pasare&);
    friend ostream& operator <<(ostream&, const Pasare&);
    void citire(istream&);
    void afisare(ostream&)const;
};

Pasare& Pasare :: operator = (const Pasare& a){
    Vertebrate :: operator = (a);
    this -> zboara = a.zboara;
    return *this;
}

void Pasare :: citire(istream& is = cin){
    Vertebrate :: citire(is);
    if(&is == &cin){
        cout<<"Verificare daca pasarea poate zbura: ";
        is>>zboara;
    }
    else{
        is>>zboara;
    }
}

istream& operator>>(istream& is, Pasare& a){
    a.citire();
    return is;
}

void Pasare :: afisare(ostream& os = cout)const{
    Vertebrate :: afisare(os);
    if(zboara){
        os<<"Pasarea poate zbura\n";
    }
    else{
        os<<"Pasarea nu poate zbura\n";
    }
}
ostream& operator<<(ostream& os, Pasare& a){
    a.afisare();
    return os;
}
