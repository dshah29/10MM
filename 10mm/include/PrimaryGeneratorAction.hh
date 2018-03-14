#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;
class G4GeneralParticleSource;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event* anEvent);
    G4ParticleGun* GetParticleGun();

  private:
	G4GeneralParticleSource* particleGun;

};

#endif

