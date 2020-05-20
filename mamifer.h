class Mamifer: public Vertebrate{
private:
    bool extinct; // daca este animal pe cale de disparitie
    int greutate;
    string tip; // daca e erbivor, omnivor sau carnivor
public:
    Mamifer(int v = 0, int m = 0, string n = "", bool e = false, int g = 0, string t = ""):Vertebrate(v, m, n){
    this -> extinct = e;
    this -> greutate = g;
    this -> tip = t;
    }
    Mamifer(const Mamifer& a):Vertebrate(a){
    this -> extinct = a.extinct;
    this -> greutate = a.greutate;
    this -> tip = a.tip;
    }
    ~Mamifer(){}

    bool get_extinct(){
    return this -> extinct;}
    int get_greutate(){
    return this -> greutate;}
    string get_tip(){
    return this -> tip;}

    void setter(int d = 0, int nr = 0, string n = "", bool e = false, int g = 0,string t = ""){
    Vertebrate::setter(d, nr, n);
    this -> extinct = e;
    this -> greutate = g;
    this -> tip = t;
    }

    void set_extinct(bool e = false){
    this -> extinct = e;
    }

    void set_greutate(int g = 0){
    this -> greutate = g;
    }

    void set_tip(string t = ""){
        this -> tip = t;
    }

    Mamifer& operator =(const Mamifer&);
    friend istream& operator >>(istream&, Mamifer&);
    friend ostream& operator <<(ostream&, const Mamifer&);
    void citire(istream&);
    void afisare(ostream&)const;
};

Mamifer& Mamifer :: operator = (const Mamifer& a){
    Vertebrate::operator = (a);
    this -> extinct = a.extinct;
    this -> greutate = a.greutate;
    this -> tip = a.tip;
    return *this;
}

void Mamifer :: citire(istream& is = cin){
    Vertebrate :: citire(is);
    if(&is == &cin){
        cout<<"Verificam daca mamiferule este pe cale de disparitie: ";
        is>>extinct;
        cout<<"Completati greutatea mamiferului: ";
        is>>greutate;
        cout<<"Introduceti ce alimentatie are mamiferul: ";
        is>>tip;

    }
    else{
        is>>extinct>>greutate>>tip;
    }
}

istream& operator>>(istream& is, Mamifer& a){
    a.citire();
    return is;
}

void Mamifer::afisare(ostream& os = cout)const{
    Vertebrate::afisare(os);
    if(extinct){
        os<<"Mamiferul este pe cale de disparitie.\n";
    }
    else{
        os<<"Mamiferul nu este pe cale de disparitie.\n";
    }
    if (greutate){
        os<<"Mamiferul cantareste "<<this -> greutate<<endl;
    }
    if (tip.length()){
        os<<"Mamiferul este "<<this -> tip<<endl;
    }
}

ostream& operator<<(ostream& os, Mamifer& a){
    a.afisare();
    return os;
}




