 inherit ROOM;
void create()
{
        set("short", "��ˮ���ֶ�");
        set("long", @LONG
��������ˮ�����طֶ�֮һ���������Ѿ����������ˡ�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"bottom2",
]));
        set("coor/x",200);
        set("coor/y",-30);
        set("coor/z",10);
        setup();
}       
