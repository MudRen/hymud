// Room: /d/jinghai/wm7.c

inherit ROOM;

void create()
{
	set("short", "�ϼ�¥");
	set("long", @LONG
��������¥����λ�������׵ļ��������ػص��߶��ţ���ʱ
��ͨ�����������¾���Ĺ۲����������ˡ�������Ȼ��̫ƽ����
������ƽʱ�����ر�ɭ�ϡ������ߵ�����ĵ�һ���о���Ҳ���
ֻ�С�ɱ�����ڡ����ĸ��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wm5",
]));
        set("objects",([
        __DIR__"npc/yong5" : 1,
]));


        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
