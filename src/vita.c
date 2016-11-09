
int module_start(void)
{
	return 0;
}

void _start() __attribute__ ((weak, alias ("module_start")));

