 inherit ROOM;
void create()
{
        set("short", "佻˳���");
        set("long", @LONG
�����Ǹ��������С���Ǹ�����ԡ�ģ����������ʮɫ�Ĳʴ�����ζ�˱ǵĻ�
�꣬������������ض��ǣ�͸������ˮ�����Կ���������������޳��Ĵ��ȣ���
ͦ�����ţ����ںڵĳ���������������
LONG
        );
        set("exits", ([
                "south" : __DIR__"hfenglang1",
                "east" : __DIR__"hfenglang3",
        ]));
        set("no_magic",1);
        set("coor/x",21);
        set("coor/y",40);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}
