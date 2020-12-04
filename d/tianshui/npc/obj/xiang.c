// xiang.c
inherit ITEM;

void init();
int do_dian(string arg);
void create()
{
        set_name("����", ({ "xiang" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������õĸ���,����Ե�ȼ��(dian)��\n");
                set("value", 100);
                set("material", "wood");
        }
	set("fire",0);
        setup();
}

void init()
{
        add_action("do_dian", "dian");
}

int do_dian(string arg)
{
	object me;
	me = this_player();
	if(!arg||arg!="xiang")
                return notify_fail("��Ҫ��ȼʲô������\n");
	if(query("fire"))
		return notify_fail("�����еĸ����Ѿ���ȼ�ˡ�\n");
	message_vision("$N��ȼ�����еĸ��㡣\n",me);
	set("fire",1);
	call_out("fire",60);
	return 1;
}

void fire()
{
        message_vision("$N�����ˡ�\n",this_object());
        destruct(this_object());
}