#include "ENCODER.h"
ENCODER::ENCODER(PinName chanA, PinName chanB) : 
                 chan_A(chanA), chan_B(chanB){
                    currState = 0;
                    prevState = 0;
                    counter = 0;
                    chan_A.rise(callback(this, &ENCODER::encode));
                    chan_A.fall(callback(this, &ENCODER::encode));
                 }
int ENCODER::getCounter(){
   return counter;
}
void ENCODER::reset(){
   counter = 0;
}
void ENCODER::encode(){
   int chanA_ = chan_A.read();
   int chanB_ = chan_B.read(); 
   currState = (chanA_ << 1) | (chanB_);
   if ((prevState == 0x3 && currState == 0x0) || (prevState == 0x0 && currState == 0x3))
   {
      counter--;
   }
   else if ((prevState == 0x2 && currState == 0x1) || (prevState == 0x1 && currState == 0x2))
   {
      counter++;
   }
   prevState = currState;
}
double ENCODER::getRadian(){
   return static_cast<double>(counter)  * 0.023620997;
}

