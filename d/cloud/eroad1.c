
// Room: /u/cloud/eroad1.c

inherit ROOM;

void create()
{
        set("coor",({2150,3800,0}));
	set("short", "�����ֵ�");
        set("long",
"������ʮ��·�ڵĶ��࣬���߷����ﶼ��Ϊ���֡������ƺ��ǼҴ�¥����ʱ�������糾Ů��\n"
"����Ц��������ȴ��Щ���̾�����������ߺ�����壬���ǼҶĳ���\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cross",
  "north" : __DIR__"jiyuan",
//  "south" : __DIR__"duchang",
  "east" : __DIR__"eroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

