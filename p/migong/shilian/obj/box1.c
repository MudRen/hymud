#include <ansi.h>
inherit ITEM; 

void create()
{
	object good;
        set_name(HIC"����"NOR, ({"baoxiang"}) );
        set_weight(300);
        set("no_get", 1);
 
        set_max_encumbrance(80000000);
        set("unit", "��");
        set("long", "һ��ɢ�������ع�â�ı��䡣\n");
        set("closed", 1);
        set("value", 2000);
 
        good = new("/clone/money/gold");
        good->set_amount(5+random(5));
        good->move(this_object());
        setup();
} 

int is_container() { return 1; }

void init()
{
        add_action("do_open","open");

}

int is_closed()
{
        return ((int) this_object()->query("closed"));
} 

int do_open(string arg)
{
        object me, ob;
        me = this_player();
        if(!arg)
    		return 0;
        ob = present(arg,environment(this_object()));
        if (ob!=this_object())
 	        return 0;
 				
        if (!is_closed())
        {
                return notify_fail("�����Ѿ����ˡ� \n");
        }
        message_vision("$N������򿪡� \n", me);
        this_object()->set("closed",0);
        //me->move(environment(this_object()));
        return 1;
} 
