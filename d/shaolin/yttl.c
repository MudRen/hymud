inherit ROOM;

#include <ansi.h>
void create()
{
  set("short",HIR"��շ�ħȦ��"NOR);
  set("long",@LONG
���ô������������ϸ����˸�������һ�˵Ĵ󶴣��и�����
¶����ɫɮ��һ�ǣ��ƺ�ס�����ˡ�������һƬ���ƺ�����Ĵ�
��ͺͺ�ģ��ƺ������ܴ����������´�ݲ�����
LONG );

     set("outdoors", "shaolin");
     set("exits",([
           "north" : __DIR__"yttl2",
           "out" : __DIR__"fumoquan",
     ]));
 	set("objects", ([
		"/kungfu/class/shaolin/du-e2" : 1,
"/kungfu/class/shaolin/du-jie2" : 1,
"/kungfu/class/shaolin/du-nan2" : 1,
	]));
     setup();
}
int valid_leave(object me, string dir)
{
object fang;
object who;
int i;
who=me;



	if ( objectp(present("du e", environment(me))) )
		return notify_fail("�����ɵ�����ס�����ȥ·,�Ⱥ��ұ��԰ɡ�\n");

	if ( objectp(present("du jie", environment(me))) )
		return notify_fail("�����ɵ�����ס�����ȥ·,�Ⱥ��ұ��԰ɡ�\n");
	if ( objectp(present("du nan", environment(me))) )
		return notify_fail("�����ɵ�����ס�����ȥ·,�Ⱥ��ұ��԰ɡ�\n");


        return ::valid_leave(me, dir);
}

                                                                                                                                                                                                                                                                                                                                                                                                    