 inherit ROOM;
void create()
{
        set("short", "��ʯ��·");
        set("long", @LONG
����һ���Ժ�ʯ�̳ɵĵ�·����·�����ش���һƬ���֣�����Խ���
��Խ��������������ȴ͸��һ����⣬���ڵ��ϵĺ�ʯ�ϣ��ĵ����¸���
�������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"intersection",
  "south" : __DIR__"black2",
]));
        set("outdoors", "palace"); 
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}   
