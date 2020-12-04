//chayuan.c

inherit ROOM;



void create()
{
    set("short","̫�Ͳ�԰");
    set("long", @LONG
�����Ǵ��������Ĳ�԰������̫�Ͳ�԰�����ഫ��������ܿ����������е���
�ֲ軨�������Һ족�������ӿǡ�����ĵ���衱��������ߡ��ȵȣ�������ֵ���
��������ô������̺�Ĳ軨ȴ����û������ȥ��������˵�����԰��������һ����
�ֵ���ͷ���ᰮ�軨�����Բ軨����Ϊ�����˿��ģ�����Ϊ��׬Ǯ����԰�ԣ����ż�
ֻ�׶�Ĵ���Ȯ����˵����������Ѱ����������Ȯ��ר������ס��԰�������軨��
����͵�ġ�����Ȯ�����׶��Ѿ�ҧ���˲�����͵�軨���ˡ�
LONG
);
    set("exits", ([
		"west" : __DIR__"taihe_cun",
                    ]) );
    set("objects", ([
                __DIR__"npc/langquan" : 3,
                 ]) );
	set("outdoors", "xinan" );
    setup();
}

void init()
{
    add_action("do_tou","tou");
}

int do_tou( string arg )
{
    object me;
    me = this_player();
    if( !arg )
    return notify_fail("��Ҫ͵ʲô��\n");
    if( arg == "�軨" || arg == "chahua" )
    {
	if( query_temp("flowers") >= 4 )
        return notify_fail("����Ļ��Ѿ���͵���ˡ�\n");
        message_vision("$N������ŵ��ߵ���԰���ϣ�׼������.....\n", me);
        me->start_busy(3);
        call_out("get_chahua",3,me);
        return 1;
    }
    else return notify_fail("��Ҫ͵ʲô��\n");
}           

void get_chahua( object me )
{
    object dog, owner, flower;
    dog = present("lang quan", environment(me) );
    flower = new(__DIR__"obj/chahua");
    if( random( me->query("kar") + me->query("dex") ) > 30 || !dog )
    {
        flower->move(me);
	add_temp("flowers", 1);
        message_vision("$N���ĵ�����һ��" + flower->name()
         + "����֪�����ز���������\n", me);
    }
    else 
    {
        message_vision("$N�����һ��" + flower->name() + "�����������뷢����һ���춯������\n"
                        "��һֻ����Ȯ������Ȯ���غ���˼�������$N����������\n",me);
        dog->kill_ob(me);
        me->fight_ob(dog);
        message_vision("������ͷ�����춯�����ϳ��˹�����һ��$NҪ͵���Ĳ軨����Ŀ¶��\n"
                      "�⣬�����ȵ��������͵�ҵĲ軨����������$N��ȥ��\n", me );     
        if( !owner = present( "lao tou", environment( me ) ) )
        owner = new(__DIR__"npc/boss");
        owner->move( environment(me) );
        owner->kill_ob( me );
        me->start_busy(3);
    }
}

                                
    
