#include "py/obj.h"
#include "pin.h"

// Returns the pin mode. This value returned by this macro should be one of:
// GPIO_MODE_INPUT, GPIO_MODE_OUTPUT_PP, GPIO_MODE_OUTPUT_OD,
// GPIO_MODE_AF_PP, GPIO_MODE_AF_OD, or GPIO_MODE_ANALOG.

//The GPIO ALT
#define IfxPin_Mode_inputNoPullDevice	 0	     /**< \brief Input  No pull device connected. */
#define IfxPin_Mode_inputPullDown		 8U	     /**< \brief Input  pull-down device connected. */
#define IfxPin_Mode_inputPullUp			 0x10U   /**< \brief Input  pull-up device connected. */
#define IfxPin_Mode_outputPushPullGeneral  0x80U   /**< \brief Push-pull  General-purpose output */
#define IfxPin_Mode_outputPushPullAlt1 	 0x88U   /**< \brief Push-pull  Alternate output function 1. */
#define IfxPin_Mode_outputPushPullAlt2 	 0x90U   /**< \brief Push-pull  Alternate output function 2. */
#define IfxPin_Mode_outputPushPullAlt3 	 0x98U   /**< \brief Push-pull  Alternate output function 3. */
#define IfxPin_Mode_outputPushPullAlt4 	 0xA0U   /**< \brief Push-pull  Alternate output function 4. */
#define IfxPin_Mode_outputPushPullAlt5 	 0xA8U   /**< \brief Push-pull  Alternate output function 5. */
#define IfxPin_Mode_outputPushPullAlt6 	 0xB0U   /**< \brief Push-pull  Alternate output function 6. */
#define IfxPin_Mode_outputPushPullAlt7 	 0xB8U   /**< \brief Push-pull  Alternate output function 7. */
#define IfxPin_Mode_outputOpenDrainGeneral  0xC0U   /**< \brief Open-drain  General-purpose output. */
#define IfxPin_Mode_outputOpenDrainAlt1	 0xC8U   /**< \brief Open-drain  Alternate output function 1. */
#define IfxPin_Mode_outputOpenDrainAlt2	 0xD0U   /**< \brief Open-drain  Alternate output function 2. */
#define IfxPin_Mode_outputOpenDrainAlt3	 0xD8U   /**< \brief Open-drain  Alternate output function 3. */
#define IfxPin_Mode_outputOpenDrainAlt4	 0xE0U   /**< \brief Open-drain  Alternate output function 4. */
#define IfxPin_Mode_outputOpenDrainAlt5	 0xE8U   /**< \brief Open-drain  Alternate output function 5. */
#define IfxPin_Mode_outputOpenDrainAlt6	 0xF0U   /**< \brief Open-drain  Alternate output function 6. */
#define IfxPin_Mode_outputOpenDrainAlt7	 0xF8U   /**< \brief Open-drain  Alternate output function 7. */

