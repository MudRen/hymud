 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����Ӻ�Ժ");
        set("long", @LONG
��Ժ�����ǵ͵͵���ǽ��ǽ��������������������ż������裬������Ķ�
�黨������Ѥ�á�Ժ������һ��������ľ�˺�һ�������ܣ����Ϻ��Ҹ��ŵ�����һ
��ʮ�������Ů����������üĿ����¶�ŵ����İ��
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"dazuiju1",
        ]));
        set("objects", ([
                __DIR__"npc/pinggu": 1,
                __DIR__"npc/star_bunny": 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}   
