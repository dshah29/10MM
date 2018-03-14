#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "G4ios.hh"
#include "iostream"
#include "Randomize.hh"
#include "globals.hh"
#include "G4UnitsTable.hh"
#include "Randomize.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	

  particleGun = new G4GeneralParticleSource();

}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
	delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  
	particleGun->GeneratePrimaryVertex(anEvent);
	
}
