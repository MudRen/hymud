// hezhong.c
// by dicky

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "�ӵ�ʯ��");
    set("long", @LONG
����������ͨ��ˮ���е�һ��б���ϵ�ͨ���������ӵ׵�һ��ʯ
���Աߣ�ʯ������һ���������ڳ�����ˮ�ݣ�ͻȻ��о���������һ��
Ī���������������㲻�Ծ���ˮ�����ƻ�ȥ����һҧ����æ���ڹ��ֿ�
�������ֹͣ���ˡ�
LONG
        );

	set("outdoors", "houjizhen");

	set("exits", ([
		"enter" :  __DIR__"hedong",
	]));

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
       	if ( !arg || arg != "up" )
       		return notify_fail("��Ҫ������Ǳ��\n");
       	if (arg =="up")
 	{
     	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
	  return notify_fail("�����ӳ��أ��þ�ȫ��Ҳ�޷�Ǳ������!\n");
         message_vision(YEL"$N�ֽ��뻮��˳��ˮ�������渡ȥ��\n"NOR, me);
         me->move(__DIR__"hezhong1");
         tell_room(environment(me), me->name() + "�����沨��һ��Ǳ��������\n", ({ me }));
         message_vision (HIC"$Nֻ���������ѹ�������˲��٣�$N����һ������\n"NOR,me);
         return 1;
	 } 
	return 1;
}
