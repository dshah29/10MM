

#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class RunAction;

class EventAction : public G4UserEventAction
{
public:
  EventAction(RunAction*);
  virtual ~EventAction();

  void  BeginOfEventAction(const G4Event*);
  void    EndOfEventAction(const G4Event*);
    
  void total_secondary_gammas(G4double);
  void energy_deposit(G4double);
 
private:
   RunAction*  runAct;
   
   G4double  EnergyAbs;
   G4double AddEnergy;

};

#endif

    
