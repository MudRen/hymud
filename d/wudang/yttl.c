inherit ROOM;

#include <ansi.h>
void create()
{
  set("short",HIG"�䵱�㳡"NOR);
  set("long",@LONG
����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱����ѧϰ�书�ͻ����д�ĵص㡣
��Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ���ڴ�ɨ��
�ϱ�������������

LONG);

     set("outdoors", "xiaoyao");
     set("exits",([
           "south" : __DIR__"sanqingdian",
     ]));
 	set("objects", ([
		"/kungfu/class/mingjiao/sd1" : 1,
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
		return notify_fail("�����ɵ�����ס�����ȥ·,����˵��лѷ�����䣬��\n");

	if ( objectp(present("miejue shitai", environment(me))) )
		return notify_fail("��ü�ɵ�����ס�����ȥ·,����˵��лѷ�����䣬��\n");

	if ( objectp(present("he taichong", environment(me))) )
		return notify_fail("�����ɵ�����ס�����ȥ·,����˵��лѷ�����䣬��\n");

	if ( objectp(present("tang wenliang", environment(me))) )
		return notify_fail("����ɵ�����ס�����ȥ·,����˵��лѷ�����䣬��\n");

	if ( objectp(present("xian yutong", environment(me))) )
		return notify_fail("��ɽ�ɵ�����ס�����ȥ·,����˵��лѷ�����䣬��\n");


   if(who->query("jinyong/book12")==1)
{
		i = 950+random(2000);
		who->set("jinyong/book12",2);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+12000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}

        return ::valid_leave(me, dir);
}

                                                                                                                                                                                                                                                                                                                                                                                                    