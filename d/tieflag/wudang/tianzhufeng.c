 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���˽��󣬾�������������߷�--�����塣������������ɾ�
֮�С�ɽ��������·�Ҫ�˷��ȥһ�㡣�����������ƣ�����½����
�����ڷ����棬ǧ�����������Ⱥɽ�����ǧ����ƺ���û��������
�⡢����仯���������η��ڣ��������˱�ӿ��������ǧ���������ǡ�
LONG
        );
        set("exits", ([
        "eastdown" : __DIR__"feishengya",
        "westdown" : __DIR__"yinxuanyan",
                "northdown" : __DIR__"jindian",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",110);
        set("coor/y",-180);
    set("coor/z",100);
        set("objects", ([
        __DIR__"npc/tianfeng14": 1,
        ]) );
        setup();
        
        
        
}       
