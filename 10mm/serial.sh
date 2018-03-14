#bin/bash
#PBS -k o
#PBS -e output.err
#PBS -o output.our
#PBS -l mem=1gb
#PBS -m abe
#PBS -r n
#PBS -V
source /home/goyal/geant4/geant4.9.4.p01/env.sh
export G4WORKDIR=/home/goyal/geant4/apxs/new/10mm
export LD_LIBRARY_PATH=/home/goyal/CLHEP/lib/:$LD_LIBRARY_PATH

cd /home/goyal/geant4/apxs/new/10mm
make
/home/goyal/geant4/apxs/new/10mm/bin/Linux-g++/apxs_ti_10mm run.mac <out.txt
