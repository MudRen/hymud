
// Room: /u/cloud/shijie1.c

inherit ROOM;

void create()
{
        set("coor",({4050,-1100,0}));
	set("short", "��ʯ��·");
        set("long",
"��������һ����ʯ���̳ɵ���С����,��������ƽ�����ɽ���ֻ�ܿ������ϵ�ʯ��,һ\n"
"��һ�����ߴ���ȥ,��Զ����ȥ.....ǰ���·����,��������������Ϣ��.\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shijie2",
  "southwest" : __DIR__"nroad4",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

