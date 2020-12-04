// С��ǰ /d/menpai/shennong/wuqian.c
// By lala, 1998-01-26

inherit ROOM;



void create()
{
    set("short",    "С��ǰ");
    set("long", @LONG
������һ�������С��ǰ��������é�����ɵģ����з�һ���ͻᵹ�ĸо���
��ǰ���߰���ķ���Щ����ƺ��Ǻþ�û�������ˡ�С·�����������죬��
��С�ݣ�һֱͨ��ɽ����
LONG
    );
    set("exits",    ([  /*sizeof()==3*/
        "eastup"    :   __DIR__"dong_shanao",
        "enter"     :   __DIR__"xiaowu",
        "westdown"  :   __DIR__"shanxi",
    ]) );
    set("objects",  ([
        __DIR__"npc/bangzhong"  :   2,
    ]) );
    set("outdoors", "wuliang");
    setup();
}

int valid_leave(object ppl, string dir)
{
    object npc, here = this_object();

    if( !npc = present( "bang zhong", here ) )
        return ::valid_leave(ppl, dir);
    if( living(npc) 
     && dir != "westdown" )
    {
        if( ppl->query("family/family_name") == "��ũ��" )
        {
            message_vision( "$N��$n�к������������������࡫����\n", 
                npc, ppl );
            return ::valid_leave(ppl, dir);
        }
        if( !ppl->query("family/family_name") )
        {
            message_vision( "$Nб�ۿ��˿�$n���������������ݰ���Ϊʦ�ġ�����\n", 
                npc, ppl );
            return ::valid_leave(ppl, dir);
        }
        return notify_fail( "��ũ���������һ�����ȵ�����ʲô�ˣ�����ʲô����\n" );
    }
    if( living(npc) 
     && !ppl->query("family/family_name") 
     && !ppl->query_temp("CanPass") )
        return notify_fail( "��ũ�������Цһ��������ô�ģ����˲���ʦ�����ߣ�����\n" );
    return ::valid_leave(ppl, dir);
}    
