inherit ROOM;

#include <ansi.h>
void create()
{
  set("short",HIR"����ǰ��"NOR);
  set("long",@LONG
������������۴�����ȥ����������ѩɽ����Ө��͸����
��ƺƣ��������ơ�������Ұǧ����������������ɽΡΡ��
��������������߳�����ְ˰���������ܶ��ǰ�

LONG);

     set("outdoors", "xiaoyao");
     set("exits",([
           "north" : __DIR__"dadian",
     ]));
 	set("objects", ([
		"/kungfu/class/mingjiao/sd1" : 1,
		"/kungfu/class/mingjiao/sd2" : 1,
		"/kungfu/class/mingjiao/sd3" : 1,
		"/kungfu/class/mingjiao/sd4" : 1,
		"/kungfu/class/mingjiao/sd5" : 1,
		"/kungfu/class/mingjiao/sd6" : 1,
	]));
     setup();
}
int valid_leave(object me, string dir)
{
object fang;
object who;
int i;
who=me;



	if ( objectp(present("kong zhi", environment(me))) )
		return notify_fail("�����ɵ�����ס�����ȥ·,���һ��Ҫ����ħ�̡�\n");

	if ( objectp(present("miejue shitai", environment(me))) )
		return notify_fail("��ü�ɵ�����ס�����ȥ·,���һ��Ҫ����ħ�̡�\n");

	if ( objectp(present("song yuanqiao", environment(me))) )
		return notify_fail("�䵱�ɵ�����ס�����ȥ·,���һ��Ҫ����ħ�̡�\n");

	if ( objectp(present("he taichong", environment(me))) )
		return notify_fail("�����ɵ�����ס�����ȥ·,���һ��Ҫ����ħ�̡�\n");

	if ( objectp(present("tang wenliang", environment(me))) )
		return notify_fail("����ɵ�����ס�����ȥ·,���һ��Ҫ����ħ�̡�\n");

	if ( objectp(present("xian yutong", environment(me))) )
		return notify_fail("��ɽ�ɵ�����ס�����ȥ·,���һ��Ҫ����ħ�̡�\n");


  if((int)who->query("jinyong/book12")==3)
{
		i = 1250+random(2000);
		who->set("jinyong/book12",4);
		who->add("combat_exp",i+14000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+14000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}

        return ::valid_leave(me, dir);
}

                                                                                                                                                                                                                                                                                                                                                                                                    