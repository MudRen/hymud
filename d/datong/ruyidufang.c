// Room: /open/dt/ruyidufang.c
inherit ROOM;
void create()
{
	set("short", "����ķ�");
	set("long", @LONG
����ķ��Ƿ�Բ���������Ķĳ��������кܶ������ҲĽ
���������ĳ���ʮ����ʱ�������˶�Ǯ���Ӳ�Ъҵ��������ͷӿ
�����з������ʮ����Ů������װ���񴩻�����һ���ڳ�����
Ȼ��ȥ����ʱ��ֶ�ͽ���������ۣ��㲻��Ҳ������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"youfujie2",
]));



        set("objects",([
        __DIR__"npc/judge" : 1,
]));


	setup();
}
