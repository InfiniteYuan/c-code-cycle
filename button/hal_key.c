#include "esp_system.h"
#include "driver/gpio.h"
#include "multi_button.h"
#include "hal_key.h"

TS_StateTypeDef ts_state;

struct Button btn1;
struct Button btn2;
struct Button btn3;

uint8_t read_button1_GPIO(void) 
{
	return (uint8_t)gpio_get_level(GPIO_NUM_39);
}

uint8_t read_button2_GPIO(void) 
{
	return (uint8_t)gpio_get_level(GPIO_NUM_38);
}

uint8_t read_button3_GPIO(void) 
{
	return (uint8_t)gpio_get_level(GPIO_NUM_37);
}


/****************************************button handle*************************************************/
void BTN1_PRESS_DOWN_Handler(void* btn)
{
	printf("BTN1_PRESS_DOWN_Handler\n");
	ts_state.touchX = 20;
	ts_state.touchY = 20;
	ts_state.touchDetected = 1;
}

void BTN1_PRESS_UP_Handler(void* btn)
{
	printf("BTN1_PRESS_UP_Handler\n");
	ts_state.touchDetected = 0;
}

void BTN1_PRESS_REPEAT_Handler(void* btn)
{
	printf("BTN1_PRESS_REPEAT_Handler\n");
}

void BTN1_SINGLE_Click_Handler(void* btn)
{
	printf("BTN1_SINGLE_Click_Handler\n");
}

void BTN1_DOUBLE_Click_Handler(void* btn)
{
	printf("BTN1_DOUBLE_Click_Handler\n");
}
void BTN1_LONG_RRESS_START_Handler(void* btn)
{
	printf("BTN1_LONG_RRESS_START_Handler\n");
}
void BTN1_LONG_PRESS_HOLD_Handler(void* btn)
{
	printf("BTN1_LONG_PRESS_HOLD_Handler\n");
}

void BTN2_PRESS_DOWN_Handler(void* btn)
{
	printf("BTN2_PRESS_DOWN_Handler\n");
	ts_state.touchX = 160;
	ts_state.touchY = 20;
	ts_state.touchDetected = 1;
}
void BTN2_PRESS_UP_Handler(void* btn)
{
	printf("BTN2_PRESS_UP_Handler\n");
	ts_state.touchDetected = 0;
}
void BTN2_PRESS_REPEAT_Handler(void* btn)
{
	printf("BTN2_PRESS_REPEAT_Handler\n");
}
void BTN2_SINGLE_Click_Handler(void* btn)
{
	printf("BTN2_SINGLE_Click_Handler\n");
}
void BTN2_DOUBLE_Click_Handler(void* btn)
{
	printf("BTN2_LONG_PRESS_HOLD_Handler\n");
}

void BTN2_LONG_RRESS_START_Handler(void* btn)
{
	printf("BTN2_LONG_RRESS_START_Handler\n");
}
void BTN2_LONG_PRESS_HOLD_Handler(void* btn)
{
	printf("BTN2_LONG_PRESS_HOLD_Handler\n");
}

void BTN3_PRESS_DOWN_Handler(void* btn)
{
	printf("BTN3_PRESS_DOWN_Handler\n");
	ts_state.touchX = 300;
	ts_state.touchY = 20;
	ts_state.touchDetected = 1;
}
void BTN3_PRESS_UP_Handler(void* btn)
{
	printf("BTN3_PRESS_UP_Handler\n");
	ts_state.touchDetected = 0;
}
void BTN3_PRESS_REPEAT_Handler(void* btn)
{
	printf("BTN3_PRESS_REPEAT_Handler\n");
}
void BTN3_SINGLE_Click_Handler(void* btn)
{
	printf("BTN3_SINGLE_Click_Handler\n");
}
void BTN3_DOUBLE_Click_Handler(void* btn)
{
	printf("BTN3_LONG_PRESS_HOLD_Handler\n");
}

void BTN3_LONG_RRESS_START_Handler(void* btn)
{
	printf("BTN3_LONG_RRESS_START_Handler\n");
}
void BTN3_LONG_PRESS_HOLD_Handler(void* btn)
{
	printf("BTN3_LONG_PRESS_HOLD_Handler\n");
}

