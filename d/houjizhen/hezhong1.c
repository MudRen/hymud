// hezhong.c
// by dicky

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "����ͨ��");
    set("long", @LONG
����������Ǳ����ˮ���е�һ��б���ϵ�ͨ��֮�С�����������
�䣬��ˮ����̹ǣ�������ˮ�ݴ�������Χ������֪���İ��㻺���ζ�
�����������ˮ��ȴ����������������
LONG
        );
    set("outdoors", "houjizhen");
    setup();
}

void init()
{
       object me;
       me=this_player();
       add_action("do_qian","qian");
       if ((int)me->query("qi", 1) < 0||(int)me->query("jing", 1) < 0){
 	me->set_temp("last_damage_from","��ˮ̶�б���");
       	me->unconcious();
       	me->die();
       	return ;
       }       
}

int do_qian(string arg)
{
	object me;
       	me=this_player();
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
       	if ( !arg || (arg != "down" && arg != "up") )
       		return notify_fail("��Ҫ������Ǳ��\n");
       if (arg =="down"){
    	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() <= 50) 
	   return notify_fail("�����������������޷�������Ǳ!\n");
          message_vision(HIG"$Nһ�����ԣ�Ǳ����ȥ��\n"NOR, me);
          me->receive_damage("jing", 50);
	  me->receive_damage("qi", 100);
          me->move(__DIR__"hedi");
          me->start_busy(1);
          tell_room(environment(me), me->name() + "������Ǳ��������\n", ({ me }));
          message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);
          return 1; 
       	  }
       	else {
     	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
	  return notify_fail("�����ӳ��أ��þ�ȫ��Ҳ�޷�Ǳ������!\n");
         message_vision(YEL"$N�ֽ��뻮��˳��ˮ�������渡ȥ��\n"NOR, me);
         me->move(__DIR__"hezhong");
         tell_room(environment(me), me->name() + "�����沨��һ��Ǳ��������\n", ({ me }));
 	message_vision (HIC"$Nֻ���������ѹ�������˲��٣�$N����һ������\n"NOR,me);
         return 1;
	 } 
     return 1;
}
