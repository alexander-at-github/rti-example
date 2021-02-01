#pragma once

#include <rti/particle/i_particle.hpp>

template<typename numeric_type>
class particle : public rti::particle::i_particle<numeric_type> {

public:

    numeric_type
    get_sticking_probability
    (RTCRay& rayin,
     RTCHit& hitin,
     rti::geo::meta_geometry<numeric_type>& geometry,
     rti::rng::i_rng& rng,
     rti::rng::i_rng::i_state& rngstate) override final
  {
    return 0.8;
  }

  void init_new() override final {}
};
