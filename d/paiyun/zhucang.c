// Room: /d/paiyun/zhucang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������߰���ѷ���ľͷ��������֮��Ķ�������
������һ�䴢���ҡ�
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu10",
]));
set("objects", ([
	"/clone/weapon/changjian":1,
        "/clone/weapon/gangdao":1,
       "/clone/weapon/tiejia":1,
       ]) );
	setup();
	replace_program(ROOM);
}
