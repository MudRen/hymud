 inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIG"���ĺ���Ҷ"NOR,({ "haitang" }) );
  if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",1000);
                set("unit","Ƭ");
                set("long", HIG
"˵�������ֻ֪�׶��졢��ȸ����ī��֭������ࡢ�ʺ����
�̲��ѡ������ѡ���ľ�����ѿ�ȵȣ���ʵ�����ȴ�������ĺ��ġ�
�ⶾ����ɫ�޳�����Ӱ���١����������������������ţ��������
�ˡ��������������壩\n"NOR);
                }
} 
void init()
{
  if(this_player()==environment())
        add_action("do_cure","die");
} 
int do_cure()
{
        object me,room, death_room,corpse;
        me = this_player();
        message_vision("$N�����ĺ���Ҷһ��������ȥ��\n",me);
        room = environment(me);
        if(objectp(corpse = CHAR_D->make_corpse(me, me)))
                corpse->move(room);
        death_room = find_object("/d/eren/chunliuju1");
        if(!objectp(death_room))
                death_room = load_object("/d/eren/chunliuju1");
        if (me->query("combat_exp")>2000)
                me->add("combat_exp",-2000);
                else me->set("combat_exp",0);
        tell_object(me,"������Լ��ļ��⽩Ӳ������Ҳ����ʹ���ˡ�\n");
        message_vision("$N���ˡ�\n",me);
        me -> unconcious(); 
        me->move(death_room);
   destruct(this_object());     
        return 1;
}   