uint32_t pin_get_mode(const pin_obj_t *pin) {
    uint32_t raw_mode,mode;

	if(pin != NULL)
	{
        raw_mode = py_tc397_get_pin_mode(pin->pin);
        if((raw_mode == IfxPin_Mode_inputNoPullDevice)||
		   (raw_mode == IfxPin_Mode_inputPullDown)||
		   (raw_mode == IfxPin_Mode_inputPullUp))
        {  mode = GPIO_MODE_INPUT;     }
		else if(raw_mode == IfxPin_Mode_outputPushPullGeneral)
		{  mode = GPIO_MODE_OUTPUT_PP; }
		else if(raw_mode == IfxPin_Mode_outputOpenDrainGeneral)
		{  mode = GPIO_MODE_OUTPUT_OD; }
		else if( (raw_mode == IfxPin_Mode_outputPushPullAlt1)||
			     (raw_mode == IfxPin_Mode_outputPushPullAlt2)||
			     (raw_mode == IfxPin_Mode_outputPushPullAlt3)||
			     (raw_mode == IfxPin_Mode_outputPushPullAlt4)||
			     (raw_mode == IfxPin_Mode_outputPushPullAlt5)||
			     (raw_mode == IfxPin_Mode_outputPushPullAlt6)||
			     (raw_mode == IfxPin_Mode_outputPushPullAlt7))  
		{  mode = GPIO_MODE_AF_PP;  }
	    else if( (raw_mode == IfxPin_Mode_outputOpenDrainAlt1)||
			     (raw_mode == IfxPin_Mode_outputOpenDrainAlt2)||
			     (raw_mode == IfxPin_Mode_outputOpenDrainAlt3)||
			     (raw_mode == IfxPin_Mode_outputOpenDrainAlt4)||
			     (raw_mode == IfxPin_Mode_outputOpenDrainAlt5)||
			     (raw_mode == IfxPin_Mode_outputOpenDrainAlt6)||
			     (raw_mode == IfxPin_Mode_outputOpenDrainAlt7))    
	    {  mode = GPIO_MODE_AF_OD;	}
	}
	return mode;
}

// Returns the pin pullup/pulldown. The value returned by this macro should
// be one of GPIO_NOPULL, GPIO_PULLUP, or GPIO_PULLDOWN.
uint32_t pin_get_pull(const pin_obj_t *pin) {

  uint32_t pull_state = GPIO_NOPULL,raw_state;
  if(pin != NULL)
  {  
     if(pin->port == PORT_P33)
     {
        raw_state = py_tc397_get_pin_mode(pin->pin);
        if(raw_state == IfxPin_Mode_inputNoPullDevice)      { pull_state = GPIO_NOPULL  ;}
		else if(raw_state == IfxPin_Mode_inputPullDown)     { pull_state = GPIO_PULLDOWN;}
		else if(raw_state == IfxPin_Mode_inputPullUp)       { pull_state = GPIO_PULLUP  ;}
     }
  }
  return  pull_state;
}

// Returns the af (alternate function) index currently set for a pin.

uint32_t pin_get_af(const pin_obj_t *pin) {

  uint32_t af_idx = 0,raw_mode;
  if(pin != NULL)
  {
	  raw_mode = py_tc397_get_pin_mode(pin->pin);
	  if((raw_mode == IfxPin_Mode_outputPushPullAlt1)||(raw_mode == IfxPin_Mode_outputOpenDrainAlt1))
	  {  af_idx = 0x1; }
	  else if((raw_mode == IfxPin_Mode_outputPushPullAlt2)||(raw_mode == IfxPin_Mode_outputOpenDrainAlt2))
	  {  af_idx = 0x2; }
      else if((raw_mode == IfxPin_Mode_outputPushPullAlt3)||(raw_mode == IfxPin_Mode_outputOpenDrainAlt3))
      {  af_idx = 0x3; }
      else if((raw_mode == IfxPin_Mode_outputPushPullAlt4)||(raw_mode == IfxPin_Mode_outputOpenDrainAlt4))
      {  af_idx = 0x4; }
      else if((raw_mode == IfxPin_Mode_outputPushPullAlt5)||(raw_mode == IfxPin_Mode_outputOpenDrainAlt5))
      {  af_idx = 0x5; }
      else if((raw_mode == IfxPin_Mode_outputPushPullAlt6)||(raw_mode == IfxPin_Mode_outputOpenDrainAlt6))
      {  af_idx = 0x6; }
      else if((raw_mode == IfxPin_Mode_outputPushPullAlt7)||(raw_mode == IfxPin_Mode_outputOpenDrainAlt7))
      {  af_idx = 0x7; }
  }
  return af_idx;
}
void pin_set_high(const pin_obj_t *pin)
{  
  if(pin != NULL)
  {
    if(pin->port == PORT_P33) { py_tc397_set_pin_high(pin->pin); }
  }
}
void pin_set_low(const pin_obj_t *pin)
{
  if(pin != NULL)
  {
    if(pin->port == PORT_P33){ py_tc397_set_pin_low(pin->pin); }
  }
}
mp_uint_t pin_read(const pin_obj_t *pin)
{
  if(pin != NULL)
  {
    if(pin->port == PORT_P33){ return py_tc397_get_pin_state(pin->pin);}
  }
  return 0; 
}

