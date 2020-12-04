 // Room: nilu1.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "����ɽ·"); 
        set("long", @LONG
����������·���ƺ����¹��꣬ɽ·Ҳ������Ţ���У����һ�Ÿ�һ����ǰŬ
�����ţ���һ������������������б��ˡ�ǰ�治Զ�ƺ��������ӣ��мҵ��̣���
��ǰ�ߣ�ɽ����������󣬵����������޷��������ǰ�Ķ����ˡ�
LONG);
        //{{ --- by MapMaker
        set("outdoors","shanliu");
        set("exits",([
        "northup":__DIR__"qigeban",
        "eastdown":__DIR__"nilu2",
        ]) );
        //}}
                set("objects", ([
                __DIR__"npc/tianzong3" : 1,
       ]) );
        set("outdoors", "shanliu");
        set("coor/x",-95);
        set("coor/y",-640);
        set("coor/z",30);
        setup();
        //replace_program(ROOM);
}
void init()
{
        object me;
        if (interactive(me=this_player()) && userp(me) && (me->query_temp("��ɽ��/�Ͷ���") || (string)me->query("organization/org_name")=="ɽ��"))
        {
                remove_call_out("killshanliu");
        call_out("killshanliu", 1, me);
        }
}
void killshanliu(object me)
{
        object ayan;
        if( !me || environment(me) != this_object() ) return;
   ayan = present("a yan",this_object());
        if (!ayan)
        {
                ayan = new(__DIR__"npc/tianzong3");
                ayan->move(this_object());
                message_vision("$N��ǰ��Ȼһ����һ����Ӱ��������ǰ��\n",me);
        }
        ayan->ccommand("rascal a yan");
        ayan->kill_ob(me);
} 
int valid_leave(object me, string dir)
{
        
        object assassinator;
        if (me->query_temp("��ɽ��/�Ͷ���"))
        {
                if ((assassinator = present("a yan",this_object())) && dir == "northup")
                {
                        return notify_fail(assassinator->name()+"����бָ����סȥ·�������������ߣ���ɱ���ҡ�\n");
                        //return notify_fail("no up");
                }
        }                
        if (random(6))
        {
                tell_object(me,"ɽ·Ҳ������Ţ���У����һ�Ÿ�һ����ǰŬ������\n");
                return notify_fail("");
        }                       
        return 1;
}   
