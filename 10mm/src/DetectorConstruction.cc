#include "DetectorConstruction.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
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
DetectorConstruction::DetectorConstruction(){}

G4VPhysicalVolume* DetectorConstruction::Construct()
{return ConstructCalorimeter();}

G4VPhysicalVolume* DetectorConstruction::ConstructCalorimeter()
{
  G4double startangle = 0.*deg;
  G4double spanningangle = 360.*deg;
  G4String symbol;     

  //G4double a, z;
  G4double density, fractionmass;  
  G4int ncomponents;// natoms;
  

 G4Element* O = new G4Element("Oxygen"  ,"O" , 3);
 G4Isotope* O16 =new G4Isotope ("O16",8,16,16*g/mole);
  G4Isotope* O17 =new G4Isotope ("O17",8,17,17*g/mole);
  G4Isotope* O18 =new G4Isotope ("O18",8,18,18*g/mole);
  O->AddIsotope(O16,0.9976);
  O->AddIsotope(O17,0.00038);
  O->AddIsotope(O18,0.00204);

 G4Element* Na = new G4Element("Sodium"  ,"Na" , 1);
  G4Isotope* Na23 =new G4Isotope ("Na23",11,23,23*g/mole);
  Na->AddIsotope(Na23,1.0);

G4Element* Mg = new G4Element("Magnesium"  ,"Mg" , 3);
 G4Isotope* Mg24 =new G4Isotope ("Mg24",12,24,24*g/mole);
  G4Isotope* Mg25 =new G4Isotope ("Mg25",12,25,25*g/mole);
  G4Isotope* Mg26 =new G4Isotope ("Mg26",12,26,26*g/mole);
Mg->AddIsotope(Mg24,0.7899);
  Mg->AddIsotope(Mg25,0.1000);
  Mg->AddIsotope(Mg26,0.1101);

 
  G4Isotope* Al27 = new G4Isotope("Al27", 13, 27, 27*g/mole); 
  G4Element* Al = new G4Element("Aluminium"  ,"Al" , 1);
  Al->AddIsotope (Al27, 1.0);

  G4Element* Si = new G4Element("Silicon"  ,"Si" , 3);
  G4Isotope* Si28 =new G4Isotope ("Si28",14,28,28*g/mole);
  G4Isotope* Si29 =new G4Isotope ("Si29",14,29,29*g/mole);
  G4Isotope* Si30 =new G4Isotope ("Si30",14,30,30*g/mole);
  Si->AddIsotope(Si28,0.92223);
  Si->AddIsotope(Si29,0.04685);
  Si->AddIsotope(Si30,0.03092);




  G4Element* C = new G4Element("Carbon"  ,"C" , 2);
  G4Isotope* C12  =new G4Isotope ("C12",6,12,12*g/mole);
  G4Isotope* C13  =new G4Isotope ("C13",6,13,13*g/mole);
  C->AddIsotope(C12,0.9893);
  C->AddIsotope(C13,0.0107);




    G4Material* Co2 = 
  new G4Material("Co2", density= 0.00197*g/cm3, ncomponents=2);
  Co2->AddElement(C , fractionmass=27.3*perCent);
  Co2->AddElement(O , fractionmass=72.7*perCent);





  G4Element* N = new G4Element("Nitrogen"  ,"N" , 2);
  G4Isotope* N14  =new G4Isotope ("N14",7,14,14*g/mole);
  G4Isotope* N15  =new G4Isotope ("N15",7,15,15*g/mole);
  N->AddIsotope(N14,0.99636);
  N->AddIsotope(N15,0.00634);



  G4Element* He = new G4Element("Helium"  ,"He" , 1);
  G4Isotope* He4  =new G4Isotope ("He4",2,4,4*g/mole);
  He->AddIsotope(He4,1);




  G4Element* Ne = new G4Element("Neon"  ,"Ne" , 3);
  G4Isotope* Ne20  =new G4Isotope ("Ne20",10,20,20*g/mole);
  G4Isotope* Ne21  =new G4Isotope ("Ne21",10,21,22*g/mole);
  G4Isotope* Ne22  =new G4Isotope ("Ne22",10,21,22*g/mole);
  Ne->AddIsotope(Ne20,0.9048);
  Ne->AddIsotope(Ne21,0.0027);
  Ne->AddIsotope(Ne22,0.0925);


  G4Element* Ar = new G4Element("Argon"  ,"Ar" , 3);
  G4Isotope* Ar36  =new G4Isotope ("Ar36",18,36,36*g/mole);
  G4Isotope* Ar38  =new G4Isotope ("Ar38",18,38,38*g/mole);
  G4Isotope* Ar40  =new G4Isotope ("Ar40",18,40,40*g/mole);
  Ar->AddIsotope(Ar36,0.003336);
  Ar->AddIsotope(Ar38,0.000629);
  Ar->AddIsotope(Ar40,0.996035);



  G4Element* Kr = new G4Element("Krypton"  ,"Kr" , 6);
  G4Isotope* Kr78  =new G4Isotope ("Kr78",36,78,78*g/mole);
  G4Isotope* Kr80  =new G4Isotope ("Kr80",36,80,80*g/mole);
  G4Isotope* Kr82  =new G4Isotope ("Kr82",36,82,82*g/mole);
  G4Isotope* Kr83  =new G4Isotope ("Kr83",36,83,83*g/mole);
  G4Isotope* Kr84  =new G4Isotope ("Kr84",36,84,84*g/mole);
  G4Isotope* Kr86  =new G4Isotope ("Kr86",36,86,86*g/mole);
  Kr->AddIsotope(Kr78,0.00355);
  Kr->AddIsotope(Kr80,0.02286);
  Kr->AddIsotope(Kr82,0.11593);
  Kr->AddIsotope(Kr83,0.11500);
  Kr->AddIsotope(Kr84,0.56987);
  Kr->AddIsotope(Kr86,0.17279);



G4Element* Xe = new G4Element("Xenon"  ,"Xe" , 9);
  G4Isotope* Xe124  =new G4Isotope ("Xe124",54,124,124*g/mole);
  G4Isotope* Xe126  =new G4Isotope ("Xe126",54,126,126*g/mole);
  G4Isotope* Xe128  =new G4Isotope ("Xe128",54,128,128*g/mole);
  G4Isotope* Xe129  =new G4Isotope ("Xe129",54,129,129*g/mole);
  G4Isotope* Xe130  =new G4Isotope ("Xe130",54,130,130*g/mole);
  G4Isotope* Xe131  =new G4Isotope ("Xe131",54,131,131*g/mole);
  G4Isotope* Xe132  =new G4Isotope ("Xe132",54,132,132*g/mole);
  G4Isotope* Xe134  =new G4Isotope ("Xe134",54,134,134*g/mole);
  G4Isotope* Xe136  =new G4Isotope ("Xe136",54,136,136*g/mole);
  Xe->AddIsotope(Xe124,0.000952);
  Xe->AddIsotope(Xe126,0.000890);
  Xe->AddIsotope(Xe128,0.019102);
  Xe->AddIsotope(Xe129,0.264006);
  Xe->AddIsotope(Xe130,0.040710);
  Xe->AddIsotope(Xe131,0.212324);
  Xe->AddIsotope(Xe132,0.269086);
  Xe->AddIsotope(Xe134,0.104357);
  Xe->AddIsotope(Xe136,0.088573);



    G4Material* sio2 = 
  new G4Material("sio2", density= 2.648*g/cm3, ncomponents=2);
  sio2->AddElement(O , fractionmass=53.34*perCent);
  sio2->AddElement(Si , fractionmass=46.66*perCent);

G4Element* K = new G4Element("Potassium"  ,"K" , 3);
  G4Isotope* K39 =new G4Isotope ("K39",19,39,39*g/mole);
  G4Isotope* K40 =new G4Isotope ("K40",19,40,40*g/mole);
  G4Isotope* K41 =new G4Isotope ("K41",19,41,41*g/mole);
  K->AddIsotope(K39,0.932581);
  K->AddIsotope(K40,0.000117);
  K->AddIsotope(K41,0.067302);
  



  G4Element* Ca = new G4Element("Calcium"  ,"Ca" , 6);
  G4Isotope* Ca40 =new G4Isotope ("Ca40",20,40,40*g/mole);
  G4Isotope* Ca42 =new G4Isotope ("Ca42",20,42,42*g/mole);
  G4Isotope* Ca43 =new G4Isotope ("Ca43",20,43,43*g/mole);
  G4Isotope* Ca44 =new G4Isotope ("Ca44",20,44,44*g/mole);
  G4Isotope* Ca46 =new G4Isotope ("Ca46",20,46,46*g/mole);
  G4Isotope* Ca48 =new G4Isotope ("Ca48",20,48,48*g/mole);

  Ca->AddIsotope(Ca40,0.96933);
  Ca->AddIsotope(Ca42,0.00648);
  Ca->AddIsotope(Ca43,0.00135);
  Ca->AddIsotope(Ca44,0.02092);
  Ca->AddIsotope(Ca46,0.00004);
  Ca->AddIsotope(Ca48,0.00188);

G4Element* Ti= new G4Element("Titanium"  ,"Ti" , 5);
  G4Isotope* Ti46 =new G4Isotope ("Ti46",22,46,46*g/mole);
  G4Isotope* Ti47 =new G4Isotope ("Ti47",22,47,47*g/mole);
  G4Isotope* Ti48 =new G4Isotope ("Ti48",22,48,48*g/mole);
  G4Isotope* Ti49 =new G4Isotope ("Ti49",22,49,49*g/mole);
  G4Isotope* Ti50 =new G4Isotope ("Ti50",22,50,50*g/mole);
  
Ti->AddIsotope(Ti46,0.0825);
Ti->AddIsotope(Ti47,0.0744);
Ti->AddIsotope(Ti48,0.7372);
Ti->AddIsotope(Ti49,0.0541);
Ti->AddIsotope(Ti50,0.0518);



  
G4Element* Cr= new G4Element("Chromium" ,"Cr" , 4);
  G4Isotope* Cr50 =new G4Isotope ("Cr50",24,50,50*g/mole);
  G4Isotope* Cr52 =new G4Isotope ("Cr52",24,52,52*g/mole);
  G4Isotope* Cr53 =new G4Isotope ("Cr53",24,53,53*g/mole);
  G4Isotope* Cr54 =new G4Isotope ("Cr54",24,54,54*g/mole);


Cr->AddIsotope(Cr50,0.04306);
Cr->AddIsotope(Cr52,0.8379);
Cr->AddIsotope(Cr53,0.09553);
Cr->AddIsotope(Cr54,0.02351);


G4Element* Cu= new G4Element("Copper" ,"Cu" , 2);
  G4Isotope* Cu63 =new G4Isotope ("Cu63",29,63,63*g/mole);
  G4Isotope* Cu65 =new G4Isotope ("Cu65",29,65,65*g/mole);


  Cu->AddIsotope(Cu63,0.6915);
Cu->AddIsotope(Cu65,0.3085);


G4Element* Ga= new G4Element("Gallium" ,"Ga" , 2);
  G4Isotope* Ga69 =new G4Isotope ("Ga69",31,69,69*g/mole);
  G4Isotope* Ga71 =new G4Isotope ("Ga71",31,71, 71*g/mole);


Ga->AddIsotope(Ga69,0.60108);
 Ga->AddIsotope(Ga71,0.39892);

G4Element* Br= new G4Element("Bromine" ,"Br" , 2);
  G4Isotope* Br79 =new G4Isotope ("Br79",35, 79, 79*g/mole);
  G4Isotope* Br81 =new G4Isotope ("Br81",35, 81, 81*g/mole);


 Br->AddIsotope(Br79,0.5069);
 Br->AddIsotope(Br81,0.4931);


  G4Element* Zn= new G4Element("Zinc"  ,"Zn" , 5);
  G4Isotope* Zn64 =new G4Isotope ("Zn64",30,64,64*g/mole);
  G4Isotope* Zn66 =new G4Isotope ("Zn66",30,66,66*g/mole);
  G4Isotope* Zn67 =new G4Isotope ("Zn67",30,67,67*g/mole);
  G4Isotope* Zn68 =new G4Isotope ("Zn68",30,68,68*g/mole);
  G4Isotope* Zn70 =new G4Isotope ("Zn70",30,70,70*g/mole);

  Zn->AddIsotope(Zn64,0.48268);
  Zn->AddIsotope(Zn66,0.27975);
  Zn->AddIsotope(Zn67,0.04102);
  Zn->AddIsotope(Zn68,0.19024);
  Zn->AddIsotope(Zn70,0.00631);


 G4Element* Mn = new G4Element("Manganese"  ,"Mn" , 1);
G4Isotope* Mn55 = new G4Isotope("Mn55", 25, 55, 55*g/mole); 
  Mn->AddIsotope (Mn55, 1.0);

  
 G4Element* Nb = new G4Element("Niobium"  ,"Nb" , 1);
G4Isotope* Nb93 = new G4Isotope("N93", 41, 93, 93*g/mole); 
  Nb->AddIsotope (Nb93, 1.0);

  


  G4Element* Cd= new G4Element("Cadmium"  ,"Cd" , 8);
  G4Isotope* Cd106 =new G4Isotope ("Cd106",48,106, 106*g/mole);
  G4Isotope* Cd108 =new G4Isotope ("Cd108",48,108, 108*g/mole);
  G4Isotope* Cd110 =new G4Isotope ("Cd110",48,110, 110*g/mole);
  G4Isotope* Cd111 =new G4Isotope ("Cd111",48,111, 111*g/mole);
  G4Isotope* Cd112 =new G4Isotope ("Cd112",48,112, 112*g/mole);
  G4Isotope* Cd113 =new G4Isotope ("Cd113",48,113, 113*g/mole);
  G4Isotope* Cd114 =new G4Isotope ("Cd114",48,114, 114*g/mole);
  G4Isotope* Cd116 =new G4Isotope ("Cd116",48,116, 116*g/mole);

  Cd->AddIsotope(Cd106,0.0125);
  Cd->AddIsotope(Cd108,0.0089);
  Cd->AddIsotope(Cd110,0.1249);
  Cd->AddIsotope(Cd111,0.1280);
  Cd->AddIsotope(Cd112,0.2413);
  Cd->AddIsotope(Cd113,0.1222);
  Cd->AddIsotope(Cd114,0.2873);
  Cd->AddIsotope(Cd116,0.0749);

  


  G4Element* Mo= new G4Element("Molybdenum"  ,"Mo" , 7);
  G4Isotope* Mo92 =new G4Isotope ("Mo92",42,92, 92*g/mole);
  G4Isotope* Mo94 =new G4Isotope ("Mo94",42,94, 94*g/mole);
  G4Isotope* Mo95 =new G4Isotope ("Mo95",42,95, 95*g/mole);
  G4Isotope* Mo96 =new G4Isotope ("Mo96",42,96, 96*g/mole);
  G4Isotope* Mo97 =new G4Isotope ("Mo97",42,97, 97*g/mole);
  G4Isotope* Mo98 =new G4Isotope ("Mo98",42,98, 98*g/mole);
  G4Isotope* Mo100 =new G4Isotope ("Mo100",42,100, 100*g/mole);
  Mo->AddIsotope(Mo92,0.1477);
  Mo->AddIsotope(Mo94,0.0923);
  Mo->AddIsotope(Mo95,0.1590);
  Mo->AddIsotope(Mo96,0.1668);
  Mo->AddIsotope(Mo97,0.0956);
  Mo->AddIsotope(Mo98,0.2419);
  Mo->AddIsotope(Mo100,0.0967);


  G4Element* Sn= new G4Element("Tin"  ,"Sn" , 10);
  G4Isotope* Sn112 =new G4Isotope ("Sn112",50, 112, 112*g/mole);
  G4Isotope* Sn114 =new G4Isotope ("Sn114",50, 114, 114*g/mole);
  G4Isotope* Sn115 =new G4Isotope ("Sn115",50, 115, 115*g/mole);
  G4Isotope* Sn116 =new G4Isotope ("Sn116",50, 116, 116*g/mole);
  G4Isotope* Sn117 =new G4Isotope ("Sn117",50, 117, 117*g/mole);
  G4Isotope* Sn118 =new G4Isotope ("Sn118",50, 118, 118*g/mole);
  G4Isotope* Sn119 =new G4Isotope ("Sn119",50, 119, 119*g/mole);
  G4Isotope* Sn120 =new G4Isotope ("Sn120",50, 120, 120*g/mole);
  G4Isotope* Sn122 =new G4Isotope ("Sn122",50, 122, 122*g/mole);
  G4Isotope* Sn124 =new G4Isotope ("Sn124",50, 124, 124*g/mole);
  Sn->AddIsotope(Sn112,0.0097);
  Sn->AddIsotope(Sn114,0.0066);
  Sn->AddIsotope(Sn115,0.0034);
  Sn->AddIsotope(Sn116,0.1454);
  Sn->AddIsotope(Sn117,0.0768);
  Sn->AddIsotope(Sn118,0.2422);
  Sn->AddIsotope(Sn119,0.0859);
  Sn->AddIsotope(Sn120,0.3258);
  Sn->AddIsotope(Sn122,0.0463);
  Sn->AddIsotope(Sn124,0.0579);


  G4Element* Pb= new G4Element("Lead"  ,"Pb" , 4);
  G4Isotope* Pb204 =new G4Isotope ("Pb204",82,204,204*g/mole);
  G4Isotope* Pb206 =new G4Isotope ("Pb206",82,206,206*g/mole);
  G4Isotope* Pb207 =new G4Isotope ("Pb207",82,207,207*g/mole);
  G4Isotope* Pb208 =new G4Isotope ("Pb208",82,208,208*g/mole);
  Pb->AddIsotope(Pb204,0.014);
  Pb->AddIsotope(Pb206,0.241);
  Pb->AddIsotope(Pb207,0.221);
  Pb->AddIsotope(Pb208,0.524);


  G4Element* Fe= new G4Element("Iron"  ,"Fe" , 4);
  G4Isotope* Fe54 =new G4Isotope ("Fe54",26,54,54*g/mole);
  G4Isotope* Fe56 =new G4Isotope ("Fe56",26,56,56*g/mole);
  G4Isotope* Fe57 =new G4Isotope ("Fe57",26,57,57*g/mole);
  G4Isotope* Fe58 =new G4Isotope ("Fe58",26,58,58*g/mole);
  Fe->AddIsotope(Fe54,0.05847);
  Fe->AddIsotope(Fe56,0.9176);
  Fe->AddIsotope(Fe57,0.02111);
  Fe->AddIsotope(Fe58,0.00282);


 G4Element* Rb = new G4Element("Rubidium"  ,"Rb",2);
 G4Isotope* Rb85 = new G4Isotope("Rb85", 37, 85, 85*g/mole);
 G4Isotope* Rb87 = new G4Isotope("Rb87", 37, 87, 87*g/mole);
 Rb->AddIsotope (Rb85, 0.7217);
 Rb->AddIsotope (Rb87, 0.2783);


  G4Element* Sr= new G4Element("strontium"  ,"Sr" ,4);
  G4Isotope* Sr84 =new G4Isotope ("Sr84",38,84,84*g/mole);
  G4Isotope* Sr86 =new G4Isotope ("Sr86",38,86,86*g/mole);
  G4Isotope* Sr87 =new G4Isotope ("Sr87",38,87,87*g/mole);
  G4Isotope* Sr88 =new G4Isotope ("Sr88",38,88,88*g/mole);
  Sr->AddIsotope(Sr84,0.0056);
  Sr->AddIsotope(Sr86,0.098);
  Sr->AddIsotope(Sr87,0.0704);
  Sr->AddIsotope(Sr88,0.8260);

  G4Element* Be = new G4Element ("Berilium", "Be", 1);
  G4Isotope* Be9 = new G4Isotope ("Be9", 4, 9, 9*g/mole);
  Be -> AddIsotope(Be9, 1.0);

  G4Element* Zr= new G4Element("Zincronium"  ,"Zr" , 5);
  G4Isotope* Zr90 =new G4Isotope ("Zr90",40,90,90*g/mole);
  G4Isotope* Zr91 =new G4Isotope ("Zr91",40,91,91*g/mole);
  G4Isotope* Zr92 =new G4Isotope ("Zr92",40,92,92*g/mole);
  G4Isotope* Zr94 =new G4Isotope ("Zr94",40,94,94*g/mole);
  G4Isotope* Zr96 =new G4Isotope ("Zr96",40,96,96*g/mole);

  Zr->AddIsotope(Zr90,0.51450);
  Zr->AddIsotope(Zr91,0.11220);
  Zr->AddIsotope(Zr92,0.17150);
  Zr->AddIsotope(Zr94,0.17380);
  Zr->AddIsotope(Zr96,0.0280);

  G4Element * Ni = new G4Element ("Nickel", "Ni",5);
  G4Isotope* Ni58 = new G4Isotope ("Ni58", 28, 58, 58*g/mole);
  G4Isotope* Ni60 = new G4Isotope ("Ni60", 28, 60, 60*g/mole);
  G4Isotope* Ni61 = new G4Isotope ("Ni61", 28, 61, 61*g/mole);
  G4Isotope* Ni62 = new G4Isotope ("Ni62", 28, 62, 62*g/mole);
  G4Isotope* Ni64 = new G4Isotope ("Ni64", 28, 64, 64*g/mole);

  Ni -> AddIsotope (Ni58, 0.680769);
  Ni -> AddIsotope (Ni60, 0.262231);
  Ni -> AddIsotope (Ni61, 0.011399);
  Ni -> AddIsotope (Ni62, 0.036345);
  Ni -> AddIsotope (Ni64, 0.009256);

G4Element* Ge= new G4Element("Germanium"  ,"Ge" , 5);
  G4Isotope* Ge70 =new G4Isotope ("Ge70",32,70,70*g/mole);
  G4Isotope* Ge72  =new G4Isotope ("Ge72",32,72,72*g/mole);
  G4Isotope* Ge73 =new G4Isotope ("Ge73",32,73,73*g/mole);
  G4Isotope* Ge74 =new G4Isotope ("Ge74",32,74,74*g/mole);
  G4Isotope* Ge76 =new G4Isotope ("Ge76",32,76,76*g/mole);

  Ge->AddIsotope(Ge70,0.2038);
  Ge->AddIsotope(Ge72,0.2731);
  Ge->AddIsotope(Ge73,0.0776);
  Ge->AddIsotope(Ge74,0.3672);
  Ge->AddIsotope(Ge76,0.0783);

  

G4Element* V= new G4Element("Vanadium" ,"V" , 2);
  G4Isotope* V50 =new G4Isotope ("V50",23,50,50*g/mole);
  G4Isotope* V51 =new G4Isotope ("V51",23,51,51*g/mole);
  
  V->AddIsotope(V50,0.0025);
V->AddIsotope(V51,0.9975);

G4Element* As= new G4Element("Arsenic"  ,"As" , 1);
  G4Isotope* As75 =new G4Isotope ("As75",33,75,75*g/mole);
  As->AddIsotope(As75, 1.0);

  G4Element* Nd= new G4Element("Nubidium"  ,"Nd" , 7);
  G4Isotope* Nd142=new G4Isotope ("Nd142",60,142,142*g/mole);
  G4Isotope* Nd143=new G4Isotope ("Nd143",60,143,143*g/mole);
  G4Isotope* Nd144=new G4Isotope ("Nd144",60,144,144*g/mole);
  G4Isotope* Nd145=new G4Isotope ("Nd145",60,145,145*g/mole);
  G4Isotope* Nd146=new G4Isotope ("Nd146",60,146,146*g/mole);
  G4Isotope* Nd148=new G4Isotope ("Nd148",60,148,148*g/mole);
  G4Isotope* Nd150=new G4Isotope ("Nd150",60,150,150*g/mole);
Nd->AddIsotope(Nd142,0.2720);
Nd->AddIsotope(Nd143,0.1220);
Nd->AddIsotope(Nd144,0.2380);
Nd->AddIsotope(Nd145,0.0830);
Nd->AddIsotope(Nd146,0.1720);
Nd->AddIsotope(Nd148,0.0570);
Nd->AddIsotope(Nd150,0.0560);




  G4Material* Silcon = new G4Material("Silcon", density= 2.329*g/cm3, ncomponents=1);
  Silcon->AddElement(Si , fractionmass=100.*perCent);

  G4Material* Calcim = new G4Material("Calcim", density= 1.55*g/cm3, ncomponents=1);
  Calcim->AddElement(Ca , fractionmass=100.*perCent);

  G4Material* Aluminum = new G4Material("Aluminum", density= 2.7*g/cm3, ncomponents=1);
  Aluminum->AddElement(Al , fractionmass=100.*perCent);

  G4Material* Zircon = new G4Material("Zircon", density= 6.52*g/cm3, ncomponents=1);
  Zircon->AddElement(Zr , fractionmass=100.*perCent);

  G4Material* Nickl = new G4Material("Nickl", density= 8.908*g/cm3, ncomponents=1);
  Nickl->AddElement(Ni , fractionmass=100.*perCent);
  
  G4Material* Berilum = new G4Material("Berilum", density= 1.85*g/cm3, ncomponents=1);
  Berilum->AddElement(Be , fractionmass=100.*perCent);

  G4Material* AlEnclosure = new G4Material ("AlEnclosure", density = 2.7*g/cm3, ncomponents=13);
  AlEnclosure->AddElement(Al, fractionmass=0.9696);
  AlEnclosure->AddElement(Mg, fractionmass=0.0129);
  AlEnclosure->AddElement(Si, fractionmass=0.0059);
  AlEnclosure->AddElement(Mn, fractionmass=0.00075);
  AlEnclosure->AddElement(Fe, fractionmass=0.0059);
  AlEnclosure->AddElement(Cu, fractionmass=0.0018);
  AlEnclosure->AddElement(Zn, fractionmass=0.00047);
  AlEnclosure->AddElement(Nb, fractionmass=0.00031);
  AlEnclosure->AddElement(Cd, fractionmass=0.00002);
  AlEnclosure->AddElement(Mo, fractionmass=0.00032);
  AlEnclosure->AddElement(Sn, fractionmass=0.00005);
  AlEnclosure->AddElement(Pb, fractionmass=0.00003);
  AlEnclosure->AddElement(O, fractionmass=0.00195);

  G4Material* AluminumPlate = new G4Material ("AluminumPlate", density=2.763*g/cm3, ncomponents=3);
 
AluminumPlate->AddElement(Al, fractionmass=99.649*perCent);
AluminumPlate->AddElement(Si, fractionmass=0.218*perCent);
AluminumPlate->AddElement(Fe, fractionmass=0.133*perCent);
  G4Material* Lunarsimulant = 
   new G4Material("Lunarsimulant", density= 3.726*g/cm3, ncomponents=5);
 Lunarsimulant->AddElement(Ti, fractionmass=89.7*perCent);
 Lunarsimulant->AddElement(Al, fractionmass=5.911*perCent);
 Lunarsimulant->AddElement(V, fractionmass=4.05*perCent);
 Lunarsimulant->AddElement(Si, fractionmass=0.174*perCent);
 Lunarsimulant->AddElement(Fe, fractionmass=0.165*perCent);
 // G4Material* Vacuum =
 // new G4Material("Vacuum", z=1, a=1.008*g/mole, density = universe_mean_density, kStateGas, 0.1*kelvin, 1e-19*pascal);
  // const G4double expTemp = STP_Temperature+20.*kelvin; 
  //
G4RotationMatrix *yRot = new G4RotationMatrix;
yRot->rotateY (0.*deg);
//G4Material* defaultMaterial = new G4Material("Galactic", 1., 1.01*g/mole,universe_mean_density, kStateGas, 2.73*kelvin, 3.e-18*pascal); 



  G4Material* Air = new G4Material("Air", density=0.0011839*g/cm3, ncomponents=8, kStateGas, 293.*kelvin, 101325.*pascal);
  Air-> AddElement(N,  fractionmass=0.78084);
  Air-> AddElement(O,  fractionmass=0.209705);
  Air-> AddElement(C, fractionmass=0.000085);
  Air-> AddElement(He, fractionmass=0.00000524);
  Air-> AddElement(Ne, fractionmass=0.00001818);
  Air-> AddElement(Ar, fractionmass=0.00934);
  Air-> AddElement(Kr, fractionmass=0.000006493);
  Air-> AddElement(Xe, fractionmass=0.000000087);

  //Air reference from Noble gas geochemistry by MINORU OZIMA PAGE 11




  motherbox = new G4Box ("motherbox", 1000.*mm, 1000.*mm, 1000.*mm); //world volume
  motherlogic = new G4LogicalVolume(motherbox, Air, "motherlogic");//world volume_logic volume
  physi_mother = new G4PVPlacement(0,	G4ThreeVector(0, 0, 0),	motherlogic,	"physi_mother",	0,	false,	0);
 
  G4SubtractionSolid* subtraction2; 
  G4SubtractionSolid* subtraction3; 
  G4SubtractionSolid* subtraction1; 
  G4SubtractionSolid* subtraction4; 
  G4SubtractionSolid* subtraction5; 
  G4SubtractionSolid* subtraction6; 
  G4SubtractionSolid* subtraction7;
  
  G4Box* solidbox3;
  G4Box* solidbox2;
  G4Box* solidbox4;

  solidbox1 = new G4Box("solidbox1", 43.*mm, 34.*mm, 44.5*mm); // x , y , z
  solidbox2 = new G4Box("solidbox2", 42.*mm, 33.*mm, 43.5*mm);
  solidbox3 = new G4Box("solidbox3", 43.*mm, 34.*mm, 0.6*mm);
  solidbox4 = new G4Box("solidbox4", 0.6*mm, 16.5*mm, 42.*mm);
  
  solidtube1 = new G4Tubs("solidtube1", 0.*mm, 1.6*mm, 0.6*mm, startangle, spanningangle);
  subtraction1 = new G4SubtractionSolid ("solidbox1-solidbox2", solidbox1, solidbox2);
  subtraction2 = new G4SubtractionSolid ("subtraction1-solidbox3", subtraction1, solidbox3, yRot, G4ThreeVector(0.*mm, 0.*mm, 44.*mm));
  subtraction3 = new G4SubtractionSolid ("subtraction2-solidbox4", subtraction2, solidbox4, yRot, G4ThreeVector(42.5*mm, 0.*mm, 3.*mm));
  subtraction4 = new G4SubtractionSolid ("subtraction3-solidtube1", subtraction3, solidtube1, yRot, G4ThreeVector(35.5*mm, 26.5*mm, -44.*mm));
  subtraction5 = new G4SubtractionSolid ("subtraction4-solidtube1", subtraction4, solidtube1, yRot, G4ThreeVector(-35.5*mm, 26.5*mm, -44.*mm));
  subtraction6 = new G4SubtractionSolid ("subtraction5-solidtube1", subtraction5, solidtube1, yRot, G4ThreeVector(35.5*mm, -26.5*mm, -44.*mm));
  subtraction7 = new G4SubtractionSolid ("subtraction6-solidtube1", subtraction6, solidtube1, yRot, G4ThreeVector(-35.5*mm, -26.5*mm, -44.*mm));
  
 logic_box = new G4LogicalVolume(subtraction7,	AlEnclosure,	"logic_box");
 physi_box = new G4PVPlacement(0, G4ThreeVector(0, 0, 0),	logic_box,	"physi_box",	motherlogic,	false,	0);
  

  G4SubtractionSolid* sourceholdersubtraction1;
  G4SubtractionSolid* sourceholdersubtraction2;
  G4SubtractionSolid* sourceholdersubtraction3;
  G4SubtractionSolid* sourceholdersubtraction4;
  G4SubtractionSolid* sourceholdersubtraction5;
  G4SubtractionSolid* sourceholdersubtraction6;
  G4SubtractionSolid* sourceholdersubtraction7;
  G4SubtractionSolid* sourceholdersubtraction8;
  G4SubtractionSolid* sourceholdersubtraction9;
  G4SubtractionSolid* sourceholdersubtraction10;
  G4SubtractionSolid* sourceholdersubtraction11;
  G4SubtractionSolid* sourceholdersubtraction12;
  G4SubtractionSolid* sourceholdersubtraction13;
  G4SubtractionSolid* sourceholdersubtraction14;
  G4SubtractionSolid* sourceholdersubtraction15;
  G4SubtractionSolid* sourceholdersubtraction16;
  G4SubtractionSolid* sourceholdersubtraction17;
  G4SubtractionSolid* sourceholdersubtraction18;

  G4SubtractionSolid* sourceholdersubtraction19;
  G4SubtractionSolid* sourceholdersubtraction20;
  G4SubtractionSolid* sourceholdersubtraction21;
  G4SubtractionSolid* sourceholdersubtraction22;
  G4SubtractionSolid* sourceholdersubtraction23;
  G4SubtractionSolid* sourceholdersubtraction24;

  G4UnionSolid* sourceholderunion1;
  G4UnionSolid* sourceholderunion2;
  G4UnionSolid* sourceholderunion3;
  G4UnionSolid* sourceholderunion4;
  G4UnionSolid* sourceholderunion5;
  
  G4UnionSolid* sourceholderunion6;
  G4UnionSolid* sourceholderunion7;
  G4UnionSolid* sourceholderunion8;
  G4UnionSolid* sourceholderunion9;
  G4UnionSolid* sourceholderunion10;
  G4UnionSolid* sourceholderunion11;

  G4UnionSolid* sourceholderunion12;
  G4UnionSolid* sourceholderunion13;
  G4UnionSolid* sourceholderunion14;

  G4Box* sourceholderbox1;
  G4Box* sourceholderbox2;
  G4Box* sourceholderbox3;

  G4Tubs* sourceholderhole1;
  G4Tubs* sourceholderdia1;
  G4Tubs* sourceholderdia2;
  G4Tubs* sourceholderdia3;
  G4Tubs* sourceholderdia4;
  G4Tubs* sourceholderdia5;
  G4Tubs* sourceholderdia6;
  G4Tubs* sourceholderdia7;
  G4Tubs* sourceholderdia8;
  G4Tubs* sourceholderdia9;

  G4Tubs* sourcedia1;
  G4Tubs* detectorpin; 

G4RotationMatrix *yRot4deg = new G4RotationMatrix;
yRot4deg->rotateY (4.*deg);
//yRot4deg->rotateX (10.*deg);

G4RotationMatrix *yRot176deg = new G4RotationMatrix;
yRot176deg->rotateY (-4.*deg);

G4RotationMatrix *yRotcomb1 = new G4RotationMatrix;
yRotcomb1->rotateY (2.*deg);
yRotcomb1->rotateX (-3.4641*deg);

G4RotationMatrix *yRotcomb2 = new G4RotationMatrix;
yRotcomb2->rotateY (-2.*deg);
yRotcomb2->rotateX (-3.4641*deg);

G4RotationMatrix *yRotcomb3 = new G4RotationMatrix;
yRotcomb3->rotateY (-2.*deg);
yRotcomb3->rotateX (3.4641*deg);

G4RotationMatrix *yRotcomb4 = new G4RotationMatrix;
yRotcomb4->rotateY (2.*deg);
yRotcomb4->rotateX (3.4641*deg);

  sourceholderbox1 = new G4Box("sourceholderbox1", 43.*mm, 34.*mm, 0.5*mm); // x , y , z
  sourceholderbox2 = new G4Box("sourceholderbox2", 41.75*mm, 32.75*mm, 0.75*mm); // x , y , z
  sourceholderbox3 = new G4Box("sourceholderbox3", 40.75*mm, 31.75*mm, 0.8*mm); // x , y , z

  sourceholderhole1 = new G4Tubs("sourceholderhole1", 0.*mm, 1.6*mm, 2.5*mm, startangle, spanningangle);
  
  sourceholderdia1 = new G4Tubs("sourceholderdia1", 30.*mm, 31.*mm, 5.*mm, startangle, spanningangle);
  sourceholderdia2 = new G4Tubs("sourceholderdia2", 0.*mm, 28.*mm, 1.5*mm, startangle, spanningangle);
  sourceholderdia3 = new G4Tubs("sourceholderdia3", 28.*mm, 30.*mm, 4.5*mm, startangle, spanningangle);
  sourceholderdia4 = new G4Tubs("sourceholderdia4", 11.*mm, 30.*mm, 1.25*mm, startangle, spanningangle);
  sourceholderdia5 = new G4Tubs("sourceholderdia5", 3.5*mm, 11.*mm, 0.35*mm, startangle, spanningangle);
  sourceholderdia6 = new G4Tubs("sourceholderdia6", 0.*mm, 4.75*mm, 1.26*mm, startangle, spanningangle); // actually is 2.5mm, to cut
 
  detectorpin = new G4Tubs("detectorpin", 0.*mm, 0.5*mm, 2.*mm, startangle, spanningangle);
   
  sourceholdersubtraction1 = new G4SubtractionSolid("sourceholdersubtraction1", sourceholderbox2, sourceholderbox3);
  sourceholderunion1 = new G4UnionSolid("sourceholderunion1", sourceholderbox1, sourceholdersubtraction1, yRot, G4ThreeVector(0.*mm, 0.*mm, -1.25*mm));
  
  sourceholdersubtraction2 = new G4SubtractionSolid("sourceholdersubtraction2", sourceholderunion1, sourceholderhole1, yRot, G4ThreeVector(35.5*mm, 26.5*mm, 0.*mm));
  sourceholdersubtraction3 = new G4SubtractionSolid("sourceholdersubtraction3", sourceholdersubtraction2, sourceholderhole1, yRot, G4ThreeVector(-35.5*mm, 26.5*mm, 0.*mm));
  sourceholdersubtraction4 = new G4SubtractionSolid("sourceholdersubtraction4", sourceholdersubtraction3, sourceholderhole1, yRot, G4ThreeVector(35.5*mm, -26.5*mm, 0.*mm));
  sourceholdersubtraction5 = new G4SubtractionSolid("sourceholdersubtraction5", sourceholdersubtraction4, sourceholderhole1, yRot, G4ThreeVector(-35.5*mm, -26.5*mm, 0.*mm));
 
  sourceholderunion2	   = new G4UnionSolid("sourceholderunion2", sourceholdersubtraction5, sourceholderdia1, yRot, G4ThreeVector(-11.*mm, 0.*mm, 5.5*mm));//0.5 to 10.5
  sourceholdersubtraction6 = new G4SubtractionSolid("sourceholdersubtraction6", sourceholderunion2, sourceholderdia2, yRot, G4ThreeVector(-11.*mm, 0.*mm, -0.75*mm));
  
  sourceholderunion3 = new G4UnionSolid("sourceholderunion3", sourceholdersubtraction6, sourceholderdia3, yRot, G4ThreeVector(-11.*mm, 0.*mm, -5.5*mm)); 
  
  sourceholderunion4 = new G4UnionSolid("sourceholderunion4", sourceholderunion3, sourceholderdia4, yRot, G4ThreeVector(-11.*mm, 0.*mm, -8.75*mm)); //-7.5 to -10
  sourceholderunion5 = new G4UnionSolid("sourceholderunion5", sourceholderunion4, sourceholderdia5, yRot, G4ThreeVector(-11.*mm, 0.*mm, -8.85*mm)); //-8.5 to -9.2

  sourceholdersubtraction7 = new G4SubtractionSolid("sourceholdersubtraction7", sourceholderunion5, detectorpin, yRot, G4ThreeVector(-16.6*mm, 0.*mm, -8.85*mm)); 
  sourceholdersubtraction8 = new G4SubtractionSolid("sourceholdersubtraction8", sourceholdersubtraction7, detectorpin, yRot, G4ThreeVector(-16.6*mm, -2.54*mm, -8.85*mm)); 
  sourceholdersubtraction9 = new G4SubtractionSolid("sourceholdersubtraction9", sourceholdersubtraction8, detectorpin, yRot, G4ThreeVector(-16.6*mm, 2.54*mm, -8.85*mm));

  sourceholdersubtraction10 = new G4SubtractionSolid("sourceholdersubtraction10", sourceholdersubtraction9, detectorpin, yRot, G4ThreeVector(-5.4*mm, 2.54*mm, -8.85*mm)); 
  sourceholdersubtraction11 = new G4SubtractionSolid("sourceholdersubtraction11", sourceholdersubtraction10, detectorpin, yRot, G4ThreeVector(-5.4*mm, 0.*mm, -8.85*mm)); 
  sourceholdersubtraction12 = new G4SubtractionSolid("sourceholdersubtraction12", sourceholdersubtraction11, detectorpin, yRot, G4ThreeVector(-5.4*mm, -2.54*mm, -8.85*mm)); 

  sourceholdersubtraction13 = new G4SubtractionSolid("sourceholdersubtraction13", sourceholdersubtraction12, detectorpin, yRot, G4ThreeVector(-11*mm, 5.6*mm, -8.85*mm)); 
  sourceholdersubtraction14 = new G4SubtractionSolid("sourceholdersubtraction14", sourceholdersubtraction13, detectorpin, yRot, G4ThreeVector(-13.54*mm, 5.6*mm, -8.85*mm)); 
  sourceholdersubtraction15 = new G4SubtractionSolid("sourceholdersubtraction15", sourceholdersubtraction14, detectorpin, yRot, G4ThreeVector(-8.46*mm, 5.6*mm, -8.85*mm));

  sourceholdersubtraction16 = new G4SubtractionSolid("sourceholdersubtraction16", sourceholdersubtraction15, detectorpin, yRot, G4ThreeVector(-11.*mm, -5.6*mm, -8.85*mm)); 
  sourceholdersubtraction17 = new G4SubtractionSolid("sourceholdersubtraction17", sourceholdersubtraction16, detectorpin, yRot, G4ThreeVector(-13.54*mm, -5.6*mm, -8.85*mm)); 
  sourceholdersubtraction18 = new G4SubtractionSolid("sourceholdersubtraction18", sourceholdersubtraction17, detectorpin, yRot, G4ThreeVector(-8.46*mm, -5.6*mm, -8.85*mm)); 

  sourceholdersubtraction19 = new G4SubtractionSolid("sourceholdersubtraction19", sourceholdersubtraction18, sourceholderdia6, yRot, G4ThreeVector(-29.6*mm, 0.*mm, -8.75*mm)); 
  sourceholdersubtraction20 = new G4SubtractionSolid("sourceholdersubtraction20", sourceholdersubtraction19, sourceholderdia6, yRot, G4ThreeVector(-1.7*mm, 16.1*mm, -8.75*mm));
  sourceholdersubtraction21 = new G4SubtractionSolid("sourceholdersubtraction21", sourceholdersubtraction20, sourceholderdia6, yRot, G4ThreeVector(7.6*mm, 0.*mm, -8.75*mm));
  sourceholdersubtraction22 = new G4SubtractionSolid("sourceholdersubtraction22", sourceholdersubtraction21, sourceholderdia6, yRot, G4ThreeVector(-1.7*mm, -16.1*mm, -8.75*mm));
  sourceholdersubtraction23 = new G4SubtractionSolid("sourceholdersubtraction23", sourceholdersubtraction22, sourceholderdia6, yRot, G4ThreeVector(-20.3*mm, 16.1*mm, -8.75*mm));
  sourceholdersubtraction24 = new G4SubtractionSolid("sourceholdersubtraction24", sourceholdersubtraction23, sourceholderdia6, yRot, G4ThreeVector(-20.3*mm, -16.1*mm, -8.75*mm));   // cut from -11 to 1 
  
  sourcedia1 = new G4Tubs("sourcedia1", 4.75*mm, 6.9*mm, 3.25*mm, startangle, spanningangle); // should start from -7.5 toward zero
  sourceholderdia7 = new G4Tubs("sourceholderdia7", 3.25*mm, 6.9*mm, 0.5*mm, startangle, spanningangle);
  sourceholderdia8 = new G4Tubs("sourceholderdia8", 5.2*mm, 6.9*mm, 0.4*mm, startangle, spanningangle);
  sourceholderdia9 = new G4Tubs("sourceholderdia9", 4.9*mm, 6.9*mm, 0.85*mm, startangle, spanningangle);
 
  sourceholderunion6 = new G4UnionSolid("sourceholderunion6", sourcedia1, sourceholderdia7, yRot, G4ThreeVector( 0.*mm, 0.*mm, 3.75*mm));
  sourceholderunion7 = new G4UnionSolid("sourceholderunion7", sourceholderunion6, sourceholderdia8, yRot, G4ThreeVector(0.*mm, 0.*mm, 4.65*mm));
  sourceholderunion8 = new G4UnionSolid("sourceholderunion8", sourceholderunion7, sourceholderdia9, yRot, G4ThreeVector(0.*mm, 0.*mm, 5.9*mm));
  
  sourceholderunion9 = new G4UnionSolid("sourceholderunion9", sourceholdersubtraction24, sourceholderunion8, yRot176deg, G4ThreeVector(-29.6*mm, 0.*mm, -4.*mm)); //total length 10 mm, should start from -7.5 toward zero
  sourceholderunion10 = new G4UnionSolid("sourceholderunion9", sourceholderunion9, sourceholderunion8, yRotcomb1, G4ThreeVector(-1.7*mm, 16.1*mm, -4.*mm)); //total length 10 mm, should start from -7.5 toward zero
  sourceholderunion11 = new G4UnionSolid("sourceholderunion9", sourceholderunion10, sourceholderunion8, yRot4deg, G4ThreeVector(7.6*mm, 0.*mm, -4.*mm)); //total length 10 mm, should start from -7.5 toward zero
  sourceholderunion12 = new G4UnionSolid("sourceholderunion9", sourceholderunion11, sourceholderunion8, yRotcomb4, G4ThreeVector(-1.7*mm, -16.1*mm, -4.*mm)); //total length 10 mm, should start from -7.5 toward zero
  sourceholderunion13 = new G4UnionSolid("sourceholderunion9", sourceholderunion12, sourceholderunion8, yRotcomb2, G4ThreeVector(-20.3*mm, 16.1*mm, -4.*mm)); //total length 10 mm, should start from -7.5 toward zero
  sourceholderunion14 = new G4UnionSolid("sourceholderunion9", sourceholderunion13, sourceholderunion8, yRotcomb3, G4ThreeVector(-20.3*mm, -16.1*mm, -4.*mm)); //total length 10 mm, should start from -7.5 toward zero

  logic_box1 = new G4LogicalVolume(sourceholderunion14,	AlEnclosure,	"logic_box1");
 physi_box1 = new G4PVPlacement(0,	G4ThreeVector(0, 0, 44.5*mm),	logic_box1,	"physi_box1",	motherlogic,	false,	0);
  
  
 detector_window = new G4Tubs("detector_window", 0*mm, 4.3*mm, 0.004*mm, startangle, spanningangle); 
 logic_window= new G4LogicalVolume(detector_window,	Berilum,	"logic_window"); 
 physi_window = new G4PVPlacement(0,	G4ThreeVector(-11.*mm, 0, 44.3*mm),	logic_window,	"physi_window",	motherlogic,	false,	0);
 detector_collimator = new G4Tubs("detector_collimator", 3.5*mm, 4.8*mm, 0.2*mm, startangle, spanningangle); 
  logic_collimator = new G4LogicalVolume(detector_collimator,	Nickl,	"logic_collimator"); 
  physi_collimator = new G4PVPlacement(0,	G4ThreeVector(-11.*mm, 0,	43.7*mm),	logic_collimator,	"physi_collimator",	motherlogic,	false,	0);
  
  cone = new G4Cons("cone", 6.6*mm, 7.*mm, 4.25*mm, 4.65*mm,  1.1*mm, 35.*deg, 360.*deg);
  cone_logic = new G4LogicalVolume(cone,	Nickl,	"cone_logic");                                
  physicone = new G4PVPlacement(0,	G4ThreeVector(-11.*mm, 0, 43.2*mm),	cone_logic,	"physicone",	motherlogic, false,	0);
  
  silica_collimator = new G4Tubs("silica_collimator", 3.09*mm, 3.9*mm, 0.5*mm, 0.*deg, 360.*deg);
  logic_silica_collimator = new G4LogicalVolume(silica_collimator,	Zircon,	"logic_silica_collimator"); // detectr_silica from 61.5 to 63.5
  physi_silica_collimator = new G4PVPlacement(0,	G4ThreeVector(-11.*mm, 0, 42.6*mm),	logic_silica_collimator,	"physi_silica_collimator",	motherlogic,	false,	0);
  
  silica = new G4Tubs("silica", 0.*mm, 4.0*mm, 0.225*mm, 0.*deg, 360.*deg);
  logic_silica = new G4LogicalVolume(silica,	Silcon,	"logic_silica"); // detectr_silica from 61.5 to 63.5
  physi_silica = new G4PVPlacement(0,	G4ThreeVector(-11.*mm, 0, 41.875*mm),	logic_silica,	"physi_silica",	motherlogic,	false,	0);
 
  detector = new G4Tubs("detector", 6.6*mm, 7.0*mm, 3.675*mm, startangle, spanningangle);
  logic_detector = new G4LogicalVolume(detector,	Nickl,	"logic_detector");
  physi_detector = new G4PVPlacement(0,	G4ThreeVector(-11.*mm, 0, 37.975*mm),	logic_detector,	"physi_detector",	motherlogic,	false,	0);
G4Tubs* source_cover = new G4Tubs("source_cover", 0*mm, 4.8*mm, 1.5*mm, startangle, spanningangle);
G4LogicalVolume *logic_sourcecover= new G4LogicalVolume(source_cover,	AlEnclosure,	"logic_sourcecover"); 

 G4VPhysicalVolume *physi_sourcecover0 = new G4PVPlacement(0, G4ThreeVector(-29.6*mm, 0.*mm, 35.5*mm),	logic_sourcecover,	"physi_sourcecover0",	motherlogic,	false,	0); // soruce from -10 to -5

 G4VPhysicalVolume *physi_sourcecover1 = new G4PVPlacement(0, G4ThreeVector(-1.7*mm, 16.1*mm, 35.5*mm),	logic_sourcecover,	"physi_sourcecover1",	motherlogic,	false,	1); //-1.7, 16.1, 41 with 2mm total length of source, and dia is 9mm

G4VPhysicalVolume *physi_sourcecover2 = new G4PVPlacement(0, G4ThreeVector(7.6*mm, 0.*mm, 35.5*mm),	logic_sourcecover,	"physi_sourcecover2",	motherlogic,	false,	2);

 G4VPhysicalVolume *physi_sourcecover3 = new G4PVPlacement(0, G4ThreeVector(-1.7*mm, -16.1*mm, 35.5*mm),	logic_sourcecover,	"physi_sourcecover3",	motherlogic,	false,	3);

G4VPhysicalVolume *physi_sourcecover4 = new G4PVPlacement(0, G4ThreeVector(-20.3*mm, 16.1*mm, 35.5*mm),	logic_sourcecover,	"physi_sourcecover4",	motherlogic,	false,	4);

G4VPhysicalVolume *physi_sourcecover5 = new G4PVPlacement(0, G4ThreeVector(-20.3*mm, -16.1*mm, 35.5*mm),	logic_sourcecover,	"physi_sourcecover5	",	motherlogic,	false,	5);

 moon = new G4Box("moon", 150.*mm, 150.*mm, 5.*mm);//distance between src and moon is <5mm now detector is at 45mm distance
 logic_moon = new G4LogicalVolume(moon,	Lunarsimulant,	"logic_moon"); 
 physi_moon = new G4PVPlacement(0,	G4ThreeVector(0, 0, 60.*mm),	logic_moon,	"physi_moon",	motherlogic,	false,	0);
 
  // geometery is at 45 mm
  {
	  G4VisAttributes* atb1= new G4VisAttributes(G4Colour(1.0,1.0,1.0)); // used to set the colour of the tube (logicbox)
	atb1->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_box->SetVisAttributes(atb1);
  }
	 {
	  G4VisAttributes* atb2= new G4VisAttributes(G4Colour(1.0,0.0,1.0)); // used to set the colour of the tube (logicbox)
	atb2->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_box1->SetVisAttributes(atb2);
  }

    {
	  G4VisAttributes* atb3= new G4VisAttributes(G4Colour(1.0,0.0,1.0)); // used to set the colour of the tube (logicbox)
	atb3->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	cone_logic->SetVisAttributes(atb3);
  }
  {
	  G4VisAttributes* atb4= new G4VisAttributes(G4Colour(1.0,0.0,1.0)); // used to set the colour of the tube (logicbox)
	atb4->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_collimator->SetVisAttributes(atb4);
  }
	  {
	  G4VisAttributes* atb5= new G4VisAttributes(G4Colour(1.0,0.0,1.0)); // used to set the colour of the tube (logicbox)
	atb5->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_detector->SetVisAttributes(atb5);
	}  
	  
{
	  G4VisAttributes* atb6 = new G4VisAttributes(G4Colour(1.0,1.0,1.0)); // used to set the colour of the tube (logicbox)
	atb6->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_silica->SetVisAttributes(atb6);
  }	  
{
	  G4VisAttributes* atb7 = new G4VisAttributes(G4Colour(0.0,0.0,1.0)); // used to set the colour of the tube (logicbox)
	atb7->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_silica_collimator->SetVisAttributes(atb7);
  }
	  
	{G4VisAttributes* atb8= new G4VisAttributes(G4Colour(1.0,0.8,0.0)); // used to set the colour of the tube (logicbox)
	atb8->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_window->SetVisAttributes(atb8);
 }
	
{
	G4VisAttributes* atb9= new G4VisAttributes(G4Colour(1.0, 1.0,1.0)); // used to set the colour of the tube (logicbox)
	atb9->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_sourcecover->SetVisAttributes(atb9);
 }	
	
	  {
	  G4VisAttributes* atb10= new G4VisAttributes(G4Colour(0.0,0.0,1.0)); // used to set the colour of the tube (logicbox)
	atb10->SetForceSolid(true); // if you make it true full body will be visible. this can also be made visible by invoking /vis/viewer/set/style surface
	logic_moon->SetVisAttributes(atb10);
  }

  return physi_mother;
}

DetectorConstruction::~DetectorConstruction(){;}
