// ����´ /d/menpai/shennong/dongfeng_di.c

inherit ROOM;



void create()
{
    set("short",    "����´");
    set("long",@LONG
����������ɽ�Ķ�´��С·�ƺ��Ѿ��ߵ��˾�ͷ�������������һ��ͦ�ε�
ɽ�壬��˵�Ǿ�������ɽ�ˡ�����Ҳ��һ��ɽ������ԶԶû�����������ߡ�����
��ʱ�Ĵ���Ȫˮ������������������ϸ�����ܿ�������ɽ�����м�������Ʈ����
ɽ���ƺ������̡���������ȥ��һ�¡�
LONG    );
    set("exits",    ([  /*sizeof()==1*/
        "southwest" :   __DIR__"xiaodao3"  
    ]) );
    set("outdoors", "wuliang");
    setup();
}

void init()
{
    add_action("do_climb",  "climb");
}

int do_climb( string arg )
{   
    object ppl=this_player();

    if( !arg )
        return notify_fail("��Ҫ��ʲô��������\n");
    if( arg != "up" )
        return notify_fail("��������޴����֣�û������\n");
    message_vision("$N�ֽŲ��ã�������ȥ��\n",ppl);
    ppl->move( __DIR__"shanxi" );
    return 1;
}