void pin_hal_gpio_init(const pin_obj_t *pin, GPIO_InitTypeDef *GPIO_Init) {

	uint32_t raw_mode = IfxPin_Mode_inputNoPullDevice;
	if(GPIO_Init->Mode == GPIO_MODE_INPUT)
	{  
	  //When set as the input,then can configure the pull-down and pull-up for the input
      if(GPIO_Init->Pull = GPIO_NOPULL)         {  raw_mode = IfxPin_Mode_inputNoPullDevice; }
	  else if(GPIO_Init->Pull = GPIO_PULLUP)    {  raw_mode = IfxPin_Mode_inputPullUp;       }
	  else if(GPIO_Init->Pull = GPIO_PULLDOWN)  {  raw_mode = IfxPin_Mode_inputPullDown;     }
	}
	else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT_PP)
	{
	  raw_mode = IfxPin_Mode_outputPushPullGeneral;
	}
    else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT_OD)
    {
	  raw_mode = IfxPin_Mode_outputOpenDrainGeneral;
	}
	else if(GPIO_Init->Mode == GPIO_MODE_AF_PP)
	{
  	  if(GPIO_Init->Alternate == 1)			    { raw_mode = IfxPin_Mode_outputPushPullAlt1; }
  	  else if(GPIO_Init->Alternate == 2)		{ raw_mode = IfxPin_Mode_outputPushPullAlt2; }
  	  else if(GPIO_Init->Alternate == 3)		{ raw_mode = IfxPin_Mode_outputPushPullAlt3; }
  	  else if(GPIO_Init->Alternate == 4)		{ raw_mode = IfxPin_Mode_outputPushPullAlt4; }
  	  else if(GPIO_Init->Alternate == 5)		{ raw_mode = IfxPin_Mode_outputPushPullAlt5; }
  	  else if(GPIO_Init->Alternate == 6)		{ raw_mode = IfxPin_Mode_outputPushPullAlt6; }
  	  else if(GPIO_Init->Alternate == 7)		{ raw_mode = IfxPin_Mode_outputPushPullAlt7; }   
	}
	else if(GPIO_Init->Mode == GPIO_MODE_AF_OD)
	{
	  if(GPIO_Init->Alternate == 1)			    { raw_mode = IfxPin_Mode_outputOpenDrainAlt1;}
	  else if(GPIO_Init->Alternate == 2)		{ raw_mode = IfxPin_Mode_outputOpenDrainAlt2;}
	  else if(GPIO_Init->Alternate == 3)		{ raw_mode = IfxPin_Mode_outputOpenDrainAlt3;}
	  else if(GPIO_Init->Alternate == 4)		{ raw_mode = IfxPin_Mode_outputOpenDrainAlt4;}
	  else if(GPIO_Init->Alternate == 5)		{ raw_mode = IfxPin_Mode_outputOpenDrainAlt5;}
	  else if(GPIO_Init->Alternate == 6)		{ raw_mode = IfxPin_Mode_outputOpenDrainAlt6;}
	  else if(GPIO_Init->Alternate == 7)		{ raw_mode = IfxPin_Mode_outputOpenDrainAlt7;}       
	}
	else if(GPIO_Init->Mode == GPIO_MODE_ANALOG)
	{
       //Reserved
	}
	else if((GPIO_Init->Mode == GPIO_MODE_IT_RISING)||(GPIO_Init->Mode == GPIO_MODE_IT_FALLING))
	{
	   //Reserved
	}
	//Set the mode into the AURIX-TC397
	py_tc397_set_pin_mode(pin->pin,raw_mode);
}
