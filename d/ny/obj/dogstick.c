
// dogstick.c

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(HIC "�򹷰�" NOR,({"dog stick" , "stick"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
		{
		set("unit","��");
		set("value",100000);
		set("material","jade");
		set("long","����һ����ͬѰ��������̹�,���ɽ�ʵ.\n");
		set("wield_msg","$N�ó�һ��$n��������.\n");
	set("uneqip_msg","$N��$n�������.\n");
		}
	init_staff(50);
	setup();
}
