
class Peste: public Vertebrate {
private:
    int lungime;
    bool rapitor;
public:
    Peste(int d = 0, int nr = 0, string n = "", int l = 0, bool r = false):Vertebrate(d, nr, n){
        this -> lungime = l;
        this -> rapitor = r;
    }
    Peste(const Peste& a):Vertebrate(a){
        this -> lungime = a.lungime;
        this -> rapitor = a.rapitor;
    }
    ~Peste(){}

     void setter(int d = 0, int nr = 0, string n = "",  int l = 0, bool r = false){
    Vertebrate :: setter(d, nr, n);
    this -> rapitor = r;
    this -> lungime = l;
    }
    void set_rapitor(bool r = false){
    this -> rapitor = r;
    }
    bool get_rapitor(){
    return this -> rapitor;
    }
    void set_lungime(int l = 0){
    this -> lungime = l;
    }
    int get_lungime(){
    return this -> lungime;}

    Peste& operator =(const Peste&);
    friend istream& operator >>(istream&, Peste&);
    friend ostream& operator <<(ostream&, const Peste&);
    void citire(istream&);
    void afisare(ostream&)const;
};
Peste& Peste::operator=(const Peste& a){
    Vertebrate::operator=(a);
    this -> rapitor = a.rapitor;
    this -> lungime = a.lungime;
    return *this;
}

void Peste::citire(istream& is = cin){
    Vertebrate::citire(is);
    if(&is == &cin){
        cout<<"Verificare daca pestele este rapitor: ";
        is>>rapitor;
        cout<<"Lungimea pestelui este:";
        is>>lungime;
    }
    else{
        is>>rapitor>>lungime;
    }
}

istream& operator>>(istream& is, Peste& a){

    a.citire();
    return is;
}

void Peste::afisare(ostream& os = cout)const{
    Vertebrate::afisare(os);
    if(rapitor){
        os<<"Pestele este rapitor\n";
    }
    else{
        os<<"Pestele nu este rapitor\n";
    }
    if(lungime){
        os<<"Lungimea pestelui este: "<<this -> lungime<<endl;
    }
}

ostream& operator<<(ostream& os, Peste& a){
    a.afisare();
    return os;
}

