// Room: /d/snow/shanao.c
// edit by pian
inherit ROOM;
void create()
{
        set("short", "ѩͤɽ��");
        set("long", @LONG
������һ��ɽ�꣬���Ͼ���ѩͤ��һ�����ѵ�С������ͨ��
��һ���ڽ���Сɽ�壬һ��ٸ����ĸ�ʾ������·�ԣ�����д����
�غڷ�ɽ���˳�û�ľ����־��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	//"north" : "/d/banghui/road1",
	"south" : __DIR__"street01",
	"west" : __DIR__"path3",
	"east" : __DIR__"path6",
]));
        set("objects", ([
                //"/d/daomeng/npc/daowang1" : 1,
            __DIR__"npc/luren" : 1,
        ]) );
        
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
