# Survivor Island Simulator

## Where you either make it back to civilization or die trying!

Apparently your nice little cruise trip turned into a holy disaster and the ship crashes on an
abandoned island! Your goal is to survive the harsh conditions on the island until you manage to
get help! Or die trying..

### How to run?

1. Clone the repo:

   ```bash
   git clone https://github.com/maggie-e-matthias/SimWorld.git
   cd SimWorld
   ```

2. Create a directory for build:

   ```bash
   mkdir build
   cd build
   ```

3. Run the cmake:
   (Windows)

   ```bash
   cmake -G "MinGW Makefiles" ..
   cmake --build .
   ```

   (Linux)

   ```bash
   cmake ..
   make
   ```

4. Run the simulation
   (Windows)
   ```bash
   ./sim.exe
   ```
   (Linux)
   ```bash
   .\sim
   ```
