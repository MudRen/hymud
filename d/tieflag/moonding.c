 // searoad.c
inherit ROOM;
void create()
{
        set("short", "���¶�");
        set("long", @LONG
������ժ�Ƿ���¶�������һ����ʯƽ̨������Χ���������ˣ���������ɽ����
����ֱ�䣬����ƽ̨ӳ�ø��ǻԻͲ��á�����������ŮΧ���������ԣ�������һ����
��ɫ����ϯ������΢����⣬Ҳ��֪��ʲô֯�ɡ�һ�����¸���б����ϯ�ϣ�Զ����
���󣭣���Ŀ��ȥ�������������ƣ�����������ӳ�һƬ��̡�
LONG
        );
        set("objects",([
                __DIR__"npc/qinggirl2" : 1,
                __DIR__"npc/qinggirl3" : 2,
                __DIR__"npc/master2"  : 1,
        ]) );
        set("exits", ([ 
                "westdown" : __DIR__"uproad4",
        
                ]));
                set("valid_startroom",1);
        set("outdoors", "tieflag");
        set("coor/x",2100);
        set("coor/y",-200);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}  
