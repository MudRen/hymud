// tanmian.c

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"ˮ̶����"NOR);
    set("long", @LONG
��˫�ֻ�ˮ��Ư����һƬˮ�����档��ֻ������ҫ�ۣ�ˮ���ϻ����˱ǣ�
���Ǳ�����ء�
LONG
        );
   
    set("outdoors", "�����");

    setup();
}

void init()
{
       object me;
       me=this_player();
       add_action("do_qian","qian");
       add_action("do_pa", "pa");
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
          me->receive_damage("jing", 50);
          me->receive_damage("qi", 50);
          me->move(__DIR__"tongdao");
          tell_room(environment(me), me->name() + "������Ǳ��������\n", ({ me }));
          message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);
          return 1;
       	  }
     return 1;
}
 
int do_pa(string arg)
{
	object me;
	int i;
	object who;
       	me=this_player();
       	who=me;
       	if ( !arg || arg != "up")
       		return notify_fail("��Ҫ����������\n");
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
        message_vision(YEL"$N��ˮ̶����������ȥ��\n"NOR, me);

  	if((int)who->query("jinyong/book10")==6 && who->query_temp("book51071"))
{
tell_object (who,"�㷢���˾���ȵ׵����ܣ�\n");
		i = 1800+random(3000);
		who->set("jinyong/book10",7);
		who->add("combat_exp",i+18000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+18000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}

	me->move(__DIR__"tanan");
	tell_room(environment(me), me->name() + "��ˮ̶���������Ƶ�����������\n", ({ me }));
	return 1;
}
