

#include "globals.hh"

#include "PhysicsList.hh"

#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"


#include "G4ParticleDefinition.hh"
#include "G4ParticleWithCuts.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"
#include "SteppingVerbose.hh"
#include "DetectorConstruction.hh"
#include "EventAction.hh"
#include "PhysicsList.hh"

#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"

#include "G4LowEnergyCompton.hh"
#include "G4LowEnergyGammaConversion.hh"
#include "G4LowEnergyPhotoElectric.hh"
#include "G4LowEnergyRayleigh.hh"
#include "G4LowEnergyIonisation.hh"
#include "G4LowEnergyBremsstrahlung.hh"

#include "G4eMultipleScattering.hh"
#include "G4hMultipleScattering.hh"

#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"
#include "G4hIonisation.hh"
#include "G4ionIonisation.hh"
#include "G4ParticleTable.hh"
#include "G4hImpactIonisation.hh"

#include "G4ProductionCutsTable.hh"

#include "G4hLowEnergyIonisation.hh"
#include "globals.hh"
#include "G4ios.hh"
#include <iomanip>

#include "G4LeptonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BosonConstructor.hh"
#include "G4ShortLivedConstructor.hh"
#include "G4IonConstructor.hh"
PhysicsList::PhysicsList():  G4VUserPhysicsList()
{
  defaultCutValue = 0.001*mm;
   SetVerboseLevel(1);

 
 }


PhysicsList::~PhysicsList()
{}


void PhysicsList::ConstructParticle()
{
  G4LeptonConstructor aC1;
  G4BaryonConstructor aC2;
  G4MesonConstructor aC3;
  G4BosonConstructor aC4;
  G4IonConstructor aC5;
  G4ShortLivedConstructor aC6;
  
  aC1.ConstructParticle();
  aC2.ConstructParticle();
  aC3.ConstructParticle();
  aC4.ConstructParticle();
  aC5.ConstructParticle();
  aC6.ConstructParticle();
}

void PhysicsList::ConstructProcess()
{
  AddTransportation();
  ConstructEM();
  ConstructGeneral();
  //AddStepMax();
}

void PhysicsList::AddTransportation() 
{

  G4VUserPhysicsList::AddTransportation();
  
}

void PhysicsList::ConstructEM()
{
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){


    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* processManager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
     
    if (particleName == "gamma") {

      // photon   

      G4LowEnergyPhotoElectric* photoelectric = new G4LowEnergyPhotoElectric();
      photoelectric->ActivateAuger(true);
      photoelectric->SetCutForLowEnSecPhotons(0.25 * keV);
      photoelectric->SetCutForLowEnSecElectrons(0.25 * keV);
      G4LowEnergyCompton* compton = new G4LowEnergyCompton;
      G4LowEnergyGammaConversion* gammaConversion = new G4LowEnergyGammaConversion;
      G4LowEnergyRayleigh* rayleigh = new G4LowEnergyRayleigh;

      processManager -> AddDiscreteProcess(photoelectric);
      processManager -> AddDiscreteProcess(compton);
      processManager -> AddDiscreteProcess(gammaConversion);
      processManager -> AddDiscreteProcess(rayleigh);
    
    } else if (particleName == "e-") {

      // electron

      G4eMultipleScattering* eMultipleScattering = new G4eMultipleScattering();
      G4LowEnergyIonisation* eIonisation = new G4LowEnergyIonisation();
      G4LowEnergyBremsstrahlung* eBremsstrahlung = new G4LowEnergyBremsstrahlung();

      processManager -> AddProcess(eMultipleScattering, -1, 1, 1);
      processManager -> AddProcess(eIonisation, -1, 2, 2);
      processManager -> AddProcess(eBremsstrahlung, -1, -1, 3);   

    } else if (particleName == "e+") {
      // positron
      processManager->AddProcess(new G4eMultipleScattering, -1, 1, 1);
      processManager->AddProcess(new G4eIonisation,         -1, 2, 2);
      processManager->AddProcess(new G4eBremsstrahlung,     -1, 3, 3);
      processManager->AddProcess(new G4eplusAnnihilation,    0,-1, 4);

             
    } else if( particleName == "proton" ||
               particleName == "pi-" ||
               particleName == "pi+"    ) {
      //proton  

      G4hLowEnergyIonisation* hIoni = new G4hLowEnergyIonisation();
      hIoni->SetFluorescence(true);
      G4hImpactIonisation* hIonisation = new G4hImpactIonisation();
      hIonisation->SetPixeCrossSectionK("ecpssr");
      hIonisation->SetPixeCrossSectionL("ecpssr");
      hIonisation->SetPixeCrossSectionM("ecpssr");
      hIonisation->SetPixeProjectileMinEnergy(1.* keV);
      hIonisation->SetPixeProjectileMaxEnergy(200. * MeV);
      hIonisation->SetCutForSecondaryPhotons(250. * eV);
      hIonisation->SetCutForAugerElectrons(250. * eV);

      G4hMultipleScattering* hMultipleScattering = new G4hMultipleScattering();

      processManager -> AddProcess(hMultipleScattering, -1, 1, 1);   
      processManager -> AddProcess(hIonisation, -1, 2, 2);
     
    } else if( particleName == "alpha" || 
	       particleName == "He3" ||
	       particleName == "pi-" ||
               particleName == "pi+" ||
	       particleName == "GenericIon" ) {

      // pions, alpha, ions (should never occur in the current example) 
	G4hLowEnergyIonisation* hIoni = new G4hLowEnergyIonisation();
	hIoni->SetFluorescence(true);	
      G4hImpactIonisation* hIonisation = new G4hImpactIonisation();
      hIonisation->SetPixeCrossSectionK("ecpssr");
      hIonisation->SetPixeCrossSectionL("ecpssr");
      hIonisation->SetPixeCrossSectionM("ecpssr");
      hIonisation->SetPixeProjectileMinEnergy(1.* keV);
      hIonisation->SetPixeProjectileMaxEnergy(200. * MeV);
      hIonisation->SetCutForSecondaryPhotons(250. * eV);
      hIonisation->SetCutForAugerElectrons(250. * eV);
      processManager->AddProcess(new G4hMultipleScattering, -1, 1, 1);
      processManager->AddProcess(new G4ionIonisation,       -1, 2, 2);
                      
    } else if ((!particle->IsShortLived()) &&
	       (particle->GetPDGCharge() != 0.0) && 
	       (particle->GetParticleName() != "chargedgeantino")) {
      //all others charged particles except geantino
      processManager->AddProcess(new G4hMultipleScattering, -1, 1, 1);
      processManager->AddProcess(new G4hIonisation,         -1, 2, 2);
    }
  }
}

#include "G4Decay.hh"

void PhysicsList::ConstructGeneral()
{
  // Add Decay Process
  G4Decay* theDecayProcess = new G4Decay();
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* processManager = particle->GetProcessManager();
    if (theDecayProcess->IsApplicable(*particle)) { 
      processManager ->AddProcess(theDecayProcess);
      // set ordering for PostStepDoIt and AtRestDoIt
      processManager ->SetProcessOrdering(theDecayProcess, idxPostStep);
      processManager ->SetProcessOrdering(theDecayProcess, idxAtRest);
    }
  }
}
  


void PhysicsList::SetCuts()
{

  SetCutsWithDefault();

  G4double lowLimit = 100. * eV;
  G4double highLimit = 100. * GeV;
  G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(lowLimit, highLimit);
     
  if (verboseLevel>0) DumpCutValuesTable();
}

