 inherit ROOM;
void create()
{
        set("short", "�����ƺ�ǽ");
        set("long", @LONG
������ǽ��ɽ���������ת���ۡ��ߴ���أ�ʹ�����߽�ɽ����
�ϸе�һ���������Ϻ�����ңԶ����˵������ʱ�ڴ˶��飬Ԣ������
���������ۼ�����
LONG
        );
        set("exits", ([
                "north" : __DIR__"qiongtaiguan",
                "southup" : __DIR__"sansongting",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",110);
        set("coor/y",-160);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}      
