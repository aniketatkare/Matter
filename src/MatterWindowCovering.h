/*
 * This file is part of the Silicon Labs Arduino Core
 *
 * The MIT License (MIT)
 *
 * Copyright 2024 Silicon Laboratories Inc. www.silabs.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MATTER_WINDOW_COVERING_H
#define MATTER_WINDOW_COVERING_H

#include "Matter.h"
#include "devices/DeviceWindowCovering.h"
#include <platform/CHIPDeviceLayer.h>
#include <app-common/zap-generated/attributes/Accessors.h>

using namespace chip;
using namespace ::chip::DeviceLayer;

class MatterWindowCovering : public ArduinoMatterAppliance {
public:

  enum window_covering_current_operation_t {
    WINDOW_COVERING_OPENING = 0x00,
    WINDOW_COVERING_CLOSING,
    WINDOW_COVERING_STOPPED
  };

  MatterWindowCovering();
  ~MatterWindowCovering();
  bool begin();
  void end();

  void set_current_operation(window_covering_current_operation_t current_operation);

  void set_actual_lift_position_raw(uint16_t lift_position);
  void set_actual_lift_position_percent(uint8_t lift_position_percent);
  uint16_t get_actual_lift_position_raw();
  uint8_t get_actual_lift_position_percent();

  uint16_t get_requested_lift_position_raw();
  uint8_t get_requested_lift_position_percent();

  void operator=(uint16_t lift_position);

private:
  DeviceWindowCovering* window_covering_device;
  EmberAfEndpointType* device_endpoint;
  DataVersion* endpoint_dataversion_storage;
  bool initialized;
};

#endif // MATTER_WINDOW_COVERING_H
