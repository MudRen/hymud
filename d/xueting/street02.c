// Room: /d/snow/stree02.c
// edit by pian
inherit ROOM;
void create()
{
        set("short", "ѩͤ�ֵ�");
        set("long", @LONG
������ѩͤ�򱱳ǵ���Ҫ�ֵ�������ͨ�����������ֵĹ㳡��
������ͨ���򱱵�ɽ·��������һ����ʯ�̵꣬��������һ�ҵ��̣�
��һ�����˸ϼ������ӣ���������̫�����߶���
LONG
        );
        
        set("objects",([
        	__DIR__"npc/traveller" :2,        
        ]));
        
        set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"street01",
//	"west" : __DIR__"daguchang",
	"south" : __DIR__"guangchang_n",
	"east":__DIR__"hockshop",
	]));
/*     set("objects", ([
         //"/d/daomeng/npc/daowang1" : 1,
                // __DIR__"npc/worker" : 1,
        ]) );
         */
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
