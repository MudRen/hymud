 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�ߵ������������ɽ�����������������ƣ�������ˮ��������
�����������ơ�����ᡣ�ع������������쾡���������۽�ĺ�ƺ�
�ڣ������޷���
LONG
        );
        set("exits", ([
        "eastup" : __DIR__"tianzhufeng",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-180);
    set("coor/z",90);
        setup();
        replace_program(ROOM);
}       
