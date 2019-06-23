#include <iostream>
#include <vector>

/* SAMMENDRAG

Dette forslaget baseres på at vi arbeider med Entities og Components
En EntityManager styrer alle Entities
Hver Entity har en rekke Components
Forskjellige Entities trenger ikke ha samme mengde Components
Dersom vi f.eks. ønsker at en Entity skal påvirkes av fysikk så gir vi den en fysikk-component (Dette kaller jeg en Rigidbody component)
Jeg bruker navn som resonerer mer med meg, er ikke så viktig hva de heter. Litt oversettelse fra begrepene du brukte:
Object = Entity
Physical = Rigidbody
Position = Translation // ikke helt det samme, beskrives lenger ned
 
*/

class Entity;
class Component;

using ComponentID = std::size_t; // size_t er basically 'unsigned int', men vi unngår mulige feil dersom vi går over til 64-bit

// vi trenger ikke tenke på å resirkulere ID for slettede Components, siden vi har ca. 4 billioner IDer å ta fra hehe
inline ComponentID getComponentID() {
	static ComponentID lastID = 0;
	return lastID++;
}

//definer vektor i 2D //

struct Vector2f
{
	float x, y;
};

// Base class
class Component {
    public:
	Entity* entity; // Komponenten er koblet til en Entity
};


// Transform-komponent som beskrives objektets posisjon, rotasjon og skalering
class Transform: public Component {
/*
Translation vs Position

'Translation means to do a local translation while setting position doesn't account for rotation.'

Kanskje bare bruke position i stedet for begge deler?
*/

	protected: Vector2f translation, rotation, scale; //float scale for uniform scale
	
	public: Transform() {
		this->scale = { 1.0f, 1.0f }; // default scale
		// translation og rotation blir satt lik {0, 0} per default håper jeg
	}
};

// Vi utfører physics på denne komponenten. Den skal inneholder metoder for beregning av kraft, akselerasjon osv.
class Rigidbody: public Component {
	protected:
	float mass;
	Vector2f velocity, acceleration;

	public:
	Rigidbody() {
		this->mass = 1.0f; // default mass
		// velocity og acceleration blir satt lik (0, 0) per default håper jeg
	}
};


// Flere eksempler på Component-typer:

class Collider: public Component { };
class Sprite: public Component { };
class Audio: public Component { };
class Renderer: public Component { };


// Hovedobjektene vi vil lage instanser av. Disse har en liste av Components som til sammen beskriver hva dette objektet 'er'.
class Entity {

	protected:
	// En liste over komponenter knyttet til denne. std::vector er en array med ubestemt størrelse
	std::vector<Component> components; 
    
	public:
	// Default konstruktør - oppretter et tomt hovedobjekt
	Entity() {

	}

	// Alternativ konstruktør - dersom man ønsker å opprette et hovedobjekt med bestemte komponenter
	Entity(Component components[]) {
		// this->components = components; // Dette virker ikke?
	};
	

	// Har nå mulighet til å legge til nye, og fjerne, komponenter (fysikk/materiale/navigasjon(AI)/audio) - selv i Runtime
	int AddComponent(Component component) { };


	// Kanskje hver komponent kan ha en 'index' som forteller hvor i listen over hovedobjektets komponenter den ligger.
	int RemoveComponent(Component component) { }; // Eller void RemoveComponent(int index) {};

	// Oppretter en instans av Entity objektet
	void Instantiate(Vector2f position) { };
};

// Denne har kontroll over alle Entities i spillet
class EntityManager {
	protected:
	Entity entities[];
};


int main() {

	// Eksempel - lag et objekt og gi det fysiske egenskaper:
	Entity entity; // Oppretter nytt objekt (dette skal egentlig EntityManager gjøre)
	Rigidbody rigidbody; // Oppretter komponent med fysiske egenskaper
	Component& componentRef = rigidbody; // Konverter til en Component type
	entity.AddComponent(rigidbody); // Angir hovedobjektet den nye komponenten

	Vector2f spawnposition = {0, 0};
	entity.Instantiate(spawnposition); // Oppretter en instans av hovedobjektet
	return 0;
}

