#pragma once

//refer to struct ImuData of MYNT SDK as standard imu struct.
struct SImuData {
  /** IMU frame id */
  std::uint32_t frame_id;
  /** IMU timestamp in 1us */
  std::uint64_t timestamp;
  /** IMU accelerometer data for 3-axis: X, Y, Z. */
  double accel[3];
  /** IMU gyroscope data for 3-axis: X, Y, Z. */
  double gyro[3];
  /** IMU temperature */
  double temperature;

  void Reset() {
    timestamp = 0;
    std::fill(accel, accel + 3, 0);
    std::fill(gyro, gyro + 3, 0);
    temperature = 0;
  }

  SImuData() {
    Reset();
  }
};
