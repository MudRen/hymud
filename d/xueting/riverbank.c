// Room: /d/xueting/riverbank.c
inherit ROOM;
void create()
{
        set("short", "�ӱ߿յ�");
        set("long", @LONG
�����Ǻӱߵ�һ���յأ��ļ��ĺ�������ı��������ϱ���ȥ��
������ĺӰ�����һ�ɶ�Զ�ĵط����Կ���һ��ˮ�����ϱ�����һ
���ƾɵĴ�լԺ��ǽ����һ����ȱ�������������ͨ����
LONG
        );
        
        set("outdoors", "xueting");
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"ruin2",
]));
        set("objects", ([

                __DIR__"npc/girl" : 1 ])
         );
        setup();
        
        replace_program(ROOM);
}
