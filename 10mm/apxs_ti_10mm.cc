
#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "Randomize.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "SteppingVerbose.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

int main(int argc,char** argv)
{
  
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  
 
  G4VSteppingVerbose::SetInstance(new SteppingVerbose);

  G4RunManager * runManager = new G4RunManager;


  DetectorConstruction* detector = new DetectorConstruction;
  runManager->SetUserInitialization(detector);

  PhysicsList* physics = new PhysicsList;
  runManager->SetUserInitialization(physics);

  PrimaryGeneratorAction* gen_action = 
                          new PrimaryGeneratorAction();
  runManager->SetUserAction(gen_action);

  RunAction* run_action = new RunAction;  
  runManager->SetUserAction(run_action);

  EventAction* event_action = new EventAction(run_action);
  runManager->SetUserAction(event_action);

  SteppingAction* stepping_action =
                    new SteppingAction(event_action);
  runManager->SetUserAction(stepping_action);

  runManager->Initialize();
  /*  
#ifdef G4VIS_USE
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
#endif*/

  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if (argc!=1)   // batch mode
    {
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
    }
  else
    { 
#ifdef G4UI_USE
      G4UIExecutive* ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
      UImanager->ApplyCommand("/control/execute vis.mac"); 
#endif
      if (ui->IsGUI())
	UImanager->ApplyCommand("/control/execute gui.mac");
      ui->SessionStart();
      delete ui;
#endif
    }
  /*
#ifdef G4VIS_USE
  delete visManager;
#endif*/
  delete runManager;

  return 0;
}
