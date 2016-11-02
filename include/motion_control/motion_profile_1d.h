#include <motion_control/profile_point.h>
#include <motion_control/fixed_size_stack.h>

#ifndef MOTION_CONTROL_PROFILE1D_H
#define MOTION_CONTROL_PROFILE1D_H

namespace MotionControl {

class MotionProfile1D {
public:
    MotionProfile1D();

    // Get a point at the given t.
    virtual ProfilePoint1D get_at_time(double t) = 0;

    // The full duration in seconds of the profile
    virtual double duration() = 0;

    // Generate the full motion profile with the given dt
    void generate(double dt);

    // Get a point at idx*dt time. Requires the profile to be pregenerated
    ProfilePoint1D get_at_index(int idx);

    // The total number of steps if this is a pregenerated motion profile
    int steps();

    // If this profile has been pregenerated
    bool is_pregenerated();

private:
    MotionControl::FixedSizeStack<ProfilePoint1D> *points;
};

}

#endif