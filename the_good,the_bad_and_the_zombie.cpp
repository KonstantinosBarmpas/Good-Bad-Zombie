/*
 * the_good,the_bad_and_the_zombie.cpp
 *
 *      Created on: May 2016
 *      Author: Konstantinos Barmpas
 *      Konstantinos Barmpas (el15020) 2o Semester NTUA ECE
 */

#include <iostream>
#include <typeinfo>
#include <list>
#include <random>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Character;

class Person
{
private:
	int hit_points;
	bool is_dead;
	Character* has_character;
public:
	Person (int y2);
	int get_hp();
	bool die (int points);
	string Type (Person pe);
	void hit(Person& p);
	Character* gethas_character() const {return has_character;}
	void sethas_character(Character* c){has_character=c;}
	int gethit_points() const {return hit_points;}
	void sethit_points(int hip){hit_points=hip;}
	bool getis_dead() const {return is_dead;}
	void setis_dead(bool id){is_dead=id;}
};

class Character
{
private:
	int character_points;
	Person* is_attached_to;
public:
	virtual void status() = 0;
    string get_character_type(Person p);
    void lower_hp(){character_points-=10;}
    Person* getis_attached_to()const{return is_attached_to;}
    void setis_attached_to(Person& p){is_attached_to=&p;}
    virtual void attack(Person& p){

    };
    virtual ~Character(){

    };
   Character* convert(Character* c,int y);
   int getcharacter_points() const {return character_points;}
   void setcharacter_points(int cp){character_points=cp;}
};

class Good : public Character {
		void status(){
				 cout << "ok" << endl;
				 }
		virtual ~Good(){

		};
		void virtual attack (Person& p){
			Character* n_character=p.gethas_character();
			string ntype=p.Type(p);
			if (ntype!="4Good"){
			if (ntype=="3Bad"){
					n_character->lower_hp();
					}
				else
			{int x=rand()%100;
		    if (x<20){
			    	x=rand()%100;
				    	if (x<40){
				    n_character=convert(n_character,0);
				    p.sethas_character(n_character);}
				    	else{
				    		n_character=convert(n_character,1);
				    		p.sethas_character(n_character);}
				    	}
				    else{
				    	n_character->lower_hp();
				}
}
		}
		}
	};

class Bad : public Character {
		void status(){
				 cout << "ok" << endl;
			 }
		virtual ~Bad(){

		};
		void virtual attack (Person& p){
			Character* n_character=p.gethas_character();
			string ntype=p.Type(p);
			if (ntype!="3Bad"){
		n_character->lower_hp();}
		}
	};

class Zombie : public Character {
		void status(){
				 cout << "ok" << endl;
			 }
		virtual ~Zombie(){

		};
		void virtual attack (Person& p){
		Character* n_character=p.gethas_character();
			string ntype=p.Type(p);
			if (ntype!="6Zombie"){
			int x=rand()%100;
			if (x<10){
				n_character=convert(n_character,2);
				p.sethas_character(n_character);
			}else{
			n_character->lower_hp();
			}
		}
		}
	};

string Character :: get_character_type(Person p){
Character* c=p.gethas_character();
string type=typeid(*c).name();
return type;
}

Person :: Person(int y2){
			switch(y2){
			case 0:
			has_character=new Good;
			break;
			case 1:
			has_character=new Bad;
			break;
			case 2:
			has_character=new Zombie;
			break;
			default:
			cout<<"error"<<endl;
			}
			hit_points=100;
			is_dead=false;
}

string Person :: Type (Person p){
string type =p.has_character->get_character_type(p);
return type;
}

int Person :: get_hp(){
	return hit_points;
}

bool Person :: die (int points){
	if (points==0){
		is_dead=true;
	}
	return is_dead;
}

void Person :: hit(Person& p){
	has_character->attack(p);
	int y=p.has_character->getcharacter_points();
	p.sethit_points(y);
	p.gethas_character()->setis_attached_to(p);
}

Character* Character :: convert(Character* c,int y){
int temp=c->character_points;
delete c;
switch (y){
case 0:
    c=new Good;
	break;
case 1:
	c=new Bad;
	break;
case 2:
	c=new Zombie;
	break;
default:
	cout<<"error convert"<<endl;
}
c->character_points=temp;
return c;
}

class World
{
	private: list<Person> pList;
	public:
World (int y1){
for (int i=1; i<=y1; i++){
	int y;
	y = rand() % 3;
	Person p(y);
	p.gethas_character()->setis_attached_to(p);
	p.gethas_character()->setcharacter_points(p.gethit_points());
	pList.push_back(p);
}
}

void Game(){
	int i=1;
	bool done=true;
	list<Person> :: iterator it;
	list<Person> :: iterator in;
	list<Person> :: iterator a;
	in=pList.begin();
    in++;
    while (i<=100 and done==true){
    it=pList.begin();
    while (it!=pList.end()){
	if (in==pList.end()){in=pList.begin();}
	Person pe=*it;
	Person next=*in;
	pe.hit(*in);
	next=*in;
	int attack_points=next.get_hp();
    bool inactive=next.die(attack_points);
	if (inactive==true){
		in=pList.erase(in);
		if (in==pList.end()){
		in=pList.begin();
		in++;
		it=pList.begin();
		break;
		}
		else{
		in++;
		it++;}
	}else{
   in++;
   it++;}
   }
    a=pList.begin();
    Person pe=*a;
    string k3=pe.Type(pe);
bool  done1=true;
cout<<"[";
for (a=pList.begin(); a!=pList.end(); a++){
	   Person pe=*a;
	   if (k3!=pe.Type(pe) and done1==true){
		   done1=false;
	   }
	   cout<<pe.Type(pe)<<"-"<<pe.get_hp()<<" ";
   }
cout<<"]"<<endl;
   if (done1==true){
	   done=false;
   }
i++;
    }
}
};

int main ()
{
	int seed=999,size;
	srand (seed);
	//srand (time(NULL));
	cout<<"exo valei ston kodika os seed=999"<<endl;
	cout<<"epeisis iparxei sthn main os sxolio tin time(NULL)"<<endl;
	cout<<"den ixera ama xreiazete ston elexo sas"<<endl;
	cout<<" "<<endl;
	cout<<"Give size of your virtual world"<<endl;
	cin>>size;
    World w(size);
	w.Game();
	return 0;
}







