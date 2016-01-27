char* vidmem = (char*) 0xB8000;

int currentPosX = 0;
int currentPosY = 0;

void set_cursor_pos(int x, int y)
{
        if(x < 0 || x >= 80 || y < 0 || y >= 25) return;
        currentPosX = x;
        currentPosY = y;
}

void put_char(char c, int x, int y)
{
	int pos = y * 80 + x;
	vidmem[pos*2] = c;
	vidmem[pos*2+1] = 0x02;
}

void put_string(const char* string)
{
	int i = 0;
	while(string[i] != 0)
	{
		put_char(string[i], currentPosX, currentPosY);
		i++;
		currentPosX++;
		if(currentPosX >= 80)
		{
			currentPosX = 0;
			currentPosY++;
			if(currentPosY >= 25) currentPosY = 0;
		}
	}
}

void put_string_pos(const char* string, int x, int y)
{
	int prevX = currentPosX;
	int prevY = currentPosY;
	set_cursor_pos(x, y);
	put_string(string);
	set_cursor_pos(prevX, prevY);
}

void clear_screen()
{
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
	int i;
	for(i = 0; i < 80; i++)
	{
		put_string("H");
	}
}
