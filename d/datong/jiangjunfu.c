// Room: /open/dt/jiangjunfu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�������������ľ���Ž����ر��š����ྲ�����رܡ�
�����ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�
С����ԩ�õġ�������������ǰѲ�ߡ�

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jinyangjie5",
]));

        set("objects",([
       "/d/city/npc/bing" :2,
       "/d/city/npc/yayi" :2,	
       "/d/city/npc/wujiang" :1,		
]));
	setup();
	replace_program(ROOM);
}
