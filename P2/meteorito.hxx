#include <vector>

/*****************************************************************/
  defM::defM(){

    code = vector<string>();
    mas=0.0;
    fall=false;
    year="";
    lat=0;  
    lon=0;
  }

/*****************************************************************/

  defM::defM(const defM & x){

    code=x.code;
    mas=x.mas;
    fall=x.fall;
    year=x.year;
    lat=x.lat;
    lon=x.lon;
  }

/*****************************************************************/

  bool defM::setCode(const string & s){

    bool correcto;

    if (/*(find(code.begin(),code.end(),s) == code.end()) && */(s != "")){

      code.push_back(s);
      correcto = true;
    }

    else{

      correcto = false;
    }

    return correcto;
  }

/*****************************************************************/
  
  void defM::setMas(const double &  m){

    mas = m;
  }

/*****************************************************************/

  void defM::setFall(bool f){

    fall = f;
  }

/*****************************************************************/

  void defM::setYear(const string & y){

    year = y;
  }

/*****************************************************************/

  void defM::setLat(double & l){

    lat = l;
  }

/*****************************************************************/

  void defM::setLong(double & l){

    lon = l;
  }

/*****************************************************************/

  vector<string> defM::getCodes(){

    return code;
  }

/*****************************************************************/

  double defM::getMas(){

    return mas;
  }

/*****************************************************************/

  bool defM::getFall(){

    return fall;
  }

/*****************************************************************/

  string defM::getYear(){

    return year;
  }

/*****************************************************************/

  double defM::getLat(){

    return lat;
  }

/*****************************************************************/

  double defM::getLong(){

    return lon;
  }

/*****************************************************************/

  ostream& operator<< ( ostream& os, const defM & def){

    for(int i=0; i < def.code.size(); i++){

       os << def.code[i] << ",";

    }

    os << ";";
    
    if(def.mas != 0)
        os << def.mas;
    
    os << ";";
  
    if(def.fall)
        os << "Found";
    else
        os << "Fell";
  
    os << ";";
    os << def.year;
    os << ";";
    
    if(def.lat != 0)
        os << def.lat;
    
    os << ";";
  
    if(def.lon != 0)
        os << def.lon;

    return os;
}


/*****************************************************************/

ostream & operator<< ( ostream& os, const meteorito & m){

  os << m.first << ";" << m.second;

  return os;

}

/*****************************************************************/