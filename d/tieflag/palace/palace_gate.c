 inherit ROOM;
void create()
{
        set("short", "�ճ�԰");
        set("long", @LONG
���ţ�ֻ��������䣬����Ͳ�����������������������
ϸ�������������Ϳ�Σ�һɫˮĥȺǽ����ʯ̨�ף������
��������������ѩ�׷�ǽ�����滢Ƥʯ��������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"palace_front",
  "westdown" : __DIR__"palace_path4",
]));
        set("outdoors", "palace"); 
        set("coor/x",140);
        set("coor/y",0);
        set("coor/z",30);
        set("coor/x",140);
        set("coor/y",0);
        set("coor/z",30);
        set("coor/x",140);
        set("coor/y",0);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}        
