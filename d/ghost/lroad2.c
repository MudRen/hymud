 inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
����һ������������·��·���Ӳݴ�����·����Ţ����������ǰ��
�ͽ�����һƬԭʼɭ�֣���û���߳������
LONG
        );
        set("exits", ([
                "north" : __DIR__"lroad1",
                "south" : __DIR__"lroad3",
        ]));
        set("coor/x",-1190);
        set("coor/y",-30);
        set("coor/z",-10);
        setup();
 replace_program(ROOM); 
}  