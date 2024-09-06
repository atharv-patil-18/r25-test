#include <stdint.h>
#include <math.h>

// Constants
#define CHANNEL_MIN 0
#define CHANNEL_MAX 2047
#define PWM_MIN 0
#define PWM_MAX 255

int interpolation(uint16_t channel) {
    // Clamp channel value to be within the expected range
    if (channel < CHANNEL_MIN) {
        channel = CHANNEL_MIN;
    } else if (channel > CHANNEL_MAX) {
        channel = CHANNEL_MAX;
    }

    // Perform linear interpolation
    int pwm = (int)(((float)(channel - CHANNEL_MIN) / (CHANNEL_MAX - CHANNEL_MIN)) * (PWM_MAX - PWM_MIN) + PWM_MIN);

    // Return the interpolated PWM value
    return pwm;
}