void key_init(void)
{
	gpio_set_direction(GPIO_NUM_39, GPIO_MODE_INPUT);
	gpio_set_direction(GPIO_NUM_38, GPIO_MODE_INPUT);
	gpio_set_direction(GPIO_NUM_37, GPIO_MODE_INPUT);

	button_init(&btn1, read_button1_GPIO, 0);
	button_init(&btn2, read_button2_GPIO, 0);
	button_init(&btn3, read_button3_GPIO, 0);
	
	button_attach(&btn1, PRESS_DOWN,       BTN1_PRESS_DOWN_Handler);
	button_attach(&btn1, PRESS_UP,         BTN1_PRESS_UP_Handler);
	button_attach(&btn1, PRESS_REPEAT,     BTN1_PRESS_REPEAT_Handler);
	button_attach(&btn1, SINGLE_CLICK,     BTN1_SINGLE_Click_Handler);
	button_attach(&btn1, DOUBLE_CLICK,     BTN1_DOUBLE_Click_Handler);
	button_attach(&btn1, LONG_RRESS_START, BTN1_LONG_RRESS_START_Handler);
	button_attach(&btn1, LONG_PRESS_HOLD,  BTN1_LONG_PRESS_HOLD_Handler);

	button_attach(&btn2, PRESS_DOWN,       BTN2_PRESS_DOWN_Handler);
	button_attach(&btn2, PRESS_UP,         BTN2_PRESS_UP_Handler);
	button_attach(&btn2, PRESS_REPEAT,     BTN2_PRESS_REPEAT_Handler);
	button_attach(&btn2, SINGLE_CLICK,     BTN2_SINGLE_Click_Handler);
	button_attach(&btn2, DOUBLE_CLICK,     BTN2_DOUBLE_Click_Handler);
	button_attach(&btn2, LONG_RRESS_START, BTN2_LONG_RRESS_START_Handler);
	button_attach(&btn2, LONG_PRESS_HOLD,  BTN2_LONG_PRESS_HOLD_Handler);

	button_attach(&btn3, PRESS_DOWN,       BTN3_PRESS_DOWN_Handler);
	button_attach(&btn3, PRESS_UP,         BTN3_PRESS_UP_Handler);
	button_attach(&btn3, PRESS_REPEAT,     BTN3_PRESS_REPEAT_Handler);
	button_attach(&btn3, SINGLE_CLICK,     BTN3_SINGLE_Click_Handler);
	button_attach(&btn3, DOUBLE_CLICK,     BTN3_DOUBLE_Click_Handler);
	button_attach(&btn3, LONG_RRESS_START, BTN3_LONG_RRESS_START_Handler);
	button_attach(&btn3, LONG_PRESS_HOLD,  BTN3_LONG_PRESS_HOLD_Handler);

	button_start(&btn1);
	button_start(&btn2);
	button_start(&btn3);
#ifdef youhua
	button_init  (&btn, button_read_pin, 0);
    button_attach(&btn, PRESS_DOWN,       button_callback);
    button_attach(&btn, PRESS_UP,         button_callback);
    button_attach(&btn, PRESS_REPEAT,     button_callback);
    button_attach(&btn, SINGLE_CLICK,     button_callback);
    button_attach(&btn, DOUBLE_CLICK,     button_callback);
    button_attach(&btn, LONG_RRESS_START, button_callback);
    button_attach(&btn, LONG_PRESS_HOLD,  button_callback);
    button_start (&btn);
#endif
}

void button_callback(void *btn)
{
    uint32_t btn_event_val; 
    
    btn_event_val = get_button_event((struct button *)btn); 
    
    switch(btn_event_val)
    {
    case PRESS_DOWN:
        rt_kprintf("button press down\n"); 
    break; 

    case PRESS_UP: 
        rt_kprintf("button press up\n");
    break; 

    case PRESS_REPEAT: 
        rt_kprintf("button press repeat\n");
    break; 

    case SINGLE_CLICK: 
        rt_kprintf("button single click\n");
    break; 

    case DOUBLE_CLICK: 
        rt_kprintf("button double click\n");
    break; 

    case LONG_RRESS_START: 
        rt_kprintf("button long press start\n");
    break; 

    case LONG_PRESS_HOLD: 
        rt_kprintf("button long press hold\n");
    break; 
    }
}
