// ganjiangsword.c
// by dicky

#include <weapon.h>
#include <ansi.h>
inherit SWORD;


void create()
{
        set_name(HIB"�ɽ�"NOR, ({ "ganjiang sword","sword" }) );
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("no_get", 1);
		set("no_give", 1);
		set("long", "�˽����ĳߣ������������������������޷����У�
ȴɱ��ɭȻ��ʵ���Ϲŵ�һ�����\n");
		set("value", 2000);
		set("material", "blacksteel");
		set("wield_msg", HIY"$N৵�һ���ӱ���������ɽ��������������ˣ�ɱ����ã��
��Բ֮�ں�Ȼ������������ɱ��֡�\n"NOR);             
                set("unwield_msg", BLU "$N���ɽ���ؽ��ң�ɱ���ټ����Ϲ�Ҳ������ʧ��\n" NOR);
		set("wield_skill",([
			"sword" : 100,
		]));
		set("wield_ability",([
			"combat_exp" : 50000,
		]));
	}
        init_sword(920);
        setup();
}
