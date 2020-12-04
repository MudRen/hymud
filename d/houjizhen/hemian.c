// tanmian.c
// by dicky

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", "��������");
    set("long", @LONG
��˫�ֻ�ˮ��Ư����һƬˮ�����档��ֻ����ˮ����̹ǣ���Ͻ��˹��ֿ���
����΢�о��������
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
       add_action("do_pa", "pa");
       if ((int)me->query("jingli", 1) < 0||(int)me->query("qi", 1) < 0){
	me->set_temp("last_damage_from","�ں����б���");
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
       	if ( !arg || arg != "down"  )
       		return notify_fail("��Ҫ������Ǳ��\n");
       if (arg =="down"){
  	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() <= 50) 
           return notify_fail("�����������������޷�������Ǳ!\n");
          message_vision(HIG"$Nһ�����ԣ�Ǳ����ȥ��\n"NOR, me);
          me->receive_damage("qi", 100);
          me->receive_damage("jing", 50);
          me->move(__DIR__"hezhong");
          tell_room(environment(me), me->name() + "������Ǳ��������\n", ({ me }));
          message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);
          return 1;
       	  }
     return 1;
}
 
int do_pa(string arg)
{
	object me;
       	me=this_player();
       	if ( !arg || arg != "up")
       		return notify_fail("��Ҫ����������\n");
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
        message_vision(YEL"$N����������������ȥ��\n"NOR, me);
	me->move(__DIR__"hean1");
	tell_room(environment(me), me->name() + "�Ӻ������������Ƶ�����������\n", ({ me }));
	return 1;
}
