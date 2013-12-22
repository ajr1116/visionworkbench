// __BEGIN_LICENSE__
//  Copyright (c) 2006-2013, United States Government as represented by the
//  Administrator of the National Aeronautics and Space Administration. All
//  rights reserved.
//
//  The NASA Vision Workbench is licensed under the Apache License,
//  Version 2.0 (the "License"); you may not use this file except in
//  compliance with the License. You may obtain a copy of the License at
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
// __END_LICENSE__

#include <vw/Camera/OrbitingPushbroomModel.h>

using namespace vw;
using namespace camera;

OrbitingPushbroomModel::OrbitingPushbroomModel( int number_of_lines,
                        int samples_per_line,
                        int sample_offset,
                        double focal_length,
                        double along_scan_pixel_size,
                        double across_scan_pixel_size,
                        double line_integration_time,
                        double t0_camera_pose,
                        double dt_camera_pose,
                        double t0_position,
                        double dt_position,
                        Vector3 pointing_vec,
                        Vector3 u_vec,
                        std::vector<Quaternion<double> > const& camera_poses,
                        std::vector<Vector3> const& positions) :
LinescanModel<Curve3DPositionInterpolation,
              SLERPPoseInterpolation>::LinescanModel(number_of_lines,
                                                     samples_per_line,
                                                     sample_offset,
                                                     focal_length,
                                                     along_scan_pixel_size,
                                                     across_scan_pixel_size,
                                                     line_integration_time,
                                                     pointing_vec, u_vec,
                                                     Curve3DPositionInterpolation(positions, t0_position, dt_position),
                                                     SLERPPoseInterpolation(camera_poses, t0_camera_pose, dt_camera_pose)) {}

// This constructor is used when the exposure time varies from
// scanline to scanline, e.g. in the case of HRSC.
OrbitingPushbroomModel::OrbitingPushbroomModel( int number_of_lines,
                                                int samples_per_line,
                                                int sample_offset,
                                                double focal_length,
                                                double along_scan_pixel_size,
                                                double across_scan_pixel_size,
                                                std::vector<double> line_times,
                                                double t0_camera_pose,
                                                double dt_camera_pose,
                                                double t0_position,
                                                double dt_position,
                                                Vector3 pointing_vec,
                                                Vector3 u_vec,
                                                std::vector<Quaternion<double> > const& camera_poses,
                                                std::vector<Vector3> const& positions) :
LinescanModel<Curve3DPositionInterpolation,
              SLERPPoseInterpolation>::LinescanModel(number_of_lines,
                                                     samples_per_line,
                                                     sample_offset,
                                                     focal_length,
                                                     along_scan_pixel_size,
                                                     across_scan_pixel_size,
                                                     line_times,
                                                     pointing_vec, u_vec,
                                                     Curve3DPositionInterpolation(positions, t0_position, dt_position),
                                                     SLERPPoseInterpolation(camera_poses, t0_camera_pose, dt_camera_pose)) {}

OrbitingPushbroomModel::~OrbitingPushbroomModel() {}
std::string OrbitingPushbroomModel::type() const { return "OrbitingPushbroom"; }
