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
           "south" : __DIR__"yttl",
     ]));
 	set("objects", ([
		"/kungfu/class/shaolin/chengkun" : 1,
	]));
     setup();
}
                                                                                                                                                                                                                                                                                                                                                                                              