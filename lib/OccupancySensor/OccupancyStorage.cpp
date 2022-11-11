#include "OccupancyStorage.h"

namespace Victor::Components {

  OccupancyStorage::OccupancyStorage(const char* filePath) : FileStorage(filePath) {
    _maxSize = 256;
  }

  void OccupancyStorage::_serializeTo(const OccupancySetting* model, DynamicJsonDocument& doc) {
    // button
    const JsonArray buttonArr = doc.createNestedArray(F("button"));
    buttonArr[0] = model->buttonPin;
    buttonArr[1] = model->buttonTrueValue;
    // sensor
    const JsonArray sensorArr = doc.createNestedArray(F("sensor"));
    sensorArr[0] = model->sensorPin;
    sensorArr[1] = model->sensorTrueValue;
    // others
    doc[F("debounce")] = model->debounce;
  }

  void OccupancyStorage::_deserializeFrom(OccupancySetting* model, const DynamicJsonDocument& doc) {
    // button
    const auto buttonArr   = doc[F("button")];
    model->buttonPin       = buttonArr[0];
    model->buttonTrueValue = buttonArr[1];
    // sensor
    const auto sensorArr   = doc[F("sensor")];
    model->sensorPin       = sensorArr[0];
    model->sensorTrueValue = sensorArr[1];
    // others
    model->debounce = doc[F("debounce")];
  }

  // global
  OccupancyStorage occupancyStorage;

} // namespace Victor::Components
