#include <typeinfo>
template <class T = Animal> class AtlasZoologic{
	private:
		list <T> animale;
		int n;
    public:
        AtlasZoologic(){
        n = 0;
        cout<<typeid(*this).name()<<"\n";

        }
		~AtlasZoologic(){}
		list<T> get_animale(){
		return this -> animale;}
		int get_n(){
		return this -> n;}
		const AtlasZoologic& operator+=(T a){
			this -> animale.push_back(a);
			this -> n++;
			return *this;
			}

        friend istream& operator >>(istream& is, AtlasZoologic<T>& at){
		    if(&is == &cin){
             cout<<"n = ";
		    }
            is>>at.n;
            T aux;
            for(int i = 0; i < at.n; i++){
                is>>aux;
                at.animale.push_back(aux);
            }

            return is;
		}
		friend ostream& operator <<(ostream& os, AtlasZoologic<T>& at){
            for (auto& i: at.obiecte) {
                os << i << "\n";
            }
            return os;
		}
};

template<> class AtlasZoologic <Peste>{
	private:
	    list <Peste> obiecte;
		int n;
		int pesti;
	public:
		AtlasZoologic(){
            n = 0;
            pesti = 0;
		}

		const AtlasZoologic& operator+=(Peste a){
			this -> obiecte.push_back(a);
			this -> n++;
			if (a.get_rapitor() && a.get_lungime()>1){
				this -> pesti++;
			}
			return *this;
		}
		list <Peste> get_obiecte(){
			return obiecte;
		}
		int get_pesti(){
			return this -> pesti;
		}

		friend istream& operator >>(istream& is, AtlasZoologic<Peste>& at){
		    if(&is == &cin){
             cout<<"n = ";
		    }
            is>>at.n;
            Peste aux;
            for(int i = 0; i < at.n; i++){
                is>>aux;
                at.obiecte.push_back(aux);
                if (aux.get_rapitor() && aux.get_lungime()>1){
                    at.pesti++;
                }
            }

            return is;
		}
		friend ostream& operator <<(ostream& os, AtlasZoologic<Peste>& at){
		    os<<"In total sunt "<<at.pesti<<" pesti rapitori cu lungime de cel putin 1 metru\n";
            for (auto& i: at.obiecte) {
                os << i << "\n";
            }
            return os;
		}
};


