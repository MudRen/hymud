 inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
��ˮ�峺͸������ʱ���Կ�����β������ˮ�档��ˮ��ͷ
��һ�����ٲ�����������������ٲ���ɽ��ֱ����£�������
�������������һ���ʯ����д�����������
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"grassland1",
                "north" : __DIR__"lake2",
                ]));
         set("objects", ([ 
                __DIR__"npc/watcher_taoist" : 1,
                __DIR__"npc/feng" : 1,
                ]));
 
        set("resource/water",1);
        set("liquid", (["container":"��"]));
        set("outdoors", "taoguan");
        set("coor/x",-10);
        set("coor/y",2070);
        set("coor/z",80);
        setup();
}       
