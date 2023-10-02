# lqr_rendezvous

This is a C++ simulation of spaceflight dynamics for a satellite in low-earth orbit.
It will implement a control law for a time-optimal rendezvous with another satellite.

## Getting Started

In order to use this project locally, you must make sure you have cmake installed, as well as a working C++ compiler.
Additionally you will want to activate my additional bash file(s) to automate build, rebuild, and compile commands.

### Prerequisites

- CMAKE VERSION 3.25.2
- C++ compiler
- activate bash script(s) via terminal command: "chmod +x rebuild.sh" (as an example of one bash file)

### Installing

- Clone Git Repo
- check cmake version for compatability; run: "cmake --version"
- run command(s) to make bash script(s) executable (see above)

## Usage

- in root directory run ./rebuild.sh to build the project
- to output compiled program, run ./fast in the build directory (run cd build first)
- use post-processing script(s) for data analysis+visualization (in data_processing directory)

Here is a 3D plot of a rendezvous trajectory in the Hill Frame of the Target Satellite:

![Alt Text](./cool_plots/rendezvous_3d_450mN.png)
![Alt Text](./cool_plots/control_signal_450mN.png.png)
This one has a limit set for the Control Force at 450 mN.

Here is another 3D plot of a similar rendezvous trajectory in the hill frame without a limit on control force (it didn't surpass 15 Newtons):

![Alt Text](./cool_plots/spiral_rendezvous.png)


It looks pretty solid, saturation in the beginning, but quick convergence nonetheless.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
