 inherit ROOM;
void create()
{
        set("short", "���˶�");
        set("long", @LONG
����ʯ����ֻ����ľ�״У��滨���ף�һ���������ӻ�ľ�
к��ʯ϶֮�¡�������֮��������Ϫк��ʯ���ƣ���ʯΪ����
�������ӣ�ʯ�����ۣ��������¡�
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"palace_front",
  "southdown" : "/d/tieflag/troad0",
]));
        set("objects", ([
               __DIR__"npc/master2" : 1,
       ]) );
        set("valid_startroom", 1);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",40);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",40);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}   
