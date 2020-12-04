// Room: /d/linzhi/lin31.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���·��");
	set("long", @LONG
�����Ǹ�ԭ���·�������������ֻ����ڱ�һ��С·��
�����ӡ���С�ĵ��ƹ�һ������ڣ������ע���ſ��ܷ�����һ
�С�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin30",
  "west" : __DIR__"lin32",
  "southeast" : __DIR__"lin22",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
