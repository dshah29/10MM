#include "RunAction.hh"

#include <stdlib.h>
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include <iomanip>
//G4int energy_count [71];

RunAction::RunAction()
{}


RunAction::~RunAction()
{}

//G4int energy_count [71] = {0};

void RunAction::BeginOfRunAction(const G4Run*)
{ 
  G4RunManager::GetRunManager()->SetRandomNumberStore(true);
  sumEAbs = 0;
  energy_count=(int *)calloc(71,sizeof(int));
}
void RunAction::fillPerEvent(G4double EAbs)
{
  sumEAbs += EAbs;
}

void RunAction::fillenergycount(G4double edep) 
{
	if ((int (edep/100)) <= 70 & edep > 0) 
		energy_count [int((edep/100)+1) ]++; 
}
void RunAction::EndOfRunAction(const G4Run*)
{
  G4int m;
G4cout<<"endofrun";
  //FILE *particlecount;
//particlecount=fopen("/home/goyal/geant4/apxs/new/10mm/particlecount.txt","a");
  std::ofstream particlecount;
  particlecount.open("particlecount.xls");
  for (m = 1; m <= 70; m++)
  {
		  particlecount<< m << "\t" <<energy_count[m]<<G4endl;
	//	fprintf(particlecount, "%d \t", m);
	//	fprintf(particlecount, "%d \n", energy_count[m]);
	
  }
//fclose (particlecount);
  free(energy_count);
}
