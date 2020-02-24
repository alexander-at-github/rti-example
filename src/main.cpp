#include <cmath>
#include <cstdlib>
#include <iostream>
//#include <memory>

#include <rti/device.hpp>

#include "particle.hpp"

int main(int argc, char** argv)
{
  auto rtidevice = rti::device<float> {};
  auto particleV = std::make_unique<particle<float> > ();
  rtidevice.set_points({{0,0,0}, {1,1,0}});
  rtidevice.set_normals({{0,0,1}, {0,0,1}});
  rtidevice.set_grid_spacing({std::sqrt(2), std::sqrt(2)});
  rtidevice.set_sticking_coefficient(0.5);
  rtidevice.set_number_of_rays(1024*1024);
  rtidevice.set_particle(std::move(particleV));
  rtidevice.run();
  auto mcestimates = rtidevice.get_mc_estimates();

  auto seperator = ",";
  auto sep = "";
  for(size_t idx = 0; idx < mcestimates.size(); ++idx) {
    std::cout << sep << mcestimates[idx];
    sep = seperator;
  }
  std::cout << std::endl;

  exit(EXIT_SUCCESS);
}
