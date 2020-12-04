// sword_and_qiao.c

#include <ansi.h>
#include <weapon.h>


inherit HAMMER;
// inherit ITEM;

int no_save_in_home() { return 1; }

void create()
{
        set_name("���ʵı���", ({ "qsword" }) );
        set_weight(10000);
	set("valid_number",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѵ��ʵı�����������Ƕ�ű�ʯ��
���Ľ����Ͽ������������С�֣���
ϸ�����������ġ�\n");
                set("value", 2000);
		set("material", "blacksteel");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(35);
        setup();
}

void init()
{
	add_action("do_ba","ba");
}

int do_ba(string arg,object who)
{
	object sword,qiao;

	if(!arg || !id(arg) )
		return notify_fail("��Ҫ��ʲô��\n");

	if( !who || who->query("id") != "youfang lama" )
		return notify_fail("���þ�ȫ�������͵�һ�Σ������ڽ�����ȴ��˿û����\n");

	sword = new(__DIR__"jinghong_sword");
	sword->move(who);
	qiao = new(__DIR__"qiao");
	qiao->move(who);

	message_vision("$N˫��һ������ֻ������ॡ�һ���ѽ����˳�����\n",who);
	call_out("dest",1);
	return 1;
}

private void dest()
{
	destruct(this_object());
}
