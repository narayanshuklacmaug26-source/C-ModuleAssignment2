//============================================================================
// Name        : GameEngineSystem.cpp
// Author      : Narayan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;



class Entity{

private:

	string name;
	int health;
	int level;
	string type;


public :

	Entity& setName(const string& name){
		this->name=name;
		return *this;
	}

	Entity&  setHealth(int health){
		this->health=health;
		return *this;

	}

	Entity& setLevel(int level){
		this->level=level;
		return *this;

	}


	Entity& setType(const string& type){
		this->type=type;
		return *this;
	}



	string getName() const{
		return name;
	}

	int getHealth() const{
		return health;
	}

	int getLevel() const{
		return level;

	}
	string getType()const{
		return type;
	}


	void displayInfo()const {
		cout<<" Name is "<<name<<endl;
		cout<<" Health is "<<health<<endl;
		cout<<" level is "<<level<<endl;
		cout<<" Type is "<<type<<endl;
	}

};


namespace Physics{

    double clamp(double val,double min,double max){

    	if(val<min){
    		return min;
    	}
    	if(val>max){
    		return max;
    	}
    	return val;
    }

    	double lerp(double a, double b, double t){
    		return  a+(b-a)*t;

    }
}


namespace GameMath{

  int clamp(int val,int min,int max){
	  if(val<min){
		  return min;
	  }

	  if(val>max){
		  return max;
	  }

	  return val;
  }

  double lerp(double a,double b,double t){
	  return a+(b-a)*t;
  }

}


int main() {

	Entity player,enemy,item;
	player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player"); // This is called method chaining.
	enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
	item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");
	player.displayInfo();
	enemy.displayInfo();
	item.displayInfo();


	cout<<GameMath::lerp(15.0, 0.0, 10.0)<<endl;
	cout<<Physics::lerp(12.00, 4.00,6.00)<<endl;
	cout<<Physics::clamp(15.5, 0.0, 10.0) << endl;
	cout<<GameMath::clamp(15, 0, 10) << endl;


	int r,c;
	cout<<"Enter a rows"<<endl;
	cin>>r;
	cout<<"Enter a column"<<endl;
	cin>>c;

	int **map= new int*[r]; // Allocate outer array
	for(int i=0;i<r; i++){ // Allocate  each row
		map[i]=new int[c];
	}

	srand(time(0));

	// Fill map

	for(int i=0;i<r; i++){
		for(int j=0;j<c; j++){
			map[i][j]=rand()%5;
		}
	}


	// Display map
	cout<<"\n====Game map("<<r<<"x"<<c<<")====="<<endl;

	for(int i=0; i<r; i++){
		for(int j=0;j<c; j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}


	//Legend
	cout<<"\nLegend: "<<"0=Grass "<<"1=water "<<"2=Mountain "<<"3=Forest "<<"4=Dungeon "<<endl;



	//counters

	int grass=0;
	int water=0;
	int mountain=0;
	int forest=0;
	int dungeon=0;

	//Count tiles
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			switch(map[i][j]){

			case 0:
				grass++;
				break;

			case 1:
				water++;
				break;
			case 2:
				mountain++;
				break;
			case 3:
				forest++;
				break;
			case 4:
				dungeon++;
				break;

			}
		}

	}


	// Display count
	cout<<"\n Tile count "<<endl;
	cout<<"Grass : "<<grass<<endl;
	cout<<"Water: "<<water<<endl;
	cout<<"Mountain : " << mountain << endl;
	cout<<"Forest   : " << forest << endl;
	cout<<"Dungeon  : " << dungeon << endl;



    // ---------- BONUS: Scope Resolution ----------

    int level = 10;

    cout << "\n===== SCOPE RESOLUTION =====" << endl;

    cout << "Local level  : " << level << endl;
    cout << "Global level : " << ::level << endl;


    // Nested namespace
    Engine::Audio::playSound("sword_clash");


    // ---------- DEALLOCATE MEMORY ----------

    for (int i = 0; i < r; i++)
    {
        delete[] map[i];
    }

    delete[] map;



	return 0;
}
