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
                "north" : "/d/xizang/citygate",
                "south" : __DIR__"lroad2",
        ]));
        set("coor/x",-1190);
        set("coor/y",-20);
        set("coor/z",-10);
        setup();
replace_program(ROOM); 
}   
