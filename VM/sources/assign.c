#include "cpu.h"

void			assign(uint32_t v, uint32_t **bit)
{
	int			val;
	int			i;
	int			prev;

	val = v;
	val <<= 8;
	i = 0;
	prev = 0;
	while (i < 4)
	{
		val >>= 2;
		(*bit)[i] = (val & v) - prev;
		prev = (val & v);
		i++;
	}
}
