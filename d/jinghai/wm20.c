// Room: /d/jinghai/wm20.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����ĳ�����������ϸϸ�Ļ����������ʺ����䡣���ӵ���
Χ������һ��һ�ŵı����ܣ����澡�Ǹ�ʽ��������ű�������
���ɵ����˵����Ǿ����������д����գ������ĵá��ϱ���һ��
С·����Զ������֪ͨ��δ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wm8",
]));
        set("objects",([
        __DIR__"npc/yong7" : 3,
]));


        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
