
// bamboo_stick.c

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name("���",({"bamboo stick" , "stick"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
		{
		set("unit","��");
		set("value",100);
		set("material","bamboo");
		set("long","����һ��Ѱ�������,���ɽ�ʵ.\n");
		set("wield_msg","$N�ó�һ��$n��������.\n");
	set("uneqip_msg","$N��$n�������.\n");
		}
	init_staff(5);
	setup();
}
