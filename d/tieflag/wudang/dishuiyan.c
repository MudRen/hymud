 inherit ROOM;
void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
ͥԺ�����Ũ����ǡ�ľҶ��в���ҡҷ��ȴ�ĵ���ؼ����
�ž����쳾�е����ַ��ţ����ѳ���δ��ͥԺ��
LONG
        );
        set("exits", ([
                "north" : __DIR__"wuroad1",
                "south" : __DIR__"qiongtaiguan",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",110);
        set("coor/y",-140);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}   
