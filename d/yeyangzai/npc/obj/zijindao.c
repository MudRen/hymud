// blade.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(MAG"�Ͻ�"NOR,({"zijindao","sword","jian"}));
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",3000);
		set("material", "iron");
		set("long","��˵������ұ�����ִ���ı�����ʮ�ֳ��ء�\n");
		set("wield_msg","$Nһ��������$n���ᡱ��һ��Ծ��$N�����С�\n");
		set("unequip_msg","$N����΢̧������$n��ಡ���һ�����뽣���С�\n");
	}
        init_sword(90);
	setup();
}
