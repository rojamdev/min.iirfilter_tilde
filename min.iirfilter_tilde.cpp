/// @file
///	@ingroup 	minexamples
///	@copyright	Copyright 2018 The Min-DevKit Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"
#include "first_order_iir.h"

using namespace c74::min;


class iirfilter : public object<iirfilter>, public sample_operator<1, 1> 
{
public:
    MIN_DESCRIPTION	{ "Baisc IIR low-pass filter" };
    MIN_TAGS		{ "audio" };
    MIN_AUTHOR		{ "Rojam" };
    MIN_RELATED		{ "phasor~" };

    inlet<>     input       { this, "(signal) input" };
    inlet<>     alpha_in    { this, "(float) alpha", m_alpha };
    outlet<>    output      { this, "(signal) output", "signal" };

    attribute<float, threadsafe::no, limit::clamp> m_alpha {
		this, 
		"alpha", 
		0.5,
		description {"Alpha value to control the filter."},
		range {0.01, 0.99}
	};

    message<> m_number {
        this, 
        "number", 
        "Set the alpha value for the filter.",
		MIN_FUNCTION {
            if (inlet == 1) 
                m_alpha = args[0];
	        return {};
        }
    };

    sample operator()(sample x) {
		IIRfilter.setAlpha(m_alpha);
        auto y = IIRfilter.processSample(x);
        return y;
    }

private:
	FirstOrderIIR IIRfilter;
};

MIN_EXTERNAL(iirfilter);
