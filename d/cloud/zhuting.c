
// Room: /u/cloud/zhuting.c

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long",
"����һ����ͤ,��Ȼ�Ѿ����˺ܾ���,�Ե���Щ�ƾɡ�Ϊ��ȥ�������ͽ���ο͵ķ��㣬����\n"
"���˾轨�����ͤ�ӣ���·��ЪЪ�š�ͤ��������������Ϣ�أ����м���С���ӡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shijie3",
]));
	set("objects", ([
                __DIR__"npc/tea_vendor": 1,
	]) );
        set("outdoors", "cloud");

	setup();
	replace_program(ROOM);
}
