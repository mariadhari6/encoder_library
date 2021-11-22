#ifndef ENCODER_H
#define ENCODER_H

#include <mbed.h>
class ENCODER {
    public:
        typedef enum Encoding{
            X2_ENCODING,
            X4_ENCODING
        } Encoding;
        ENCODER(PinName  chanA, PinName chanB);
        InterruptIn chan_A;
        DigitalIn chan_B;
        int counter;
        int getCounter();
        void reset();
        double getRadian();
        
    private:
        int currState;
        int prevState;
        Encoding encoding_;
        void encode();
};
#endif