
class Animal{

protected:

    int durata_de_viata;
    int nr_membre;
    string nume;

public:

    Animal(int d = 0, int nr = 0, string n = ""){
         durata_de_viata = d;
         nr_membre = nr;
         nume = n;
    }

    Animal( const Animal& a){
    this -> durata_de_viata = a.durata_de_viata;
    this -> nr_membre = a.nr_membre;
    this -> nume = a.nume;
    }

    ~Animal(){}

    int getViata() {
        return durata_de_viata; }
    int getMembre() {
        return nr_membre; }
    string getNume() {
        return nume; }

    void setter(int d = 0, int nr = 0, string n = "")
    {
    this -> durata_de_viata = d;
    this -> nr_membre = nr;
    this -> nume = n;
    }

    void set_durata_de_viata(int d = 0){
         this -> durata_de_viata = d;}
    void set_nr_membre(int nr = 0){
        this -> nr_membre = nr;}
    void set_nume( string n = ""){
        this -> nume = n;}

    virtual Animal& operator =(const Animal&);
    friend istream& operator >>(istream&, Animal&);
    friend ostream& operator <<(ostream&, const Animal&);
    virtual void citire(istream&);
    virtual void afisare(ostream&)const;
};

Animal& Animal::operator = (const Animal& a){
    this -> durata_de_viata = a.durata_de_viata;
    this -> nr_membre = a.nr_membre;
    this -> nume = a.nume;
    return *this;
}

void Animal::afisare(ostream& os = cout)const{
    if(nume.length()){
        os<<"Numele animalului este "<<this -> nume<<endl;
    }
    if(durata_de_viata){
        os<<"Animalul traieste "<<this -> durata_de_viata<<endl;
    }
    if(nr_membre){
        os<<"Animalul are "<<this -> nr_membre<<" membre"<<endl;
    }
}

ostream& operator <<(ostream& os, const Animal& ob){
    ob.afisare(os);
    return os;
}

void Animal::citire(istream& is = cin){
    if(&is == &cin){
        cout<<"Introduceti numele animalului: ";
        is>>nume;
        cout<<"Introduceti speranta de viata a animalului: ";
        is>>durata_de_viata;
        cout<<"Introduceti numarul de membre al animalului: ";
        is>>nr_membre;
    }
    else{
        is>>nume>>durata_de_viata>>nr_membre;
    }
}

istream& operator >>(istream& is, Animal& ob){
    ob.citire(is);
    return is;
}




