// Room: /d/snow/stree01.c
// edit by pian
inherit ROOM;
void create()
{
        set("short", "ѩͤ�ֵ�");
        set("long", @LONG
������ѩͤ�򱱳ǵ���Ҫ�ֵ���������Զ������һ���㳡����
������ɽ���ˣ��ɼ�һ�����ѵ�ɽ·��������â�ݵ�ɽ��ͨ��ɽ��
��������һ��С·ͨ��Ϫ�ߣ���������һ����վ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"shanao",
	"south" : __DIR__"street02",
	//"west" : "/u/quicksand/huangyie0",
//	"west" : __DIR__"postoffice",
	"east":__DIR__"npath1",
]));
      /*  set("objects", ([
                //"/d/daomeng/npc/daowang1" : 1,
                // __DIR__"npc/worker" : 1,
        ]) );
         */
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
