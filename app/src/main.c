#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

static const struct device *gpio_ct_dev=
	DEVICE_DT_GET(DT_NODELABEL(gpio0));

int main(void)
{
    if(!device_is_ready(gpio_ct_dev))
    {
        return 0;
    }

    int ret;
    ret= gpio_pin_configure(gpio_ct_dev, 25, GPIO_OUTPUT_ACTIVE);

    if(ret!=0)
    {
        return 0;
    }

    while(true)
    {
        ret = gpio_pin_set_raw(gpio_ct_dev,25,1);
        if(ret!=0)
        {
            return 0;
        }
        k_msleep(500);

        ret = gpio_pin_set_raw(gpio_ct_dev,25,0);
        if(ret!=0)
        {
            return 0;
        }
        k_msleep(500);

    }

    return 1;
}