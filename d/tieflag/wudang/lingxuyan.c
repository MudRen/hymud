 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������������������ഫ�ƴ������������ڴˡ�������
���ڹ����о���������������˯��������˯������˵��һ˯�ɰ��첻
�ѡ��������ҹ�ǽ���ϻ��г���������������ŵġ����١����֡���
�ơ��Ը�˯�١���
     ����м����ֽ���Сͯ���ڲ������䵱�ġ������󡰣�����ͬ��
ͬ�ˣ����ؽ��ˡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"wudang1",
        ]));
        set("outdoors", "wudangfy");
                set("objects", ([
                __DIR__"npc/swordboy1" : 1,
                __DIR__"npc/swordboy2" : 1,
                __DIR__"npc/swordboy3" : 1,
                __DIR__"npc/swordboy4" : 1,
        ]));
        set("coor/x",90);
        set("coor/y",-140);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}       
