#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�����", ({ "jingshuhe"}) );
        set_weight(300);
        set_max_encumbrance(80000);
        set("unit", "��");
        set("long", "һ�����Ϻú�ľ����ľ�У��պÿ��Էž��顣\n");
        set("closed", 1);
        set("value", 3000);
} 
int is_container() {return 1;} 
void init()
{
        if(this_player()==environment())
                 add_action("do_open","open");
}
int do_open(string arg)
{
        object          me, ob;
        if( !arg || arg != query("id") )
                return notify_fail("��Ҫ��ʲô��\n");
        me = this_player();
        ob = this_object();
        message_vision("$N����֨��һ������$n���ˡ�����\n", me, ob);
                ob->set("closed",0);
        return 1;
} 
int is_closed()
{
        return ((int) this_object()->query("closed"));
}