 // searoad.c
inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
·���ϵ�ɳʯԽ��Խϸ��������������һ����ζ��Խ��ǰ�ߣ���ζԽ���ԡ�Զ��
�������������İ���������ż���߹�ȥһ��������ˮ�Ƶ�����򣬼��Ͽ�����ߣ�ˬ
�ʵش���̸Ц��
LONG
        );
        set("objects",([
                __DIR__"npc/fishman" : 1,
        ]) );
        set("exits", ([ 
          "east" : __DIR__"searoad1",
          "west" : __DIR__"plain",
        ]));
        set("outdoors", "tieflag");
        set("coor/x",990);
        set("coor/y",-290);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}  
