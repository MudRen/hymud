// caoyuan.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ��Ե");
        set("long", @LONG
�����Ǵ��ԭ��ɳĮ����֮�أ������ϡ���ܣ��������������ȥ��
�����м�������̤������ӡ�����������ﳣ�����̶����������Ϸ�������
Щ���̡�
LONG);
        set("exits", ([
           "southwest" : __DIR__"caoyuan1",
            "northwest" : __DIR__"caoyuan2",
            "northup" : __DIR__"caoyuan3",
            "north" : __DIR__"dadao2",
            "south" : __DIR__"caoyuan1",
            "east":__DIR__"ximen",
        ]));
        

        
        set("outdoors", "dingxiang");
        setup();
}

