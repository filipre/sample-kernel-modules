#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("René Filip <renefilip@mail.com>");

#define PRINT_PREF "[KEYBOARD_INTERRUPT]: "

unsigned int scancode;

static void keyboard_tasklet_handler(unsigned long data)
{
	if (scancode & 0x80)
		printk(PRINT_PREF "Key released: %d", scancode);
	else 
		printk(PRINT_PREF "Key pressed: %d", scancode);
}

static DECLARE_TASKLET(keyboard_tasklet, keyboard_tasklet_handler, 0);

static irqreturn_t irq_handler(int irq, void *dev_id)
{
	scancode = inb (0x60);
	tasklet_schedule(&keyboard_tasklet);
	return IRQ_HANDLED;
}

static int __init my_mod_init(void)
{
	int irq_rc;
	
	printk(PRINT_PREF "Entering module.");
	irq_rc = request_irq(1, irq_handler, IRQF_SHARED, "keyboard_interrupt", (void *)(irq_handler));
	if (irq_rc > 0)
	{
		printk(PRINT_PREF "Could not request IRQ");
		return 1;
	}
	
	return 0;
}

static void __exit my_mod_exit(void)
{	
	free_irq(1, (void *)(irq_handler));
	printk(PRINT_PREF "Exiting module.");
}

module_init(my_mod_init);
module_exit(my_mod_exit);
