// Room: /d/zuojiacun/lu10.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㣬
�����粻���ӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu8",
  "east" : __DIR__"lu11",
  "south" : __DIR__"hu",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
