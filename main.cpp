#include "Simulation.cpp"

using namespace std;

int main(int argc, char ** argv)
{
  Simulation registrar;

  registrar.Read(argv[1]);
  //registrar.Simulate();
  registrar.Calculate();

}
