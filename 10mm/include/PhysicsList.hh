
#ifndef PHYSICSLIST_HH
#define PHYSICSLIST_HH 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class PhysicsList: public G4VUserPhysicsList
{
  public:
    PhysicsList();
   ~PhysicsList();

  protected:
    void ConstructParticle();
    void ConstructProcess();
	virtual void AddTransportation();
 
    void SetCuts();
    void ConstructBosons();
    void ConstructLeptons();
    void ConstructMesons();
    void ConstructBaryons();

   virtual void ConstructGeneral();
    virtual void ConstructEM();
  
  private:
   
};


#endif

 
