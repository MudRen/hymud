 // searoad.c
inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
·���ϵ�ɳʯԽ��Խϸ��������������һ����ζ��Խ��ǰ�ߣ���ζԽ���ԡ�Զ��
�������������İ���������ż���߹�ȥһ��������ˮ�Ƶ�����򣬼��Ͽ�����ߣ�ˬ
�ʵش���̸Ц��·����һƬ�Ĺ�ľ�ԣ���ľ����ȴ���ܣ�������ؿ����屳����û��
·��
LONG
        );
        set("exits", ([ 
                  "west" : __DIR__"searoad",
                  "east" : __DIR__"bat/lin1",
                  "south" : __DIR__"seaside",
                  "north":  __DIR__"seaside1",
                ]));         
                set("objects",([
                __DIR__"npc/fishman" : 1,
        ]) );
        set("outdoors", "tieflag");
        set("coor/x",1000);
        set("coor/y",-290);
        set("coor/z",-10);
        setup();
}      
