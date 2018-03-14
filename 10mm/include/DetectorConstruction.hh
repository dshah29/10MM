#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4VPVParameterisation.hh"
#include "G4UnionSolid.hh"
#include "G4IntersectionSolid.hh"
#include "G4BooleanSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4GeometryManager.hh"
#include "G4VisAttributes.hh"
#include "G4Box.hh"
#include "G4Colour.hh"
#include "G4VPVParameterisation.hh"
#include "G4PVParameterised.hh"
#include "G4Region.hh"
#include "G4RegionStore.hh"
#include "G4ProductionCuts.hh"
class G4VPhysicalVolume;
class G4Material;
class DetectorConstruction : public G4VUserDetectorConstruction // INHERITING G4VUserDetectorConstruction class
{
  private:
    G4VPhysicalVolume* ConstructCalorimeter();														//POINTER TO FUCTION OF G4VPhysicalVolume CLASS -- SKG
public:
   DetectorConstruction();
   ~DetectorConstruction();
   G4VPhysicalVolume* Construct();	
														//pointer to function of physical volume class -- skg
   G4Material*        sampleMaterial;
   G4Material* GetSampleMaterial()  {return sampleMaterial;};

   G4Box *motherbox; //world volume
  G4LogicalVolume *motherlogic;//world volume_logic volume
  G4VPhysicalVolume *physi_mother;
     
  G4Box *solidbox;
  G4Box *solidbox1;

  G4LogicalVolume *logic_box; 
  G4VPhysicalVolume *physi_box;

  G4LogicalVolume *logic_box1; 
  G4VPhysicalVolume *physi_box1;

  G4Box *moon;
  G4LogicalVolume *logic_moon; 
  G4VPhysicalVolume *physi_moon;
  
  G4Tubs *solidtube1;
  G4LogicalVolume *logictube1;                                
  G4VPhysicalVolume *physitube1;
 
  G4Tubs *solidtube2; 
  G4LogicalVolume *logictube2;                                
  G4VPhysicalVolume *physitube2;

G4Tubs *detector_window;
  G4LogicalVolume *logic_window;
G4VPhysicalVolume *physi_window;

    G4Tubs *detector_collimator;
  G4LogicalVolume *logic_collimator;
  G4VPhysicalVolume *physi_collimator;

    G4Tubs *silica_collimator;
  G4LogicalVolume *logic_silica_collimator;
  G4VPhysicalVolume *physi_silica_collimator;

  G4Tubs *detector;
  G4LogicalVolume *logic_detector;
  G4VPhysicalVolume *physi_detector;
  
  G4Tubs *detector_backcover; 
  G4LogicalVolume *logic_detector_backcover; 
  G4VPhysicalVolume *physi_detector_backcover;

  G4Cons *cone;
  G4LogicalVolume *cone_logic;                                
  G4VPhysicalVolume *physicone;

  G4Tubs *silica;
  G4LogicalVolume *logic_silica;
  G4VPhysicalVolume *physi_silica;

  G4Tubs *src; 
  G4LogicalVolume *logic_src; 
  G4VPhysicalVolume *src0;
  
  G4VPhysicalVolume *src1;
  
  G4VPhysicalVolume *src2;
  
  G4VPhysicalVolume *src3;

  G4VPhysicalVolume *src4;

  G4VPhysicalVolume *src5;
  
   G4Tubs *src_box; 
  G4LogicalVolume *logic_src_box; 
  G4VPhysicalVolume *src_box0;
  
  G4VPhysicalVolume *src_box1;
  
  G4VPhysicalVolume *src_box2;
  
  G4VPhysicalVolume *src_box3;

  G4VPhysicalVolume *src_box4;

  G4VPhysicalVolume *src_box5;

  G4Tubs *src_box_backcover; 
  G4LogicalVolume *logic_src_box_backcover; 
  G4VPhysicalVolume *src_box0_backcover;
  
  G4VPhysicalVolume *src_box1_backcover;
  
  G4VPhysicalVolume *src_box2_backcover;
  
  G4VPhysicalVolume *src_box3_backcover;

  G4VPhysicalVolume *src_box4_backcover;

  G4VPhysicalVolume *src_box5_backcover;
};

#endif

