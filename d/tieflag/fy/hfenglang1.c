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
                "west" : __DIR__"hfeng",
                "north" : __DIR__"hfenglang2",
        ]));
        set("coor/x",21);
        set("coor/y",30);
        set("coor/z",0);
        setup();
}
int valid_leave(object me, string dir)
{
        if(  dir == "north" && me->query("gender") != "Ů��")
        return notify_fail("����Ů��ԡ�ң�����ȥ��ʲô��\n");
        return 1;
}     
