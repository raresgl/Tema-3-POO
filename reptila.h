class Reptila: public Vertebrate {
private:
    string habitat;
public:
    Reptila(int d = 0, int nr = 0, string n = "", string h = ""):Vertebrate(d, nr, n){
    this -> habitat = h;
    }
    Reptila(const Reptila& a):Vertebrate(a){
    this -> habitat = a.habitat;
    }
    ~Reptila(){}

    void setter(int d = 0, int nr = 0, string n = "", string h = ""){
    Vertebrate::setter(d, nr, n);
    this -> habitat = h;
    }
    void set_nume( string h = ""){
        this -> habitat = h;}

    string get_habitat() {
        return habitat; }

    Reptila& operator =(const Reptila&);
    friend istream& operator >>(istream&, Reptila&);
    friend ostream& operator <<(ostream&, const Reptila&);
    void citire(istream&);
    void afisare(ostream&)const;
};

Reptila& Reptila :: operator =( const Reptila& a){
    Vertebrate :: operator = (a);
    this -> habitat = a.habitat;
    return *this;
}

void Reptila::citire(istream& is = cin){
    Vertebrate::citire(is);
    if(&is == &cin){
        cout<<"Introduceti habitatul din care reptila face parte: "; // habitatul reprezinta mediul in care traieste: desert, jungla etc
        is>>habitat;
    }
    else{
        is>>habitat;
    }
}

istream& operator>>(istream& is, Reptila& a){
    a.citire();
    return is;
}

void Reptila::afisare(ostream& os = cout)const{
    Vertebrate::afisare(os);
    if(habitat.length()){
        os<<"Habitatul din care reptila face parte este: "<<this -> habitat<<endl;
    }
}

ostream& operator<<(ostream& os, Reptila& a){
    a.afisare();
    return os;
}


