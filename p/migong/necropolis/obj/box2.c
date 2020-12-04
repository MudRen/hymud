#include <ansi.h>
inherit ITEM; 

void create()
{
	object good,dropper;
        set_name(HIR"����"NOR, ({"box"}) );
        set_weight(300);
        set("no_get", 1);
        set_max_encumbrance(80000000);
        set("unit", "��");
        set("long", "һ��ɢ�������ع�â�ı��䡣\n");
        set("closed", 1);
        set("value", 2000);

        //gold
        good = new("/clone/money/gold");
        good->set_amount(20+random(20));
        good->move(this_object());
        //item
        if (!random(3)) {
                for (int i = 0; i < 3; i++) 
                {
    		        good = new("/p/newweapon/weaponobj/material1" + random(2));
    		        good->move(this_object());
                }  	
  	}
        setup();
} 

int is_container() {return 1;} 
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
