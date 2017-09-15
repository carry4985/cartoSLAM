/*
 * Copyright 2016 The Cartographer Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "sensor_bridge.h"

#include "msg_conversion.h"

#include "../common/make_unique.h"

namespace cartographer_ros {

namespace carto = ::cartographer;

using carto::transform::Rigid3d;

std::unique_ptr<::cartographer::sensor::OdometryData> SensorBridge::ToOdometryData(const nav_msgs::Odometry::ConstPtr &msg)
{
    double time = msg->header.stamp.toSec();
    //TODO(liu)
    //add code here 
    return ::cartographer::common::make_unique<::cartographer::sensor::OdometryData>
            (::cartographer::sensor::OdometryData{time, ToRigid3d(msg->pose.pose)});
}
/*
void SensorBridge::HandleOdometryMessage(const string &sensor_id, const nav_msgs::Odometry::ConstPtr &msg)
{
    std::unique_ptr<::cartographer::sensor::OdometryData> odometry_data = ToOdometryData(msg);
    //if (odometry_data != nullptr)
    //{
    //    trajectory_builder_->AddOdometerData(sensor_id, odometry_data->time, odometry_data->pose);
    //}
}
*/

}  // namespace cartographer_ros
