#pragma once

#include<rti/device.hpp>

template<typename numeric_type>
class particle : public rti::i_particle<numeric_type>
{
public:
  numeric_type process_hit(size_t primID) override final
  {
    return 0.8;
  }
};
