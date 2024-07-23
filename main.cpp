#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

/* BENNABI MALEK       Groupe 02              181832067172  */


struct Heure{

int heure;
int minute;

};

struct Date{
	int jour;
	int mois;
	int annee;
};

struct Vol{

	string ville_depart;
	string ville_arrive;
	Heure heure_depart;
	Heure heure_arrive;
	Date date ;
	
};

int nb(){
    int nbLignes = 0;
    ifstream malek("C:/Users/HP/OneDrive/Desktop/L2 INFORMATIQUE/avion.txt");
    string ligne;
    while(getline(malek, ligne)){
        nbLignes++; }
        
    malek.close(); 
    //cout<< nbLignes<<"lignes.";
    return nbLignes;
}


void Ajout(string vd, string va, Heure hd, Heure ha, Date d){
	
		
    string const nomFichier("C:/Users/HP/OneDrive/Desktop/L2 INFORMATIQUE/avion.txt");
    ofstream malek(nomFichier.c_str(),ios::app);

    if(malek){
        malek << "Ville de depart: "<<vd<< endl<< endl; 
        malek << "Ville arrive: "<<va<< endl<< endl;
        malek << "Heure de depart: "<<setw(2) << setfill('0')<<hd.heure<<":"<<setw(2) << setfill('0')<<hd.minute<< endl<< endl;
        malek << "Heure arrive: "<<setw(2) << setfill('0')<<ha.heure<<":"<<setw(2) << setfill('0')<<ha.minute<< endl<< endl;
        malek << "Date du vol: "<<setw(2) << setfill('0')<<d.jour<<"/"<<setw(2) << setfill('0')<<d.mois<<"/"<<setw(2) << setfill('0')<<d.annee<< endl<<"-----------------------------------------------------"<<endl;		
		
		
		}
        
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl; }
        
        malek.close();	
}


void Lecture(){
	int r1=0,r=0,t;
	t=nb();	
	
	 if(t==0) {
	 cout<<"Fichier vide, Rien a Afficher !";}
	 
	 	 else{
	cout<<"comment voulez vous afficher les vols? "<<endl;
	cout<<"Tout les vols --> 0"<<endl<<"un nombre precis de vols --> 1"<<endl;cin>>r;cout<<endl<<endl;
	if(r==0){
	  ifstream malek("C:/Users/HP/OneDrive/Desktop/L2 INFORMATIQUE/avion.txt");

   if(malek){

      string ligne; 

      while(getline(malek, ligne)){
         cout << ligne << endl; } }
   else{
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;}
      malek.close();
}

else if(r==1){
	cout<<"combien de vols voulez vous afficher? ";cin>>r1;
	if(r1<=0)cout<<"choisissez un nombre valide !"<<endl;
	
	else if((r1*10)>t){
	  cout<<"ce fichier ne contient que "<<t/10<<" vols !"<<endl;}
	  else{ 
	  int i=1;
	  string ligne;
	  
	  ifstream malek("C:/Users/HP/OneDrive/Desktop/L2 INFORMATIQUE/avion.txt");
	  
	  while ( getline(malek, ligne) && i <= (r1*10) ) {
      
	  cout<<ligne<<endl;
      i++;}
	  
	} }
}
}

void detruire(){
	
	ofstream malek("C:/Users/HP/OneDrive/Desktop/L2 INFORMATIQUE/avion.txt");
	 
	 remove("C:/Users/HP/OneDrive/Desktop/L2 INFORMATIQUE/avion.txt");
    
        cout<<"Fichier Vide avec Succes! "<<endl<<endl;

		}


  




int main(int argc, char** argv) {
	
	string a,b,r,z;
	Heure hd,ha;
	Date d;
	int vl=0,choix=1;
	
	       
	       
	       cout<<"Bonsoir";
		   
		   
		   
		   while(choix !=0){
		   
		   cout<<" Que voulez vous faire ? "<<endl<<endl;
		   cout<<"Creer un fichier et ajouter un vol --> 1"<<endl;cout<<"Afficher un ou plusieurs vols --> 2"<<endl;
		   cout<<"Connaitre le nombre de vols --> 3"<<endl;cout<<"Supprimer tout les vols --> 4"<<endl<<"Quitter le Programme --> 0"<<endl;
		   
		  cout<<endl<<"--> ";cin>>choix;
		  
		  if(choix<0 || choix>4) cout<<"Choix invalide !"<<endl;
		  
		  else{
		  
	       
	       switch(choix){
		   
		   case 0: exit(1);
		   
		   	case 1:
	cout<<"entrez la ville Depart: ";cin>>a;cout<<endl;
	cout<<"entrez la ville Arrive: ";cin>>b;cout<<endl;
	cout<<"entrez heure de Depart: "<<endl;cin>>hd.heure;cout<<":"<<endl;cin>>hd.minute;cout<<endl;
	cout<<"entrez heure Arrive: "<<endl;cin>>ha.heure;cout<<":"<<endl;cin>>ha.minute;cout<<endl;
	cout<<"entrez date du Vol: "<<endl;cin>>d.jour;cout<<"/"<<endl;cin>>d.mois;cout<<"/"<<endl;cin>>d.annee;cout<<endl<<endl;
	Ajout(a,b,hd,ha,d);
	
	 cout<<"voulez vous ajouter un autre vol? ";cin>>r;	
	while(r=="oui" || r=="OUI"|| r=="Oui"){
	
	cout<<"entrez la ville Depart: ";cin>>a;cout<<endl;
	cout<<"entrez la ville Arrive: ";cin>>b;cout<<endl;
	cout<<"entrez heure de Depart: "<<endl;cin>>hd.heure;cout<<":"<<endl;cin>>hd.minute;cout<<endl;
	cout<<"entrez heure Arrive: "<<endl;cin>>ha.heure;cout<<":"<<endl;cin>>ha.minute;cout<<endl;
	cout<<"entrez date du Vol: "<<endl;cin>>d.jour;cout<<"/"<<endl;cin>>d.mois;cout<<"/"<<endl;cin>>d.annee;cout<<endl<<endl;


	Ajout(a,b,hd,ha,d);
		cout<<"voulez vous ajouter un autre vol ? ";cin>>r;} break;
		
		case 2: Lecture(); break;
		
		case 3: vl=nb(); cout<<"Il y a "<<vl/10<<" vols !"<<endl; break;
		
		case 4: if(nb()>0){
	   cout<<"supprimer tout le Fichier --> OUI/ NON"<<endl;cin>>z;
     	if(z=="Oui" || z=="OUI" || z=="oui") detruire();} break;
     	
     	
           cout<<"Bonsoir Que voulez vous faire ? "<<endl<<endl;
		   cout<<"Creer un fichier et ajouter un vol --> 1"<<endl;cout<<"Afficher un ou plusieurs vols --> 2"<<endl;
		   cout<<"Connaitre le nombre de vols --> 3"<<endl;cout<<"Supprimer tout les vols --> 4"<<endl<<"Quitter le Programme --> 0"<<endl;
		   
		  cout<<endl<<"--> ";cin>>choix;}}
 }	       
	
	return 0;
}
