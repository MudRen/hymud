#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIW"����Կ��"NOR, ({ "key" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "jade");
        set("long", "һ�Ѿ��µİ���СԿ�ף���֪�������ڣ�Use key���������ϣ���\n");
        }
    
} 
void init()
{
        add_action("do_open", "use");
} 
int do_open(string arg)
{
        object obj, room, room1;
        object *team;
        int i;
        if (arg == "key" || arg == "����Կ��" || arg = "Կ��") {
        if (environment(this_object())!=this_player() || !arg)
                return 0;
        if (!objectp(obj=present("jade door",environment(this_player()))))
                return notify_fail("��������򲻿�ʲô�š�\n");
        message_vision(YEL"$N��Կ�ײ嵽������һת��֨ѽһ��������С�Ŵ��ˣ�ʯ����¶
��һ��ͨ��������Կ��ȴ�۶��������\n"NOR, this_player());
        room1 = find_object("/d/eren/eren2/jailroad5");
        if(!objectp(room1)) 
                room1 = load_object("/d/eren/eren2/jailroad5");   
        room1->set("exits/north","/d/eren/eren2/mouseroom1");
        destruct(this_object());
        }
        return 1;
}    
