void requestEvent() {
  value.toCharArray(i2c_data, I2C_ARRAY_LENGHT);
  Wire.write(i2c_data, REQUEST_LENGHT);
}
