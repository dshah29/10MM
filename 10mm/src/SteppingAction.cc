
#include "SteppingAction.hh"
#include "EventAction.hh"

#include "G4Step.hh"
SteppingAction::SteppingAction(EventAction* evt)
:eventaction(evt)					 
{ }

SteppingAction::~SteppingAction()
{ }

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
  G4double edep = aStep->GetTotalEnergyDeposit();
  G4Track* track=aStep->GetTrack();
  G4ParticleDefinition* particle=track->GetDefinition();
  G4String particleName = particle->GetParticleName();
  G4String physicname=aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName();

  if (physicname == "physi_silica" & (edep/eV) > 0)
	{
		  eventaction->total_secondary_gammas(1);
		  eventaction->energy_deposit(edep/eV);
	}
}
