#pragma once
#include <vector>

class CircularBuffer
{
public:
    CircularBuffer()
    {
        sampleArray = std::vector<double>();
        writeIndex = bufferLength = 0;
    }

    CircularBuffer(int length)
    {
        bufferLength = length;
        sampleArray.resize(bufferLength, 0.0);
        writeIndex = 0;
    }

    void setData(double sample)
    {
        sampleArray[writeIndex] = sample;
    }

    double getData(int delay)
    {
        double delayedSample = 0.0;
        
        if (delay > 0 && delay < bufferLength)
        {
            // Sets read index to n number of samples behind writeIndex
            // determined by "delay" variable
            int readIndex = writeIndex - delay;

            // Loops back around to the end of the buffer
            if (readIndex < 0)
                readIndex += bufferLength;

            delayedSample = sampleArray[readIndex];
        }

        return delayedSample;
    }

    void nextSample()
    {
        writeIndex++;

        if (writeIndex >= bufferLength)
            writeIndex = 0;
    }

private:
    std::vector<double> sampleArray;
    int writeIndex;
    int bufferLength;
};