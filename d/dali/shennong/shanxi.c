// ɽϪ /d/menpai/shennong/shan_xi.c
// By lala, 1998-01-26

inherit ROOM;



void create()
{   
    set("short",    "ɽϪ");
    set("long",@LONG
һ������������СϪ��ɽ���������£�ת��һ��ɽͷ��Ȼ�󲻼��ˡ�Ϫˮ��
�峺������һ�������ס�ż�����м�����֪������������ȥ��������ȥ׽ʱ����
��һת���ֲ����ˡ���ɽ��������һ��С·��ɽ�ϵĴ����������м�������ð����
��֪������ô�Źֵ����ڡ�
LONG    );
    set("exits",    ([  /*sizeof()==1*/
        "eastup" :   __DIR__"wuqian",
    ]) );
    set("outdoors", "wuliang");
    set("resource/water",   1);
    set("fillplace",   "ɽϪ");
    setup();
}

void init()
{   
    add_action("do_climb",  "climb");
}

int do_climb( string arg )
{
    object ppl = this_player();

    if( !arg ) 
        return notify_fail("��Ҫ��ʲô��������\n");
    if( arg != "down" )
        return notify_fail("��������޴����֣�û������\n");
    message_vision("$N�ֽŲ��ã�������ȥ��\n", ppl);
    ppl->move( __DIR__"dongfeng_di" );
    return 1;
}
