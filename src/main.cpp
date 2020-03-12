#include <cmath>
#include <cstdlib>
#include <iostream>
//#include <memory>

#include <rti/device.hpp>

#include "particle_factory.hpp"

int main(int argc, char** argv)
{
  auto rtidevice = rti::device<float> {};
  auto particlefactory = std::make_unique<particle_factory<float> > ();
  rtidevice.set_points(input::get_points());
  rtidevice.set_normals(normals());
  rtidevice.set_grid_spacing(spacing());
  //rtidevice.set_sticking_coefficient(0.5);
  rtidevice.set_number_of_rays(1 * 1024 * 1024);
  rtidevice.register_particle_factory(std::move(particlefactory));
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
