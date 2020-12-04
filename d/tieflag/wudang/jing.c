#include <ansi.h>
inherit ROOM; 
void create()
{
    set("short", "ˮ����");
    set("long", @LONG
��ˮ�����������������ܾ��ڻ������֡��������ڲ�������֪
��β��ܳ�ȥ�����л������ģ�����ʲô��û�С������������һ�£�
Ҳ������������
LONG
        );
    set("item_desc", ([
        "wall": "�������ֵľ��ڡ������������(climb)��ȥ��\n",
        "����": "�������ֵľ��ڡ������������(climb)��ȥ��\n",
        ]) );
    set("coor/x",150);
    set("coor/y",-130);
    set("coor/z",-40);
    setup();
} 
void init()
{
    add_action("do_climb", "climb");
    add_action("do_search", "search");
    call_out("airing", 5, this_player());
} 
int do_search(string arg)
{
    object ob;
    
    ob = this_player();
    if( ob->is_busy() )
        return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
    message_vision("$N��ϸ�Ĳ鿴���ܵľ��ڣ��ѱ��˸������䡣\n", ob);
    ob->start_busy(2);
    call_out("search_obj", 4, ob);
    return 1;
} 
int search_obj(object me)
{
    int kar;
    int exp;
    object sword, box ;
    
    if(!(this_object()->query("marks/û��")))
    {
        kar = (int)me->query("kar");
        exp = (int)me->query("combat_exp");
        if( kar > 40 ) kar = 40;
        if( (random(40 - kar) < 5) && exp >= 2000000 && me->query_skill("dodge",1)>=100)
        {
            this_object()->set("marks/û��", 1);
            message_vision(HIY "$N�ҵ���һ���������У��Ž��˻��\n"NOR, me);
            me->set_temp("marks/���ǽ�", 1);
            me->command("remove all");
            seteuid(geteuid(me));
            sword = new(__DIR__"obj/msword2");
            box = new(__DIR__"obj/box");
            sword->set_temp("marks/owner", me);
            sword->set_temp("marks/owner_name",me->query("id"));
            sword->move(box);
            box->move(me);
            if(!me->query("m_success/���ǽ�"))
            {
                me->set("m_success/���ǽ�",1);
                me->add("score",150);
                me->add("combat_exp",15000);
                me->add("potential",1900);
                tell_object(me,"�����ģ���õ�150�����ۣ�1900��Ǳ�ܣ�15000�㾭�飡\n");
                tell_object(me,"���������ǿ��뿪����ɡ�\n");
            }
        }
        else message_vision("$Nʲô��û�ҵ���\n", me);
    }
    else message_vision("$Nʲô��û�ҵ���\n", me);
    return 1;
} 
int airing(object ob)
{
    int i, htime, ntime;
    
    if( environment(ob) == this_object())
    {
        htime = (int)ob->query("str") + (int)ob->query("kar");
        if(!(ntime = (int)ob->query_temp("marks/��ʱ")))  ntime = 5;
        else ntime = ntime + 5;
        ob->set_temp("marks/��ʱ", ntime);
        if( ntime > htime ) {
            ob->die();
            ob->set_temp("marks/��ʱ", 0);
        }
        else if( ntime > (htime - 15) )
            message_vision(HIR "$N�Ѿ���óɰ����״̬���ٲ����Ͽ�������ͻ�����������\n"NOR, ob);
        else if( ntime > (htime - 30) )
            message_vision(HIR "$N�Ѿ���������࣬�����֮���ٲ����������»�����������\n"NOR, ob);
        else 
            message_vision(HIW "$N�����ؿ�Խ��Խ�ƣ�����ھ����Ѵ����˺ܾá�\n"NOR, ob);
        
        call_out("airing",5, ob);
    }
    return 1;
} 
int do_climb(string arg)
{
    object obj, me;
    int kar;
    
    if(!arg || arg=="") return notify_fail("��Ҫ����������\n");
    me = this_player();
    if( arg == "wall" || arg == "����" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
        message_vision("$Nʹ�����̵�������˳�ž���������ȥ��\n", me);
        me->start_busy(1);
        call_out("climb_wall", 2, me);
        return 1;
    }
    return notify_fail("�㲻������"+arg+"��\n");
}        
int climb_wall(object me)
{
    int kar;
    if (me->is_ghost()) return 0;
    kar = (int)me->query("kar");
    if( kar > 60 ) kar = 60;
    if( random(60 - kar) < 15 )
    {
        me->set_temp("marks/��ʱ", 0);
        me->move(__DIR__"wudang3.c");
        message_vision("$N��ˮ��ʪ���ܵ����˳�����\n", me);
    }
    else message_vision("$N����һ��ûץ�ȣ��ֵ���������\n", me);
    return 1;
}  
void reset()
{
    ::reset();
    delete("marks/û��");
}     
