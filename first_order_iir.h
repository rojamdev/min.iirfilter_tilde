#pragma once

class FirstOrderIIR {
public:
	FirstOrderIIR() {
		lastSample = alpha = 0.0;
	}

	double processSample(double sample) {
		double newSample = ((1 - alpha) * sample) + (alpha * lastSample);
		lastSample = newSample;
		return newSample;
	}

	void setAlpha(double alpha) {
		this->alpha = alpha;
	}

private:
	double alpha;
	double lastSample;
};