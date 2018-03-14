

#include "EventAction.hh"

#include "RunAction.hh"

#include "G4Event.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>
EventAction::EventAction(RunAction* run)
:runAct(run)
{
}

EventAction::~EventAction()
{
}
  void EventAction::total_secondary_gammas(G4double de)
  {
	  EnergyAbs += de;
  }
  void EventAction::energy_deposit(G4double edep)
  {
	  AddEnergy += edep;
  }
void EventAction::BeginOfEventAction(const G4Event*)
{
 EnergyAbs = 0;
 AddEnergy = 0;
}

void EventAction::EndOfEventAction(const G4Event*)
{
  runAct->fillPerEvent(EnergyAbs);
  runAct->fillenergycount(AddEnergy);
	  
}  
