// Room: /d/canyon/canyon6.c
//#include <roadbusy.h>

inherit ROOM;

void create()
{
	set("coor",({-300,4150,0}));
	set("short", "���Źعȵ�");
	set("long",
"���ʵ������������Ź����࣬�м��ǲ��������Ĺȵأ����������ѹ��ĺõط�����ô������\n"
"������Ĺ�ϵһֱ�ǳ����ͣ���˴��������´򿪡����ŵĺ����и��ܴ�Ļ�еװ��(machi\n"
"ne)��������ͨ�����ǵ�·�������ͳ������Źء�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"canyon7",
  "north" : __DIR__"canyon5",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "mechine" : "���Ǹ��ܴ�Ľ��̣������ǿ��������õġ�\n",
]));

        set("outdoors","yanmen");
	setup();
//        replace_program(ROOM);
}