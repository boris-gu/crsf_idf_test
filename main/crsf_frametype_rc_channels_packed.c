/**
 * Channels data (both handset to TX and RX to flight controller)
 */
#pragma once

#include "crsf_frametype_rc_channels_packed.h"

crsf_rc_channels_packed crsf_default2rc_channels_packed(crsf_default pkt)
{

}

int crsf_rc_channels_packed2array(crsf_rc_channels_packed in_pkt, uint8_t* out_pkt)
{
  
}