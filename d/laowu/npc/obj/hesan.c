#include <ansi.h>
inherit ITEM; 
void create()
{
set_name(HIB"���ɢ"NOR, ({ "lihunsan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�������������ӵĶ�����ҩ�������ã������磩���Լ����ϡ�\n");
        }
        
}
void init()
{
        add_action("do_yong","yong");
} 
int do_yong(string arg)
{
        object ob,room;
        object me,corpse;
        me=this_player();
        if(me->is_busy()) return notify_fail("����æ���ء�\n");
        if (!arg) return notify_fail("��Ҫ����˭���ϣ�\n");
        if ( me->query("combat_exp") < 1500000 )
                return notify_fail("�㾭��̫���ˣ�����"+this_object()->name()+"�����������˺��Լ��ġ�\n");
        ob=present(arg,environment(me));
        if (ob!=me) 
                return notify_fail("�鵤��ҩ�����˷��ڱ�������?\n");
        if( environment(me)->query("no_fight") ||
                environment(me)->query("no_magic") ||
                        environment(me)->query("no_spells") )
                return notify_fail("�����ﲻ�������������\n");
        message_vision("$NС�����������$n������ȥ��\n",me, this_object());
        message_vision(BLU "$Nֻ�����Ʈ�������ƻ������˿���γ����⡣\n"NOR,ob);
        message_vision("$N���ˡ�\n",me);
        room = environment(me);
        if(objectp(corpse = CHAR_D->make_corpse(me, me)))
                        corpse->move(room);
   me->move("/d/death/yanluo");
        me->be_ghost(1);
        tell_object(me,"���"+RED"�ڹ��ķ�"NOR+"�����ˡ�\n");
        tell_object(me,"���"+RED"�˻���֮��"NOR+"�����ˡ�\n");
        tell_object(me,"���"+RED"�����Ṧ"NOR+"�����ˡ�\n");
        me -> unconcious();  
        destruct(this_object());     
        return 1;
}   
