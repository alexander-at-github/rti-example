#include <cmath>
#include <cstdlib>
#include <iostream>
//#include <memory>

#include <rti/device.hpp>

#include "particle_factory.hpp"

int main(int argc, char** argv)
{
  auto points = std::vector<std::array<float, 3> > {{0,0,0}, {1,1,0}};
  auto normals = std::vector<std::array<float, 3> > {{0,0,1}, {0,0,1}};
  auto spacing = std::vector<float> {std::sqrt(2), std::sqrt(2)};

  auto rtidevice = rti::device<float> {};
  auto particlefactory = std::make_unique<particle_factory<float> > ();
  rtidevice.set_points(points);
  rtidevice.set_normals(normals);
  rtidevice.set_grid_spacing(spacing);
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
