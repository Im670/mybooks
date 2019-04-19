/*定义 tasklet 和底半部函数并关联*/
void xxx_do_tasklet(unsigned long);
DECLARE_TASKLET(xxx_tasklet, xxx_do_tasklet, 0);


/*中断处理上半部*/
void xxx_do_tasklet(unsigned long)
{
	//...
}

/*中断处理下半部*/
irqreturn_t xxx_interrupt(int irq, void *dev_id)
{
	//...
 	tasklet_schedule(&xxx_tasklet);
 	//...
}

/*设备驱动模块加载函数*/
int __init xxx_init(void)
{
	//...
	/*申请中断*/
	result = request_irq(xxx_irq, xxx_interrupt,IRQF_SHARED, "xxx", dev_id);
	//...
}

/*设备驱动模块卸载函数*/
void __exit xxx_exit(void)
{
	//...
	/*释放中断*/
	free_irq(xxx_irq, dev_id);
}

