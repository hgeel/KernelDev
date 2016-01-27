void put_char(char c, int x, int y)
{
	char* vidmem = (char*) 0xB8000;
	int pos = y * 80 + x;
	vidmem[pos*2] = c;
	vidmem[pos*2+1] = 0x02;
}

void put_string_pos(const char* string, int x, int y)
{
	int i = 0;
	while(string[i] != 0)
	{
		put_char(string[i], x, y);
		x = x+1;
		i = i+1;
		if(x >= 80)
		{
			x = 0;
			y = y+1;
			if(y >= 25) y = 0;
		}
	}
}

void put_string(const char* string)
{
	put_string_pos(string, 0, 0);
}

void clear_screen()
{
	char* vidmem = (char*) 0xB8000;
	int i = 0;
	while(i < 80 * 25 * 2)
	{
		vidmem[i] = ' ';
		vidmem[i+1] = 0x07;
		i = i+2;
	}
}

void kernel_main(void)
{
	clear_screen();
	put_string("Hello World Kernel!");
}
