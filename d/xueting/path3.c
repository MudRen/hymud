// Room: /d/path2/shanlu1.c

inherit ROOM;

void create()
{
        set("short", "�ƾɹٵ�");
        set("long", @LONG
����һ�����ʧ�޵Ĺٵ���·�����Գ����˹�ľ�ԣ�·��һ��
����������ǳǳд�������ǰ�ķ������ԴӺڷ�ɽ�������ۣ̾�ѩ
����ս��������ٵ�������һ��ɽ�ꡣ
LONG
        );
        
        set("objects",([
        	__DIR__"npc/traveller" :2,        
        ]));
        
        set("exits", ([ /* sizeof() == 1 */
//        "eastup" : "/d/heifeng/lu1",
        "west" : __DIR__"path2",
        "east": __DIR__"shanao.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
