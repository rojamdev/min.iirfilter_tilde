/// @file
///	@ingroup 	minexamples
///	@copyright	Copyright 2018 The Min-DevKit Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"
#include "circular_buffer.h"
#include "first_order_iir.h"

using namespace c74::min;


class iirfilter : public object<iirfilter>, public sample_operator<1, 1> 
{
public:
    MIN_DESCRIPTION	{ "Baisc IIR low-pass filter" };
    MIN_TAGS		{ "audio" };
    MIN_AUTHOR		{ "Me" };
    MIN_RELATED		{ "phasor~" };

    inlet<>     input {this, "(signal) input"};
    inlet<>     alpha_input {this, "(number) frequency", alpha_value};
    outlet<>    output {this, "(signal) output", "signal"};

    /* argument<number> frequency_arg {this, "frequency", "Initial frequency in hertz.",
        MIN_ARGUMENT_FUNCTION {
            frequency = arg;
        }
    };

    message<> m_number { this, "number", "Set the frequency in Hz.",
        MIN_FUNCTION {
            frequency = args;
            return {};
        }
    };

    attribute<number> frequency { this, "frequency", 1.0,
        description {"Frequency in Hz"},
        setter { MIN_FUNCTION {
            m_oscillator.frequency(args[0], samplerate());
            return args;
        }}
    }; */

    attribute<number> alpha_value {this, "alpha", 0.5};

    sample operator()(sample x)
    {
		auto y = x * alpha_value;
        
        return y;
    }

private:
};

MIN_EXTERNAL(iirfilter);
