
// Room: /u/cloud/nroad4.c

inherit ROOM;

void create()
{
        set("coor",({4000,-1150,0}));
	set("short", "ɽ·");
        set("long",
"������������һ��ɽ���С·��,С·�����������де���ľ�Ͳݴ�(grass)��ż�����м���\n"
"Ұ�������ּ䴫�������������\n"
);
        set("item_desc", ([/*sizeof() == 1 */
             "grass" : "��ֻ��һ����ͨ�Ĳݶ��ѣ���ʲô�ÿ�����?\n",
            ]));
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shijie1",
  "south" : __DIR__"nroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

